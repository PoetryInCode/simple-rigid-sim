#include "Quad.h"

class Cube {
  public:
  myColor color;
  Quad left,top,right,bottom,back,front;
  Vertex btl,btr,bbr,bbl,ftl,ftr,fbr,fbl;
  
  Cube(Vertex backTopLeft,
    Vertex backTopRight,
    Vertex backBottomRight,
    Vertex backBottomLeft,
    Vertex frontTopLeft,
    Vertex frontTopRight,
    Vertex frontBottomRight,
    Vertex frontBottomLeft
  );
  Cube(Quad left,
    Quad top,
    Quad right,
    Quad bottom,
    Quad front,
    Quad back
  );
  void setColor(myColor c);
};