#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H

#include "cuenta.h"

class CuentaAhorros : public Cuenta
{
public:
	CuentaAhorros( string, double, double );
	~CuentaAhorros();
	
	double calcularInteres() const;

private:
	double interes;
	
};


#endif