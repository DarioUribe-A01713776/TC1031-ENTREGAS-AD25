// piloto.cpp
#include "piloto.h"

// Constructor
Piloto::Piloto(string nom, string dor, int hab, int prob)
    : nombre(nom), dorsal(dor), habilidad(hab), probError(prob) {}

// Métodos getters
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
