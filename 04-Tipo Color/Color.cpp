#include <stdint.h> // Aca está definido el tipo de dato unit8_t. Si quiero optimizar más el codigo podría buscar en que lugar especifico de la librería se encuentra y solo exportar esa parte
#include <cassert> // Incluyo para que no tire error en los assert

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


int main(){
    Color violetaOscuro = {127,0,127};
//testeo mezclarColores
    assert(isIgual(violetaOscuro,  mezclarColores(rojo,azul)));
    assert(isIgual({127,0,127},  mezclarColores(rojo,azul)));

    assert(not isIgual(rojo, azul));
    assert(isIgual(rojo, rojo));

}


// Paso los parametros por valor y no por referencia solo porque el resto de estructuras posiblemente los pase por referencia.
//Como dijo el profe, lo dejo por valor asi tengo un ejemplo de pasar parametros por valor.
Color mezclarColores(const Color unColor, const Color otroColor){ 
    Color colorFinal;
    colorFinal.red = (unColor.red + otroColor.red)/2;
    colorFinal.green = (unColor.green + otroColor.green)/2;
    colorFinal.blue = (unColor.blue + otroColor.blue)/2;

    return colorFinal;
}

bool isIgual (const Color& unColor, const Color& otroColor){
    return unColor.red == otroColor.red and unColor.green == otroColor.green and unColor.blue == otroColor.blue;
}