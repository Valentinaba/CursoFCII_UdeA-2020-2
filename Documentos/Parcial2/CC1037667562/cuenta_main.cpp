/*
main para la cadena de herencias de cuenta
*/


#include <iostream>
#include <iomanip>

#include "cuenta.h"
#include "ahorros.h"
#include "cheques.h"

using namespace std; 

int main()
{
	cout << setw(20) << "\n#·······#" << endl;
	cout << "Probando clase Cuenta" << endl;

	//probamos que funcionen las excepciones 
	Cuenta cuenta1( -15.9 );
	Cuenta cuenta2( 2000.12 );

	cuenta2.abonarSaldo( 100.8 );
	cuenta2.abonarSaldo( -1.0 );

	cuenta2.cargarSaldo( 400000.0 );
	cuenta2.cargarSaldo( 500 );
	

	cout << setw(20) << "\n#·······#" << endl;
	cout << "Probando clase CuentaAhorros" << endl;

	CuentaAhorros ahorros1( 2000.0, 0.01);

	cout << "\nUsando las funciones de la clase base" << endl;
	ahorros1.abonarSaldo( 130.21 );
	ahorros1.cargarSaldo( 87.9 );

	cout << "\nAgregamos los intereses: " << endl; 
	ahorros1.addInteres();
	

	cout << setw(20) << "\n#·······#" << endl;
	cout << "Probando clase CuentaCheques" << endl;

	CuentaCheques cheques1( 2000.0, 10.0);

	cout << "\nUsando las funciones de la clase base modificadas" << endl;
	cheques1.abonarSaldo( 130.21 );
	cheques1.cargarSaldo( 87.9 );


	return 0;
}

