#include "cuenta.h"
#include <iomanip>

// ------------------- Constructor ---------------------------

Cuenta::Cuenta(const string nombre = " ", double saldoInicial = 0)
	: propietario(nombre), saldo0( (saldoInicial < 0) ? 0 : saldoInicial)
{
	
	if (saldoInicial < 0){
		cout << "El saldo inicial introducido es invalido, se establecio en cero." << endl;
		saldo = 0;
	}
	else saldo = saldoInicial;
}

// ----------------- Metodos de la clase ---------------------

void Cuenta::abonar(double monto){

	if (monto < 0)
		cout << "transaccion invalida, el abono debe ser mayor a cero" << endl; 
	
	else saldo += monto; // Si el abono ingresado es valido se añade

}


void Cuenta::cargar(double monto){
	
	if (saldo - monto < 0)
		cout << "transaccion invalida, el monto a cargar exedio el saldo de la cuenta" << endl;
	
	else
		saldo -= monto; // Si el retiro solicitado es valido se saca

}


double Cuenta::getSaldo(void) const{
	
	return saldo;

}

void Cuenta::getTitular(void) const{

	cout << propietario ;

}

void Cuenta::setTipo(string tipoCuenta){

	tipo = tipoCuenta;

}

void Cuenta::cuentaInfo(void) const{

	cout << " ------------ Datos de la cuenta ------------ " << endl;
	cout << setfill('.') << "Titular: " << setw(15) << propietario << endl;
	cout << "Tipo: " << setw(15) << tipo << endl;
	cout << "Saldo inicial: " << setw(15)<< dec << saldo0 << endl;
	cout << "Saldo Actual :" << setw(15) << dec << saldo << endl;

}