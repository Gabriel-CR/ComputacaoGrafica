#ifndef SHAPE_H
#define SHAPE_H

#include <objeto.h>

class Shape : public Objeto {
public:
    Shape();
    ~Shape();
    void desenha();
};

#endif // SHAPE_H
