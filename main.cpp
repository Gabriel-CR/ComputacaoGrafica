#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include <controller.h>

#include <gui.h>
#include <objeto.h>

#include <carro.h>
#include <cubo.h>
#include <sofa.h>
#include <televisao.h>
#include <cama.h>
#include <guardaroupa.h>
#include <cadeira.h>
#include <mesa.h>
#include <fogao.h>
#include <geladeira.h>
#include <microondas.h>
#include <pc.h>
#include <mouse.h>
#include <documento.h>
#include <mesapc.h>
#include <piscina.h>
#include <escorregador.h>
#include <vasosanitario.h>
#include <pia.h>
#include <chuveiro.h>
#include <parede.h>
#include <teto.h>

Vetor3D t = Vetor3D(0, 0, 0);
Vetor3D r = Vetor3D(0, 0, 0);
Vetor3D e = Vetor3D(1, 1, 1);

vector<Objeto*> objetos;

bool desenha_objetos = false;
bool selecionar = true;
int s = (int)objetos.size() - 1;
int cam_id = 0;

void zerar_vetores() {
    t = objetos[s]->translacao;
    r = objetos[s]->rotacao;
    e = objetos[s]->escala;
}

void selecionar_proximo() {
    if (selecionar) {
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
}

void selecionar_anterior() {
    if (selecionar) {
        objetos[s]->selecionado = false;
        (s == 0) ? s = objetos.size() - 1 : s -= 1;
        objetos[s]->selecionado = true;
        zerar_vetores();
    }
}

void apagar_objeto() {
    objetos.erase(objetos.begin() + s);
}

void apagar_ultimo_objeto() {
    objetos.pop_back();
}

void trocar_camera() {
    (cam_id + 1 > 6) ? cam_id = 0 : cam_id += 1;

    switch (cam_id) {
    case 0:
        glutGUI::cam = new CameraDistante(0,10,20, 0,0,0, 0,1,0);
        break;
    case 1:
        glutGUI::cam = new CameraDistante(8,19,21,  1,1,3,  0,1,0);
        break;
    case 2:
        glutGUI::cam = new CameraDistante(8,10,10,  1,1,3,  0,1,0);
        break;
    case 3:
        glutGUI::cam = new CameraDistante(8,5,3,  1,1,3,  0,1,0);
        break;
    case 4:
        glutGUI::cam = new CameraJogo(8,1,2,  1,1,3,  0,1,0);
        break;
    case 5:
        glutGUI::cam = new CameraJogo(8,9,2,  1,1,3,  0,1,0);
        break;
    case 6:
        glutGUI::cam = new CameraJogo(8,4,7,  1,1,3,  0,1,0);
        break;
    }
}

void salvar_cenario() {
    std::ofstream arquivo("../cenario.txt");
    if (arquivo.is_open()) {
        // Escreve no arquivo
        for (int i = 0; i < (int)objetos.size(); i++) {
            arquivo << objetos[i]->escala.x << endl;
            arquivo << objetos[i]->escala.y << endl;
            arquivo << objetos[i]->escala.z << endl;
            arquivo << objetos[i]->rotacao.x << endl;
            arquivo << objetos[i]->rotacao.y << endl;
            arquivo << objetos[i]->rotacao.z << endl;
            arquivo << objetos[i]->translacao.x << endl;
            arquivo << objetos[i]->translacao.y << endl;
            arquivo << objetos[i]->translacao.z << endl;
        }

        // Fecha o arquivo
        arquivo.close();

        std::cout << "Dados escritos com sucesso no arquivo." << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}

// USAR ESSA ESTRATÉGIA PARA DESENHAR O CENARIO
// FATORAR ESSA ESTRATÉGIA PARA CADA CÔMODO DA CASA
// AO SALVAR AS MODIFICAÇÕES DO CENÁRIO, USAR OS VALORES DOS VETORES PARA COLOCAR NO ARQUIVO
//  vetores de rotacao, translacao, escala
void cenario() {
    cout << "desenhando..." << endl;
    objetos.clear();

    objetos.push_back(new Cama());
    objetos.push_back(new MesaPc());
    objetos.push_back(new Pc());
    objetos.push_back(new Documento());
    objetos.push_back(new Cadeira());
    objetos.push_back(new GuardaRoupa());

    objetos.push_back(new Sofa());
    objetos.push_back(new Sofa());
    objetos.push_back(new Televisao());

    objetos.push_back(new Chuveiro());
    objetos.push_back(new Pia());
    objetos.push_back(new VasoSanitario());

    objetos.push_back(new Mesa());
    objetos.push_back(new Cadeira());
    objetos.push_back(new Cadeira());

    objetos.push_back(new Geladeira());
    objetos.push_back(new Fogao());
    objetos.push_back(new GuardaRoupa());
    objetos.push_back(new Microondas());

    objetos.push_back(new Piscina());
    objetos.push_back(new Escorregador());

    objetos.push_back(new Parede());

    // CAMA
    objetos[0]->translacao.add( Vetor3D(1, 0, 5.3) );
    objetos[0]->rotacao.add( Vetor3D(0, -90, 0) );
    // MESA PC
    objetos[1]->translacao.add( Vetor3D(1, 0, 2.3) );
    // PC
    objetos[2]->translacao.add( Vetor3D(0.2, 1.1, 2.3) );
    // DOCUMENTOS
    objetos[3]->translacao.add( Vetor3D(1.7, 1.1, 2.3) );
    // CADEIRA
    objetos[4]->rotacao.add( Vetor3D(0, 180, 0) );
    objetos[4]->translacao.add( Vetor3D(1, 0, 2.7) );
    // GUARDA ROUPA
    objetos[5]->rotacao.add( Vetor3D(0, -90, 0) );
    objetos[5]->translacao.add( Vetor3D(4, 0, 4) );

    // SOFA 1
    objetos[6]->rotacao.add( Vetor3D(0, -90, 0) );
    objetos[6]->translacao.add( Vetor3D(3, 0, -1) );
    // SOFA 2
    objetos[7]->rotacao.add( Vetor3D(0, 180, 0) );
    objetos[7]->translacao.add( Vetor3D(1, 0, 0.5) );
    // TELEVISAO
    objetos[8]->translacao.add( Vetor3D(1, 0, -3) );

    // CHUVEIRO
    objetos[9]->rotacao.add( Vetor3D(0, 180, 0) );
    objetos[9]->translacao.add( Vetor3D(6, 0, 6.5) );
    // PIA
    objetos[10]->rotacao.add( Vetor3D(0, 180, 0) );
    objetos[10]->translacao.add( Vetor3D(7.1, 1, 3) );
    // VASO SANITARIO
    objetos[11]->rotacao.add( Vetor3D(0, 90, 0) );
    objetos[11]->translacao.add( Vetor3D(5, 0, 3) );

    // MESA
    objetos[12]->translacao.add( Vetor3D(5.5, 0, -2) );
    // CADEIRA 1
    objetos[13]->translacao.add( Vetor3D(5.5, 0, -3) );
    // CADEIRA 2
    objetos[14]->rotacao.add( Vetor3D(0, 180, 0) );
    objetos[14]->translacao.add( Vetor3D(5.5, 0, -1) );

    // GELADEIRA
    objetos[15]->translacao.add( Vetor3D(0, 0, -5.8) );
    // FOGAO
    objetos[16]->translacao.add( Vetor3D(2, 0, -5.5) );
    // ARMARIO
    objetos[17]->escala.add( Vetor3D(-0.06, -0.5, 0) );
    objetos[17]->translacao.add( Vetor3D(5, 0, -6) );
    // MICROONDAS
    objetos[18]->translacao.add( Vetor3D(5, 1.3, -6) );

    // PISCINA
    objetos[19]->escala.add( Vetor3D(0.5, 0.5, 0.5) );
    objetos[19]->rotacao.add( Vetor3D(0, 90, 0) );
    objetos[19]->translacao.add( Vetor3D(-4.7, 0.01, 2) );
    // ESCORREGADOR
    objetos[20]->rotacao.add( Vetor3D(0, 45, 0) );
    objetos[20]->translacao.add( Vetor3D(-6, 0, -5) );

    // PAREDE
    objetos[21]->translacao.add( Vetor3D(3, 0, 0) );
}

void desenha() {
    GUI::displayInit();
    GUI::setLight(0, -5,5,3, true, false);
    GUI::setColor(1,0.6,0);
    GUI::drawFloor(15, 13);
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

//    Cama c = Cama();
//    c.desenha();

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
//    GUI::keyInit(tecla, mx,my);

    switch (tecla) {
    case 27:
        exit(0);
        break;
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
        if (desenha_objetos) { objetos.push_back(new Cadeira()); }
        break;
    case 'g':
        if (desenha_objetos) { objetos.push_back(new GuardaRoupa()); }
        break;
    case 'G':
        if (desenha_objetos) { objetos.push_back(new Geladeira()); }
        break;
    case 's':
        if (desenha_objetos) { objetos.push_back(new Sofa()); }
        break;
    case 'T':
        if (desenha_objetos) { objetos.push_back(new Televisao()); }
        break;
    case 'm':
        if (desenha_objetos) { objetos.push_back(new Mesa()); }
        break;
    case 'M':
        if (desenha_objetos) { objetos.push_back(new Microondas()); }
        break;
    case 'f':
        if (desenha_objetos) { objetos.push_back(new Fogao()); }
        break;
    case 'p':
        if (desenha_objetos) { objetos.push_back(new Pc()); }
        break;
    case 'r':
        if (desenha_objetos) { objetos.push_back(new Mouse()); }
        break;
    case 'P':
        if (desenha_objetos) { objetos.push_back(new Documento()); }
        break;
    case 'e':
        if (desenha_objetos) { objetos.push_back(new MesaPc()); }
        break;
    case 'a':
        if (desenha_objetos) { objetos.push_back(new Piscina()); }
        break;
    case 'E':
        if (desenha_objetos) { objetos.push_back(new Escorregador()); }
        break;
    case 'v':
        if (desenha_objetos) { objetos.push_back(new VasoSanitario()); }
        break;
    case 'k':
        if (desenha_objetos) { objetos.push_back(new Pia()); }
        break;
    case 'V':
        if (desenha_objetos) { objetos.push_back(new Chuveiro()); }
        break;
    case 'o':
        if (desenha_objetos) { objetos.push_back(new Parede()); }
        break;
    case 'O':
        if (desenha_objetos) { objetos.push_back(new Teto()); }
        break;

    case 'n':
        if (desenha_objetos) { cenario(); }
        break;
    case 'Q':
        trocar_camera();
        break;
    case 'F':
        if (s > -1) { apagar_objeto(); }
        break;
    case 'A':
        if (s > -1) { apagar_ultimo_objeto(); }
        break;
    case 'L':
        objetos[s]->desenha_local = !objetos[s]->desenha_local;
        break;
    case '-':   // zerar t, r, e && colocar uma função para essa operação
        if (objetos.size() > 0) { selecionar_anterior(); }
        break;
    case '+':   // zerar t, r, e && colocar uma função para essa operação
        if (objetos.size() > 0) { selecionar_proximo(); }
        break;
    case '/':   // zerar t, r, e && colocar uma função para essa operação
        selecionar = !selecionar;
        objetos[s]->selecionado = false;
        break;
    case '9':   // zerar t, r, e && colocar uma função para essa operação
        salvar_cenario();
        break;

    default:
        break;
    }
}

int main() {
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}
