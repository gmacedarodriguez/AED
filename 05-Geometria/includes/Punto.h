#pragma once
#include <stdint.h>
#include <fstream>
#include <iostream>
using namespace std;

struct Punto{
    double x;
    double y;
};

bool isIgualPunto(const Punto unPunto, const Punto otroPunto);
double distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto);
bool extraerPunto (ifstream& in, Punto& punto);
bool enviarPunto (ofstream& out,const Punto& punto);