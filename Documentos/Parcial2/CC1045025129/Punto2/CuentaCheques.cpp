#include <iostream>
using namespace std;


#include "CuentaCheques.h"

// constructor
CuentaCheques::CuentaCheques( double saldo, double transaccion )
  // llama explícitamente al constructor de la clase base
  : Cuenta( saldo )
{
  Transaccion = ( transaccion > 0.0 ) ? transaccion : 0.0; // valida y almacena el valor de la operación
 
}

double CuentaCheques::Abonar(double abono) 
{
  return Cuenta::Abonar(abono) - Transaccion;//Redefine la función Abonar, usando la de la clase base y restando el valor de la transacción (variable privada) 
}


double CuentaCheques::Cargar(double retiro){//Nueva función cargar
  if(retiro + Transaccion <= Cuenta::getSaldo()){//Nuevo saldo
    return Cuenta::Cargar(retiro) - Transaccion;}
  else{//Saldo insuficiente
    cout << "Lo sentimos, usted no tiene saldo suficiente para realizar esta transacción. " << endl;}
  
}
