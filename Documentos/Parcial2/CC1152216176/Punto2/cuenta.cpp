#include <iostream>
#include "cuenta.h"

using namespace std;

//Constructor Cuenta
Cuenta::Cuenta(double s)
{
	//comprobar si el saldo es valido
	if(s < 0.0)
	{
		cout << "Saldo inválido, su saldo inicial se establecera como 0,0$.\n";
		saldo = 0.0;
	}
 	else
	{
		abonar(s);
	}
}

//Funcion abonar Cuenta
bool Cuenta::abonar(double d)
{
	//comprobar si el monto a depositar es valido
	if(d < 0.0)
	{
		cout << "Monto a depositar inválido, si desea retirar utilice la funcion cargar, su saldo no se vera afectado.\n";
		return false;
	}
 	else
	{
		saldo += d;
		return true;
	}
}

//Funcion cargar Cuenta
bool Cuenta::cargar(double r)
{
	//comprobar si el monto a retirar es valido
	if(r > saldo)
	{
		cout << "El monto a cargar excedio el saldo de la cuenta.\n";
		return false;
	}
	else if(r < 0.0)
	{
		cout << "Monto a retirr inválido, si desea hacer un deposito utilice la funcion cargar, su saldo no se vera afectado.\n";
		return false;
	}
	else
	{
		saldo -= r;
		return true;
	}
}

//Funcion getSaldo
double Cuenta::getSaldo()
{
	return saldo;
}

//Constructor CuentaAhorros
CuentaAhorros::CuentaAhorros(double s,double t) : Cuenta(s)
{
	//comprobar si la tasa de interes es valida
	if(0.0 > t >= 1.0)
	{
		cout << "Tasa de interes inválida, se establecera una tasa de interes del 2 porciento mensual\n";
		tasa = 0.02;
	}
 	else
	{
		tasa = t;
	}
}

//Funcion calcularInteres
double CuentaAhorros::calcularInteres()
{
	return getSaldo()*tasa;
}

//Constructor CuentaCheques
CuentaCheques::CuentaCheques(double s,double c) : Cuenta(s)
{
	//comprobar si la cuota ingresada es valida
	if(c < 0.0)
	{
		cout << "Cuota ingresada inválida, se establecera una cuota de 5.000$\n";
		cuota = 5000;		
	}
 	else
	{
		cuota = c;
	}
}

//Funcion abonar CuentaCheques
bool CuentaCheques::abonar(double d)
{
	if(Cuenta::abonar(d) && (getSaldo() >= cuota))
	{
		Cuenta::cargar(cuota);
	}
}

//Funcion cargar CuentaCheques
bool CuentaCheques::cargar(double r)
{
	if(Cuenta::cargar(r) && (getSaldo() >= cuota))
	{
		Cuenta::cargar(cuota);
	}
}
