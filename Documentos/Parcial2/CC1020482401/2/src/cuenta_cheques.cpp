#include "cuenta_cheques.h"
#include <iomanip>

// ------------------- Constructor ---------------------------

CuentaCheques::CuentaCheques(const string nombre = " ", double saldoInicial = 0, double costo = 0) 
    : Cuenta(nombre, saldoInicial)
{
	Cuenta::setTipo("Cheque");
    costo_trans = costo;
}

// ----------------- Metodos de la clase ---------------------

void CuentaCheques::abonar(double monto){
	
	monto = monto - costo_trans; // se modifica el monto segun el costo de la transaccion
	
	// si el monto modificado no satisface los criterios para la 
	// transacion esta no se lleva a cabo por como esta definido 
	// el metodo heredado abonar

	Cuenta::abonar(monto); 

}

void CuentaCheques::cargar(double monto){
	
	monto = monto + costo_trans; 
	Cuenta::cargar(monto);
}

void CuentaCheques::cuentaInfo(void) const{

	Cuenta::cuentaInfo();
	cout << "Costo transaccion" << setw(15) << costo_trans << endl;
}


