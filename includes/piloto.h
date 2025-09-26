//piloto.h
//Autor: Darío A. Uribe

#ifndef PILOTO_H
#define PILOTO_H

#include <string>
using namespace std;

class Piloto {
private: 
    string nombre;
    string dorsal;
    int habilidad;
    int probError;

public:
    Piloto(string nom, string dor, int hab, int prob);

    string getNombre() const;
    string getDorsal() const;
    int getHabilidad() const;
    int getProbError() const;
};

#endif
