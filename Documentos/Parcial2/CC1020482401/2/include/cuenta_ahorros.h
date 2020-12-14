#ifndef CUENTA_AHORROS_H
#define CUENTA_AHORROS_H

#include <iostream>
#include <string>
#include "cuenta.h" // clase padre

using namespace std;

class CuentaAhorros : public Cuenta
{
public:
	CuentaAhorros(const string, double, double);

	double tasa_interes;
	
	double calcularInteres(void) const; // Operacion calcular utilidad por intereses
	void cuentaInfo(void) const; // Transaccion de consulta

};


#endif