#include <stdint.h>

#ifndef COLOR
#define COLOR

#ifndef RED
#define RED 255,0,0,255
#endif
#ifndef GREEN
#define GREEN 0,255,0,255
#endif
#ifndef BLUE
#define BLUE 0,0,255,255
#endif
#ifndef PURPLE
#define PURPLE 255,0,255,255
#endif
#ifndef WHITE
#define WHITE 255,255,255,255
#endif
#ifndef BLACK
#define BLACK 0,0,0,255
#endif

typedef unsigned char Uint8;

class Color {
  public:
  uint8_t r,g,b,a;
  Color();
  Color(uint8_t r,uint8_t g,uint8_t b,uint8_t a);
};
#endif
