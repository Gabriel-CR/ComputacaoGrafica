#include "documento.h"

Documento::Documento() {
    documento = new Model3DS("../3ds/documento.3DS");
}

Documento::~Documento() {
    delete documento;
}

void Documento::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0.25, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(0.1, 0.1, 0.1);
            documento->draw();
        glPopMatrix();
        if (this->selecionado) {
            glPushMatrix();
                GUI::setColor(0, 1, 0, 0.6);
                glTranslatef(0, -0.05, 0);
                glScalef(0.6, 0.6, 0.4);
                c.desenha();
            glPopMatrix();
        }
    glPopMatrix();
}
