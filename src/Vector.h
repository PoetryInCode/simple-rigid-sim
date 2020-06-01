#ifndef VECTOR
#define VECTOR
class Vector {
  public:
  float x,y;
  Vector();
  Vector(float x, float y);
  int distanceTo(Vector vec);
};
#endif