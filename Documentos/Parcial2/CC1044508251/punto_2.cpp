#include<iostream>
#include "manejo_cuentas.h"

using namespace std;

int main()
{

  string name;
  double sInit;

  cout << "Titular: ";
  cin >> name;

  cout << "Saldo inicial: ";
  cin >> sInit;

  double a;
  double r;
  
  cout << "Abono: ";
  cin >> a;
  
  cout << "Retirar: ";
  cin >> r;
    
  cout << "\n============CUENTA BASE=============" << endl;
  
  Cuenta cuenta_ejemplo(name, sInit);

  cuenta_ejemplo.abonar(a);
  cuenta_ejemplo.cargar(r);

  cuenta_ejemplo.getSaldo();

  cout << "\n============CUENTA AHORRO=============" << endl;
  
  double inter;

  cout << "Interes: ";
  cin >> inter;
  
  CuentaAhorros cuenta_ejemplo2(name, sInit, inter);

  cuenta_ejemplo2.abonar(a);
  cuenta_ejemplo2.cargar(r);
  cuenta_ejemplo2.calcularInteres();
  cuenta_ejemplo2.addInteres();
  
  cout << "\n============CUENTA CHEQUES=============" << endl;
  
  double trans;

  cout << "Cuota de transaccion: ";
  cin >> trans;
  
  CuentaCheques cuenta_ejemplo3(name, sInit, trans);

  cuenta_ejemplo3.abonar(a);
  cuenta_ejemplo3.cargar(r);
  
  return 0;
}
