#include "Circle.h"
#include <SDL2/SDL2_gfxPrimitives.h>

#ifndef PI
#define PI 3.14159265359
#endif

#define toradians(a) a*PI/180

Circle::Circle(Vector c, int r) {
  center.x = c.x;
  center.y = c.y;
  radius = r;
}

void Circle::translate(Vector vec) {
  if(vec.x != 0) {
    center.x += vec.x;
  }
  if(vec.y != 0) {
    center.y += vec.y;
  }
}

void Circle::setColor(Color c) {
  this->color = c;
}

void Circle::render(SDL_Renderer *renderer) {
  uint8_t r,g,b,a;
  SDL_GetRenderDrawColor(renderer,&r,&g,&b,&a);
  SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
  for(int x=center.x-radius; x<=center.x+radius; x++) {
    for(int y=center.y-radius; y<=center.y+radius; y++) {
      if((pow(center.y-y,2)+pow(center.x-x,2)) <= pow(radius,2)) {
        SDL_RenderDrawPoint(renderer,x,y);
      }
    }
  }
  SDL_SetRenderDrawColor(renderer,r,g,b,a);
}