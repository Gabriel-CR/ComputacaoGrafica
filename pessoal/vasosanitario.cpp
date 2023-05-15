#include "vasosanitario.h"

VasoSanitario::VasoSanitario() {
    vaso_sanitario = new Model3DS("../3ds/vaso.3DS");
}

void VasoSanitario::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90, 0, 1, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(0.04, 0.04, 0.04);
            vaso_sanitario->draw();
        glPopMatrix();
        if (this->selecionado) {
            glPushMatrix();
                GUI::setColor(0, 1, 0, 0.5);
                glTranslatef(0, -0.05, 0.1);
                glScalef(1, 1.2, 1.2);
                c.desenha();
            glPopMatrix();
        }
    glPopMatrix();
}
