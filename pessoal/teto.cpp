#include "teto.h"

Teto::Teto() {
}

void Teto::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.67, 0.3, 0.07);
            glBegin(GL_POLYGON);
                glNormal3f(0, 1, 0);
                glVertex3f(-2, 4.5, -4);
                glVertex3f(-2, 4.5, 4);
                glVertex3f(2, 4.5, 4);
                glVertex3f(2, 4.5, -4);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, -0.25, 3);
            glRotatef(35, 1, 0, 0);
            glBegin(GL_POLYGON);
                glNormal3f(0, 1, 0);
                glVertex3f(-2, 4.5, -2);
                glVertex3f(-5, 4.5, 2);
                glVertex3f(5, 4.5, 2);
                glVertex3f(2, 4.5, -2);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, -0.25, -2.8);
            glRotatef(-38, 1, 0, 0);
            glBegin(GL_POLYGON);
                glNormal3f(0, 1, 0);
                glVertex3f(-5, 4.5, -2);
                glVertex3f(-2, 4.5, 2);
                glVertex3f(2, 4.5, 2);
                glVertex3f(5, 4.5, -2);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.80, -0.25, 0);
            glRotatef(-38, 0, 0, 1);
            glBegin(GL_POLYGON);
                glNormal3f(0, 1, 0);
                glBegin(GL_POLYGON);
                    glNormal3f(0, 1, 0);
                    glVertex3f(-2, 4.5, -4);
                    glVertex3f(-2, 4.5, 4);
                    glVertex3f(2, 4.5, 7.5);
                    glVertex3f(2, 4.5, -7.5);
                glEnd();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.80, -0.25, 0);
            glRotatef(38, 0, 0, 1);
            glBegin(GL_POLYGON);
                glNormal3f(0, 1, 0);
                glBegin(GL_POLYGON);
                    glNormal3f(0, 1, 0);
                    glVertex3f(-2, 4.5, -7.5);
                    glVertex3f(-2, 4.5, 7.5);
                    glVertex3f(2, 4.5, 4);
                    glVertex3f(2, 4.5, -4);
                glEnd();
        glPopMatrix();
    glPopMatrix();
}
