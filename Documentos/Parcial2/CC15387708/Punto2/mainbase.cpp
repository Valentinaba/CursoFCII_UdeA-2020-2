#include <iostream>
#include "cuentabase.h"

using namespace std;

int main()
{
  Cuenta cuenta1(400000);
  
  cuenta1.abonar(500000);

  cout << "Con el abono el saldo es de " << cuenta1.getSaldo() << " pesos\n" << endl;
  
  cuenta1.cargar(1000000); // Carga un mayor valor a retirar que el saldo, indicando que el monto excedió el saldo
  
  return 0;
}
