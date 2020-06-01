#include "Quad.h"
#include <cstdlib>
#include <stdint.h>

/*Quad::Quad(Vector topL, Vector topR, Vector botR, Vector botL) {
  this->topL=topL;
  this->topR=topR;
  this->botR=botR;
  this->botL=botL;
}*/

Quad::Quad(Vector topLeft, int width, int height) {
  topL.x = topLeft.x;
  topL.y = topLeft.y;
  topR.x = topLeft.x+width;
  topR.y = topLeft.y;
  botR.x = topLeft.x+width;
  botR.y = topLeft.y-height;
  botL.x = topLeft.x;
  botL.y = topLeft.y-height;
  center = Vector(abs(topL.x-topR.x),abs(topL.y-botL.y));
}
Quad::Quad(Vector corner1,Vector corner2) {
  topL.x = corner1.x;
  topL.y = corner1.y;
  topR.x = corner2.x;
  topR.y = corner1.x;
  botR.x = corner2.x;
  botR.y = corner2.y;
  botL.x = corner1.x;
  botL.y = corner2.y;
  center = Vector(abs(topL.x-topR.x),abs(topL.y-botL.y));
}
Quad::Quad() {}

void Quad::render(SDL_Renderer *renderer) {
  uint8_t r,g,b,a;
  SDL_GetRenderDrawColor(renderer,&r,&g,&b,&a);
  SDL_SetRenderDrawColor(renderer, color.r,color.g,color.b,color.a);
  int xstart,xend;
  if(topL.x > topR.x) {
    xstart = topR.x;
    xend = topL.x;
  } else {
    xstart = topL.x;
    xend = topR.x;
  }
  int ystart,yend;
  if(topL.y > botL.y) {
    ystart = botL.y;
    yend = topL.y;
  } else {
    ystart = topL.y;
    yend = botL.y;
  }
  for(int x=xstart; x<xend; x++) {
    for(int y=ystart; y<yend; y++) {
      SDL_RenderDrawPoint(renderer,x,y);
    }
  }
  SDL_SetRenderDrawColor(renderer,r,g,b,a);
}

void Quad::setColor(Color c) {
  this->color=c;
}

void Quad::translate(Vector vec) {
  if(vec.x != 0) {
    topL.x += vec.x;
    topR.x += vec.x;
    botR.x += vec.x;
    botL.x += vec.x;
  }
  if(vec.y != 0) {
    topL.y += vec.y;
    topR.y += vec.y;
    botR.y += vec.y;
    botL.y += vec.y;
  }
}

std::vector<int> Quad::yvalues() {
  std::vector<int> values;
  values.push_back(topL.y);
  values.push_back(topR.y);
  values.push_back(botR.y);
  values.push_back(botL.y);
  return values;
}

/*
bool Quad::isInitialized() {
  if(topL.x != NULL) {
    return true;
  } else {
    return false;
  }
}*/