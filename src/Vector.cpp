#include "Vector.h"
#include <math.h>

Vector::Vector(float x, float y) {
  this->x=x;
  this->y=y;
}

Vector::Vector() {
  this->x=0;
  this->y=0;
}

int Vector::distanceTo(Vector vec) {
  return sqrt(pow(abs(x - vec.x),2)+pow(abs(y - vec.y),2));
}