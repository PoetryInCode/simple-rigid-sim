#define RED_f4 1.0f,0.0f,0.0f,1.0f
#define GREEN_f4 0.0f,1.0f,0.0f,1.0f
#define BLUE_f4 0.0f,0.0f,1.0f,1.0f
#define PURPLE_f4 1.0f,0.0f,1.0f,1.0f

class Color {
  public:
  float r,g,b,a;
  Color();
  Color(float r,float g,float b,float a) {
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
  }
};