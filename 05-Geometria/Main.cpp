#include <Poligono.h>
using namespace std;
#define INITIAL_CAPACITY 2

main(){
    map <int, Poligono> myPoligonos;
    
//    Poligono poligonoPrueba;

    ifstream infile ("readFile.txt");
    extraerPoligonos(infile,myPoligonos);

    cout << "Ën el MAIN tengo los siguientes valores: " << endl;
    cout << "Poligono 1, PUNTO 1 coordenada x : " << myPoligonos.at(0).primerNodo->punto.x << endl;
    cout << "Poligono 1, PUNTO 1 coordenada y : " << myPoligonos.at(0).primerNodo->punto.y << endl;
   
    cout << "Poligono 1, PUNTO 2 coordenada x : " << myPoligonos.at(0).primerNodo->next->punto.x << endl;
    cout << "Poligono 1, PUNTO 2 coordenada y : " << myPoligonos.at(0).primerNodo->next->punto.y << endl;

    infile.close();
    double limitePerimetro = 50;

    ofstream outfile ("writeFile.txt");

    for(unsigned i = 0; myPoligonos.size() > i and getPerimetro(myPoligonos.at(i)) > limitePerimetro; i++ )
        enviarPoligono(outfile, myPoligonos.at(i));

    outfile.close();

}