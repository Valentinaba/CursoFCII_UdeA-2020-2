#include <iostream>
#include "ahorros.h"

using namespace std;

CuentaAhorros::CuentaAhorros(double Saldo, double Interes)
	
	:Cuenta(Saldo)
{
	setInteres(Interes); //valida el interés inicial
}

void CuentaAhorros::setInteres(double Interes_n) //se fija el interés
{
	if (Interes_n < 0) //verifica que el interés no sea negativo
	{
		cout << "La tasa de interés ingresada es negativa" << endl;
		interes = 0.0; 
		cout << "por lo cual, se fija la tasa de interés a: " << interes << endl;
	}
	else
	{
		interes = Interes_n;
		cout << "Tasa de interés ingresada y fijada en: " << interes << endl; 
	}
}

double CuentaAhorros::cal_Interes() const  //función para obtener el interés de una cuenta
{
	double valor;

	valor = Cuenta::getSaldo() * interes; //utiliza getSaldo para calcular el interés 

	return valor;
} 

void CuentaAhorros::agr_Interes() //suma el interés al saldo de la cuenta
{
	double Sum;
	Sum = cal_Interes();
	Cuenta::abonar(Sum); //utiliza abonar para sumar los intereses
}
