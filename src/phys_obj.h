#include "BoundingBox.h"

class phys_obj {
  public:
  Vector velocity;
  Quad obj;
  BoundingBox bounds;
  phys_obj(Quad object, Vector init_vel);
  void force(Vector vec);
  void render(SDL_Renderer *rend);
};