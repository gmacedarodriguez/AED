#include <Poligono.h>
#include <cmath>



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
    int perimetro = 0;
    unsigned i; //Porque comparo con un unsigned
    for(i = 0; i < poligono.cantidadPuntosReales-1; i++)
        perimetro += distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[i+1]);
    perimetro += distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[0]);
    return perimetro;
}

int distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto){
    int distancia = pow (unPunto.x - otroPunto.x , 2) + pow(unPunto.y - otroPunto.y, 2);
    return distancia;
}
