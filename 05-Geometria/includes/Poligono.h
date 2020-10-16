#include <stdint.h>
#include <array>
#include <fstream>
#include <iostream>
using namespace std;

struct Color{
    uint8_t red; //elijo unsigned porque los valores de intensidad de un color rgb no pueden ser negativo
    uint8_t  green; // Con 8 bits se pueden representar numeros de 0 a 255 (2^8)
    uint8_t  blue;
};


struct Punto{
    double x;
    double y;
};

//Supongo que puede tener como máximo 200 puntos
struct Poligono{
    std::array<Punto,200> puntos;
    Color colorPoligono;
    unsigned cantidadPuntosReales = 0; //Cantidad de puntos a los que les fue asignado un valor.
};



void addVertice(Poligono& poligono, const Punto puntoAAgregar);
Punto getVertice(const Poligono& poligono, const int numeroDeVertice);
void setVertice(Poligono& poligono, const Punto punto, const int posicionVertice);
void removeVertice(Poligono& poligono, const int numeroDeVertice);
int getCantidadLados(const Poligono& poligono);
double getPerimetro(const Poligono& poligono);
double distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto);
bool isIgualPunto(const Punto unPunto, const Punto otroPunto);
bool extraerColor(ifstream& in, Color& color);
bool extraerComponenteColor(ifstream& in, uint8_t& componente);
bool extraerSeparador(ifstream& in);
bool extraerPoligonos (ifstream& in);
bool enviarPoligonos(ofstream& out);
bool enviarPoligono (ofstream& out,const Poligono& poligono);
bool enviarColor (ofstream& out,const Color& color);
bool enviarPunto (ofstream& out,const Punto& punto);
