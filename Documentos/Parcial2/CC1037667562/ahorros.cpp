/*
Implementación de la clase CuentaAhorros
*/

#include <iostream>
#include "ahorros.h"

using namespace std;

CuentaAhorros::CuentaAhorros( double inSaldo, double inInteres)
	//llamamos al constructor de la clase base
	:Cuenta(inSaldo)
{
	setInteres( inInteres ); //valida y almacena el Interes incial
}

//función para fijar interes
void CuentaAhorros::setInteres( double nwInteres )
{
	if ( nwInteres < 0 ) //verifica que no sea negativo
	{
		cout << "Tasa de interes ingresada es negativa" << endl;
		interes = 0.0; //set a cero por defecto
		cout << "fijando tasa de interes a: " << interes << endl;
	}
	else
	{
		interes = nwInteres;
		cout << "Tasa de interes ingresada y fijada en: " << interes << endl; 
	}
}

//función que obtiene el monto de interes para una cuenta 
double CuentaAhorros::calcularInteres() const
{
	double value;

	//calcula los ingresos a traves de getSaldo
	value = Cuenta::getSaldo() * interes; 

	return value;
} 

//agrega el monto de interes al saldo de la cuenta
void CuentaAhorros::addInteres()
{
	double toSum;
	toSum = calcularInteres();

	//agrega los intereses a traves de abonarSaldo 
	Cuenta::abonarSaldo(toSum);
}



