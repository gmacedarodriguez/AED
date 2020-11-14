// Ctrl + K + C to comment
// Ctrl + K + U to uncomment

#include <Poligono.h>
#include <Punto.h>
#include <Color.h>
using namespace std;

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
double getPerimetro(const Poligono& poligono){
    double perimetro = 0;
    unsigned i; //Porque comparo con un unsigned
    for(i = 0; i < poligono.cantidadPuntosReales-1; i++)
        perimetro += distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[i+1]);
    return perimetro += distanciaEntrePuntos(poligono.puntos[i], poligono.puntos[0]);
}

bool extraerSeparador(ifstream& in){
    in.clear();
    char c = '!';
    in >> c;
    return c=='#' and in;
 } 

bool extraerPoligono (ifstream& in, Poligono& poligono){
    cout << "Estoy en el CONT" << endl;
    if(extraerColor(in, poligono.colorPoligono))
        for (int i = 0; extraerPunto(in, poligono.puntos.at(i)); i++)
            addVertice(poligono, poligono.puntos.at(i));
    return extraerSeparador(in);
 }
bool extraerPoligonos (ifstream& in, map <int, Poligono>& myPoligonos){

    for(int i = 0; not in.eof(); i++){
        Poligono poligonoAux;
        extraerPoligono(in, poligonoAux);

        myPoligonos.insert({i, poligonoAux});

    }
    return in.eof();
}

bool enviarPoligono (ofstream& out, Poligono& poligono){
    enviarColor(out, poligono.colorPoligono);
    unsigned i;
    for(i = 0; poligono.cantidadPuntosReales>i and enviarPunto(out, poligono.puntos.at(i)); i++);
    return poligono.cantidadPuntosReales == i;
}

// bool enviarPoligonos(ofstream& out){
//     unsigned i;
//     for(i = 0; myPoligonos.size()>i and enviarPoligono(out, myPoligonos[i]); i++);
//     return myPoligonos.size() == i;
// }