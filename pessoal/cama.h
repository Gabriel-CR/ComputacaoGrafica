#ifndef CAMA_H
#define CAMA_H

#include <objeto.h>
#include <cubo.h>

class Cama : public Objeto {
public:
    Cama();
    ~Cama();
    void cama_solteiro();
    void desenha();
};

#endif // CAMA_H
