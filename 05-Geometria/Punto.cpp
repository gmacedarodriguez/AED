#include <Punto.h>
#include <cmath>
using namespace std;

bool isIgualPunto(const Punto unPunto, const Punto otroPunto){
    return (unPunto.x == otroPunto.x) and (unPunto.y == otroPunto.y);
}

double distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto){
    return pow (unPunto.x - otroPunto.x , 2) + pow(unPunto.y - otroPunto.y, 2);
}

bool extraerPunto (ifstream& in, Punto& punto){
    in >> punto.x;
    in >> punto.y;
    return static_cast<bool> (in);
}

bool enviarPunto (ofstream& out,const Punto& punto){
    out << punto.x << " " << punto.y << " ";
    return static_cast<bool> (out);
}