// Ctrl + K + C to comment
// Ctrl + K + U to uncomment
#include <Poligono.h>
#include <cmath>

// #include <map>
// map <int, Poligono> myPoligonos;


bool isIgualPunto(const Punto unPunto, const Punto otroPunto){
    return (unPunto.x == otroPunto.x) and (unPunto.y == otroPunto.y);
}


void push (Nodo** cabeza, const Punto puntoNuevo){
    Nodo * newNodo = new Nodo;

    newNodo->punto.x=puntoNuevo.x;
    newNodo->punto.y=puntoNuevo.y;

    newNodo->next=*cabeza;
 
    *cabeza=newNodo;

}

void addVertice(Poligono& poligono, const Punto puntoAAgregar ){
    cout<<"ta todo bien"<< endl;
    push(&poligono.primerNodo, puntoAAgregar);

    poligono.cantidadPuntosReales++;
}

Punto getVertice(Poligono poligono, const int numeroDeVertice ){
    for(int i = 0; numeroDeVertice>i; i++)
        poligono.primerNodo = poligono.primerNodo->next;
    
    return poligono.primerNodo->punto;
}

void setVertice(Poligono& poligono, const Punto punto, const int posicionVertice){
    for(int i = 0; posicionVertice>i; i++)
        poligono.primerNodo = poligono.primerNodo->next;
    poligono.primerNodo->punto=punto;   
}

void removeVertice(Poligono& poligono, const int numeroDeVertice){ //Supongo que siempre quiero remover el ultimo
    for(int i = 0; numeroDeVertice>i; i++)
        poligono.primerNodo = poligono.primerNodo->next;
    delete poligono.primerNodo;
    poligono.cantidadPuntosReales --;
}

int getCantidadLados(const Poligono& poligono){
    return poligono.cantidadPuntosReales;
}
double getPerimetro(const Poligono& poligono){
   double perimetro = 0;
    unsigned i; //Porque comparo con un unsigned
    for(i = 0; i < poligono.cantidadPuntosReales-1; i++)
        perimetro += distanciaEntrePuntos(getVertice(poligono, i), getVertice(poligono,i+1));
    return perimetro += distanciaEntrePuntos(getVertice(poligono, i), getVertice(poligono,0));
}

double distanciaEntrePuntos(const Punto unPunto, const Punto otroPunto){
    return pow (unPunto.x - otroPunto.x , 2) + pow(unPunto.y - otroPunto.y, 2);
}

// Agregado de la clases del 1/10 - Como extraer un poligono de un archivo txt

//Extraer uno o mas poligonos y despues enviarlos por flujo de salida

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

 bool extraerPunto (ifstream& in, Punto& punto){
    in >> punto.x;
    in >> punto.y;
    cout << "valor de la entrada " <<  static_cast<bool> (in) << endl;
    return static_cast<bool> (in);
 }

bool extraerSeparador(ifstream& in){
    in.clear();
    char c = '!';
    in >> c;
    return c=='#' and in;
 } 

bool extraerPoligono (ifstream& in, Poligono& poligono){
    if(extraerColor(in, poligono.colorPoligono))
        for (int i = 0; extraerPunto(in, poligono.puntos.at(i)); i++)
            addVertice(poligono, poligono.puntos.at(i));
    return extraerSeparador(in);
 }

// void push (Poligono *poligono, int index, Poligono value, int *size, int *capacity){
//      cout << "Current capacity: %d\n" << *capacity << endl;
//      cout << "Current capacity: %d\n" << index << endl;
//     if(*size > *capacity){
//           realloc(poligono, sizeof(poligono) * 2);
//           *capacity = sizeof(poligono) * 2;
//      }
//      poligono[index] = value;
//      *size = *size + 1;
// }

bool extraerPoligonos (ifstream& in, map <int, Poligono>& myPoligonos){

    for(int i = 0; not in.eof() and extraerPoligono(in, myPoligonos[i]); i++);
    return in.eof();
}

// -------------

bool enviarPunto (ofstream& out,const Punto& punto){
    out << punto.x << " " << punto.y << " ";
    return static_cast<bool> (out);
}

bool enviarColor (ofstream& out,const Color& color){
    cout << static_cast<short> (color.red) << " " 
        << static_cast<short> (color.green) << " "
        << static_cast<short> (color.blue) << " ";

    out << static_cast<short> (color.red) << " " 
        << static_cast<short> (color.green) << " "
        << static_cast<short> (color.blue) << " "; //Sin este casteo me muestra el valor del codigo ascii
    return static_cast<bool> (out);
}

bool enviarPoligono (ofstream& out,const Poligono& poligono){
    
    enviarColor(out, poligono.colorPoligono);
    unsigned i;
    for(i = 0; poligono.cantidadPuntosReales>i; i++)
        enviarPunto(out, poligono.primerNodo->punto);
    return poligono.cantidadPuntosReales == i;
}







