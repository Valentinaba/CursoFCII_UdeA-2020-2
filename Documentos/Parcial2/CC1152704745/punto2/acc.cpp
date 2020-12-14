#include "acc.h"

// ___________________ CUENTA BASE ____________________

Cuenta::Cuenta(double s){
	if (s < 0.0){
		cout << "Saldo inicial invalido. Se asignara un valor de $0.0 ." << endl;
		saldo = 0.0;
	}
	else {
		cout << "Saldo asignado a $" << s << endl;
		saldo = s;
	}
};

// se define la función abonar para sumar saldo al ya existente
void Cuenta::abonar(double s) {
	// la función abonar sólo debe usarse para sumar a la cuenta, por lo tanto, el monto a abonar debe ser positivo
	if (s < 0.0) {
		cout << "Monto a abonar invalido, el saldo permanece sin cambio." << endl;
	}
	else {
		cout << "Se ha abonado $" << s << " al saldo. Saldo total: $";
		saldo += s;
		cout << saldo << endl;
	}
}

// se define la función cargar para retirar dinero de la cuenta
void Cuenta::cargar(double s) {
	// solo se puede retirar dinero de la cuenta si la cantidad que se quiere retirar es menor o igual a la cantidad actual
	if (s > saldo) {
		cout << "Cantidad a retirar invalida. No puede retirarse mas de lo que hay en la cuenta." << endl;
	}
	else if (s < 0.0) {
		cout << "No puede retirar una cantidad negativa. Use la función abonar." << endl;
	}
	else {
		cout << "Retirando $" << s << " de la cuenta. Saldo total: $";
		saldo -= s;
		cout << saldo << endl;
	}
}

// se define la función getSaldo, la cual devuelve el saldo actual en la cuenta
void Cuenta::getSaldo() const {
	cout << "Saldo total: $" << saldo << endl;
}


// _____________________ CUENTA DE AHORROS _______________________

// el constructor de la clase utiliza el constructor de la clase base para determinar el saldo, y además
// usa una salvaguarda para evitar ingresar tasas de interés negativas. 

// se define ahora una función que calcula y devuelve el interés asociado a la cuenta considerando
// el saldo actual en la cuenta y el interés que se definió para esta

double CuentaAhorros::calcInt() {
	double cint = saldo*tInt/100.;

	cout << "El interes para la cuenta es de: $" << cint << endl;

	return cint;
}

// se definen funciones para resetear la tasa de interés, para imprimirla, y para revisar si la tasa de
// interés es válida (que no sea negativa)

void CuentaAhorros::check_int(double i) {
	if (i < 0){
			cout << "Tasa de interes invalida. Se asignara una tasa de interes del 1%." << endl;
			tInt = 1;
		}
	else {
		get_int();
	}
}

void CuentaAhorros::get_int() {
	cout << "La tasa de interes actual es del " << tInt << "%." << endl;
}

void CuentaAhorros::reset_int(double i) {
	if (i < 0) {
		cout << "Tasa de interes invalida. Esta permanecera sin cambio." << endl;
	}
	else {
		cout << "Tasa de interes fijada al " << i << "%." << endl;
		tInt = i;
	}
}


// _____________________ CUENTA DE CHEQUE _______________________

// el constructor de la clase hace uso del constructor de la clase base para determinar el saldo de la cuenta
// y también se verifica que la cuota asignada a la cuenta sea válida

// se define una función que determina la validés de la cuota asignada, y de no ser el caso, se asigna
// una cuota por defecto del 0.8% del saldo inicial de la cuenta
void CuentaCheques::check_cuot(double cuo) {
	if (cuo < 0) {
		cout << "Monto de la cuota invalido. La cuota por defecto sera el 8% del saldo actual." << endl;
		cuot = saldo * 0.08;
		cout << "Monto de la cuota fijado a $" << cuot << endl;
	}
	else {
		cout << "Monto de la cuota fijado a $" << cuot << endl;
		cuot = cuo;
	}
}

// se define una función para cambiar la cuota asociada a la cuenta
void CuentaCheques::reset_cuot(double cuo) {
	if (cuo < 0) {
		cout << "Monto de la cuota invalido. La cuota permanecera sin cambio." << endl; 
	}
	else {
		cout << "Monto de la cuota fijado a $" << cuot << endl;
		cuot = cuo;
	}
}

// redefinición de las funciones miembro abonar y cargar de la clase base
void CuentaCheques::abonar(double ab) {
	bool op_made = op_verif_abonar(ab);

	if (op_made) {
		saldo -= cuot;
	}
	else {
		cout << "La operación no pudo ser realizada. La cuota no fue cobrada." << endl;
	}
}

void CuentaCheques::cargar(double ca) {
	bool op_made = op_verif_cargar(ca);

	if (op_made) {
		saldo -= cuot;
	}
	else {
		cout << "La operación no pudo ser realizada. La cuota no fue cobrada." << endl;
	}
}

// para determinar si una transacción fue exitosa, se define una función tipo booleana que 
// revisa si el saldo de la cuenta fue modificado. Esta función realiza además la operación
bool CuentaCheques::op_verif_abonar(double cant) {
	double ori_saldo = saldo;
	Cuenta::abonar(cant);

	if (ori_saldo != saldo) {
		return true;
	}
	else {
		return false;
	}
}

bool CuentaCheques::op_verif_cargar(double cant) {
	double ori_saldo = saldo;
	Cuenta::cargar(cant);

	if (ori_saldo != saldo) {
		return true;
	}
	else {
		return false;
	}
}
