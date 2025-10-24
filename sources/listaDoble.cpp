// ListaDoble.cpp
// Autor: Darío A. Uribe

#include "ListaDoble.h"
#include <iostream>

using namespace std;

Nodo::Nodo(Monoplaza* m) : monoplaza(m), siguiente(nullptr), anterior(nullptr) {}
ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr), tamano(0) {}

void ListaDoble::agregar(Monoplaza* m) {
    Nodo* nuevo = new Nodo(m);
    
    if (!cabeza) {
        
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
    tamano++;
}

void ListaDoble::agregarInicio(Monoplaza* m) {
    Nodo* nuevo = new Nodo(m);
    
    if (!cabeza) {
        cabeza = cola = nuevo;
    } else {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
    tamano++;
}

void ListaDoble::eliminar(Nodo* nodo) {
    if (!nodo) return;
    
    if (nodo->anterior) {
        nodo->anterior->siguiente = nodo->siguiente;
    } else {
        cabeza = nodo->siguiente;
    }
    
    if (nodo->siguiente) {
        nodo->siguiente->anterior = nodo->anterior;
    } else {
        cola = nodo->anterior;
    }
    
    delete nodo;
    tamano--;
}

Nodo* ListaDoble::buscar(string nombrePiloto) {
    Nodo* actual = cabeza;
    while (actual) {
        actual = actual->siguiente;
    }
    return nullptr;
}

Nodo* ListaDoble::getCabeza() const {
    return cabeza;
}

Nodo* ListaDoble::getCola() const {
    return cola;
}

int ListaDoble::getTamano() const {
    return tamano;
}

bool ListaDoble::estaVacia() const {
    return cabeza == nullptr;
}

vector<Monoplaza*> ListaDoble::toVector() {
    vector<Monoplaza*> vec;
    Nodo* actual = cabeza;
    while (actual) {
        vec.push_back(actual->monoplaza);
        actual = actual->siguiente;
    }
    return vec;
}

void ListaDoble::actualizarDesdeVector(vector<Monoplaza*>& vec) {
    Nodo* actual = cabeza;
    for (size_t i = 0; i < vec.size() && actual; i++) {
        actual->monoplaza = vec[i];
        actual = actual->siguiente;
    }
}

void ListaDoble::limpiar() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cola = nullptr;
    tamano = 0;
}

void ListaDoble::mostrarTodos() {
    Nodo* actual = cabeza;
    int pos = 1;
    while (actual) {
        cout << pos << ". ";
        actual->monoplaza->mostrarInfor();
        actual = actual->siguiente;
        pos++;
    }
}

void ListaDoble::mostrarInverso() {
    Nodo* actual = cola;
    int pos = tamano;
    while (actual) {
        cout << pos << ". ";
        actual->monoplaza->mostrarInfor();
        actual = actual->anterior;
        pos--;
    }
}

ListaDoble::~ListaDoble() {
    limpiar();
}