#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <vector>
#include "Quad.h"

SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
SDL_GLContext gContext;

Color cc;

int init() {
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr,"\033[92m[ ERROR ] Could not initialize SDL:\n%s\n", SDL_GetError());
    return 0;
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
  if(rend == NULL) {
    return 0;
  } else {
    return 1;
  } 
}

uint8_t rt,gt,bt,at;

void clear(SDL_Renderer *renderer) {
  SDL_GetRenderDrawColor(renderer,&rt,&gt,&bt,&at);
  SDL_SetRenderDrawColor(renderer,cc.r,cc.g,cc.b,cc.a);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer,rt,gt,bt,at);
}

bool clamp(float *value, float val) {
  if(value[0] > val) {
    value[0] = 0.0;
    return false;
  } else {
    return true;
  }
}

int main() {
  init();
  cc = Color(BLACK);
  
  bool run = true;
  int w,h;
  //int mouseX,mouseY;

  SDL_GetWindowSize(win,&w,&h);

  Vector vec = Vector(0,0);

  Quad quad = Quad(vec,20,20);
  quad.setColor(Color(RED));

  Vector buffer = Vector(0.0,0.0);
  bool change_vector[2] = {false,false};

  float step = 5.0;
  //float clamp_min = 0.5;

  bool trackmouse = false,modified=false;

  int x1,y1,x2,y2;

  Quad rect;

  Quad *grav_objs = (Quad *)malloc(0);
  std::vector<Quad> objs;

  while(run) {
    if(modified) {
      clear(rend);
    }
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      modified = true;
      switch (event.type) {
        case SDL_QUIT:
          run = false;
        break;
        case SDL_MOUSEBUTTONDOWN:
          trackmouse = true;
          x1 = event.motion.x;
          y1 = event.motion.y;
          x2 = event.motion.x;
          y2 = event.motion.y;
          printf("Click at %i,%i\n",x1,y1);
        break;
        case SDL_MOUSEBUTTONUP:
          printf("Mouse released at %i,%i\n",x2,y2);
          trackmouse = false;
          objs.push_back(rect);
          //grav_objs = (Quad *)calloc(1,sizeof(Quad));
          //grav_objs[sizeof(grav_objs)/sizeof(grav_objs[0])] = rect;
          //printf("grav objs: %lu\n",(sizeof(grav_objs)/sizeof(grav_objs[0])));
        break;
        case SDL_MOUSEMOTION:
          if(trackmouse) {
            x2 = event.motion.x;
            y2 = event.motion.y;
          }
        break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_w:
              buffer.y=-step;
              change_vector[1] = false;
            break;
            case SDLK_a:
              buffer.x=-step;
              change_vector[0] = false;
            break;
            case SDLK_s:
              buffer.y=step;
              change_vector[1] = false;
            break;
            case SDLK_d:
              buffer.x=step;
              change_vector[0] = false;
            break;
          }
        case SDL_KEYUP:
          switch (event.key.state) {
            case SDL_RELEASED:
              switch(event.key.keysym.sym) {
                case SDLK_w:
                  buffer.y=0;
                  change_vector[1] = true;
                break;
                case SDLK_a:
                  buffer.x=0;
                  change_vector[0] = true;
                break;
                case SDLK_s:
                  buffer.y=0;
                  change_vector[1] = true;
                break;
                case SDLK_d:
                  buffer.x=0;
                  change_vector[0] = true;
                break;
              }
            break;
          }
        break;
      break;
      }
    }
    //change_vector[0] = clamp(&buffer.x,clamp_min);
    //change_vector[1] = clamp(&buffer.y,clamp_min);
    if(trackmouse) {
      rect = Quad(Vector(x1,y1),Vector(x2,y2));
      rect.setColor(Color(GREEN));
      rect.render(rend);
    }
    /*for(int i=0; i<sizeof(grav_objs)/sizeof(grav_objs[0]); i++) {
      grav_objs[i].setColor(Color(WHITE));
      grav_objs[i].render(rend);
    }*/
    for(int i=0; i<objs.size(); i++) {
      objs[i].render(rend);
    }
    if(change_vector[0]) {
      if(buffer.x != 0.0) {
        buffer.x = buffer.x/1.05;
        printf("%f",buffer.x);
      } else {
        buffer.x = 0;
      }
    }
    if(change_vector[1]) {
      if(buffer.y != 0.0) {
        buffer.y = buffer.y/1.05;
        printf("%f",buffer.x);
      } else {
        buffer.y = 0;
      }
    }
    quad.translate(buffer);
    quad.render(rend);
    SDL_RenderPresent(rend);
    SDL_GetWindowSize(win,&w,&h);
    SDL_Delay(1000/60);
  }
  return 0;
}
