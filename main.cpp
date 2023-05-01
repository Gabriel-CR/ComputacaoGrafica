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

void desenha() {
    GUI::displayInit();
    GUI::setLight(0, 1,2,3, true, false);
    GUI::setColor(1,0.6,0);
    GUI::drawFloor();
//    GUI::drawOrigin(0.5);
    GUI::drawOriginAL(2.5);

//    if (s > -1) {
////        objetos[s - 1]->selecionado = true;
////        objetos[s]->selecionado = false;
//        objetos[s]->selecionado = true;
//    }


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
    GUI::keyInit(tecla, mx,my);

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
        (s == 0) ? s = 0 : s -= 1;
        break;
    case '+':   // zerar t, r, e && colocar uma função para essa operação
        (s > (int)objetos.size()) ? s = (int)objetos.size() - 1 : s += 1;
        break;

    default:
        break;
    }
}

int main() {
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}
