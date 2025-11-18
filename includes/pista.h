// pista.h
// Autor: Darío A. Uribe

/*
La clase Pista representa un circuito de Fórmula 1 con sus características
específicas como nombre, número de vueltas y un identificador único.

Esta clase será utilizada por la clase Temporada para organizar el calendario
de carreras de la temporada.
*/

#ifndef PISTA_H
#define PISTA_H

#include <string>

using namespace std;

class Pista {
private:
    int id;
    string nombre;
    int vueltas;

public:
    Pista(int id, string nombre, int vueltas);

    int getId() const;
    
    string getNombre() const;
    
    int getVueltas() const;
    
    void mostrarInfo() const;
};

#endif