#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "phys_obj.h"
#include "Circle.h"
#include <time.h>

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

clock_t t=0;
void gravity(phys_obj *obj) {
  obj[0].velocity = Vector(obj[0].velocity.x,obj[0].velocity.x++);
}

int main() {
  init();
  cc = Color(BLACK);

  bool run = true;
  int w,h;
  //int mouseX,mouseY;

  SDL_GetWindowSize(win,&w,&h);

  //Vector vec = Vector(0,0);

  //Quad quad = Quad(vec,20,20);
  //quad.setColor(Color(RED));

  Vector buffer = Vector(0.0,0.0);
  bool change_vector[2] = {false,false};

  float step = 5.0;
  //float clamp_min = 0.5;

  bool trackmouse = false,modified=false;

  int x1,y1,x2,y2;

  //Quad rect;
  Circle draw;

  std::vector<phys_obj> objs;
  //std::vector<int> yvalues;

  //Circle c = Circle(Vector(250,250),50);
  //c.setColor(Color(RED));
  
  //objs.push_back(phys_obj(c));

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
          objs.push_back(phys_obj(draw, Vector(0,0)));
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
      case SDL_WINDOWEVENT:
        switch(event.window.event) {
          case SDL_WINDOWEVENT_RESIZED:
            SDL_GetWindowSize(win,&w,&h);
          break;
        }
      break;
      }
    }
    if(trackmouse) {
      /*rect = Quad(Vector(x1,y1),Vector(x2,y2));
      rect.setColor(Color(GREEN));
      rect.render(rend);*/
      if(x1 != x2 && y1 != y2) {
        draw = Circle(Vector(x1,y1),Vector(x1,y1).distanceTo(Vector(x2,y2)));
        draw.setColor(Color(GREEN));
        draw.render(rend);
      }
    }
    int floor_dis;
    for(uint i=0; i<objs.size(); i++) {
      floor_dis = objs[i].obj.center.distanceTo(Vector(objs[i].obj.center.x,h));
			objs[i].calculate_vectors(&objs,Vector(w,h));
      if(floor_dis >= objs[i].obj.radius) {
        objs[i].force(Vector(0,1));
        objs[i].translate(objs[i].velocity);
        printf("velocity of object %i (%f,%f)\n",i,objs[i].velocity.x,objs[i].velocity.y);
        //objs[i].calculate_vectors(objs);
      }/* else {
        if(objs[i].velocity.y != 0) {
          printf("Zeroing object %i\n",i);
          objs[i].velocity.y = 0;
          printf("velocity: (%f,%f)\n",objs[i].velocity.x,objs[i].velocity.y);
        }
        if(objs[i].obj.y != (h-objs[i].obj.radius)) {
          objs[i].obj.y = h-objs[i].obj.radius;
          printf("Moving %i off of border to (%i,%i)\n",i,objs[i].obj.x,objs[i].obj.y);
        }
      }*/
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
    //c.translate(buffer);
    //c.render(rend);
    //quad.translate(buffer);
    //quad.render(rend);
    SDL_RenderPresent(rend);
    SDL_Delay(1000/60);
  }
  return 0;
}
