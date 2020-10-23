#include <Poligono.h>
using namespace std;
#define INITIAL_CAPACITY 2
main(){
    map <int, Poligono> myPoligonos;
    ifstream infile ("readFile.txt");
    ofstream outfile ("writeFile.txt");
    extraerPoligonos(infile, myPoligonos);
    infile.close();
    double limitePerimetro = 50;

    for(int i = 0; myPoligonos.size() > i and getPerimetro(myPoligonos.at(i)) > limitePerimetro; i++ )
        enviarPoligono(outfile, myPoligonos.at(i));

    outfile.close();

    // int size = 0;
    // int capacity = INITIAL_CAPACITY;
    // Poligono poligonoPrueba;
    
    // Poligono *poligono = new Poligono[INITIAL_CAPACITY];
    // push(poligono, 0, poligonoPrueba, &size, &capacity);
    // push(poligono, 1, poligonoPrueba, &size, &capacity);
    // push(poligono, 2, poligonoPrueba, &size, &capacity);
    
    // cout << "Current capacity: %d\n" << capacity << endl; // Current capacity: 2
    // push(poligono, 3, poligonoPrueba, &size, &capacity);
    // push(poligono, 4, poligonoPrueba, &size, &capacity);
    // push(poligono, 5, poligonoPrueba, &size, &capacity);
    // printf("Current capacity: %d\n", capacity); // Current capacity: 16



}