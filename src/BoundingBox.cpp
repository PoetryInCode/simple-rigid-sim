#include "BoundingBox.h"
#include <cstdlib>

BoundingBox::BoundingBox(Quad &quad) {
  this->parent = (size_t)&quad;
  init(quad);
}
BoundingBox::BoundingBox() {}

void BoundingBox::update() {
  Quad *quad = (Quad *)parent;
  init(quad[0]);
}

void BoundingBox::render(SDL_Renderer *rend) {
  uint8_t r,g,b,a;
  SDL_GetRenderDrawColor(rend,&r,&g,&b,&a);
  SDL_SetRenderDrawColor(rend,WHITE);
  SDL_RenderDrawLine(rend,box.topL.x,box.topL.y,box.topR.x,box.topR.y);
  SDL_RenderDrawLine(rend,box.topR.x,box.topR.y,box.botR.x,box.botR.y);
  SDL_RenderDrawLine(rend,box.botR.x,box.botR.y,box.botL.x,box.botL.y);
  SDL_RenderDrawLine(rend,box.botL.x,box.botL.y,box.topL.x,box.topL.y);
  SDL_SetRenderDrawColor(rend,r,g,b,a);
}