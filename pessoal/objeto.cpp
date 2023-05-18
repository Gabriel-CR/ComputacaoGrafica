#include "objeto.h"

Objeto::Objeto() {
}

Objeto::~Objeto() {
}

void Objeto::desenha() {
    // T.Rz.Ry.Rx.S (correspondente ao T'' da Q1 da lista 1)
    glTranslatef(translacao.x, translacao.y, translacao.z); //transformacao (matriz) mais a esquerda (mais global)
    glRotatef(rotacao.z, 0, 0, 1);  // \ .
    glRotatef(rotacao.y, 0, 1, 0);  //  | Rz.Ry.Rx . v
    glRotatef(rotacao.x, 1, 0, 0);  // /
    if (this->desenha_local) { GUI::drawOrigin(1); }
    glScalef(escala.x, escala.y, escala.z); //transformacao (matriz) mais a direita (mais local)
}

void Objeto::set_selecionado() {
    this->selecionado = !this->selecionado;
}

void Objeto::set_desenha_local() {
    this->desenha_local = !this->desenha_local;
}
