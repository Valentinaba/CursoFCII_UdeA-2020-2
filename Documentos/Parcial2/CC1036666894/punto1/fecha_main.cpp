#include <iostream>

using namespace std;

#include "fecha.h"

int main()
{
  
  Fecha fecha1;  //objeto de la clase Fecha

  fecha1.imprimirFecha();  // imprimir el dia ingresado
  fecha1.diaSiguiente();   // imprimir el siguiente dia al ingresado
  
  return 0;
}
