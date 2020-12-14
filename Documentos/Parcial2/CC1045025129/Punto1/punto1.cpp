#include <iostream>

using namespace std;

#include "fecha.h"

int main()
{
  Fecha fecha1( 04,10, 2000 );
  Fecha fecha2;
  int d, m, a;
  
  cout << "La fecha de chequeo del sistema es fecha1 = ";
  fecha1.imprimir();
  cout << "\nLa fecha por default del programa es fecha2 = ";
  fecha2.imprimir();
  cout << "\nAhora le pedimos a usted que ingrese la fecha que desee";
  cout << "\nEl dia ";
  cin >> d;
  cout << "El mes ";
  cin >> m;
  cout << "El anio ";
  cin >> a;

  Fecha fecha3(d,m,a);
  cout << "\n\nEl día siguiente a la fecha que usted ingresó es  ";
  fecha3.diaSig();
  cout << endl;
  
  return 0;
}
