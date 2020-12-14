#include "CuentaCheques.h"

CuentaCheques::CuentaCheques( double saldoInicial, double costoTransaccion ): CuentaBancaria(saldoInicial)
{
	this -> costoTransaccion = costoTransaccion;
}

void CuentaCheques::abonar(double abono)
{
	if (CuentaBancaria::abonar(abono)){ saldo -= costoTransaccion; } // Usa el metodo abonar de la clase base para saber si hace el cobro de la transaccion
}

void CuentaCheques::cargar(double retiro)
{
	if (CuentaBancaria::cargar(retiro)){ saldo -= costoTransaccion; } // Usa el metodo cargar de la clase base para saber si hace el cobro de la transaccion
}