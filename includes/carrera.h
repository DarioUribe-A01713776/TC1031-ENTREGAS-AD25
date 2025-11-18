// carrera.h
// Autor: Darío A. Uribe

/*
La clase Carrera representa una competencia de Fórmula 1 en una pista específica.
Maneja la simulación de la carrera, eventos aleatorios (pit stops, retiros, adelantamientos)
y el cálculo de puntos para el campeonato.

Utiliza la Lista Doblemente Ligada para gestionar los monoplazas durante la carrera,
Merge Sort para ordenar los resultados finales.
*/

#ifndef CARRERA_H
#define CARRERA_H

#include "pista.h"
#include "monoplaza.h"
#include "listaDoble.h"
#include <vector>

using namespace std;

class Carrera {
private:
    Pista pista;
    ListaDoble parrilla;
    vector<Monoplaza*> resultados;
    int puntos[11] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1, 0};  
    
    void merge(vector<Monoplaza*>& arr, int izquierda, int medio, int derecha);
    
    void mergeSort(vector<Monoplaza*>& arr, int izquierda, int derecha);

public:
    Carrera(Pista p);
    
    void agregarMonoplaza(Monoplaza* m);
    
    void simularCarrera();
    
    void simularVuelta(int numeroVuelta, int totalVueltas);
    
    void mostrarResultados();
    
    vector<Monoplaza*> getResultados() const;
    
    Pista getPista() const;
    
    int obtenerPuntos(int posicion) const;
};

#endif