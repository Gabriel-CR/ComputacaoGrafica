#include "sofa.h"

Sofa::Sofa() {
}

void Sofa::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();

        GUI::setColor(1, 0.64, 0);
        glPushMatrix();
            glScaled(2, 0.5, 1);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1.2, 0, 0);
            glScalef(0.5, 1, 1);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-1.2, 0, 0);
            glScalef(0.5, 1, 1);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 0, -0.6);
            glScalef(2.9, 1.5, 0.25);
            c.desenha();
        glPopMatrix();
    glPopMatrix();


}
