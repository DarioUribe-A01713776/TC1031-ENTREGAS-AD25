// temporada.h
// Autor: Darío A. Uribe

/*
La clase Temporada representa una temporada completa de Fórmula 1. Gestiona:
- El calendario de carreras (pistas)
- La parrilla de pilotos y escuderías
- La simulación de cada carrera
- La clasificación final usando MaxHeap

El flujo es:
1. Cargar pilotos, escuderías y pistas desde archivos CSV
2. Crear monoplazas asociando pilotos con escuderías
3. Para cada pista en el calendario:
   - Simular la carrera
   - Actualizar puntos en el MaxHeap
4. Mostrar clasificación final del campeonato
*/

#ifndef TEMPORADA_H
#define TEMPORADA_H

#include "pista.h"
#include "carrera.h"
#include "piloto.h"
#include "monoplaza.h"
#include "maxheap.h"
#include "listaDoble.h"
#include <vector>
#include <string>

using namespace std;

class Temporada {
private:
    vector<Pista> calendario;
    vector<Piloto> pilotos;
    vector<Carrera> carreras;
    MaxHeap clasificacionCampeonato;
    ListaDoble parrilla;
    int numeroTemporada;

public:
    Temporada(int numero);
    
    void cargarPilotos(const string& archivo);
    
    void cargarCalendario(const string& archivo);
    
    void crearParrilla();
    
    void simularTemporada();
    
    void simularCarrera(int indexCarrera);
    
    void actualizarClasificacion(Carrera& carrera);
    
    void mostrarCalendario();
    
    void mostrarClasificacionCampeonato();
    
    void mostrarResumenTemporada();
    
    int getNumeroTemporada() const;
    
    MaxHeap getClasificacion() const;
};

#endif