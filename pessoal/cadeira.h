#ifndef CADEIRA_H
#define CADEIRA_H

#include <objeto.h>
#include <cubo.h>

class Cadeira : public Objeto {
public:
    Cadeira();
    Cadeira(float ex, float ey, float ez, float rx, float ry, float rz, float tx, float ty, float tz);
    ~Cadeira();
    void desenha();
};

#endif // CADEIRA_H
