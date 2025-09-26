// monoplaza.h
// Autor: Darío A. Uribe

#ifndef MONOPLAZA_H
#define MONOPLAZA_H

#include "piloto.h"
#include <string>
#include <iostream>

using namespace std;

class Monoplaza {
protected:
    string escuderia;
    Piloto piloto;
    int velocidad;
    int fiabilidad;
    int tiempoCarrera;

public:
    Monoplaza(string esc, Piloto pil, int vel, int fiab);

    virtual void correr() = 0;

    void mostrarInfor();

    int getTiempoCarrera() const;
};


class Sauber : public Monoplaza {
public:
    Sauber(Piloto pil);
    void correr() override;
};

class Alpine : public Monoplaza {
public:
    Alpine(Piloto pil);
    void correr() override;
};

class RB : public Monoplaza {
public:
    RB(Piloto pil);
    void correr() override;
};

class AstonMartin : public Monoplaza {
public:
    AstonMartin(Piloto pil);
    void correr() override;
};

class Ferrari : public Monoplaza {
public:
    Ferrari(Piloto pil);
    void correr() override;
};

class Haas : public Monoplaza {
public:
    Haas(Piloto pil);
    void correr() override;
};

class McLaren : public Monoplaza {
public:
    McLaren(Piloto pil);
    void correr() override;
};

class Mercedes : public Monoplaza {
public:
    Mercedes(Piloto pil);
    void correr() override;
};

class RedBull : public Monoplaza {
public:
    RedBull(Piloto pil);
    void correr() override;
};

class Williams : public Monoplaza {
public:
    Williams(Piloto pil);
    void correr() override;
};

#endif
