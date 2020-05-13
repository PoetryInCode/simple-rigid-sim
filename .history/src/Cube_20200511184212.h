#include <Quad.h>
#include <Vertex.h>

class Cube {
    public:
    Quad left,top,right,bottom,back,front;
    Vertex btl,btr,bbr,bbl,ftl,ftr,fbr,fbl;

    Cube(Vertex backTopLeft,
        Vertex backTopRight,
        Vertex backBottomRight,
        Vertex backBottomLeft,
        Vertex frontTopLeft,
        Vertex frontTopRight,
        Vertex frontBottomRight,
        Vertex frontBottomLeft
    ) {
        this->btl=backTopLeft;
        this->btr=backTopRight;
        this->bbr=backBottomRight;
        this->bbl=backBottomLeft;
        this->ftl=frontTopRight;
        this->ftl=frontTopRight;
        this->fbl=frontBottomLeft;
        this->fbr=frontBottomRight;
    }
};