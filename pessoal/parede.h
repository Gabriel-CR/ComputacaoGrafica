#ifndef PAREDE_H
#define PAREDE_H

#include <objeto.h>
#include <cubo.h>

class Parede : public Objeto {
public:
    Parede();
    ~Parede();
    void desenha();
};

#endif // PAREDE_H
