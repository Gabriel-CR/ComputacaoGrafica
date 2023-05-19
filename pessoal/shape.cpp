#include "shape.h"

Shape::Shape() {
}

Shape::Shape(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Shape::~Shape() {
}

void Shape::desenha() {
//    GUI::setColor(0.871/0.6, 0.416/0.6, 0.047/0.6);
    glBegin(GL_POLYGON);
        glNormal3f(0, 1, 0);
        glVertex3f(0.5, 0.0, -0.5);
        glVertex3f(-0.5, 0.0, -0.5);
        glVertex3f(-0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.5);
    glEnd();
}
