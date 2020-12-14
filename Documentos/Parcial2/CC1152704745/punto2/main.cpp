#include "acc.h"

void norm_separator();
void doubl_separator();

int main(){

	cout << ">>> Cuenta Base: " << endl;

	// Instancia de la cuenta base
	cout << "Cuenta base, inicializacion correcta" << endl;
	Cuenta cb_instancia1(1299.34); // creación de instancia exitosa

	norm_separator();

	// uso normal y uso inválido de la función miembro abonar
	cb_instancia1.abonar(12.3);
	cb_instancia1.abonar(-34.2);

	norm_separator();

	// uso de la función miembro para visualizar el saldo
	cb_instancia1.getSaldo();

	norm_separator();

	// uso normal y uso inválido de la función miembro cargar
	cb_instancia1.cargar(14.2);
	cb_instancia1.cargar(-44.3);
	cb_instancia1.cargar(44231445.4);

	doubl_separator();

	cout << "Cuenta base, inicializacion incorrecta" << endl;

	Cuenta cb_instancia2(-4235.3); // creación de instancia con valor de saldo inválido

	norm_separator();

	// uso normal y uso inválido de la función miembro abonar
	cb_instancia2.abonar(12.3);
	cb_instancia2.abonar(-34.2);

	norm_separator();

	// uso de la función miembro para visualizar el saldo
	cb_instancia2.getSaldo();

	norm_separator();

	// uso normal y uso inválido de la función miembro cargar
	cb_instancia2.cargar(14.2);
	cb_instancia2.cargar(-44.3);
	cb_instancia2.cargar(44231445.4);

	doubl_separator();
	
	cout << ">>> Cuenta de Ahorros: " << endl;

	// instancia de la cuenta de ahorros
	cout << "Cuenta de ahorros, inicializacion correcta" << endl;
	CuentaAhorros ca_instancia1(3412.4,1.2);	

	norm_separator();

	// funciones miembro de calcular interés, revisar la tasa, y de cambiar la tasa
	ca_instancia1.calcInt();
	ca_instancia1.get_int();

	// uso correcto e incorrecto de la función para cambiar la tasa de interés
	ca_instancia1.reset_int(1.34);
	ca_instancia1.reset_int(-1.32);

	doubl_separator();

	// Inicialización inválida de la cuenta de ahorros
	cout << "Cuenta de ahorros, inicializacion incorrecta" << endl;
	CuentaAhorros ca_instancia2(-331.4,-1.56);

	doubl_separator();

	// Instancia de la cuenta de cheque
	cout << ">>> Cuenta de cheques: " << endl;

	// Inicialización correcta de una cuenta de cheque 
	cout << "Cuenta de cheques, incialización correcta" << endl;
	CuentaCheques cc_instancia1(943245.5,530.);

	norm_separator();

	// uso normal e incorrecto de las funciones miembro de la cuenta cheque
	cc_instancia1.abonar(234.5);
	cc_instancia1.cargar(456.2);
	cc_instancia1.reset_cuot(33.2);	

	norm_separator();

	cc_instancia1.abonar(-345.2);
	cc_instancia1.cargar(34959582377.56);
	cc_instancia1.cargar(-34.5);
	cc_instancia1.reset_cuot(-34.2);

	doubl_separator();

	// inicialización incorrecta de la instancia de función cheque
	CuentaCheques cc_instancia2(-2345.3,-452.3);

	return 0;
}

// funciones para imprimir separadores entre los mensajes
void norm_separator() {
	cout << " ----- " << endl;
}

void doubl_separator() {
	cout << " ----------------- " << endl;
	cout << endl;
}

