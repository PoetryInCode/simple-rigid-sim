#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "Color.h"

class Window {
  public:
  Color *clearColor = new Color(BLACK);
  SDL_Window *win;
  SDL_Renderer *rend;
  virtual int update() {};
  int initUI() {};
  int setClearColor(Color c) {};
  int setClearColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a) {};
};