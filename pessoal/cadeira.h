#ifndef CADEIRA_H
#define CADEIRA_H

#include <objeto.h>
#include <cubo.h>

class Cadeira : public Objeto {
public:
    Cadeira();
    ~Cadeira();
    void desenha();
};

#endif // CADEIRA_H
