// pista.cpp
// Autor: Darío A. Uribe

#include "pista.h"
#include <iostream>

using namespace std;

Pista::Pista(int id, string nombre, int vueltas)
    : id(id), nombre(nombre), vueltas(vueltas) {}

int Pista::getId() const {
    return id;
}

string Pista::getNombre() const {
    return nombre;
}

int Pista::getVueltas() const {
    return vueltas;
}

void Pista::mostrarInfo() const {
    cout << "[" << id << "] " << nombre << " - " << vueltas << " vueltas" << endl;
}