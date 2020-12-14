#include <iostream>
#include "fecha.h"

using namespace std;

int main()
{
	//creacion de objeto
	Fecha fecha1(15,6,1900);
	cout << "fecha inicial: ";
	fecha1.imprimirFecha();
	cout << "\n\n";

	//prueva setFecha
	fecha1.setFecha(26,1,1997);
	cout << "cambio de fecha usando setFecha: ";
	fecha1.imprimirFecha();
	cout << "\n";

	//prueva diaSig en un dia normal
	fecha1.diaSig();
	cout << "prueva funcion diaSig: ";
	fecha1.imprimirFecha();
	cout << "\n\n";

	//prueva diaSig en cambio de mes 31 dias
	fecha1.setFecha(31,1,1999);
	cout << "fecha inicial: ";
	fecha1.imprimirFecha();
	cout << "\n";
	fecha1.diaSig();
	cout << "prueva funcion diaSig: ";
	fecha1.imprimirFecha();
	cout << "\n\n";

	//30 dias
	fecha1.setFecha(30,4,1999);
	cout << "fecha inicial: ";
	fecha1.imprimirFecha();
	cout << "\n";
	fecha1.diaSig();
	cout << "prueva funcion diaSig: ";
	fecha1.imprimirFecha();
	cout << "\n\n";

	//29 dias
	fecha1.setFecha(29,2,2020);
	cout << "fecha inicial: ";
	fecha1.imprimirFecha();
	cout << "\n";
	fecha1.diaSig();
	cout << "prueva funcion diaSig: ";
	fecha1.imprimirFecha();
	cout << "\n\n";

	//28 dias
	fecha1.setFecha(28,2,2019);
	cout << "fecha inicial: ";
	fecha1.imprimirFecha();
	cout << "\n";
	fecha1.diaSig();
	cout << "prueva funcion diaSig: ";
	fecha1.imprimirFecha();
	cout << "\n\n";

	//prueva diaSig en cambio de año
	fecha1.setFecha(31,12,2005);
	cout << "fecha inicial: ";
	fecha1.imprimirFecha();
	cout << "\n";
	fecha1.diaSig();
	cout << "prueva funcion diaSig: ";
	fecha1.imprimirFecha();
	cout << "\n";

	return 0;
}
