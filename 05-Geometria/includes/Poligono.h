#pragma once
#include <Punto.h>
#include <Color.h>
#include <array>
#include <map>
using namespace std;


struct Nodo{
    Punto punto;
    Nodo * next;
};

struct Poligono{
    std::array<Punto,200> puntos;
    Nodo * primerNodo;
    Color colorPoligono;
    unsigned cantidadPuntosReales = 0; //Cantidad de puntos a los que les fue asignado un valor.
};


void push (Nodo** cabeza, const Punto puntoNuevo);
void deleteNodo(Nodo** cabeza, int position );
void addVertice(Poligono& poligono, const Punto puntoAAgregar);
Punto getVertice(const Poligono poligono, const int numeroDeVertice);
void setVertice(const Poligono& poligono, const Punto punto, const int posicionVertice);
void removeVertice(Poligono& poligono, const int numeroDeVertice);
int getCantidadLados(const Poligono& poligono);
double getPerimetro(const Poligono& poligono);


bool extraerSeparador(ifstream& in);
bool extraerPoligono (ifstream& in, Poligono& poligono);
bool extraerPoligonos (ifstream& in, map <int, Poligono>& myPoligonos);
bool enviarPoligono (ofstream& out, Poligono& poligono);


