TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += trab1
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/cadeira.cpp \
    pessoal/cama.cpp \
    pessoal/carro.cpp \
    pessoal/circle.cpp \
    pessoal/cubo.cpp \
    pessoal/documento.cpp \
    pessoal/escorregador.cpp \
    pessoal/fogao.cpp \
    pessoal/geladeira.cpp \
    pessoal/guardaroupa.cpp \
    pessoal/mesa.cpp \
    pessoal/mesapc.cpp \
    pessoal/microondas.cpp \
    pessoal/mouse.cpp \
    pessoal/objeto.cpp \
    pessoal/pc.cpp \
    pessoal/piscina.cpp \
    pessoal/shape.cpp \
    pessoal/sofa.cpp \
    pessoal/televisao.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/cadeira.h \
    pessoal/cama.h \
    pessoal/carro.h \
    pessoal/circle.h \
    pessoal/cubo.h \
    pessoal/documento.h \
    pessoal/escorregador.h \
    pessoal/fogao.h \
    pessoal/geladeira.h \
    pessoal/guardaroupa.h \
    pessoal/mesa.h \
    pessoal/mesapc.h \
    pessoal/microondas.h \
    pessoal/mouse.h \
    pessoal/objeto.h \
    pessoal/pc.h \
    pessoal/piscina.h \
    pessoal/shape.h \
    pessoal/sofa.h \
    pessoal/televisao.h
