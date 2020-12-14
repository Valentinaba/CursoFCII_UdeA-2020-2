#include "Cuenta.h"


Cuenta :: Cuenta(const double Init_Saldo)
{
  Set_saldo(Init_Saldo);
}
/*
Cuenta :: ~Cuenta()
{
  cout << "Destructor" <<endl;
  }*/
void Cuenta :: Set_saldo(const double init_sald)
{
  if (init_sald<0)
    {
      Saldo_cuenta = 0.0;
      cout <<"Saldo inválido. Su cuenta ha sido inicializada en 0.0"<< endl;
    }
  else
    Saldo_cuenta = init_sald;
}

//Esta función suma el abono a la cuenta
void Cuenta :: abonar(const double abono)
{
  Saldo_cuenta += abono;
}

//Esta función carga el retiro y verigica que no exceda el saldo
void Cuenta :: cargar(double carga)
{
  if (Saldo_cuenta-carga<0)
    cout << "El dinero a retirar excede el saldo de su cuenta." << endl;
  else
    Saldo_cuenta -= carga;
}

//Función para obtener el saldo de la cuenta
double Cuenta:: getSaldo(void) const
{
  return Saldo_cuenta;
}
