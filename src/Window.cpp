#include "Window.h"

int Window::setClearColor(Color c) {
  clearColor = &c;
}

int Window::setClearColor(uint8_t r,Uint8 g,Uint8 b,Uint8 a) {
  clearColor[0].r = r;
  clearColor[0].g = g;
  clearColor[0].b = b;
  clearColor[0].a = a;
}

int Window::initUI() {
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr,"\033[92m[ ERROR ] Could not initialize SDL:\n%s\n", SDL_GetError());
  }
  win = SDL_CreateWindow("Simple Rigid Sim",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    500,
    500,
    0
  );
  rend = SDL_CreateRenderer(win,
    -1,
    SDL_RENDERER_ACCELERATED
  );
}

