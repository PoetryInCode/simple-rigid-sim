#include "phys_obj.h"

/*
phys_obj::phys_obj(Quad object, Vector init_vel) {
  this->obj=object;
  this->velocity=init_vel;
  this->bounds=BoundingBox(object);
}*/
void phys_obj::force(Vector vec) {
  this->velocity.x += vec.x;
  this->velocity.y += vec.y;
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
  if(distanceTo(o.obj) <= obj.radius) {
    return true;
  } else {
    return false;
  }
}

void phys_obj::calculate_vectors(std::vector<phys_obj> objects) {
  for(int i=0; i<objects.size(); i++) {
    Vector step;
    int xvel = objects[i].velocity.x;
    int yvel = objects[i].velocity.y;
    if(xvel != 0) {
      if(xvel < 0) {
        objects[i].velocity.x++;
        step.x = -1;
      } else {
        if(xvel > 0) {
          objects[i].velocity.x--;
          step.x = 1;
        }
      }
    }
    if(yvel != 0) {
      if(yvel < 0) {
        objects[i].velocity.y++;
        step.y = -1;
      } else {
        if(yvel > 0) {
          objects[i].velocity.y--;
          step.y = 1;
        }
      }
    }
    objects[i].translate(step);
    for(int y=0; y<objects.size(); y++) {
      if(y != i) {
      }
    }
  }
}