#include <iostream>
#include <vector>

using namespace std;

#include <gui.h>
#include <objeto.h>
#include <cubo.h>
#include <sofa.h>
#include <televisao.h>
#include <caixasom.h>

Vetor3D t = Vetor3D(0, 0, 0);
Vetor3D r = Vetor3D(0, 0, 0);
Vetor3D e = Vetor3D(1, 1, 1);

vector<Objeto*> objetos;

//Cubo* s = new Cubo();
Sofa* o = new Sofa();
CaixaSom* x = new CaixaSom();

Model3DS carro = Model3DS("../3ds/cartest.3DS");

void desenha() {
    GUI::displayInit();
    GUI::setLight(0, 1,2,3, true, false);
    GUI::setColor(1,0.6,0);
    GUI::drawFloor();
    GUI::drawOrigin(0.5);

//    s->set_selecionado();
    x->set_selecionado();

//    objetos.push_back(s);
    objetos.push_back(o);
    objetos.push_back(x);

    for (int i = 0; i < (int)objetos.size(); i++) {
        if (objetos[i]->selecionado) {
            objetos[i]->translacao = t;
            objetos[i]->rotacao = r;
            objetos[i]->escala = e;
        }
        objetos[i]->desenha();
//        glPushMatrix();
//            objetos[i]->desenha();
//        glPopMatrix();
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
    case 'L': // desenhar ou não coordenada local
        o->set_desenha_local();
    default:
        break;
    }
}

int main() {
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}
