#include<iostream>
#include"Cuentas.h"

using namespace std;

int main(){

  Cuenta cuenta_base( 100 );
  CuentaAhorros cuenta_ahorros( 100 , 0.1 );
  CuentaCheques cuenta_cheques( 100 , 2);

  cout << "Cuenta base:\n";
  cout << "Saldo inicial: " <<  cuenta_base.getSaldo() << "\n";
  cuenta_base.abonar( 100 );
  cout << "Saldo luego de abonar 100: " << cuenta_base.getSaldo() << "\n";
  cuenta_base.cargar( 50 );
  cout << "Saldo luego de cargar 50: " << cuenta_base.getSaldo() << "\n";

  cout << "Cuenta ahorros con saldo inicial negativo:\n";
  CuentaAhorros cuenta_error( -10 , 0.1 );
  cout << "Saldo: " << cuenta_error.getSaldo() << "\n";

  cout << "Cuenta ahorros:\n";
  cout << "Saldo inicial: " <<  cuenta_ahorros.getSaldo() << "\n";
  cuenta_ahorros.abonar( cuenta_ahorros.calcularInteres() );
  cout << "Saldo luego de intereses: " <<  cuenta_ahorros.getSaldo() << "\n";

  cout << "Cuenta cheques:\n";
  cout << "Saldo inicial: " <<  cuenta_cheques.getSaldo() << "\n";
  cuenta_cheques.abonar( 100 );
  cout << "Saldo luego de abonar 100: " << cuenta_cheques.getSaldo() << "\n";
  cout << "Intentando cargar 200 ...\n";
  cuenta_cheques.cargar( 200 );
  cout << "Saldo luego de intentar cargar 200: " << cuenta_cheques.getSaldo() << "\n";
  cout << "Intentando cargar 198 ...\n";
  cuenta_cheques.cargar( 198 );
  cout << "Saldo luego de intentar cargar 198: " << cuenta_cheques.getSaldo() << "\n";  
  
  return 0;
}
