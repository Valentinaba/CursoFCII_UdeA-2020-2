/*
main del punto 1 del parcial 3 - prueba y uso de la clase fecha
*/

#include <iostream>
#include "fecha.h"

using namespace std;

int main()
{
	// Comprobando funcionamiento de fecha
	cout << "Probando la clase Fecha" << endl;
	Fecha comprobar( 8, 32, 1900 );

	//Calculando día siguiente 
	cout << "\nComprobando que si cambie de mes" << endl;
	Fecha diaSig1( 3, 31, 1998 );
	diaSig1.diaSig();
	
	cout << "\nComprobando que si cambie de día" << endl;
	Fecha diaSig2( 2, 28, 2020 );
	diaSig2.diaSig();

	cout << "\nComprobando que si cambie de año" << endl;
	Fecha diaSig3( 12, 31, 1999);
	diaSig3.diaSig();

	return 0;
}