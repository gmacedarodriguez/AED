#include <Poligono.h>
using namespace std;
#define INITIAL_CAPACITY 2

main(){
    map <int, Poligono> myPoligonos;
    
    Poligono poligonoPrueba;

    ifstream infile ("readFile.txt");
    ofstream outfile ("writeFile.txt");
    extraerPoligono(infile,poligonoPrueba);

    cout << poligonoPrueba.primerNodo->punto.x << endl;
    infile.close();
    double limitePerimetro = 50;

//    for(int i = 0; myPoligonos.size() > i and getPerimetro(myPoligonos.at(i)) > limitePerimetro; i++ )
        enviarPoligono(outfile, poligonoPrueba);

    outfile.close();

}