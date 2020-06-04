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
  return sqrt(pow(abs(xDif(vec)),2)+pow(abs(yDif(vec)),2));
}
int Vector::xDif(Vector vec) {
	return x-vec.x;
}
int Vector::yDif(Vector vec) {
	return y-vec.y;
}
