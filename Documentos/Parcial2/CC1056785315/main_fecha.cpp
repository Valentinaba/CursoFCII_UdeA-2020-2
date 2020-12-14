#include "fecha.h"

int main()
{
  Fecha fecha1(29, 2, 2020); // Fecha valida
  Fecha fecha2(31, 12, -1000); // Caso anio invalido
  Fecha fecha3(31, 2, 1997); //Caso dia o mes invalido
  
  cout << "fecha1 = ";
  fecha1.imprimir();
  cout << "\nfecha2 = ";
  fecha2.imprimir();
  cout << "\nfecha3 = ";
  fecha3.imprimir();
  cout << endl;

  fecha1.diaSig();
  fecha2.diaSig(); //Se aumenta en un dia cada fecha
  fecha3.diaSig();
  
  cout << "1 dia despues..." << endl;
  
  cout << "fecha1 = ";
  fecha1.imprimir();
  cout << "\nfecha2 = ";
  fecha2.imprimir();
  cout << "\nfecha3 = ";
  fecha3.imprimir();
  cout << endl;
  
  return 0;
}
