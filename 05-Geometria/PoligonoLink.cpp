// Ctrl + K + C to comment
// Ctrl + K + U to uncomment
#include <Poligono.h>
#include <Punto.h>
#include <Color.h>
using namespace std;

void push (Nodo** cabeza, const Punto puntoNuevo){
    Nodo * newNodo = new Nodo;

    newNodo->punto.x=puntoNuevo.x;
    newNodo->punto.y=puntoNuevo.y;
    newNodo->next=*cabeza;
    *cabeza=newNodo;

}

void addVertice(Poligono& poligono, const Punto puntoAAgregar ){
    push(&poligono.primerNodo, puntoAAgregar);

    poligono.cantidadPuntosReales++;
}

Punto getVertice(const Poligono poligono, const int numeroDeVertice ){
    int i = 0;

    for (auto p = poligono.primerNodo; p!=nullptr ; p = p -> next)
    {
        if(numeroDeVertice==i)
            return p->punto;
        i++;
    }
    // throw invalid_argument("Pruebe con un numero de vértice más chico");
}

void setVertice(const Poligono& poligono, const Punto punto, const int posicionVertice){ //agregar const
    int i = 0;

    for (auto p = poligono.primerNodo; p!=nullptr ; p = p -> next)
    {
        if(posicionVertice==i)
        {
            p->punto=punto;;
            return;
        }
        i++;
    }  
}

void deleteNodo(Nodo** cabeza, int position ){
    //Si la lista esta vacia
    if(*cabeza == NULL)
        return;
    // Referencio la cabeza con el nodo    
    Nodo* nodoAux = *cabeza;
    //Si tengo que remover la cabeza
    if(position == 0)
    {
        *cabeza = nodoAux->next;
        delete nodoAux;
        return;
    }

    // Recorro hasta encontrar el nodo anterior al que quiero eliminar
    for(int i = 0; nodoAux!=NULL and i<position-1; i++)
        nodoAux=nodoAux->next;
    //Si la position es mayor al numero de nodos
    if(nodoAux==NULL or nodoAux->next==NULL)
        return;
    //nodoAux->next es el nodo que quiero eliminar
    //Guardo la referencia al nodo siguiente al que quiero eliminar
    Nodo* next = nodoAux->next->next; 
    //Elimino el nodo de la lista 
    delete nodoAux->next;
    nodoAux->next=next;
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
    unsigned i;
    for(i = 0; i < poligono.cantidadPuntosReales-1; i++)
        perimetro += distanciaEntrePuntos(getVertice(poligono, i), getVertice(poligono,i+1));
    return perimetro += distanciaEntrePuntos(getVertice(poligono, i), getVertice(poligono,0));
}

bool extraerSeparador(ifstream& in){
    in.clear();
    char c = '!';
    in >> c;
    return c=='#' and in;
 } 

bool extraerPoligono (ifstream& in, Poligono& poligono){
    Punto puntoAux;
    if(extraerColor(in, poligono.colorPoligono))
        while (extraerPunto(in, puntoAux))
            addVertice(poligono, puntoAux);
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
    unsigned i = 0;
    for(auto p = poligono.primerNodo; p!=nullptr and enviarPunto(out, poligono.primerNodo->punto); p=p->next,i++)
        poligono.primerNodo = poligono.primerNodo->next;
    return poligono.cantidadPuntosReales == i;
}








