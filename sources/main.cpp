//main.cpp
//Autor: Darío A. Uribe

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>
#include "monoplaza.h"
#include "piloto.h"
#include "ListaDoble.h"

using namespace std;

/*
AVANCE 2: Mejoras implementadas
1. Carga de datos desde archivo CSV
2. Uso de lista doblemente ligada en lugar de vector (Ocupo el vector para ordernar y cargar los datos, 
pero depues los implemento en la double linked list
datos los  en la linked double list)
3. Programa interactivo con selección de piloto y vueltas

El algoritmo MergeSort se mantiene para ordenar los resultados.
*/

vector<Piloto> cargarPilotos(const string& archivo) {
    vector<Piloto> pilotos;
    ifstream file(archivo);
    
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << archivo << endl;
        return pilotos;
    }
    
    string linea;
    getline(file, linea);
    
    while (getline(file, linea)) {
        stringstream ss(linea);
        string nombre, dorsal, hab, prob;
        
        getline(ss, nombre, ',');
        getline(ss, dorsal, ',');
        getline(ss, hab, ',');
        getline(ss, prob, ',');
        
        pilotos.push_back(Piloto(nombre, dorsal, stoi(hab), stoi(prob)));
    }
    
    file.close();
    return pilotos;
}

Piloto* buscarPiloto(vector<Piloto>& pilotos, const string& nombre) {
    for (auto& p : pilotos) {
        if (p.getNombre() == nombre) {
            return &p;
        }
    }
    return nullptr;
}

void merge(vector<Monoplaza*>& arr, int izquierda, int medio, int derecha) {
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

void mergeSort(vector<Monoplaza*>& arr, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arr, izquierda, medio);
        mergeSort(arr, medio + 1, derecha);

        merge(arr, izquierda, medio, derecha);
    }
}

int main() {
    srand(time(0));

    cout << "   SIMULADOR DE CARRERAS DE F1 2025" << endl;
    cout << endl;

    vector<Piloto> pilotos = cargarPilotos("sources/pilotos.csv");    
    
    if (pilotos.empty()) {
        cout << "No se pudieron cargar los pilotos." << endl;
        return 1;
    }

    cout << "Pilotos cargados exitosamente: " << pilotos.size() << " pilotos" << endl;
    cout << endl;

    cout << "PILOTOS DISPONIBLES:" << endl;
    for (size_t i = 0; i < pilotos.size(); i++) {
        cout << (i + 1) << ". " << pilotos[i].getNombre() 
             << " (#" << pilotos[i].getDorsal() << ")"
             << " - Habilidad: " << pilotos[i].getHabilidad() << endl;
    }
    cout << endl;

    // Selección de piloto favorito
    int opcionPiloto;
    cout << "Selecciona tu piloto favorito (1-" << pilotos.size() << "): ";
    cin >> opcionPiloto;
    
    while (opcionPiloto < 1 || opcionPiloto > (int)pilotos.size()) {
        cout << "Opción invalida. Intenta de nuevo (1-" << pilotos.size() << "): ";
        cin >> opcionPiloto;
    }
    
    Piloto pilotoFavorito = pilotos[opcionPiloto - 1];
    cout << "\nSeleccionaste a " << pilotoFavorito.getNombre() << "!" << endl;
    cout << endl;

    int vueltas;
    cout << "Ingresa el numero de vueltas para la carrera (1-71): ";
    cin >> vueltas;
    
    while (vueltas < 1 || vueltas > 71) {
        cout << "Numero inválido. Intenta de nuevo (1-71): ";
        cin >> vueltas;
    }
    
    cout << "\nConfiguración de carrera:" << endl;
    cout << "- Vueltas: " << vueltas << endl;
    cout << "- Piloto favorito: " << pilotoFavorito.getNombre() << endl;
    cout << endl;

    // Crear todos los monoplazas (usando los pilotos cargados)
    Piloto* p_verstappen = buscarPiloto(pilotos, "Max Verstappen");
    Piloto* p_norris = buscarPiloto(pilotos, "Lando Norris");
    Piloto* p_bortoleto = buscarPiloto(pilotos, "Gabriel Bortoleto");
    Piloto* p_doohan = buscarPiloto(pilotos, "Jack Doohan");
    Piloto* p_gasly = buscarPiloto(pilotos, "Pierre Gasly");
    Piloto* p_antonelli = buscarPiloto(pilotos, "Andrea Kimi Antonelli");
    Piloto* p_alonso = buscarPiloto(pilotos, "Fernando Alonso");
    Piloto* p_leclerc = buscarPiloto(pilotos, "Charles Leclerc");
    Piloto* p_stroll = buscarPiloto(pilotos, "Lance Stroll");
    Piloto* p_tsunoda = buscarPiloto(pilotos, "Yuki Tsunoda");
    Piloto* p_albon = buscarPiloto(pilotos, "Alexander Albon");
    Piloto* p_hulkenberg = buscarPiloto(pilotos, "Nico Hulkenberg");
    Piloto* p_lawson = buscarPiloto(pilotos, "Liam Lawson");
    Piloto* p_ocon = buscarPiloto(pilotos, "Esteban Ocon");
    Piloto* p_colapinto = buscarPiloto(pilotos, "Franco Colapinto");
    Piloto* p_hamilton = buscarPiloto(pilotos, "Lewis Hamilton");
    Piloto* p_sainz = buscarPiloto(pilotos, "Carlos Sainz");
    Piloto* p_russell = buscarPiloto(pilotos, "George Russell");
    Piloto* p_piastri = buscarPiloto(pilotos, "Oscar Piastri");
    Piloto* p_bearman = buscarPiloto(pilotos, "Oliver Bearman");

    Sauber sb1(*p_hulkenberg);
    Sauber sb2(*p_bortoleto);
    Alpine alp1(*p_gasly);
    Alpine alp2(*p_colapinto);
    RB rb1(*p_lawson);
    RB rb2(*p_doohan);
    AstonMartin atm1(*p_stroll);
    AstonMartin atm2(*p_alonso);
    Ferrari ferr1(*p_leclerc);
    Ferrari ferr2(*p_hamilton);
    Haas has1(*p_bearman);
    Haas has2(*p_ocon);
    McLaren mcl1(*p_norris);
    McLaren mcl2(*p_piastri);
    Mercedes mer1(*p_russell);
    Mercedes mer2(*p_antonelli);
    RedBull rbl1(*p_verstappen);
    RedBull rbl2(*p_tsunoda);
    Williams will1(*p_albon);
    Williams will2(*p_sainz);

    // Crear lista doble en lugar de vector
    ListaDoble parrilla;
    
    parrilla.agregar(&sb1);
    parrilla.agregar(&sb2);
    parrilla.agregar(&alp1);
    parrilla.agregar(&alp2);
    parrilla.agregar(&rb1);
    parrilla.agregar(&rb2);
    parrilla.agregar(&atm1);
    parrilla.agregar(&atm2);
    parrilla.agregar(&ferr1);
    parrilla.agregar(&ferr2);
    parrilla.agregar(&has1);
    parrilla.agregar(&has2);
    parrilla.agregar(&mcl1);
    parrilla.agregar(&mcl2);
    parrilla.agregar(&mer1);
    parrilla.agregar(&mer2);
    parrilla.agregar(&rbl1);
    parrilla.agregar(&rbl2);
    parrilla.agregar(&will1);
    parrilla.agregar(&will2);

    cout << "*Imaginar el semaforo de la carrera*" << endl;
    cout << "COMIENZA LA CARRERA" << endl;
    cout << "Simulando " << vueltas << " vueltas..." << endl;
    cout << endl;

    Nodo* actual = parrilla.getCabeza();
    while (actual) {
        actual->monoplaza->correr();
        actual = actual->siguiente;
    }

    vector<Monoplaza*> vecTemp = parrilla.toVector();
    mergeSort(vecTemp, 0, vecTemp.size() - 1);
    parrilla.actualizarDesdeVector(vecTemp);

    cout << "       RESULTADOS DE LA CARRERA" << endl;
    cout << endl;
    
    parrilla.mostrarTodos();
    
    cout << endl;
    cout << "LA SIMULACION TERMINO" << endl;

    return 0;
}