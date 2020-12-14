#ifndef CUENTA_H
#define CUENTA_H

using namespace std;

class Cuenta
{
public:
	Cuenta(double); 

	void setSaldo(double); //verifica el saldo ingresado
	double getSaldo() const; //saldo de cuenta
	bool abonar(double); //abono, suma al saldo
	bool cargar(double); //retiro, resta al saldo

private:
	double saldo;
};

#endif 
