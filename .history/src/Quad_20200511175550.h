#include <Color.h>
#include <Vertex.h>
#include <GL/glew.h>

class Quad {
  public:
  Color color;
  Vertex topL,topR,botR,botL;
  void setColor(Color color);
  void render();
  Quad(Vertex topL, Vertex topR, Vertex botR, Vertex botL) {
    this->topL=topL;
    this->topR=topR;
    this->botR=botR;
    this->botL=botL;
  }
};

void Quad::setColor(Color c) {
  color = c;
}

void Quad::render() {
  glColor4f(color.r,color.g,color.b,color.a);
  glVertex3f(topL.x,topL.y,topL.z);
  glVertex3f(topR.x,topR.y,topR.z);
  glVertex3f(botR.x,botR.y,botR.z);
  glVertex3f(botL.x,botL.y,botL.z);
}