/*
Implementación de la clase cuenta 
*/

#include <iostream>
#include "cuenta.h"

using namespace std; 

//constructor 
Cuenta::Cuenta( double inSaldo )
{
	setSaldo(inSaldo); //valida y almacena Saldo inicial
}

//verificación de saldo
void Cuenta::setSaldo( double nwSaldo )
{
	if ( nwSaldo < 0.0 ) //si es menor que cero
	{
		saldo = 0.0; //fija en 0.0 el saldo
		cout << "Valor ingresado no es válido " << endl;
	}
	else
	{
		saldo = nwSaldo; //inicializa para valores válidos
		cout << "Valor ingresado correctamente " << endl;
	}

	//informa al usuario el saldo inicial
	cout << "Saldo fijado en: " << saldo << endl; 
}

//obteniendo saldo - variable privada de la clase
double Cuenta::getSaldo() const
{
	return saldo;
}

//función para ingresar dinero a la cuenta
bool Cuenta::abonarSaldo( double income )
{
	if ( income >= 0.0 ) //si el monto es válido
	{
		saldo += income; //aumenta el saldo 
		cout << "Se agregó " << income << " a su cuenta " << endl;
		cout << "Saldo actual: " << saldo << endl;
		return true;
	}
	else
	{
		//si el monto no es válido informa al usuario
		cout << "Ingrese monto a abonar válido" << endl;
		return false;
	}
}

//función para retirar dinero de la cuenta 
bool Cuenta::cargarSaldo( double outcome )
{
	//verifica el monto a retirar 
	if ( outcome > saldo) 
	{
		//el saldo no cambia si el monto no es válido 
		cout << "El monto a cargar excede el saldo de la cuenta... " << endl;
		cout << "Saldo actual: " << saldo << endl;
		return false;
	}

	else if ( outcome < 0.0)
	{
		//notifica al usuario cuando la transacción no se lleva a cabo
		cout << "Transacción no permitida... Saldo actual: " << saldo << endl;
		return false;
	}

	else
	{
		saldo -= outcome; //resta el monto si es valido
		cout << "Se retiró: " << outcome << " de su cuenta "<< endl;
		cout << "Saldo actual: " << saldo << endl;
		return true;
	}
}


