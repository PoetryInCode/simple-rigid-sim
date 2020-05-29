#include "phys_obj.h"

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