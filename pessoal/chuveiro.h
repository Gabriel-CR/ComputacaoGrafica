#ifndef CHUVEIRO_H
#define CHUVEIRO_H

#include <objeto.h>
#include <cubo.h>

class Chuveiro : public Objeto {
    Model3DS* chuveiro;
public:
    Chuveiro();
    void desenha();
};

#endif // CHUVEIRO_H
