//Interfaz

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "P2CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(double CAsaldo, double CAinteres){
	setSaldo(CAsaldo);
	setInteres(CAinteres);

}

double CuentaAhorros::calcularInteres() const {
	double total = CuentaAhorros::getSaldo()*CuentaAhorros::interes;
	cout << "Interés: " << total <<"$"<<endl;
	return total;
}

void CuentaAhorros::setInteres(double CAinteres){
	interes = abs(CAinteres);
}
					
