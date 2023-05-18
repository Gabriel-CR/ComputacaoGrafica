#ifndef MESA_H
#define MESA_H

#include <objeto.h>
#include <cubo.h>

class Mesa : public Objeto {
public:
    Mesa();
    ~Mesa();
    void desenha();
};

#endif // MESA_H
