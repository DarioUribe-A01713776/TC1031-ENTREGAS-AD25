// piloto.cpp
// Autor: Darío A. Uribe

/*
    Implementación de la clase Piloto con constructor vacío para uso en estructuras
    como el heap, y operador de comparación para búsquedas por nombre.
*/

#include "piloto.h"

Piloto::Piloto() : nombre(""), dorsal("0"), habilidad(0), probError(0) {}

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

bool Piloto::operator==(const Piloto& otro) const {
    return nombre == otro.nombre;
}