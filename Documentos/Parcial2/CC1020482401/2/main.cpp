#include <iostream>
#include <string>
#include "cuenta_ahorros.h"
#include "cuenta_cheques.h"
#include <iomanip>

using namespace std;


int main(int argc, char const *argv[])
{
	CuentaAhorros cuenta1("Obrero 1",  900000, 0.025);
	CuentaCheques cuenta2("Mac pato", 2000000, 5400);

	// Se muestra la info de las cuentas
	cout << "test de las clases..." << endl;
	cout << "Cuenta 1:" << endl;
	cuenta1.cuentaInfo();
	cout << endl;
	cout << fixed << setprecision(0);
	cout << "Cuenta 2:" << endl;
	cuenta2.cuentaInfo();
	cout << endl;

	// Se realiza un abono de 50000 a ambas cuentas 
	
	cuenta1.abonar(50000);
	cuenta2.abonar(50000);

	cout << "Luego del priemer abono los saldos son: " << endl;
	cout << "Cuenta 1: " << cuenta1.getSaldo() << endl;
	cout << "Cuenta 2: " << cuenta2.getSaldo() << endl;
	cout << endl;

	// Se realiza un retiro de 50000 a ambas cuentas 
	
	cuenta1.cargar(50000);
	cuenta2.cargar(50000);

	cout << "Luego del retiro los saldos son: " << endl;
	cout << "Cuenta 1: " << cuenta1.getSaldo() << endl;
	cout << "Cuenta 2: " << cuenta2.getSaldo() << endl;
	cout << endl;

	// se realiza un abono y un 
	// retiro invalido a la cuenta 2
	
	cuenta2.abonar(5300); // el abono no puede ser menor al costo de la transaccion
	cuenta2.cargar(cuenta2.getSaldo()); // si se retira todo el dinero no se podría pagar el costo de transacion

	cout << "Luego de las transaciones invalidas los saldos son: " << endl;
	cout << "Cuenta 1: " << cuenta1.getSaldo() << endl;
	cout << "Cuenta 2: " << cuenta2.getSaldo() << endl;
	cout << endl;

	

	return 0;
}