// maxheap.cpp
// Autor: Darío A. Uribe

#include "maxheap.h"
#include <algorithm>

using namespace std;

NodoHeap::NodoHeap(Piloto p, int pts)
    : piloto(p), puntosTotales(pts) {}

MaxHeap::MaxHeap() {}

int MaxHeap::getPadre(int indice) const {
    return (indice - 1) / 2;
}

int MaxHeap::getHijoIzq(int indice) const {
    return 2 * indice + 1;
}

int MaxHeap::getHijoDer(int indice) const {
    return 2 * indice + 2;
}

bool MaxHeap::existeIndice(int indice) const {
    return indice >= 0 && indice < (int)heap.size();
}

void MaxHeap::flotar(int indice) {
    while (indice > 0) {
        int padre = getPadre(indice);
        
        if (heap[indice].puntosTotales > heap[padre].puntosTotales) {
            swap(heap[indice], heap[padre]);
            indice = padre;
        } else {
            break;
        }
    }
}

void MaxHeap::hundir(int indice) {
    while (true) {
        int mayor = indice;
        int izq = getHijoIzq(indice);
        int der = getHijoDer(indice);
        
        if (existeIndice(izq) && heap[izq].puntosTotales > heap[mayor].puntosTotales) {
            mayor = izq;
        }
        
        if (existeIndice(der) && heap[der].puntosTotales > heap[mayor].puntosTotales) {
            mayor = der;
        }
        
        if (mayor != indice) {
            swap(heap[indice], heap[mayor]);
            indice = mayor;
        } else {
            break;
        }
    }
}

void MaxHeap::insertar(NodoHeap nodo) {
    heap.push_back(nodo);
    flotar(heap.size() - 1);
}

void MaxHeap::actualizarPuntos(string nombrePiloto, int puntos) {
    // Buscar el piloto en el heap
    for (size_t i = 0; i < heap.size(); i++) {
        if (heap[i].piloto.getNombre() == nombrePiloto) {
            int puntoAnterior = heap[i].puntosTotales;
            heap[i].puntosTotales += puntos;
            
            // Si aumentaron los puntos, flotar; si no, hundir
            if (heap[i].puntosTotales > puntoAnterior) {
                flotar(i);
            } else {
                hundir(i);
            }
            return;
        }
    }
    
    // Si no existe, crear nuevo nodo
    insertar(NodoHeap(Piloto(nombrePiloto, "0", 0, 0), puntos));
}

NodoHeap MaxHeap::getCampeon() const {
    if (!estaVacio()) {
        return heap[0];
    }
    return NodoHeap(Piloto("N/A", "0", 0, 0), 0);
}

NodoHeap MaxHeap::extraerRaiz() {
    if (estaVacio()) {
        return NodoHeap(Piloto("N/A", "0", 0, 0), 0);
    }
    
    NodoHeap raiz = heap[0];
    
    if (heap.size() == 1) {
        heap.pop_back();
    } else {
        heap[0] = heap.back();
        heap.pop_back();
        hundir(0);
    }
    
    return raiz;
}

int MaxHeap::getTamano() const {
    return heap.size();
}

bool MaxHeap::estaVacio() const {
    return heap.empty();
}

void MaxHeap::mostrarClasificacion() {
    // Crear copia temporal para no alterar el heap original
    MaxHeap tempHeap;
    tempHeap.heap = heap;
    
    int posicion = 1;
    while (!tempHeap.estaVacio()) {
        NodoHeap nodo = tempHeap.extraerRaiz();
        cout << posicion << ". " << nodo.piloto.getNombre() 
             << " - " << nodo.puntosTotales << " puntos" << endl;
        posicion++;
    }
}

vector<NodoHeap> MaxHeap::getClasificacionOrdenada() {
    vector<NodoHeap> clasificacion;
    MaxHeap tempHeap;
    tempHeap.heap = heap;
    
    while (!tempHeap.estaVacio()) {
        clasificacion.push_back(tempHeap.extraerRaiz());
    }
    
    return clasificacion;
}