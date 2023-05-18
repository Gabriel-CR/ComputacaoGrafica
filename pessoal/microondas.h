#ifndef MICROONDAS_H
#define MICROONDAS_H

#include <objeto.h>
#include <cubo.h>

class Microondas : public Objeto {
    Model3DS* microondas;
public:
    Microondas();
    ~Microondas();
    void desenha();
};

#endif // MICROONDAS_H
