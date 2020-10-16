// Ctrl + K + C to comment
// Ctrl + K + U to uncomment

#include <Poligono.h>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>
#include <map>

map <int, Poligono> myPoligonos;

bool isIgualPunto(const Punto unPunto, const Punto otroPunto){
    return (unPunto.x == otroPunto.x) and (unPunto.y == otroPunto.y);
}



void addVertice(Poligono& poligono, const Punto puntoAAgregar ){
    poligono.puntos.at(poligono.cantidadPuntosReales) = puntoAAgregar;
    poligono.cantidadPuntosReales++;
}

Punto getVertice(const Poligono& poligono, const int numeroDeVertice ){ //Si paso poligono por referencia, al no copiarse un nuevo poligono dentro de la funcion, es mas performante? Pongo const ya que no quiero modificar nada dentro de la func
    return poligono.puntos.at(numeroDeVertice);
}


void setVertice(Poligono& poligono, const Punto punto, const int posicionVertice){ //setVertice
        poligono.puntos.at(posicionVertice) = punto;   
}

void removeVertice(Poligono& poligono, const int numeroDeVertice){ //Supongo que siempre quiero remover el ultimo
    poligono.cantidadPuntosReales --;
}

int getCantidadLados(const Poligono& poligono){
    return poligono.cantidadPuntosReales;
}
double getPerimetro(const Poligono& poligono){
    double perimetro = 0;
    unsigned i; //Porque comparo con un unsigned
    for(i = 0; i < poligono.cantidadPuntosReales-1; i++)
        perimetro += distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[i+1]);
    return perimetro += distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[0]);
}

double distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto){
    return pow (unPunto.x - otroPunto.x , 2) + pow(unPunto.y - otroPunto.y, 2);
}

// Agregado de la clases del 1/10 - Como extraer un poligono de un archivo txt

//Extraer uno o mas poligonos y despues enviarlos por flujo de salida

bool extraerComponenteColor(ifstream& in, uint8_t& componente){
    int aux;
    in >> aux;
    componente = aux;
    return static_cast<bool> (in);
}


bool extraerColor(ifstream& in, Color& color){
    return  extraerComponenteColor(in, color.red) and
            extraerComponenteColor(in, color.green) and
            extraerComponenteColor(in, color.blue);
} 

 bool extraerPunto (ifstream& in, Punto& punto){
    in >> punto.x;
    in >> punto.y;
    return static_cast<bool> (in);
 }

bool extraerSeparador(ifstream& in){
    in.clear();
    char c = '!';
    in >> c;
    return c=='#' and in;
 } 

bool extraerPoligono (ifstream& in, Poligono& poligono){
    if(extraerColor(in, poligono.colorPoligono))
        for (int i = 0; extraerPunto(in, poligono.puntos.at(i)); i++)
            addVertice(poligono, poligono.puntos.at(i));
    return extraerSeparador(in);
 }
bool extraerPoligonos (ifstream& in){
    for(int i = 0; not in.eof() and extraerPoligono(in, myPoligonos[i]); i++);
    return in.eof();
}

// -------------

bool enviarPunto (ofstream& out,const Punto& punto){
    out << punto.x << " " << punto.y << " ";
    return static_cast<bool> (out);
}

bool enviarColor (ofstream& out,const Color& color){
    out << static_cast<short> (color.red) << " " 
        << static_cast<short> (color.green) << " "
        << static_cast<short> (color.blue) << " "; //Sin este casteo me muestra el valor del codigo ascii
    return static_cast<bool> (out);
}

bool enviarPoligono (ofstream& out,const Poligono& poligono){
    enviarColor(out, poligono.colorPoligono);
    unsigned i;
    for(i = 0; poligono.cantidadPuntosReales>i and enviarPunto(out, poligono.puntos.at(i)); i++);
    return poligono.cantidadPuntosReales == i;
}

bool enviarPoligonos(ofstream& out){
    unsigned i;
    for(i = 0; myPoligonos.size()>i and enviarPoligono(out, myPoligonos[i]); i++);
    return myPoligonos.size() == i;
}

