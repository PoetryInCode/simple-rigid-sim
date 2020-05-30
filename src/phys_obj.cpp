#include "phys_obj.h"

#ifndef PI
#define PI 3.14159265359
#endif

phys_obj::phys_obj(Quad object, Vector init_vel) {
  this->obj=object;
  this->velocity=init_vel;
  this->bounds=BoundingBox(object);
}
void phys_obj::force(Vector vec) {
  this->velocity.x += vec.x;
  this->velocity.y += vec.y;
}
void phys_obj::render(SDL_Renderer *rend) {
  obj.render(rend);
  bounds.render(rend);
}

void phys_obj::translate(Vector vec) {
  obj.translate(vec);
  bounds.update();
}

bool phys_obj::checkCollision(phys_obj o) {
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