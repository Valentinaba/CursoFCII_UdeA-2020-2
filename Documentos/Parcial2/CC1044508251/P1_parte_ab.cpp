#include <iostream>

using namespace std;

#include "fecha.h"

int main()
{
  int d, m, y;

  cout << "Ingrese el dia: ";
  cin >> d;

  cout << "Ingrese el mes: ";
  cin >> m;

  cout << "Ingrese el anio: ";
  cin >> y;
  
  Fecha fecha1( d, m, y);
  
  cout << "fecha1 = ";
  fecha1.imprimir();
  
  fecha1.Bisiesto();
  
  cout << "\nfecha1: El anio ";
  fecha1.imprimirBisiesto();

  int a; 

  cout << "\nIngrese dias para aumentar: " ;
  cin >> a;
  
  for(int i=0; i<a; i++)
    {
      cout << "\nfecha1_aumentada = ";
      fecha1.diaSig();
      cout << "\n";
    }

  return 0;
}
