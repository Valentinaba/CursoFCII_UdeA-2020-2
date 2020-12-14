#ifndef CUENTA_H
#define CUENTA_H


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Cuenta
{
public:
	Cuenta( double , string); // constructor (saldo_inicial, nombre_propietario)
	~Cuenta(); // destructor

	void abonar( double );  // aumenta el saldo
	void cargar( double );  // retira saldo de la cuenta
	double getSaldo() const;  // muestra el saldo actual
	string getNombre() const;

private:
	double saldo;
	string nombre_propietario;  // nombre del propietario de la cuenta
};

#endif