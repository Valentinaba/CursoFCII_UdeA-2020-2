#ifndef CUENTACHEQUES_H
#define CUENTACHEQES_H

#include "cuenta.h"


class CuentaCheques : public Cuenta
{
public:
	CuentaCheques(string, double, double);  // (nombre propietario, saldo inicial, cuota transaccion)
	~CuentaCheques();

	// se debe redefinir abonar y cargar de la clase Cuenta
	void abonar(double);
	void cargar(double);

private:
	double cuota_trans;
	
};


#endif