#include <iostream>

using std::cout;
using std::endl;

#ifndef ACC_H
#define ACC_H

class Cuenta {
	public:
	Cuenta(double);
	
	void abonar(double);
	void cargar(double);
	void getSaldo() const;

	protected:
	double saldo;
};


class CuentaAhorros : public Cuenta {
	public:
	// se usa directamente el constructor de la clase origen para inicializar el saldo de la cuenta de ahorros
	CuentaAhorros(double s,double i) : Cuenta(s), tInt(i) {
		check_int(i);	
	};
	double calcInt();	
	void get_int();
	void reset_int(double);

	private:
	double tInt;
	void check_int(double);
};

class CuentaCheques : public Cuenta {
	public:
	// se usa nuevamente el constructor de la clase origen para inicializar el saldo de la cuenta de cheque
	// y además se revisa que el monto de la cuota sea válido
	CuentaCheques(double s, double cuo) : Cuenta(s), cuot(cuo) {
		check_cuot(cuo);
	};
	
	void abonar(double);
	void cargar(double);
	void reset_cuot(double);
	
	private:
	double cuot;

	void check_cuot(double);
	bool op_verif_abonar(double);
	bool op_verif_cargar(double);
};

#endif
