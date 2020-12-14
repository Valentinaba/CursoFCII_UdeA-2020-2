//Main del Parcial2 punto 1.

#include "P1.h"

#include <cstring>
#include <string>
#include <iostream>
using namespace std;

//######### MAIN #############//
int main()
{
  int mes1 = 1;
  int dia1 = 1;
  int anio1 = 2000;

cout<<"Ingrese mes, día y año respectivamente: "<<endl;
  cout<<"Mes: ";
  cin>>mes1;
  cout<<"Día: ";
  cin>>dia1;
  cout<<"Año: ";
  cin>>anio1;

  Fecha fecha1( mes1, dia1, anio1 );//Mes, dia año
  
  cout << "Fecha:         ";
  fecha1.imprimir();
  fecha1.diaSig();

  return 0;
}
