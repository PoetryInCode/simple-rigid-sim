#include "Color.h"
#include "Vertex.h"
#include <GL/glew.h>

class Quad {
  public:
  myColor color;
  Vertex topL,topR,botR,botL;
  Quad(Vertex topL, Vertex topR, Vertex botR, Vertex botL);
  Quad();
  void setColor(myColor c);
  void render();
};