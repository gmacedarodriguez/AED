#include <stdint.h> // Aca está definido el tipo de dato unit8_t. Si quiero optimizar más el codigo podría buscar en que lugar especifico de la librería se encuentra y solo exportar esa parte
#include <cassert> // Incluyo para que no tire error en los assert
#include <cmath>
#include <array>
struct Color{
    uint8_t red; //elijo unsigned porque los valores de intensidad de un color rgb no pueden ser negativo
    uint8_t  green; // Con 8 bits se pueden representar numeros de 0 a 255 (2^8)
    uint8_t  blue;
};


struct Punto{
    int x;
    int y;
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
int getPerimetro(const Poligono& poligono);
int distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto);
bool isIgualPunto(const Punto unPunto, const Punto otroPunto);




int main(){

    Poligono poligono;
    Punto puntoPrueba = {0 , 0};

    addVertice(poligono,puntoPrueba );

    assert( 1 == poligono.cantidadPuntosReales );
    assert( not(0 == poligono.cantidadPuntosReales) );

    assert( isIgualPunto(puntoPrueba, puntoPrueba) );

    assert(isIgualPunto(puntoPrueba, getVertice(poligono, 0)));
    assert(not(isIgualPunto({1,0},getVertice(poligono,0))));

    setVertice(poligono, puntoPrueba, 1);

    assert(isIgualPunto(puntoPrueba, getVertice(poligono, 1)));
    assert(not(isIgualPunto({1,0},getVertice(poligono,1))));

    assert(1 == getCantidadLados(poligono));
    assert(not(2 == getCantidadLados(poligono)));

    assert(0 == distanciaEntrePuntos(puntoPrueba,puntoPrueba));
    assert(1 == distanciaEntrePuntos({0,1},puntoPrueba));

    assert(0 == getPerimetro(poligono));
    assert(not(1 == getPerimetro(poligono)));
}









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
int getPerimetro(const Poligono& poligono){
    int perimetro, i;
    for(i = 0; i < poligono.cantidadPuntosReales-1; i++)
        perimetro =+ distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[i+1]);
    perimetro = distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[0]);
}

int distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto){
    int distancia = pow (unPunto.x - otroPunto.x , 2) + pow(unPunto.y - otroPunto.y, 2);
    return distancia;
}
