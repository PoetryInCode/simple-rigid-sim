#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>

SDL_Window *gWindow = NULL;
SDL_GLContext gContext;

bool gRenderQuad = true;
int width=500,height=500;

bool init() {
  bool success = true;
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "[ERROR] Could not initialize SDL video\n%s\n", SDL_GetError());
    success = false;
  } else {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    gWindow = SDL_CreateWindow("Hydro Simulator",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      width,
      height,
      SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    if(gWindow == NULL) {

      fprintf(stderr, "[ERROR] Could not create an SDL window\n%s\n", SDL_GetError());
      success = false;

    } else {
      gContext = SDL_GL_CreateContext(gWindow);
      if(gContext == NULL) {
        fprintf(stderr, "[ERROR]Could not create an SDL OpenGL context\n%s\n", SDL_GetError());
        success = false;
      } else {
        if(SDL_GL_SetSwapInterval(1) < 0) {
          fprintf(stderr, "[ERROR] Could not set SDL vsync\n%s\n", SDL_GetError());
          success = false;
        }
      }
    }
  }
  return success;
}

bool initGL() {
  bool success = true;
  GLenum error = GL_NO_ERROR;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  error = glGetError();
  if(error != GL_NO_ERROR) {
    fprintf(stderr, "[ERROR] Could not initialize OpenGL matrix projection\n%s\n", gluErrorString(error));
    success = false;
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  error = glGetError();
  if(error != GL_NO_ERROR) {
    fprintf(stderr, "[ERROR] Could not initialize OpenGL matrix modelview\n%s\n", gluErrorString(error));
    success = false;
  }
  glClearColor(0,0,0,255);
  error = glGetError();
  if(error != GL_NO_ERROR) {
    fprintf(stderr, "[ERROR] Could not initialize the OpenGL clear color\n%s\n", gluErrorString(error));
    success = false;
  }
  return success;
}
void handleKeys(unsigned char key, int x, int y) {
  if(key == 'q') {
    gRenderQuad = !gRenderQuad;
  } else {
    if(key==SDL_SCANCODE_ESCAPE) {
      gRenderQuad = false;
    }
  }
}
void update() {
}
void render() {
  glClear(GL_COLOR_BUFFER_BIT);
  if(gRenderQuad) {
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);//green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
      
      glColor3f(1.0f, 0.5f, 0.0f);// Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
      
      glColor3f(1.0f, 0.0f, 0.0f);// Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
      
      glColor3f(1.0f, 1.0f, 0.0f);// Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
      
      glColor3f(0.0f, 0.0f, 1.0f);// Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      
      glColor3f(1.0f, 0.0f, 1.0f);// Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
  }
}
int main() {
  init();
  initGL();
  SDL_StartTextInput();
  bool quit = false;
  SDL_Event e;
  while(!quit) {
    while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
        quit = true;
      } else {
        if(e.type == SDL_TEXTINPUT) {
          int x=0,y=0;
          SDL_GetMouseState(&x,&y);
          handleKeys(e.text.text[0], x, y);
        }
      }
    }
    render();
    SDL_GL_SwapWindow(gWindow);
  }
  SDL_StopTextInput();
  return 0;
}
