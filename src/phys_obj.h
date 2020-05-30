#include "BoundingBox.h"
#include <vector>

class phys_obj {
  public:
  Vector velocity;
  Quad obj;
  BoundingBox bounds;
  phys_obj(Quad object, Vector init_vel);
  void force(Vector vec);
  void render(SDL_Renderer *rend);
  static void calculate_vectors(std::vector<phys_obj> objects);
  void translate(Vector vec);
  bool checkCollision(phys_obj o);
};