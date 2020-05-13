#include "Color.h"
#include "Vertex.h"
#include <GL/glew.h>

class Quad {
  public:
  Color color;
  Vertex topL,topR,botR,botL;
  Quad(Vertex topL, Vertex topR, Vertex botR, Vertex botL);
  Quad();
  void setColor(Color c);
  void render();
};