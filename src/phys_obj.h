#include "BoundingBox.h"
#include "Circle.h"
#include <vector>

class phys_obj {
  public:
  Vector velocity;
  Circle obj;
  BoundingBox bounds;
	bool contact_floor;
  phys_obj();
  phys_obj(Circle c);
  phys_obj(Circle c, Vector init_vel);
  void force(Vector vec);
  void render(SDL_Renderer *rend);
  static void calculate_vectors(std::vector<phys_obj> *objects, Vector win_dim);
  void translate(Vector vec);
  bool checkCollision(phys_obj o);
	float angleTo(phys_obj o);
  int distanceTo(Circle c);
  void setPosition(Vector vec);
};
