// temporada.cpp
// Autor: Darío A. Uribe

#include "temporada.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

Temporada::Temporada(int numero) : numeroTemporada(numero) {}

void Temporada::cargarPilotos(const string& archivo) {
    ifstream file(archivo);
    
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << archivo << endl;
        return;
    }
    
    string linea;
    getline(file, linea);  // Saltar encabezado
    
    while (getline(file, linea)) {
        stringstream ss(linea);
        string nombre, dorsal, hab, prob;
        
        getline(ss, nombre, ',');
        getline(ss, dorsal, ',');
        getline(ss, hab, ',');
        getline(ss, prob, ',');
        
        pilotos.push_back(Piloto(nombre, dorsal, stoi(hab), stoi(prob)));
        // Inicializar en el heap con 0 puntos
        clasificacionCampeonato.insertar(NodoHeap(pilotos.back(), 0));
    }
    
    file.close();
    cout << "Pilotos cargados: " << pilotos.size() << endl;
}

void Temporada::cargarCalendario(const string& archivo) {
    ifstream file(archivo);
    
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << archivo << endl;
        return;
    }
    
    string linea;
    getline(file, linea);  // Saltar encabezado
    
    while (getline(file, linea)) {
        stringstream ss(linea);
        string id, nombre, vueltas;
        
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, vueltas, ',');
        
        calendario.push_back(Pista(stoi(id), nombre, stoi(vueltas)));
    }
    
    file.close();
    cout << "Calendario cargado: " << calendario.size() << " carreras" << endl;
}

void Temporada::crearParrilla() {
    if (pilotos.empty()) {
        cout << "Error: No hay pilotos cargados" << endl;
        return;
    }
    
    // Asociar pilotos con escuderías (simplificado: 2 pilotos por escudería)
    // Red Bull
    parrilla.agregar(new RedBull(pilotos[0]));      // Max Verstappen
    parrilla.agregar(new RedBull(pilotos[17]));     // Yuki Tsunoda
    
    // McLaren
    parrilla.agregar(new McLaren(pilotos[1]));      // Lando Norris
    parrilla.agregar(new McLaren(pilotos[18]));     // Oscar Piastri
    
    // Ferrari
    parrilla.agregar(new Ferrari(pilotos[7]));      // Charles Leclerc
    parrilla.agregar(new Ferrari(pilotos[15]));     // Lewis Hamilton
    
    // Mercedes
    parrilla.agregar(new Mercedes(pilotos[17]));    // George Russell
    parrilla.agregar(new Mercedes(pilotos[5]));     // Andrea Kimi Antonelli
    
    // Aston Martin
    parrilla.agregar(new AstonMartin(pilotos[8]));  // Lance Stroll
    parrilla.agregar(new AstonMartin(pilotos[4]));  // Fernando Alonso
    
    // Sauber
    parrilla.agregar(new Sauber(pilotos[11]));      // Nico Hulkenberg
    parrilla.agregar(new Sauber(pilotos[2]));       // Gabriel Bortoleto
    
    // Alpine
    parrilla.agregar(new Alpine(pilotos[4]));       // Pierre Gasly
    parrilla.agregar(new Alpine(pilotos[14]));      // Franco Colapinto
    
    // RB
    parrilla.agregar(new RB(pilotos[12]));          // Liam Lawson
    parrilla.agregar(new RB(pilotos[3]));           // Jack Doohan
    
    // Haas
    parrilla.agregar(new Haas(pilotos[19]));        // Oliver Bearman
    parrilla.agregar(new Haas(pilotos[13]));        // Esteban Ocon
    
    // Williams
    parrilla.agregar(new Williams(pilotos[10]));    // Alexander Albon
    parrilla.agregar(new Williams(pilotos[16]));    // Carlos Sainz
    
    cout << "Parrilla creada: " << parrilla.getTamano() << " monoplazas" << endl;
}

void Temporada::simularCarrera(int indexCarrera) {
    if (indexCarrera < 0 || indexCarrera >= (int)calendario.size()) {
        cout << "Error: Índice de carrera inválido" << endl;
        return;
    }
    
    Carrera carrera(calendario[indexCarrera]);
    
    // Agregar todos los monoplazas a la carrera
    Nodo* actual = parrilla.getCabeza();
    while (actual) {
        carrera.agregarMonoplaza(actual->monoplaza);
        actual = actual->siguiente;
    }
    
    carrera.simularCarrera();
    carrera.mostrarResultados();
    
    carreras.push_back(carrera);
    
    // Actualizar clasificación
    actualizarClasificacion(carrera);
}

void Temporada::actualizarClasificacion(Carrera& carrera) {
    vector<Monoplaza*> resultados = carrera.getResultados();
    
    // Puntos F1: 25, 18, 15, 12, 10, 8, 6, 4, 2, 1
    int puntosF1[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    
    for (size_t i = 0; i < resultados.size() && i < 10; i++) {
        // Usar getNombrePiloto() para actualizar el heap
        clasificacionCampeonato.actualizarPuntos(
            resultados[i]->getNombrePiloto(),
            puntosF1[i]
        );
    }
}

void Temporada::simularTemporada() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "  TEMPORADA " << numeroTemporada << " DE FORMULA 1" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    for (size_t i = 0; i < calendario.size(); i++) {
        cout << "\n[Carrera " << (i + 1) << "/" << calendario.size() << "]" << endl;
        simularCarrera(i);
        
        // Pausa entre carreras para que el usuario vea el resultado
        cout << "\nPresiona Enter para continuar a la siguiente carrera...";
        cin.ignore();
    }
}

void Temporada::mostrarCalendario() {
    cout << "CALENDARIO DE LA TEMPORADA " << numeroTemporada << endl;
    cout << "========================================" << endl;
    
    for (size_t i = 0; i < calendario.size(); i++) {
        cout << (i + 1) << ". ";
        calendario[i].mostrarInfo();
    }
    cout << endl;
}

void Temporada::mostrarClasificacionCampeonato() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "  CLASIFICACION FINAL - TEMPORADA " << numeroTemporada << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    clasificacionCampeonato.mostrarClasificacion();
    
    cout << endl;
    NodoHeap campeon = clasificacionCampeonato.getCampeon();
    cout << "CAMPEON DE LA TEMPORADA: " << campeon.piloto.getNombre() 
         << " con " << campeon.puntosTotales << " puntos!" << endl;
    cout << endl;
}

void Temporada::mostrarResumenTemporada() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "  RESUMEN DE LA TEMPORADA " << numeroTemporada << endl;
    cout << "========================================" << endl;
    cout << "Carreras simuladas: " << carreras.size() << "/" << calendario.size() << endl;
    cout << "Pilotos: " << pilotos.size() << endl;
    cout << endl;
}

int Temporada::getNumeroTemporada() const {
    return numeroTemporada;
}

MaxHeap Temporada::getClasificacion() const {
    return clasificacionCampeonato;
}