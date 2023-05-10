#ifndef GELADEIRA_H
#define GELADEIRA_H

#include <objeto.h>
#include <cubo.h>

class Geladeira : public Objeto {
    Model3DS* geladeira;
public:
    Geladeira();
    void desenha();
};

#endif // GELADEIRA_H
