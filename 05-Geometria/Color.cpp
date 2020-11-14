#include <Color.h>
using namespace std;

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

bool enviarColor (ofstream& out,const Color& color){
    out << static_cast<short> (color.red) << " " 
        << static_cast<short> (color.green) << " "
        << static_cast<short> (color.blue) << " "; //Sin este casteo me muestra el valor del codigo ascii
    return static_cast<bool> (out);
}