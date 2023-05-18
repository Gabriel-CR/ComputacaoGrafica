#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto {
public:
    Vetor3D translacao = Vetor3D(0, 0, 0);
    Vetor3D rotacao = Vetor3D(0, 0, 0);
    Vetor3D escala = Vetor3D(1, 1, 1);

    bool selecionado = false;
    bool desenha_local = false;

public:
    Objeto();
    ~Objeto();
    virtual void desenha();
    void setTranslacao(Vetor3D vetor);
    void setRotacao(Vetor3D vetor);
    void setEscala(Vetor3D vetor);

    void set_selecionado();
    void set_desenha_local();
};

#endif // OBJETO_H
