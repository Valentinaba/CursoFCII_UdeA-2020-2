#include <iostream>
#include "Cuenta.h"
#include "CuentaAhorros.h"
#include "CuentaCheques.h"

using namespace std;

int main()
{
  //Testeo de la cuenta
  Cuenta test_count(100.0); 
  test_count.abonar(10000);
  double saldo = test_count.getSaldo();
  cout << " Su saldo tras el abono es:" << endl;
  cout << saldo << endl;
  cout << " Su saldo tras el cargo es:" << endl;
  test_count.cargar(10000);
  saldo = test_count.getSaldo();
  cout << saldo << endl;


  //Testeo de la cuenta de ahorros
  CuentaAhorros test_Ahorros(1000., 2);
  double interes = test_Ahorros.calcularInteres();
  cout << "El interes de la cuenta de ahorros es: "<< interes << endl;


  //Testeo de la cuenta de Cheques
  CuentaCheques testCheques(1000,10);
  testCheques.cargar(100);
  testCheques.abonar(1000);
  
  
  return 0;

}
