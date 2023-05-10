#include "televisao.h"

Televisao::Televisao() {
}

void Televisao::desenha() {
    Cubo c = Cubo();

//    glTranslatef(translacao.x, translacao.y, translacao.z);
//    glRotatef(rotacao.z, 0, 0, 1);
//    glRotatef(rotacao.y, 0, 1, 0);
//    glRotatef(rotacao.x, 1, 0, 0);
//    if (this->desenha_local) { GUI::drawOrigin(1); }
//    glScalef(escala.x, escala.y, escala.z);


    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0.5, 0);
            glPushMatrix(); // PARTE DE TRAS
                glScalef(4, 1, 1);
                glScalef(1, 2, 1);
                glScalef(1, 1, 0.5);
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.451, 0.475, 0.627);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // TELA
                glTranslatef(0, 0.25, 0.25);
                glScalef(3.5, 1, 1);
                glScalef(1, 1.5, 1);
                glScalef(1, 1, 0.125);
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.169, 0.169, 0.169);
                c.desenha();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix(); // BASE
            glScalef(3, 1, 1);
            glScalef(1, 0.25, 1);
            glScalef(1, 1, 0.5);
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.451, 0.475, 0.627);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // SUPORTE DA BASE
            glTranslatef(-1, 0.25, 0);
            glScalef(0.2, 1, 1);
            glScalef(1, 0.25, 1);
            glScalef(1, 1, 0.25);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // SUPORTE DA BASE
            glTranslatef(1, 0.25, 0);
            glScalef(0.2, 1, 1);
            glScalef(1, 0.25, 1);
            glScalef(1, 1, 0.25);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
