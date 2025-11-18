// monoplaza.cpp
// Autor: Darío A. Uribe

/*
En este archivo se implementa el cálculo del tiempo de carrera. 
La fórmula utiliza el número de vueltas como parámetro para calcular
un tiempo proporcional a la extensión de la carrera.

El tiempo base se obtiene a partir de registros reales de F1, multiplicado
por el número de vueltas y ajustado por las características del monoplaza,
la fiabilidad, y la habilidad del piloto.
*/

#include "monoplaza.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Monoplaza::Monoplaza(string esc, Piloto pil, int vel, int fiab)
    : escuderia(esc), piloto(pil), velocidad(vel), fiabilidad(fiab), tiempoCarrera(0) {}

void Monoplaza::mostrarInfor() {
    cout << escuderia << " - " << piloto.getNombre()
         << " | Tiempo: " << tiempoCarrera << "s" << endl;
}

int Monoplaza::getTiempoCarrera() const {
    return tiempoCarrera;
}

string Monoplaza::getNombrePiloto() const {
    return piloto.getNombre();
}

string Monoplaza::getEscuderia() const {
    return escuderia;
}


Sauber::Sauber(Piloto pil) : Monoplaza("Sauber", pil, 92, 75) {}
void Sauber::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Alpine::Alpine(Piloto pil) : Monoplaza("Alpine", pil, 70, 75) {}
void Alpine::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

RB::RB(Piloto pil) : Monoplaza("RB", pil, 68, 70) {}
void RB::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

AstonMartin::AstonMartin(Piloto pil) : Monoplaza("Aston Martin", pil, 80, 82) {}
void AstonMartin::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Ferrari::Ferrari(Piloto pil) : Monoplaza("Ferrari", pil, 85, 85) {}
void Ferrari::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Haas::Haas(Piloto pil) : Monoplaza("Haas", pil, 65, 68) {}
void Haas::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

McLaren::McLaren(Piloto pil) : Monoplaza("McLaren", pil, 95, 92) {}
void McLaren::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Mercedes::Mercedes(Piloto pil) : Monoplaza("Mercedes", pil, 88, 87) {}
void Mercedes::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

RedBull::RedBull(Piloto pil) : Monoplaza("Red Bull", pil, 92, 90) {}
void RedBull::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Williams::Williams(Piloto pil) : Monoplaza("Williams", pil, 76, 78) {}
void Williams::correr(int vueltas) {
    int tiempoBase = 100 * vueltas;
    tiempoCarrera = tiempoBase - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}