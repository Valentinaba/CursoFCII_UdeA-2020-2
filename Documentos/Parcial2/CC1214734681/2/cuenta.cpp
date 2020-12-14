#include "cuenta.h"

Cuenta::Cuenta( double saldo_ini = 0.0, string nombre = "  ")
{
	// inicializa el saldo en la cuenta
	if (saldo_ini >= 0.0) saldo = saldo_ini;
	else{
		cout << "El saldo ingresado es invalido, se establece a cero por defecto" << endl;
		saldo = 0.0;
	}
	nombre_propietario = nombre;
}

Cuenta::~Cuenta(){
	// destructor de la clase

	cout << "\nEliminando la cuenta de " << getNombre();
	cout << endl;
}

void Cuenta::abonar( double monto_abonar ){
	// esta funcion le agrega un monto al saldo de la cuenta

	if (monto_abonar >= 0.0) saldo += monto_abonar;
	else cout << "el saldo a abonar es invalido" << endl;
}

void Cuenta::cargar( double monto_retirar ){
	// esta funcion retira un monto de la cuenta

	if (monto_retirar < 0.0) cout << "El monto a retirar es invalido\n";
	else if (monto_retirar > saldo) cout << "Usted no tiene saldo suficiente\n";
	else saldo -= monto_retirar;
}

double Cuenta::getSaldo() const{
	// retorna el saldo en la cuenta

	return saldo;
}

string Cuenta::getNombre() const{
	// retorna el nombre del propietario de la cuenta

	return nombre_propietario;
}