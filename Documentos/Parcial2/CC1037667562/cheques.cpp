/*
Implementación de la clase CuentaCheques
*/

#include <iostream>
#include "cheques.h"

using namespace std;

CuentaCheques::CuentaCheques( double inSaldo, double inCuota ) //construccion
	//llamamos al constructor de la clase base
	: Cuenta(inSaldo)
{
	setCuota( inCuota ); //valida y fija la cuota por transacción
}

//funcion que fija la cuota por transaccion
void CuentaCheques::setCuota( double nwCuota )
{
	//verifica que la cuota sea mayor a cero
	cuota = (nwCuota < 0.0 ) ? 0.0: nwCuota; 

	cout << "La cuota fijada es: " << cuota << endl; 
}

//función para "modificar" la función base de abonar saldo
void CuentaCheques::abonarSaldo( double income)
{
	bool state; 
	state = Cuenta::abonarSaldo( income );

	if (state) //verifica que si se da la transacción 
	{
		cout << "\nSin embargo, debe considerar la cuota por transacción... " << endl;
		//resta el valor de la cuota al saldo
		Cuenta::cargarSaldo( cuota );
	}
}

//función para "modificar" la función base de cargar saldo
void CuentaCheques::cargarSaldo( double outcome )
{
	bool state;
	state = Cuenta::cargarSaldo( outcome );

	if (state) //verifica que si se da la transacción 
	{
		cout << "\nSin embargo, debe considerar la cuota por transacción... " << endl;
		//resta el valor de la cuota al saldo
		Cuenta::cargarSaldo( cuota );	
	}
}