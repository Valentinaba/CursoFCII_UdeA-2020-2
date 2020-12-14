#include <iostream>
#include <iomanip>

// se incluyen los archivos de las clases
#include "Cuenta.h"
#include "cuentaAhorros.h"
#include "cuentaCheque.h"


using namespace std;

int main(){

  // se prueba la clase cuenta
  // se prueban las funciones y algunas excepciones
  cout << "------------------------------------------------------------------------" << endl;
  cout << "Clase Cuenta: " << endl;
  cout << " " << endl;
  
  Cuenta cuenta2(-100);
  cout << " " << endl;  
  Cuenta cuenta1(100000);
  cout << " " << endl;  

  cuenta1.abonarSaldo(50000.25);
  cuenta1.abonarSaldo(0.0);
  cout << " " << endl;
  
  cuenta1.cargarSaldo(35000.15);
  cuenta1.cargarSaldo(-2000);
  cuenta1.cargarSaldo(1000000);
  
  cout << " " << endl;

  // se prueba la clase cuentaAhorros
  // se prueban las funciones y algunas excepciones
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "Clase cuentaAhorros: " << endl;
  cout << " " << endl;

  cuentaAhorros cuentaAhorros2(-30000,20);
  cout << " " << endl;
  
  cuentaAhorros cuentaAhorros3(400000,-20);
  cout << " " << endl;
  
  cuentaAhorros cuentaAhorros1(200000, 10);
  cout << " " << endl;

  cuentaAhorros1.abonarSaldo(10000.00); 
  cuentaAhorros1.sumaInteres(); // se agrega interes al saldo cuando se le abona a este
  cout << " " << endl;

  
  cuentaAhorros1.cargarSaldo(1000000);
  cout << " " << endl;  
  cuentaAhorros1.cargarSaldo(5000.35);
  cout << " " << endl;



  // se prueba la clase cuentaCheques
  // se prueban las funciones y algunas excepciones
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "Clase cuentaCheque: " << endl;
  cout << " " << endl;

  cuentaCheque cuentaCheque2(-2500, 50);
  cout << " " << endl;
  cuentaCheque cuentaCheque1(15000, 50);

  cout << " " << endl;
  cuentaCheque1.abonarSaldo(-250.25);
  cout << " " << endl;  
  cuentaCheque1.abonarSaldo(4250.25); 
  cout << " " << endl;

  
  cuentaCheque1.cargarSaldo(-500.00);
  cout << " " << endl;  

  cuentaCheque1.cargarSaldo(1000.00);
  cout << " " << endl;  
  
  return 0;

}
