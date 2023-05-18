#include "cubo.h"

Cubo::Cubo() {
}

Cubo::~Cubo() {
}

void Cubo::desenha() {
    Shape s = Shape();

//    Objeto::desenha();

    // MODIFICAR PARA ADICIONAR A COR

    /*
    glRotatef(180, 0.5, 0, 0);
    s.desenha();

    glTranslatef(0, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    s.desenha();

    glTranslatef(0, 0.5, -0.5);
    glRotatef(-90, 1, 0, 0);
    s.desenha();

    glTranslatef(0.5, 0.5, 0);
    glRotatef(-90, 0, 0, 1);
    s.desenha();

    glTranslatef(-0.5, 0.5, 0);
    glRotatef(90, 0, 0, 1);
    s.desenha();

    glTranslatef(0, 1, 0);
    s.desenha();
    */

    glPushMatrix();
        glRotatef(180, 0.5, 0, 0);
//        GUI::setColor(1, 1, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 0.5, 0.5);
        glRotatef(90, 1, 0, 0);
//        GUI::setColor(1, 1, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 0.5, -0.5);
        glRotatef(-90, 1, 0, 0);
//        GUI::setColor(1, 1, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.5, 0.5, 0);
        glRotatef(-90, 0, 0, 1);
//        GUI::setColor(1, 1, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.5, 0.5, 0);
        glRotatef(90, 0, 0, 1);
//        GUI::setColor(1, 1, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 1, 0);
//        GUI::setColor(1, 1, 1);
        s.desenha();
    glPopMatrix();
}
