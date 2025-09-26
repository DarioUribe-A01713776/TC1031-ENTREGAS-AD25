// monoplaza.h
// Autor: Darío A. Uribe

/*
    Sencillo y básico en el que se definen los getters de la clase Piloto. 
*/

#include "piloto.h"

Piloto::Piloto(string nom, string dor, int hab, int prob)
    : nombre(nom), dorsal(dor), habilidad(hab), probError(prob) {}

string Piloto::getNombre() const {
    return nombre;
}

string Piloto::getDorsal() const {
    return dorsal;
}

int Piloto::getHabilidad() const {
    return habilidad;
}

int Piloto::getProbError() const {
    return probError;
}
