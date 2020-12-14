#include <iostream>
#include "cuenta.h"

using namespace std; 

Cuenta::Cuenta(double Saldo)
{
	setSaldo(Saldo); //valida y almacena Saldo inicial
}


void Cuenta::setSaldo(double Saldo_n) //se verifica el saldo
{
	if (Saldo_n < 0.0) //caso en el que el saldo sea  menor que cero
	{
		saldo = 0.0; //se fija el saldo en 0
		cout << "El valor que ingresó no es válido, ingrese nuevamente " << endl;
	}
	else
	{
		saldo = Saldo_n; 
		cout << "Valor ingresado válido " << endl;
	}
	
	cout << "Su saldo: " << saldo << endl; 
}


double Cuenta::getSaldo() const //le muestra el saldo al usuario
{
	return saldo;
}


bool Cuenta::abonar(double abono) //abono a la cuenta
{
	if ( abono >= 0.0 ) 
	{
		saldo += abono; //se suma el saldo actual con el abono para obtener el nuevo abono 
		cout << "Se abonó " << abono << " al saldo de su cuenta " << endl;
		cout << "El saldo actual de su cuenta es: " << saldo << endl;
		return true;
	}
	else
	{
    		cout << "Ingrese un abono válido" << endl;
		return false;
	}
}

bool Cuenta::cargar(double retiro) //retiro a la cuenta
{
       	if (retiro > saldo) 
	{ 
		cout << "El monto a cargar excede el saldo de la cuenta" << endl;
		cout << "El saldo actual de su cuenta es: " << saldo << endl;
		return false;
	}

	else if (retiro < 0.0)
	{
	        cout << "Transacción no válida" << endl;
		cout << "El saldo actual de su cuenta es: " << saldo << endl;
		return false;
	}

	else
	{
		saldo -= retiro; //resta el valor del retiro al saldo de la cuenta
		cout << "Se retiró: " << retiro << " de su cuenta "<< endl;
		cout << "El saldo actual de su cuenta es: " << saldo << endl;
		return true;
	}
}
