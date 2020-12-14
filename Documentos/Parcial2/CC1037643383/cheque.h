#ifndef CHEQUES_H
#define CHEQUES_H

#include "cuenta.h"

class CuentaCheques : public Cuenta //herencia
{
public:
	CuentaCheques(double, double); 
	void setCuota(double); //se verifica la cuota ingresada
	void abonar(double); //se suma el abono al saldo y se resta la cuota
	void cargar(double); //resta la carga al saldo y además resta la cuota

private:
	double cuota;
};

#endif
