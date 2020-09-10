// Consigna: 
// Crear un tipo de dato Triangulo y otro Poligono. Cada tipo de dato tiene que tener sus operaciones, voy a tener que crear un tipo de dato punto para para ponerle dentro de ellos. 
//El poligono tiene que tener N puntos variables pero con un máximo. Ambos tienen que tener un color, puedo crear un tipo de dato para éste o usar los ya existenes

#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std; //Pongo esto porque sino me tira error con el tipo de dato string

// enum PosicionPunto (Posicion1, Posicion2, Posicion3);

struct Punto{
    int x;
    int y;

};

struct Color{
    uint8_t red; //elijo unsigned porque los valores de intensidad de un color rgb no pueden ser negativo
    uint8_t  green; // Con 8 bits se pueden representar numeros de 0 a 255 (2^8)
    uint8_t  blue;
};

const Color rojo = {255,0,0};
const Color azul = {0,0,255};
const Color verde = {0,255,0};
const Color cyan = {0,255,255};
const Color magenta = {255,0,255};
const Color amarillo = {255,255,0};
const Color negro = {0,0,0};
const Color blanco = {255,255,255};

struct Triangulo{
    Punto punto1;
    Punto punto2;
    Punto punto3;
    Color colorTriangulo;
};

//Supongo que puede tener como máximo 200 puntos
struct Poligono{
    Punto puntos[200];
    Color colorPoligono;
};




// Paso los parametros por valor y no por referencia solo porque el resto de estructuras posiblemente los pase por referencia.
//Como dijo el profe, lo dejo por valor asi tengo un ejemplo de pasar parametros por valor.
Color mezclarColores(const Color unColor, const Color otroColor){
    Color colorFinal;
    colorFinal.red = (unColor.red + otroColor.red)/2;
    colorFinal.green = (unColor.green + otroColor.green)/2;
    colorFinal.blue = (unColor.blue + otroColor.blue)/2;

    return colorFinal;
}


void addVertice(Poligono& poligono, const Punto puntoAAgregar ){
    int cantidadDePuntos = poligono.puntos.size();
    poligono.puntos[cantidadDePuntos] = puntoAAgregar;
}


int getVertice(const Poligono& poligono, const int numeroDeVertice ){ //Si paso poligono por referencia, al no copiarse un nuevo poligono dentro de la funcion, es mas performante? Pongo const ya que no quiero modificar nada dentro de la func
    return poligono.puntos[numeroDeVertice];
}


void setPoligono(Poligono& poligono, const Punto puntos[]){ //setVertice
    int cantidadDePuntos = puntos.size();
    for(int i = 0; i < cantidadDePuntos; i++)
        poligono.puntos[i] = puntos[i];   
}

void removeVertice(Poligono& poligono, const int numeroDeVertice){
    poligono.puntos.erase(numeroDeVertice);
}

int getCantidadLados(const Poligono& poligono){
    return poligono.puntos.size()-1;
}
int getPerimetro(const Poligono& poligono){
    int cantidadDePuntos = poligono.puntos.size();
    int perimetro;
    for(int i = 0; i < cantidadDePuntos-1; i++)
        perimetro =+ distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[i+1]);
    perimetro = distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[0]);
}

int distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto){
    int distancia = powunPunto.x 
}




void setTriangulo(Triangulo& triangulo, const Punto punto1, const Punto punto2, const Punto punto3){
    triangulo.punto1 = punto1;
    triangulo.punto2 = punto2;
    triangulo.punto3 = punto3;
}

void setPointTriangulo(Triangulo& triangulo, const Punto punto1, const PosicionPunto quePunto){
    
    switch (quePunto) //Aca elijo si el que quiero sustituir es el punto1, punto2 o punto3
    {
    case Posicion1:
        triangulo.punto1;
        break;
    case Posicion2:
        triangulo.punto2;
        break;
    case Posicion3:
        triangulo.punto3;
        break;   
    default:
        printf("Error, la posicion del punto no es válida");
        break;
    }
}


int main(){
    Color colorMezclado = mezclarColores(rojo,azul);
    Punto punto1={2,0}, punto2={1,1}, punto3={-1,1}, punto4={0,0};
    Punto primerosTresPuntos[]={punto1, punto2, punto3};

    Poligono poligono;
//testeo mezclarColores
    assert(magenta.red==colorMezclado.red);
    assert(magenta.green==colorMezclado.green);
    assert(magenta.blue==colorMezclado.blue);

    assert(negro.red==colorMezclado.red);
    assert(negro.green==colorMezclado.green);
    assert(negro.blue==colorMezclado.blue);

    setPoligono(poligono, primerosTresPuntos);
}