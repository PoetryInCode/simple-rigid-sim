#include "Vertex.h"

Vertex::Vertex(float x, float y, float z) {
  this->x=x;
  this->y=y;
  this->z=z;
  printf("Created a vertex at %f,%f,%f",x,y,z);
}

Vertex::Vertex() {}