#include "fecha.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	Fecha date1(28, 2, 2002); // año no biciesto
	Fecha date2(28, 2, 2000); // año biciesto

	// formatos de fecha---------------
	string formato1 = A_M_D_GUION;
	string formato2 = D_M_A_GUION;
	string formato3 = D_M_A_SLASH;
	string formato4 = D_M_A_COMPLETE;

	// se muestra en pantalla los formatos disponibles------
	cout << "------ Los formatos disponibles son  ------" << endl;
	cout << "Formato 1: ";
	date1.print(formato1);
	cout << endl;
	cout << "Formato 2: ";
	date1.print(formato2);
	cout << endl;
	cout << "Formato 3: " ;
	date1.print(formato3);
	cout << endl;
	cout << "Formato 4: " ;
	date1.print(formato4);
	cout << endl;

	// se ve el efecto de que el año sea bisiesto -----------
	cout << "----- Se avanza un dia las fechas -----" << endl;
	cout << right << "Fecha" << setw(12) << "Antes" << setw(12) << "Despues" << endl;
	cout << right << setw(3) << "1" << setw(9);
	date1.print(formato3);
	date1.diaSig();
	cout << setw(4);
	date1.print(formato3);
	cout << endl;

	cout << right << setw(3) << "2" << setw(9);
	date2.print(formato3);
	date2.diaSig();
	cout << setw(4);
	date2.print(formato3);
	cout << endl;

	// se chequea el cambio de año
	date1.setMonth(12);
	date1.setDay(31);


	cout << "----- se avanza un dia para ver el año nuevo -----" << endl;
	cout << right << "Antes" << setw(12) << "Despues" << endl;
	cout << right;
	date1.print(formato3);
	date1.diaSig();
	cout << setw(4);
	date1.print(formato3);
	cout << endl;	


	return 0;
}