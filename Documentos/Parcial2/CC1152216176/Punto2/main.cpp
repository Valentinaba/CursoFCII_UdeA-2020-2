#include <iostream>
#include <iomanip>
#include "cuenta.h"

using namespace std;

int main()
{
	//creacion de objetos
	Cuenta cuenta1(1000000);
	CuentaAhorros cuenta2(2000000,0.05);
	CuentaCheques cuenta3(3000000,3000);
	
	//prueva Cuenta::getSaldo en cuenta normal
	cout << fixed << setprecision(2) << "El valor inicial de la cuenta es: " << cuenta1.getSaldo() << "$\n";

	//prueva Cuenta::abonar en cuenta normal
	cuenta1.abonar(100000);
	cout << "El valor de la cuenta despues de abonar 100000$ es de: " << cuenta1.getSaldo() << "$\n";
	cuenta1.abonar(-100000);
	cout << "El valor de la cuenta despues de abonar -100000$ es de: " << cuenta1.getSaldo() << "$\n";

	//prueva Cuenta::cargar en cuenta normal
	cuenta1.cargar(10000);
	cout << "El valor de la cuenta despues de cargar 10000$ es de: " << cuenta1.getSaldo() << "$\n";
	cuenta1.cargar(-10000);
	cout << "El valor de la cuenta despues de cargar -10000$ es de: " << cuenta1.getSaldo() << "$\n\n";

	//prueva Cuenta::getSaldo en cuenta de ahorros
	cout << "El valor inicial de la cuenta de ahorros es: " << cuenta2.getSaldo() << "$\n";

	//prueva Cuenta::abonar en cuenta de ahorros
	cuenta2.abonar(200000);
	cout << "El valor de la cuenta de ahorros despues de abonar 200000$ es de: " << cuenta2.getSaldo() << "$\n";
	cuenta2.abonar(-200000);
	cout << "El valor de la cuenta de ahorros despues de abonar -200000$ es de: " << cuenta2.getSaldo() << "$\n";

	//prueva Cuenta::cargar en cuenta de ahorros
	cuenta2.cargar(20000);
	cout << "El valor de la cuenta despues de cargar 20000$ es de: " << cuenta2.getSaldo() << "$\n";
	cuenta1.cargar(-20000);
	cout << "El valor de la cuenta despues de cargar -20000$ es de: " << cuenta2.getSaldo() << "$\n";

	//prueva CuentaAhorros::calcularInteres en cuenta de ahorros
	cout << "El interes de su cuenta de ahorros es de: " << cuenta2.calcularInteres() << "$ mensuales\n";
	//añadir interes a la cuenta de ahorros
	cuenta2.abonar(cuenta2.calcularInteres());
	cout << "El valor de la cuenta de ahorros despues de abonar el interes es de: " << cuenta2.getSaldo() << "$\n\n";

	//prueva Cuenta::getSaldo en cuenta de cheques
	cout << "El valor inicial de la cuenta de cheques es: " << cuenta3.getSaldo() << "$\n";

	//prueva CuentaCheques::abonar en cuenta de cheques
	cuenta3.abonar(300000);
	cout << "El valor de la cuenta despues de abonar 300000$ es de: " << cuenta3.getSaldo() << "$\n";
	cuenta3.abonar(-300000);
	cout << "El valor de la cuenta despues de abonar -300000$ es de: " << cuenta3.getSaldo() << "$\n";

	//prueva CuentaCheques::cargar en cuenta de cheques
	cuenta3.cargar(30000);
	cout << "El valor de la cuenta despues de cargar 30000$ es de: " << cuenta3.getSaldo() << "$\n";
	cuenta3.cargar(-30000);
	cout << "El valor de la cuenta despues de cargar -30000$ es de: " << cuenta3.getSaldo() << "$\n\n";

	return 0;
}
