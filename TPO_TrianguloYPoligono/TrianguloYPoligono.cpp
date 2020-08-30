// Consigna: 
// Crear un tipo de dato Triangulo y otro Poligono. Cada tipo de dato tiene que tener sus operaciones, voy a tener que crear un tipo de dato punto para para ponerle dentro de ellos. 
//El poligono tiene que tener N puntos variables pero con un máximo. Ambos tienen que tener un color, puedo crear un tipo de dato para éste o usar los ya existenes

#include <iostream>
#include <string>
using namespace std; 

enum PosicionPunto (Posicion1, Posicion2, Posicion3);

struct punto{
    int x;
    int y;

};

struct triangulo{
    punto punto1;
    punto punto2;
    punto punto3;
    string color;
};

//Supongo que puede tener como máximo 200 puntos
struct poligono{
    punto puntos[200];
    string color;
};

void setTriangulo(triangulo& triangulo, const punto punto1, const punto punto2, const punto punto3){
    triangulo.punto1 = punto1;
    triangulo.punto2 = punto2;
    triangulo.punto3 = punto3;
}

void setPointTriangulo(triangulo& triangulo, const punto punto1, const PosicionPunto quePunto){
    
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

void setPoligono(poligono& poligono, const punto puntos[], int cantidadDePuntos){
    for(i = 0; i < cantidadDePuntos; i++)
        poligono.puntos[i] = puntos[i];   
}


