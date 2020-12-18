#include "Cuenta.h"


Cuenta :: Cuenta(const double SaldoInicial)
{
  setSaldo(SaldoInicial);
}


void Cuenta :: setSaldo(const double SaldoInicial) //constructor
{
  if (SaldoInicial<0)//para asegurar que el saldo sea mayor o igual a 0
    {
      saldoCuenta = 0.0;
      cout <<"El Saldo es inicial inválido."<< endl;
    }
  else
    saldoCuenta = SaldoInicial;
}

//Esta función suma el abono a la cuenta
void Cuenta :: abonar(const double Abono)
{ 
  saldoCuenta = saldoCuenta + Abono;
}

//Esta función para el retiro 
void Cuenta :: cargar(double Carga)
{
    double nuevoSaldo=saldoCuenta - Carga;
  if (nuevoSaldo < 0)//garantiza qie el retiro sea inferior al saldo
    cout << "Monto inválido. El monto del retiro excede el saldo de su cuenta." << endl;
  else
    saldoCuenta= saldoCuenta - Carga; //se descarga el dinero de la cuenta
}

//Función para el saldo de la cuenta
double Cuenta:: getSaldo(void) const
{
  return saldoCuenta;
} 
