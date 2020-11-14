#pragma once
#include <stdint.h>
#include <fstream>
#include <iostream>
using namespace std;

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

Color mezclarColores(const Color unColor, const Color otroColor);
bool isIgual (const Color& unColor, const Color& otroColor);
bool extraerComponenteColor(ifstream& in, uint8_t& componente);
bool extraerColor(ifstream& in, Color& color);
bool enviarColor (ofstream& out,const Color& color);