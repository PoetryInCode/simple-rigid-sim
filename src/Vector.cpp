#include "Vector.h"
#include <math.h>

Vector::Vector(float x, float y) {
  this->x=x;
  this->y=y;
}

Vector::Vector() {}

int Vector::distanceTo(Vector vec) {
  return sqrt(pow(abs(x - vec.x),2)+pow(abs(y - vec.y),2));
}