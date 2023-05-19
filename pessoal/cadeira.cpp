#include "cadeira.h"

Cadeira::Cadeira() {
}

//Cadeira::Cadeira(float ex, float ey, float ez, float rx, float ry, float rz, float tx, float ty, float tz) {
//    this->setEscala(Vetor3D(ex, ey, ez));
//    this->setRotacao(Vetor3D(rx, ry, rz));
//    this->setTranslacao(Vetor3D(tx, ty, tz));
//}

Cadeira::~Cadeira() {
}

void Cadeira::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // ASSENTO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(0, 0.6, 0);
            glScalef(1, 0.2, 1);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // ENCOSTO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0, 0.8, -0.4);
            glScalef(1, 1.1, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0.4, 0, 0.4);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(-0.4, 0, 0.4);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0.4, 0, -0.4);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(-0.4, 0, -0.4);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
