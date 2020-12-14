#include <iostream>
#include <iomanip>

#include "Cuenta.h" //se incluye el archivo de la clase


using namespace std;

// constructor
Cuenta::Cuenta(double saldoIn){
  cout << fixed;
  cout << setprecision(2); // se fija la precision en 2 para los numeros

  setSaldo(saldoIn); // se inicializa el saldo
}

// abonar saldo a la cuenta creada
// retorna bool para comprobar si el abono fue efectivo o no
bool Cuenta::abonarSaldo(double abonar){

  // si el abono es cero o negativo, no se abona
  // y se retorna false
  if(abonar <= 0.0){
    cout << "Valor de abono " << abonar << " invalido" << endl;
    return false;
  }

  // si el abono es efectivo, se abona y retorna true
  else {
    saldoCuenta += abonar;
    cout << "Se agrego a su cuenta " << abonar << " dolares" << endl;
    cout << "Valor actual en la cuenta es: " << saldoCuenta << endl;
    cout << " " << endl;
    return true;
  }
}


// funcion para retirar saldo, resta del saldo en la cuenta
// retorna bool para comprobar si el retiro fue efectivo o no
bool Cuenta::cargarSaldo(double cargar){

  // si el valor a retirar es cero o negativo
  // se retorna false
  if(cargar<=0){
    cout << "Valor a retirar de " << cargar << " no permitido" << endl;
    return false;
  }

  else if(cargar > saldoCuenta){
    cout << "Valor a retirar de "<< cargar << " excede el saldo en la cuenta" << endl;
    return false;
  }

  // si el valor a retirar es correcto, se resta del saldo
  // se retorna true
  else{
    saldoCuenta -= cargar;
    cout << "Valor de " << cargar << " retirado satisfactoriamente" << endl;
    cout << "Su nuevo saldo en cuenta es: " << saldoCuenta << endl;
    cout << " " << endl;
    return true;
  }
  
}

// establece el saldo en la cuenta
void Cuenta::setSaldo(double saldo){

  // comprobar si el valor del saldo es correcto
  
  if (saldo <= 0.0){
    cout << "Saldo ingresado de "<< saldo << " es invalido" << endl;
    saldoCuenta = 0.0;
  }
  else{
    cout << "Saldo ingresado de " << saldo << " puesto satisfactoriamente" << endl;
    saldoCuenta = saldo;
  }
  cout << "Su saldo actual es: " << saldoCuenta << endl; 
  
}

// retornar el saldo de la cuenta
double Cuenta::getSaldo(){
  
  return saldoCuenta;
  
}
