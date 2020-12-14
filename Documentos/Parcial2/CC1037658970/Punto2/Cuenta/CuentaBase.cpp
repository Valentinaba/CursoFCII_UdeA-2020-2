#include <iostream> 
#include "CuentaBase.h"
using namespace std;

CuentaBancaria::CuentaBancaria(double saldoInicial) 
{
  setSaldoInicial(saldoInicial);
}

void CuentaBancaria::setSaldoInicial( double saldoInicial )
{
  if (saldoInicial<0) // Corrobora que el saldo inicial sea valido
  {
    saldo  =  0;
    cout<<"Ha ingresado un valor invalido para el saldo inicial. Su saldo inicial es 0."<<endl;
  }
  else {saldo = saldoInicial;}
}  

bool CuentaBancaria::abonar( double abono )
{
  if (abono<0) // Corrobora que el abono sea valido
  {
    cout<<"Ha ingresado un abono negativo. No se hará ningún movimiento."<<endl;
    return false;
  }
  else
  {
    saldo += abono;
    return true;
  }
}
  
bool CuentaBancaria::cargar( double retiro )
{
  if (retiro<0) // Corrobora que el retiro sea valido
  {
    cout<<"Ha ingresado un retiro negativo. No se hará ningún movimiento."<<endl;
    return false;
  }

  else 
  {
    if(retiro>saldo) // Corrobora que el retiro no exceda el saldo en la cuenta
    {
      cout<<"El monto a cargar excedio el saldo de la cuenta. No se hará ningún movimiento."<<endl;
      return false;
    }
    else
    {
      saldo -= retiro;
      return true;
    }
  }
} 
  
double CuentaBancaria::getSaldo() const
{
  return saldo;
}