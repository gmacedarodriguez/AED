/* Resolución de problemas - Adición
   Programa que suma dos numeros ingresados por el usuario y los muestra por pantalla
   Gabriel Ezequiel Maceda
   23/04/2020 */

#include<iostream>
#include <iomanip>

int main()
{
  float Numero1, Numero2;
  int nDecimales=2;

  std::cout << "Ingresar el primer numero\n";
  std::cin >> Numero1;
  std::cout << "Ingresar el segundo numero\n";
  std::cin >> Numero2;

//Almacena la presición original para mas adelante restituirla
  std::streamsize precisionOriginal = std::cout.precision();
// Cambia la presición de salida asignadole el valor de nDecimales  
  std::cout.precision(nDecimales);
  std::cout << std::fixed << std::showpoint;

  std::cout << "El resultado de la adicion es: " ;

  std::cout << Numero1+Numero2;
// Cambio la presición de salida a la original
  std::cout.precision(precisionOriginal);
  std::cout << std::defaultfloat << std::noshowpoint;

  return 0;
}