#include <Punto.h>
#include <Color.h>
#include <Poligono.h>

using namespace std;

main(){
    map <int, Poligono> myPoligonos;

    ifstream infile ("readFile.txt");
    extraerPoligonos(infile,myPoligonos);
    infile.close();

    double limitePerimetro = 50;
    ofstream outfile ("writeFile.txt");

    for(unsigned i = 0; myPoligonos.size() > i; i++ )
        if(getPerimetro(myPoligonos.at(i)) > limitePerimetro)
            enviarPoligono(outfile, myPoligonos.at(i));
    outfile.close();

}