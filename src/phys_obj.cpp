#include "phys_obj.h"

/*
phys_obj::phys_obj(Quad object, Vector init_vel) {
  this->obj=object;
  this->velocity=init_vel;
  this->bounds=BoundingBox(object);
}*/
void phys_obj::force(Vector vec) {
	if(vec.x != 0) {
		this->velocity.x += vec.x;
	}
	if(vec.y != 0) {
		this->velocity.y += vec.y;
	}
}
void phys_obj::render(SDL_Renderer *rend) {
  /*
  if(obj.isInitialized()) {
    if(circle.isInitialized()) {
      circle.render(rend);
    } else {
      fprintf(stderr,"[ERROR] Could not render object");
    }
  } else {
    obj.render(rend);
  }*/
  obj.render(rend);
}

phys_obj::phys_obj(Circle c, Vector init_vel) {
  this->obj = c;
  this->velocity = init_vel;
}

phys_obj::phys_obj(Circle c) {
  this->obj = c;
  this->velocity = Vector(0,0);
}

void phys_obj::translate(Vector vec) {
  obj.translate(vec);
  //bounds.update();
}

int phys_obj::distanceTo(Circle c) {
  return obj.center.distanceTo(c.center);
}

bool phys_obj::checkCollision(phys_obj o) {
  if((o.obj.radius + obj.radius) >=  distanceTo(o.obj)) {
    return true;
  } else {
    return false;
  }
}

std::vector<float> getYforces(std::vector<phys_obj> objs) {
  std::vector<float> values;
  for(uint i=0; i<objs.size(); i++) {
    values.push_back(objs[i].velocity.y);
  }
  return values;
}

std::vector<float> getXforces(std::vector<phys_obj> objs) {
  std::vector<float> values;
  for(uint i=0; i<objs.size(); i++) {
    values.push_back(objs[i].velocity.x);
  }
  return values;
}

bool noneEq(std::vector<float> nums, float comp) {
  bool state = true;
  for(uint i=0; i<nums.size(); i++) {
    if(nums[i] == comp) {
      state = false;
    }
  }
  return state;
}

bool anyEq(std::vector<float> nums, float comp) {
  bool state = false;
  for(uint i=0; i<nums.size(); i++) {
    if(nums[i] == comp) {
      state = true;
    }
  }
  return state;
}

bool allEq(std::vector<float> nums, float comp) {
	uint state=0;
	for(uint i=0; i<nums.size(); i++) {
		if(nums[i] == comp) {
			state++;
		}
	}
	if(state == nums.size()) {
		return true;
	} else {
		return false;
	}
}

void phys_obj::calculate_vectors(
	std::vector<phys_obj> *objects,
	Vector win_dim
) {
	for(uint i=0; i<objects[0].size(); i++) {
		Circle io=objects[0][i].obj;
		Vector ic=io.center;
		for(uint a=0; a<objects[0].size(); a++) {
			Circle ao=objects[0][a].obj;
			Vector ac=ao.center;
			if(i != a) { //dont check collision against self
				if(objects[0][i].checkCollision(objects[0][a])) {//check collision
					objects[0][i].translate(Vector(//move object out of other object
						-1*( io.getOverlap(ao)*ic.xDif(ac)/ic.distanceTo(ac)),
						-1*( io.getOverlap(ao)*ic.yDif(ac)/ic.distanceTo(ac))
					));
					objects[0][a].translate(Vector(
						io.getOverlap(ao)*ic.xDif(ac)/ic.distanceTo(ac),
						io.getOverlap(ao)*ic.yDif(ac)/ic.distanceTo(ac)
					));
				}
			}
			//window border collision detection
			if(ac.x+ao.radius < 0 ) { //left wall collision
				objects[0][a].translate(Vector(
					ac.xDif(Vector(0,ac.y))+ao.radius,
					0
				));
			} else if (ac.x+ao.radius > win_dim.x) {//right wall collision
				objects[0][a].translate(Vector(
					-1*(ac.xDif(Vector(win_dim.x,0))+ao.radius),
					0
				));
			}
			if(ac.y+ao.radius < 0 ) {//top collision
				//zero out the y component if it has collided
				objects[0][a].translate(Vector(
					0,
					ac.yDif(Vector(0,ac.y+ao.radius))
				));
			} else if (ac.y+ao.radius > win_dim.y) {//bottom collision
				objects[0][a].contact_floor = true;
				objects[0][a].translate(Vector(
					0,
					-1*(ac.yDif(Vector(0,win_dim.y-ao.radius)))
				));
			}/* else {
				if(objects[0][a].contact_floor) {
					objects[0][a].contact_floor = false;
				}
			}*/
		}
	}
	/*
	do {
  	for(uint i=0; i<objects.size(); i++) {
    	Vector step, v_buffer=objects[i].velocity;
    	int xvel = objects[i].velocity.x;
    	int yvel = objects[i].velocity.y;
			if(xvel != 0) {
	     	if(xvel < 0) {
	       	v_buffer.x++;
	       	step.x = -1;
	     	} else { //if xvel > 0
	       	v_buffer.x--;
	     		step.x = 1;
	     	}
	   	}
	   	if(yvel != 0) {
	     	if(yvel < 0) {
	       	v_buffer.y++;
	       	step.y = -1;
	     	} else { //if yvel > 0
	       	v_buffer.y--;
	       	step.y = 1;
	     	}
	   	}
	   	objects[i].translate(step);//translate the object
	   	for(uint a=0; a<objects.size(); a++) {
	     	if(i != a) {//dont check collision with self
	       	if(objects[i].checkCollision(objects[a])) {
						//caulculate collision here
	       	}
	     	}
	   	}
		}
	} while(!allEq(getXforces(objects),0) || !allEq(getYforces(objects),0));
	*/
}

void phys_obj::setPosition(Vector vec) {
  obj.center = vec;
}
