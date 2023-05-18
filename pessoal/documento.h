#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <objeto.h>
#include <cubo.h>

class Documento : public Objeto {
    Model3DS* documento;
public:
    Documento();
    ~Documento();
    void desenha();
};

#endif // DOCUMENTO_H
