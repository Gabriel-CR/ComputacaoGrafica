#ifndef FOGAO_H
#define FOGAO_H

#include <objeto.h>
#include <cubo.h>


class Fogao : public Objeto {
    Model3DS* fogao;
public:
    Fogao();
    ~Fogao();
    void desenha();
};

#endif // FOGAO_H
