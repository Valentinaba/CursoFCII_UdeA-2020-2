#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#include "fecha.h"

int main()
{
  Fecha fecha1( 2, 30, 2008 );
  
  cout << "fecha  = ";
  fecha1.imprimir();
  cout << "\n";
  fecha1.diaSig(); 
  cout << " fecha día siguiente  = ";
  fecha1.imprimir();
  cout << "\n";
  return 0;
}
