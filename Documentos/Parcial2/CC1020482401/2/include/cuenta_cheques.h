#ifndef CUENTA_CHEQUES_H
#define CUENTA_CHEQES_H

#include <iostream>
#include <string>
#include "cuenta.h"


using namespace std;

class CuentaCheques : public Cuenta
{
public:
	CuentaCheques(const string, double, double);
	
	double costo_trans; // costo de un transaccion
	
	void abonar(double); // redefinicion de la Transaccion de entrada
	void cargar(double); // redefinicion de la Transaccion de salida

	void cuentaInfo(void) const; //Transaccion de consulta
	
};


#endif