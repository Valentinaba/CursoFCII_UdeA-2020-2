#include "cuenta_ahorros.h"
#include <iomanip>

// ------------------- Constructor ---------------------------

CuentaAhorros::CuentaAhorros(const string nombre = " ", double saldoInicial = 0, double tasa = 0) 
	: Cuenta(nombre, saldoInicial)
{
	Cuenta::setTipo("Ahorros");
	tasa_interes = tasa; // se define la tasa de interes
}

// ----------------- Metodos de la clase ---------------------

double CuentaAhorros::calcularInteres(void) const{

	return tasa_interes * getSaldo();

}

void CuentaAhorros::cuentaInfo(void) const{

	Cuenta::cuentaInfo();
	cout << "Tasa de interes:" << setw(15) << tasa_interes << endl;

}