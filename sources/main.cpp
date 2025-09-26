//main.cpp
//Autor: Darío A. Uribe

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "monoplaza.h"
#include "piloto.h"

using namespace std;


/*
En este programa se utiliza el algoritmo de ordenamiento MergeSort para organizar
los resultados de la carrera de Fórmula 1. La idea principal es ordenar el vector
de monoplazas (parrilla) en función de su tiempo de carrera, de menor a mayor.

MergeSort es un algoritmo de tipo "divide y vencerás". Su funcionamiento se basa en:
1. Dividir el arreglo en dos mitades recursivamente hasta obtener subarreglos de tamaño 1.
2. Una vez que se llega a ese punto, se comienza a combinar (merge) los subarreglos 
   de manera ordenada comparando elemento por elemento.
3. En el caso de este proyecto, la comparación se hace mediante el atributo 
   tiempoCarrera de cada monoplaza.

La función merge recibe dos subarreglos ya ordenados y los une en un único arreglo 
ordenado. El menor de los dos se coloca en la posición actual del arreglo original, este proceso 
se repite hasta que todos los elementos han sido insertados en orden.

De esta manera, al final de todas las combinaciones, el vector parrilla queda
completamente ordenado, representando los resultados de la carrera desde el primer
puesto hasta el último.

En cuanto a la eficiencia:
- Complejidad temporal: O(n log n), ya que en cada nivel de recursión se hacen n 
  comparaciones y hay log n niveles de división.
- Complejidad espacial: O(n), debido al uso de arreglos temporales L y R en el merge.

*/


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


// La funcion o flujo si se puede llamar asi es el siguiente: 
// 1. Se inicializan los pilotos con sus atributos.
// 2. Se crean las escuderías (monoplazas) asignando a cada una un piloto.
// 3. Se construye la parrilla de salida en un vector.
// 4. Cada monoplaza ejecuta el método "correr()" para simular su tiempo de carrera.
// 5. Se ordena la parrilla con MergeSort de menor a mayor tiempo.
// 6. Se muestran los resultados de la carrera en consola.

int main() {

    srand(time(0));

    Piloto verstappen("Max Verstappen", "1", 95, 10);
    Piloto norris("Lando Norris", "4", 90,7);
    Piloto bortoleto("Gabriel Bortoleto", "5",82,15);
    Piloto doohan("Jack Doohan","7",80,15);
    Piloto gasly("Pierre Gasly","10",85,15);
    Piloto antonelli("Andrea Kimi Antonelli","12",80,15);
    Piloto alonso("Fernando Alonso","14",97,17);
    Piloto leclerc("Charles Leclerc","16",90,12);
    Piloto stroll("Lance Stroll","18",85,15);
    Piloto tsunoda("Yuki Tsunoda","22",77,15);
    Piloto albon("Alexander Albon","23",85,5);
    Piloto hulkenberg("Nico Hulkenberg","27",80,20);
    Piloto lawson("Liam Lawson","30",75,20);
    Piloto ocon("Esteban Ocon","31",84,20);
    Piloto colapinto("Franco Colanpinto","43",80,20);
    Piloto hamilton("Lewis Hamilton","44",90,17);
    Piloto sainz("Carlos Sainz","55",90,15);
    Piloto russell ("George Russell","63",92,10);
    Piloto piastri("Osacar Piastri","81",92,6);
    Piloto bearman("Oliver Bearman","87",80,22);

   
    Sauber sb1(hulkenberg);
    Sauber sb2(bortoleto);
    Alpine alp1(gasly);
    Alpine alp2(colapinto);
    RB rb1(lawson);
    RB rb2(doohan);
    AstonMartin atm1(stroll);
    AstonMartin atm2(alonso);
    Ferrari ferr1(leclerc);
    Ferrari ferr2(hamilton);
    Haas has1(bearman);
    Haas has2(ocon);
    McLaren mcl1(norris);
    McLaren mcl2(piastri);
    Mercedes mer1(russell);
    Mercedes mer2(antonelli);
    RedBull rbl1(verstappen);
    RedBull rbl2(tsunoda);
    Williams will1(albon);
    Williams will2(sainz);

    vector<Monoplaza*> parrilla = { &sb1, &sb2, &alp1, &alp2, &rb1, &rb2, &atm1, &atm2, &ferr1, &ferr2, &has1, &has2, &mcl1, &mcl2, &mer1, &mer2, &rbl1, &rbl2, &will1, &will2};

    for (auto& m : parrilla) {
        m->correr();
    }

    mergeSort(parrilla, 0, parrilla.size() - 1);


    cout << "Resultados de la carrera:\n";
    int count = 1;
    for (auto& m : parrilla) {
        cout << count << ".";
        m->mostrarInfor();
        count++;
    }
    
    return 0;
}
