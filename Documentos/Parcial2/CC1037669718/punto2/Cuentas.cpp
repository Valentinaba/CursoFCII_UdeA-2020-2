#include"Cuentas.h"
#include<iostream>

Cuenta::Cuenta( double saldo_inicial ){
  if( saldo_inicial < 0 ){
    std::cout << "El saldo ingresado no es válido.\n" ;
  }
  else{
    abonar( saldo_inicial );
  }
}

void Cuenta::abonar( double monto ){
  saldo += monto;
}

bool Cuenta::cargar( double monto ){
  if( monto > saldo ){
    std::cout << "El monto a cargar excedio el saldo de la cuenta.\n";
    return false;
  }
  else{
    saldo -= monto;
    return true;
  }
}

double Cuenta::getSaldo(){
  return saldo;
}

CuentaAhorros::CuentaAhorros( double saldo_inicial , double tasa_inicial ) : Cuenta( saldo_inicial ){
  tasa_interes = tasa_inicial;
}

double CuentaAhorros::calcularInteres(){
  return getSaldo()*tasa_interes;
}

CuentaCheques::CuentaCheques( double saldo_inicial , double cuota_inicial ) : Cuenta( saldo_inicial ){
  cuota = cuota_inicial;
}

void CuentaCheques::abonar( double monto ){
  Cuenta::abonar( monto - cuota);
}

bool CuentaCheques::cargar( double monto ){
  bool prueba = Cuenta::cargar( monto );
  if( prueba && ( getSaldo() >= monto ) ){
    cargar( cuota );
  }
  return prueba;
}
