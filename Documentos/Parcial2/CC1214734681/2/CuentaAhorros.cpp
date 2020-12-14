#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros( string nombre = " ", double saldo_ini = 0.0, 
								double interes_ini = 0.0)
	: Cuenta(saldo_ini, nombre){  // Inicializa el saldo y el nombre del propietario

	if(interes_ini >= 0.0) interes = interes_ini;  // establece el interes de la cuenta de ahorros
	else{
		cout << "interes invalido, establecido a 0.0 por defecto" << endl;
		interes = 0.0;
	}
}

CuentaAhorros::~CuentaAhorros(){
	// elimina la cuenta de ahorros

	cout << "\nEliminando la cuenta de ahorros de " << getNombre() << endl;
}

double CuentaAhorros::calcularInteres() const{
	// calcula el interes de la cuenta de ahorros

	return interes * getSaldo();  // la subclase no puede usar saldo, pero puede obtener su valor
}