//piloto.h
//Autor: Darío A. Uribe

/*
Esta clase surge de la necesidad de diferenciar no solo a los monoplazas sino también a los pilotos.
Se me ocurrio ya cuando estaba desarrollando el proyecto.
Aunque dos corredores puedan usar el mismo auto, su rendimiento no será igual ejemplo: Verstappen vs. Tsunoda.
El atributo más relevante es probError, que representa la probabilidad de
que el piloto cometa un error, influyendo directamente en la simulación de la carrera.
*/


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
    Piloto();
    
    Piloto(string nom, string dor, int hab, int prob);

    string getNombre() const;
    string getDorsal() const;
    int getHabilidad() const;
    int getProbError() const;
    
    bool operator==(const Piloto& otro) const;
};

#endif