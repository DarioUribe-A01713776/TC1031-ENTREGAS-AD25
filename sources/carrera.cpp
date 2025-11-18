// carrera.cpp
// Autor: Darío A. Uribe

#include "carrera.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Carrera::Carrera(Pista p) : pista(p) {}

void Carrera::agregarMonoplaza(Monoplaza* m) {
    parrilla.agregar(m);
}

void Carrera::merge(vector<Monoplaza*>& arr, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    vector<Monoplaza*> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[izquierda + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izquierda;

    while (i < n1 && j < n2) {
        if (L[i]->getTiempoCarrera() <= R[j]->getTiempoCarrera()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Carrera::mergeSort(vector<Monoplaza*>& arr, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arr, izquierda, medio);
        mergeSort(arr, medio + 1, derecha);

        merge(arr, izquierda, medio, derecha);
    }
}

void Carrera::simularVuelta(int numeroVuelta, int totalVueltas) {
    // Solo mostrar progreso en vueltas significativas
    if (numeroVuelta % 10 == 0 || numeroVuelta == 1 || numeroVuelta == totalVueltas) {
        cout << endl << "  === VUELTA " << numeroVuelta << "/" << totalVueltas << " ===" << endl;
        
        Nodo* actual = parrilla.getCabeza();
        
        while (actual) {
            int evento = rand() % 100;
            int chanceEvento = 8;  // 8% de probabilidad de evento
            
            if (evento < chanceEvento) {
                int tipoEvento = rand() % 3;
                
                switch (tipoEvento) {
                    case 0: {
                        // pit stop - agrega 25 segundos
                        cout << "    [VUELTA " << numeroVuelta << "] PIT STOP - " 
                             << actual->monoplaza->getNombrePiloto() 
                             << " (" << actual->monoplaza->getEscuderia() << ")" << endl;
                        actual->monoplaza->tiempoCarrera += 25;
                        break;
                    }
                    case 1: {
                        // adelantamiento - reduce 5 segundos
                        cout << "    [VUELTA " << numeroVuelta << "] ADELANTAMIENTO - " 
                             << actual->monoplaza->getNombrePiloto() 
                             << " (" << actual->monoplaza->getEscuderia() << ")" << endl;
                        actual->monoplaza->tiempoCarrera -= 5;
                        break;
                    }
                    case 2: {
                        // error - agrega 10 segundos
                        cout << "    [VUELTA " << numeroVuelta << "] ERROR - " 
                             << actual->monoplaza->getNombrePiloto() 
                             << " (" << actual->monoplaza->getEscuderia() << ")" << endl;
                        actual->monoplaza->tiempoCarrera += 10;
                        break;
                    }
                }
            }
            
            actual = actual->siguiente;
        }
    }
}

void Carrera::simularCarrera() {
    cout << "========================================" << endl;
    cout << "  CARRERA: " << pista.getNombre() << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << "Simulando " << pista.getVueltas() << " vueltas..." << endl;
    cout << "En progreso..." << endl;
    
    Nodo* actual = parrilla.getCabeza();
    while (actual) {
        actual->monoplaza->correr(pista.getVueltas());
        actual = actual->siguiente;
    }
    
    for (int vuelta = 1; vuelta <= pista.getVueltas(); vuelta++) {
        simularVuelta(vuelta, pista.getVueltas());
    }
    
    cout << endl;
    cout << "Carrera finalizada. Procesando resultados..." << endl;
    cout << endl;
    
    // obtener vector y ordenar con merge sort
    resultados = parrilla.toVector();
    if (!resultados.empty()) {
        mergeSort(resultados, 0, resultados.size() - 1);
    }
    
    parrilla.actualizarDesdeVector(resultados);
}

void Carrera::mostrarResultados() {
    cout << "========================================" << endl;
    cout << "  RESULTADOS: " << pista.getNombre() << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    resultados = parrilla.toVector();
    
    for (size_t i = 0; i < resultados.size(); i++) {
        cout << (i + 1) << ". ";
        resultados[i]->mostrarInfor();
        
        if (i < 10) {
            cout << "    Puntos: " << puntos[i] << endl;
        } else {
            cout << "    Puntos: 0" << endl;
        }
    }
    
    cout << endl;
}

vector<Monoplaza*> Carrera::getResultados() const {
    return resultados;
}

Pista Carrera::getPista() const {
    return pista;
}

int Carrera::obtenerPuntos(int posicion) const {
    if (posicion >= 0 && posicion < 11) {
        return puntos[posicion];
    }
    return 0;
}