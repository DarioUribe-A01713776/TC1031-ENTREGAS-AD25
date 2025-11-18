// monoplaza.h
// Autor: Darío A. Uribe

/*
En este archivo se define la clase Monoplaza, que representa de forma general
a un auto de Fórmula 1. La clase incluye atributos como escudería, piloto,
velocidad, fiabilidad y tiempo de carrera, esta clase la hice para diferenciar coches, y hacer la
simulacion mas real, ya que en los monoplazas de la F1 no todos son iguales. 

El atributo piloto proviene de la clase Piloto, lo que permite asociar cada
monoplaza con un conductor específico.

A partir de esta clase base se derivan las clases hijas, que corresponden a
cada escudería de la parrilla actual de la F1. 

Además, se declaran métodos virtuales como correr, los cuales son
sobrescritos por las clases hijas para simular el comportamiento de cada
escudería durante la carrera.
*/

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

public:
    int tiempoCarrera; 
    
    Monoplaza(string esc, Piloto pil, int vel, int fiab);

    virtual void correr(int vueltas) = 0;

    void mostrarInfor();

    int getTiempoCarrera() const;
    
    string getNombrePiloto() const;
    
    string getEscuderia() const;
};


class Sauber : public Monoplaza {
public:
    Sauber(Piloto pil);
    void correr(int vueltas) override;
};

class Alpine : public Monoplaza {
public:
    Alpine(Piloto pil);
    void correr(int vueltas) override;
};

class RB : public Monoplaza {
public:
    RB(Piloto pil);
    void correr(int vueltas) override;
};

class AstonMartin : public Monoplaza {
public:
    AstonMartin(Piloto pil);
    void correr(int vueltas) override;
};

class Ferrari : public Monoplaza {
public:
    Ferrari(Piloto pil);
    void correr(int vueltas) override;
};

class Haas : public Monoplaza {
public:
    Haas(Piloto pil);
    void correr(int vueltas) override;
};

class McLaren : public Monoplaza {
public:
    McLaren(Piloto pil);
    void correr(int vueltas) override;
};

class Mercedes : public Monoplaza {
public:
    Mercedes(Piloto pil);
    void correr(int vueltas) override;
};

class RedBull : public Monoplaza {
public:
    RedBull(Piloto pil);
    void correr(int vueltas) override;
};

class Williams : public Monoplaza {
public:
    Williams(Piloto pil);
    void correr(int vueltas) override;
};

#endif