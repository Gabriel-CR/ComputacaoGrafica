#include "caixasom.h"

CaixaSom::CaixaSom() {
}

void CaixaSom::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();

        glPushMatrix();
            glScalef(1, 1.5, 1);
            GUI::setColor(1*1.6, 1*1.6, 1*1.6);
            c.desenha();
            glPopMatrix();
    glPopMatrix();
}
