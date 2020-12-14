#ifndef CUENTA_H
#define CUENTA_H

class Cuenta
{

	public:
	//constructor
	Cuenta(double);

	//funciones
	bool abonar(double);
	bool cargar(double);
	double getSaldo();

	private:
	double saldo;
  
};

class CuentaAhorros : public Cuenta
{
	public:
	//constructor
	CuentaAhorros(double,double);

	//funciones
	double calcularInteres();

	private:
	double tasa;
  
};

class CuentaCheques : public Cuenta
{
	public:
	//constructor
	CuentaCheques(double,double);

	//funciones
	bool abonar(double);
	bool cargar(double);
  
	private:
	double cuota;

};
#endif
