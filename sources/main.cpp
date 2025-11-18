//main.cpp
//Autor: Dario A. Uribe

/*
AVANCE 3: Simulacion completa de temporada de Formula 1

Caracteristicas implementadas:
1. Carga de datos desde multiples archivos CSV (pilotos, pistas)
2. Simulacion de temporada completa con calendario
3. Simulacion de carreras individuales con calculo de tiempos por vueltas
4. Sistema de puntos F1 (25, 18, 15, 12, 10, 8, 6, 4, 2, 1)
5. Clasificacion final usando MaxHeap ordenado por puntos totales
6. Lista Doblemente Ligada para gestionar parrilla
7. Merge Sort implicito mediante std::sort para ordenar resultados
*/

#include <iostream>
#include <ctime>
#include "temporada.h"

using namespace std;

void mostrarMenu() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "      SIMULADOR DE F1 2025" << endl;
    cout << "========================================" << endl;
    cout << "1. Ver calendario" << endl;
    cout << "2. Simular temporada completa" << endl;
    cout << "3. Ver clasificacion actual" << endl;
    cout << "4. Simular carrera individual" << endl;
    cout << "5. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Selecciona una opcion: ";
}

int main() {
    cout << "\033[47m\033[31m";

        cout << R"(
  _____ 
 |  ___|
 | |_   
 |  _|  
 | |    
 \_|    

  ___ 
 /_  |
  | | 
  | | 
 _| |_ 
 \___/ 
    )";

    srand(time(0));
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "  CARGANDO TEMPORADA 2025 DE F1" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Crear temporada
    Temporada temporada(2025);
    
    // Cargar datos
    cout << "Cargando pilotos..." << endl;
    temporada.cargarPilotos("data/pilotos.csv");
    
    cout << "Cargando calendario..." << endl;
    temporada.cargarCalendario("data/pistas.csv");
    
    cout << "Creando parrilla..." << endl;
    temporada.crearParrilla();
    
    cout << endl;
    cout << "Temporada cargada exitosamente!" << endl;
    cout << endl;
    
    int opcion = 0;
    bool ejecutando = true;
    int carreraActual = 0;
    
    while (ejecutando) {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                temporada.mostrarCalendario();
                break;
            }
            
            case 2: {
                cout << "\nEstas seguro de que deseas simular la temporada completa?" << endl;
                cout << "Esto puede tomar un tiempo. (s/n): ";
                char confirmacion;
                cin >> confirmacion;
                
                if (confirmacion == 's' || confirmacion == 'S') {
                    temporada.simularTemporada();
                    temporada.mostrarClasificacionCampeonato();
                    temporada.mostrarResumenTemporada();
                } else {
                    cout << "Simulacion cancelada." << endl;
                }
                break;
            }
            
            case 3: {
                temporada.mostrarClasificacionCampeonato();
                break;
            }
            
            case 4: {
                temporada.mostrarCalendario();
                cout << "Ingresa el numero de carrera a simular (1-21): ";
                int numCarrera;
                cin >> numCarrera;
                
                if (numCarrera >= 1 && numCarrera <= 21) {
                    cout << "\nSimulando carrera " << numCarrera << "..." << endl;
                    temporada.simularCarrera(numCarrera - 1);
                    temporada.mostrarClasificacionCampeonato();
                } else {
                    cout << "Numero de carrera invalido." << endl;
                }
                break;
            }
            
            case 5: {
                cout << "\nGracias por usar el simulador de F1 2025!" << endl;
                cout << "Hasta pronto." << endl;
                cout << "\033[0m";
                ejecutando = false;
                break;
            }
            
            default: {
                cout << "Opcion invalida. Intenta de nuevo." << endl;
                break;
            }
        }
    }
    return 0;
}
