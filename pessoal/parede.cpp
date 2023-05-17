#include "parede.h"

Parede::Parede() {
}

void Parede::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // PAREDE ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(-1.5, 0, 0);
            glScalef(0.05, 2.5, 13);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PAREDE DIREITA
            glTranslatef(7.5, 0, 0);
            glScalef(0.05, 2.5, 10);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PAREDE FRENTE
            glTranslatef(1.48, 0, 6.5);
            glRotatef(90, 0, 1, 0);
            glScalef(0.05, 2.5, 6);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PAREDE TRAS
            glTranslatef(1, 0, -6.5);
            glRotatef(90, 0, 1, 0);
            glScalef(0.05, 2.5, 5);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PAREDE COZINHA SALA
            glTranslatef(1, 0, -3.5);
            glRotatef(90, 0, 1, 0);
            glScalef(0.05, 2.5, 5);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PAREDE SALA QUARTO 1
            glTranslatef(1, 0, 1.5);
            glRotatef(90, 0, 1, 0);
            glScalef(0.05, 2.5, 5);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PAREDE QUARTO BANHEIRO SUITE
            glTranslatef(4.5, 0, 4);
            glScalef(0.05, 2.5, 5);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
