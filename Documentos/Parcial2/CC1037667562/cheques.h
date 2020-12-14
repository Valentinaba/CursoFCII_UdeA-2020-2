#ifndef CHEQUES_H
#define CHEQUES_H

#include "cuenta.h"

class CuentaCheques : public Cuenta //declaramos la herencia
{
public:
	CuentaCheques( double, double ); //constructor
	void setCuota( double ); //verifica la cuota ingresada

	void abonarSaldo( double ); //suma a saldo y resta la cuota
	void cargarSaldo( double ); //resta a saldo incluyendo cuota

private:
	double cuota;
};

#endif