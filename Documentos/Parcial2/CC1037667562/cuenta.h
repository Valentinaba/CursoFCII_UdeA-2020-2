#ifndef CUENTA_H
#define CUENTA_H

using namespace std;

class Cuenta
{
public:
	Cuenta( double ); //constructor

	void setSaldo( double ); //verifica el saldo ingresado
	double getSaldo() const; //obtiene el saldo de cuenta

	bool abonarSaldo( double ); //suma monto a saldo

	bool cargarSaldo( double ); //retirar dinero

private:
	double saldo;
};

#endif