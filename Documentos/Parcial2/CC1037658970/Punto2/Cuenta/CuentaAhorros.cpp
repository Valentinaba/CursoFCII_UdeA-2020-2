#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros( double saldoInicial, double tasaInteres ): CuentaBancaria(saldoInicial) // Se hereda a la clase base
{
	this -> tasaInteres = tasaInteres;
}

double CuentaAhorros::calculoInteres()
{
	return saldo*tasaInteres/100.;
}