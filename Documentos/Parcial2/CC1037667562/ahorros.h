#ifndef AHORROS_H
#define AHORROS_H

#include "cuenta.h"

class CuentaAhorros : public Cuenta //declaramos la herencia
{
public:
	CuentaAhorros( double, double ); //constructor
	void setInteres( double ); //verifica el interes ingresado

	double calcularInteres() const; //calcula el interes sobre la cuenta

	void addInteres(); //agrega el interes al saldo

private:
	double interes; 
};


#endif