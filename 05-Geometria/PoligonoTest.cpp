
#include <cassert> // Incluyo para que no tire error en los assert
#include <Poligono.h>

using namespace std;

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


    ifstream infile; 

    infile.open("afile.txt");

    extraerColor(infile, poligono.colorPoligono);

     infile.close();
}
