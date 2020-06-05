#ifndef BOUND
#define BOUND

#include <cstddef>
#include "Quad.h"
class BoundingBox {
  private:
  size_t parent;
  void init(Quad quad) {
    xvalues[0] = quad.topL.x;
    xvalues[1] = quad.topR.x;
    xvalues[2] = quad.botR.x;
    xvalues[3] = quad.botL.x;

    yvalues[0] = quad.topL.y;
    yvalues[1] = quad.topR.y;
    yvalues[2] = quad.botR.y;
    yvalues[3] = quad.botL.y;

    for(int i=0; i<4; i++) {
      if(xvalues[i] > max.x) {
        max.x = xvalues[i];
      } else {
        if(xvalues[i] < min.x) {
          min.x = xvalues[i];
        }
      }
      if(yvalues[i] > max.y) {
        max.y = yvalues[i];
      } else {
        if(min.y < yvalues[i]) {
          min.y = yvalues[i];
        }
      }
    }
    box = Quad(Vector(min.x,min.y),Vector(max.x,max.y));
  }
  public:
  int xvalues[4],yvalues[4];
  Vector max,min;
  Quad box;
  BoundingBox(Quad &quad);
  BoundingBox();
  void update();
  void render(SDL_Renderer *rend);
};
#endif
