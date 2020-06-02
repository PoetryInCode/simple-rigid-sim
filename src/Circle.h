#include <SDL2/SDL.h>
#include <cmath>
#include "Vector.h"
#include "Color.h"

#ifndef CIRCLE
#define CIRCLE
class Circle {
  private:
  int testpoint(int x,int y) {
    return pow(x,2)+pow(y,2)-pow(radius,2);
  }
  bool incircle(int x,int y) {
    return testpoint(x,y) < 0;
  }
  bool outcircle(int x,int y) {
    return testpoint(x,y) > 0;
  }
  bool oncircle(int x,int y) {
    return testpoint(x,y) == 0;
  }
  public:
  Color color;
  int x,y,radius;
  Vector center;
  Circle(Vector center, int radius);
  Circle();
  void render(SDL_Renderer *renderer);
  void translate(Vector vec);
  void setColor(Color c);
  void setPosition(Vector vec);
  //bool isInitialized();
};
#endif