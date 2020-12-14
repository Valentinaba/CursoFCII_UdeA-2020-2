#include <iostream>
#include <cstdlib>
#include "manejo_cuentas.h"

using namespace std;

Cuenta::Cuenta( const string &_nombreCuenta, double _saldoInit)
{
  nombreCuenta = _nombreCuenta;
  saldo = _saldoInit;
  
  checkSaldoInicial();
}

void Cuenta::getSaldo()
{
  cout << "Su saldo actual es: " << saldo << endl;
}

void Cuenta::checkSaldoInicial()
{
  
  if(saldo>= 0.0)
    {
      cout << "Se ha creado de forma exitosa la cuenta con titular: " << nombreCuenta << endl;
      getSaldo();
    }
  else
    {
      saldo = 0.0;
      cout << "ERROR! Saldo invalido. Se iniciara en 0.0" << endl;
      getSaldo();
    }
}

void Cuenta::abonar(double d)
{
  if(d<0)
    {
      cout << "Valor invalido" << endl;
      
    }
  else
    {
      saldo = saldo + d;
      cout << "Se ha abonado exitosamente " << d << "." << endl;
      getSaldo();
      
    }
}

void Cuenta::cargar(double d)
{

  if(d<0)
    {
      cout << "Valor invalido" << endl;
    }
  else
    {
      if(saldo-d < 0.0)
	{
	  cout << "No se puede realizar la operacion, supera sus fondos." << endl;
	  getSaldo();
	  
	}
      else
	{      
	  saldo = saldo - d;
	  cout << "Se ha retirado exitosamente " << d <<  endl;
	  getSaldo();
	  
	}
    }
}

CuentaAhorros::CuentaAhorros( const string &_nombreCuenta, double _saldoInit, double _interes) : Cuenta( _nombreCuenta, _saldoInit)
{
  if(_interes>0 && _interes<100)
    {
      interes = _interes;
      cout << "La tasa de interes es: " << interes << "%" << endl;
    }
  else
    {
      interes = 0.04;
      cout << "Valor invalido. El valor estandar es: " << interes*100 << "%" << endl;
    }
}

double CuentaAhorros::calcularInteres()
{
  double valInt = saldo*interes/100;
  cout << "Los interes obtenidos son: " << valInt << endl;  
  return valInt;
}

void CuentaAhorros::addInteres()
{
  abonar(calcularInteres());
  getSaldo();
}

CuentaCheques::CuentaCheques( const string &_nombreCuenta, double _saldoInit, double _trans) : Cuenta( _nombreCuenta, _saldoInit)
{
  if(_trans>0)
    {
      trans = _trans;
      cout << "La couta por transaccion es: " << trans << endl;
    }
  else
    {
      trans = 6;
      cout << "Valor invalido. El valor estandar es: " << trans << endl;
    }
}

void CuentaCheques::cobrarTransaccion()
{
  saldo = saldo - trans;
  cout << "Se ha efectuado el cobro por transaccion" << endl;
  getSaldo();
}

void CuentaCheques::abonar(double d)
{
  double s = saldo;
  Cuenta::abonar(d);
  if(s<saldo)
    {
      getSaldo();
      cobrarTransaccion();
    }
  else
    {
      cout << "No se realizo el deposito" << endl;
    }
}

void CuentaCheques::cargar(double d)
{
  double s = saldo;
  Cuenta::cargar(d);
  if(s>saldo)
    {
      getSaldo();
      cobrarTransaccion();
    }
  else
    {
      cout << "No se realizo el cargo" << endl;
    } 
}
