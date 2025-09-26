// monoplaza.cpp
// Autor: Darío A. Uribe


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


// ---- Escuderías ----
Sauber::Sauber(Piloto pil) : Monoplaza("Sauber", pil, 92, 75) {}
void Sauber::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Alpine::Alpine(Piloto pil) : Monoplaza("Alpine", pil, 70, 75) {}
void Alpine::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

RB::RB(Piloto pil) : Monoplaza("RB", pil, 68, 70) {}
void RB::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

AstonMartin::AstonMartin(Piloto pil) : Monoplaza("Aston Martin", pil, 80, 82) {}
void AstonMartin::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Ferrari::Ferrari(Piloto pil) : Monoplaza("Ferrari", pil, 85, 85) {}
void Ferrari::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Haas::Haas(Piloto pil) : Monoplaza("Haas", pil, 65, 68) {}
void Haas::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

McLaren::McLaren(Piloto pil) : Monoplaza("McLaren", pil, 95, 92) {}
void McLaren::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Mercedes::Mercedes(Piloto pil) : Monoplaza("Mercedes", pil, 88, 87) {}
void Mercedes::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

RedBull::RedBull(Piloto pil) : Monoplaza("Red Bull", pil, 92, 90) {}
void RedBull::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}

Williams::Williams(Piloto pil) : Monoplaza("Williams", pil, 76, 78) {}
void Williams::correr() {
    tiempoCarrera = 5400 - velocidad + (rand() % 15) - (fiabilidad / 25);
    tiempoCarrera -= piloto.getHabilidad() / 10;
    if ((rand() % 100) < piloto.getProbError()) tiempoCarrera += 10;
}
