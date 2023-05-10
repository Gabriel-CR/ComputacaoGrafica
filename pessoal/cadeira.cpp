#include "cadeira.h"

Cadeira::Cadeira() {
}

void Cadeira::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        c.desenha();
    glPopMatrix();
}
