#include "Quad.h"
#include "Vertex.h"

class Cube {
  public:
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
  )
  Cube(Quad left,
    Quad top,
    Quad right,
    Quad bottom,
    Quad front,
    Quad back
  )
  void setColor();
};

void Cube::setColor() {

}