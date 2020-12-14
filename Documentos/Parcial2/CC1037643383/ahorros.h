#ifndef AHORROS_H
#define AHORROS_H

#include "cuenta.h"

class CuentaAhorros : public Cuenta //herencia
{
public:
	CuentaAhorros(double, double);
	void setInteres(double); //interés ingresado
	double cal_Interes() const; //calcula el valor del interés sobre la cuenta
	void agr_Interes(); //agrega el interés al saldo

private:
	double interes; 
};


#endif
