// maxheap.h
// Autor: Darío A. Uribe

/*
La clase MaxHeap implementa un árbol binario heap para mantener la clasificación
de pilotos ordenados por puntos totales en la temporada.

El heap garantiza que el nodo raíz siempre contiene al piloto con más puntos,
permitiendo acceso O(1) al campeón y mantenimiento O(log n) al insertar.

Estructura de índices (para array):
- Padre de i: (i-1)/2
- Hijo izquierdo de i: 2*i + 1
- Hijo derecho de i: 2*i + 2
*/

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "piloto.h"
#include <vector>
#include <iostream>

using namespace std;

class NodoHeap {
public:
    Piloto piloto;
    int puntosTotales;
    
    NodoHeap(Piloto p, int pts = 0);
};

class MaxHeap {
private:
    vector<NodoHeap> heap;
    
    void flotar(int indice);
    
    void hundir(int indice);
    
    int getPadre(int indice) const;
    
    int getHijoIzq(int indice) const;
    
    int getHijoDer(int indice) const;
    
    bool existeIndice(int indice) const;

public:
    MaxHeap();
    
    void insertar(NodoHeap nodo);
    
    void actualizarPuntos(string nombrePiloto, int puntos);
    
    NodoHeap getCampeon() const;
    
    NodoHeap extraerRaiz();
    
    int getTamano() const;
    
    bool estaVacio() const;
    
    void mostrarClasificacion();
    
    vector<NodoHeap> getClasificacionOrdenada();
};

#endif