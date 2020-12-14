#include "CuentaCheques.h"

CuentaCheques::CuentaCheques(string nombre = " ", double saldo_ini = 0.0,
								double costo = 0.0)
	: Cuenta(saldo_ini, nombre){  // establece el nombre del propietario y el saldo inicial

	// establece el costo de la transaccion para la cuenta
	if (costo > 0.0) cuota_trans = costo;
	else{
		cout << " costo de transaccion invalido, estalbecido a 0.0 por defecto" << endl;
		cuota_trans = 0.0;
	}
}

CuentaCheques::~CuentaCheques(){
	// elimina la cuenta cheque

	cout << "\nEliminando la cuenta cheque de " << getNombre() << endl;
}

void CuentaCheques::abonar( double monto_abonar){
	// ingresa dinero a la cuenta

	double abono_neto = monto_abonar - cuota_trans;

	// lo siguiente es para asegurar que alcanza la plata
	if ( getSaldo() + abono_neto > 0) Cuenta::abonar(abono_neto);
	else cout << "El costo de transaccion supera el dinero en la cuenta cheque" << endl;
}

void CuentaCheques::cargar( double monto_retirar){
	// retira saldo de la cuenta

	double retiro_neto = monto_retirar + cuota_trans;

	// se asegura que alcanza la plata
	if ( getSaldo() - retiro_neto > 0) Cuenta::cargar(retiro_neto);
	else cout << "El costo de transaccion supera el dinero en la cuenta cheque" << endl;

}