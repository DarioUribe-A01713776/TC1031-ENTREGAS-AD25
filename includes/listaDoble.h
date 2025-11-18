// listaDoble.h
// Autor: Darío A. Uribe

/*
Se implementa una lista doblemente ligada para almacenar los monoplazas durante la simulación 
de la carrera.

Cada nodo contiene:
- Un puntero al monoplaza
- Un puntero al nodo siguiente
- Un puntero al nodo anterior

Esta estructura reemplaza al vector original para cumplir con los requisitos
del avance 2 del proyecto.
*/

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "monoplaza.h"
#include <vector>

using namespace std;

class Nodo {
public:
    Monoplaza* monoplaza;
    Nodo* siguiente;
    Nodo* anterior;
    
    Nodo(Monoplaza* m);
};

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;
    int tamano;

public:
    ListaDoble();
    
    void agregar(Monoplaza* m);
    
    void agregarInicio(Monoplaza* m);
    
    void eliminar(Nodo* nodo);
    
    Nodo* buscar(string nombrePiloto);
    
    Nodo* getCabeza() const;
    
    Nodo* getCola() const;
    
    int getTamano() const;
    
    bool estaVacia() const;
    
    vector<Monoplaza*> toVector();
    
    void actualizarDesdeVector(vector<Monoplaza*>& vec);
    
    void limpiar();
    
    void mostrarTodos();
    
    void mostrarInverso();
    
    ~ListaDoble();
};

#endif