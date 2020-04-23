/* "Hello, World!" en C++
  Programa que imprime "Hello, world!" en un archivo txt
  Gabriel Ezequiel Maceda
  23/04/2020 */

#include<iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string hola = "Hello, world!";
    ofstream file;
    file.open("output.txt");
    file << hola << endl;
    file.close();

  return 0;
}
