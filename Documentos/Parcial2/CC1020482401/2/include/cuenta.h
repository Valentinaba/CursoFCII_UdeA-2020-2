#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>

using namespace std;

class Cuenta
{
public:
	Cuenta(const string, double);

	const string propietario; // Titular de la cuenta

	void abonar(double); // Transaccion de entrada
	void cargar(double); // Transaccion de salida
	
	// Transacciones de consulta
	double getSaldo(void) const; 
	void getTitular(void) const;
	void cuentaInfo(void) const;

	void setTipo(string);

private:
	
	double saldo; // Saldo disponible	
	string tipo = "Generica"; // tipo de cuenta
	const double saldo0; // saldo de apertura

};

#endif