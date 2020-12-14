#include "cuenta_base.h"

Cuenta::Cuenta(double inicial)
{
  if (inicial >= 0.0)
    {
      saldo = inicial;
      cout << "Se creo una cuenta con saldo inicial de " << fixed << setprecision(2) << getSaldo() << " pesos\n" << endl;
    }

  else
    {
      cout << "El saldo inicial es invalido. Se establece por defecto en 0.0\n" << endl;
      saldo = 0.0;
    }
}

void Cuenta::abonar(double abono)
{
  if (abono > 0.0)
    {
      saldo += abono;
      //cout << "Ha abonado " << setprecision(2) << abono << " pesos a su cuenta. Su saldo ahora es " << getSaldo() << " pesos\n" << endl;
    }

  else
    {
      cout << "El abono debe ser mayor que cero. No se modificara su saldo.\n" << endl;
    }
}

void Cuenta::cargar(double retiro)
{
  if (retiro > 0.0 and retiro <= saldo)
    {
      saldo -= retiro;
    }

  else if (retiro > saldo)
    {
      cout << "El monto a cargar excedio el saldo de la cuenta\n" << endl;
    }

  else if (retiro <= 0.0)
    {
      cout << "Cargue un monto mayor que cero y menor o igual a su saldo\n" << endl;
    }
}

double Cuenta::getSaldo() const
{
  return saldo;
}
