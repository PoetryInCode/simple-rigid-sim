#include "Quad.h"
#include <iostream>

Quad::Quad(Vertex topL, Vertex topR, Vertex botR, Vertex botL) {
  this->topL=topL;
  this->topR=topR;
  this->botR=botR;
  this->botL=botL;
}

Quad::Quad() {}

void Quad::setColor(myColor c) {
  this->color=c;
}

void Quad::render() {
  printf("Rendering quad\n");
  glColor4f(color.r,color.g,color.b,color.a);
  glVertex3f(topL.x,topL.y,topL.z);
  glVertex3f(topR.x,topR.y,topR.z);
  glVertex3f(botR.x,botR.y,botR.z);
  glVertex3f(botL.x,botL.y,botL.z);
}