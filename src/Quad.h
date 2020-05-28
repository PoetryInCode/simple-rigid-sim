#include "Color.h"
#include "SDL2/SDL.h"
#include "Vector.h"

class Quad {
  public:
  Color color;
  Vector topL,topR,botR,botL;
  //Quad(Vector topL, Vector topR, Vector botR, Vector botL);
  Quad(Vector topLeft, int width, int height);
  Quad(Vector corner1, Vector corner2);
  Quad();
  void setColor(Color c);
  void render(SDL_Renderer *renderer);
  void translate(Vector vec);
};