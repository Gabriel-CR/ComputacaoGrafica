#include <iostream>
#include <vector>

using namespace std;

#include <gui.h>
#include <objeto.h>

#include <carro.h>
#include <cubo.h>
#include <sofa.h>
#include <televisao.h>
#include <caixasom.h>
#include <cama.h>
#include <guardaroupa.h>

Vetor3D t = Vetor3D(0, 0, 0);
Vetor3D r = Vetor3D(0, 0, 0);
Vetor3D e = Vetor3D(1, 1, 1);

vector<Objeto*> objetos;

bool desenha_objetos = false;
int s = (int)objetos.size() - 1;

void zerar_vetores() {
    t = objetos[s]->translacao;
    r = objetos[s]->rotacao;
    e = objetos[s]->escala;
}

void selecionar_proximo() {
    if (s == (int)objetos.size() - 1) {
        objetos[s]->selecionado = false;
    }

    s = (s + 1) % (int)objetos.size();

    zerar_vetores();

    if (s == 0) {
        objetos[s]->selecionado = true;
    } else {
        objetos[s]->selecionado = true;
        objetos[s - 1]->selecionado = false;
    }
}

void selecionar_anterior() {
    objetos[s]->selecionado = false;
    (s == 0) ? s = objetos.size() - 1 : s -= 1;
    objetos[s]->selecionado = true;
    zerar_vetores();
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0, 1,2,3, true, false);
    GUI::setColor(1,0.6,0);
    GUI::drawFloor();
    GUI::drawOriginAL(2.5);

    if (desenha_objetos) {
        for (int i = 0; i < (int)objetos.size(); i++) {
            if (objetos[i]->selecionado) {
                objetos[i]->translacao = t;
                objetos[i]->rotacao = r;
                objetos[i]->escala = e;
            }
            objetos[i]->desenha();
        }
    }

    t.x += glutGUI::dtx;
    t.y += glutGUI::dty;
    t.z += glutGUI::dtz;
    r.x += 4.0*glutGUI::dax;
    r.y += 4.0*glutGUI::day;
    r.z += 4.0*glutGUI::daz;
    e.x += glutGUI::dsx;
    e.y += glutGUI::dsy;
    e.z += glutGUI::dsz;

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int mx, int my) {
    if (desenha_objetos) {
        GUI::keyInit(tecla, mx,my);
    }

    switch (tecla) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'i': // colocar objeto na alinhado com o global
        t = Vetor3D(0, 0, 0);
        r = Vetor3D(0, 0, 0);
        e = Vetor3D(1, 1, 1);
        break;
    case 'd':
        desenha_objetos = !desenha_objetos;
        break;
    case 'D':   // remove todos os elementos do vetor
        objetos.clear();
        break;
    case 'b':
        if (desenha_objetos) { objetos.push_back(new Cama()); }
        break;
    case 'c':
        if (desenha_objetos) { objetos.push_back(new Carro()); }
        break;
    case 'C':
        if (desenha_objetos) { objetos.push_back(new CaixaSom()); }
        break;
    case 'g':
        if (desenha_objetos) { objetos.push_back(new GuardaRoupa()); }
        break;
    case 's':
        if (desenha_objetos) { objetos.push_back(new Sofa()); }
        break;
    case 'T':
        if (desenha_objetos) { objetos.push_back(new Televisao()); }
        break;

    case '-':   // zerar t, r, e && colocar uma função para essa operação
        selecionar_anterior();
        break;
    case '+':   // zerar t, r, e && colocar uma função para essa operação
        selecionar_proximo();
        break;

    default:
        break;
    }
}

int main() {
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
    cout << s << endl;
}
