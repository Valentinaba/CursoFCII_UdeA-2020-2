#include <iostream>
#include <iomanip>
#include "cuentabase.h"

using namespace std;

// Implementación de la clase base Cuenta

// Constructor
Cuenta::Cuenta(double saldo_ini)
{
  if (saldo_ini >= 0.0)
    {
      saldo_cuenta = saldo_ini;
      cout << fixed << "Su cuenta tiene un saldo inicial de " << setprecision(1) << saldo_cuenta << " pesos." << endl;
    }

  else
    {
      cout << "El saldo inicial debe ser positivo. Se establece en 0.0\n" << endl;
      saldo_cuenta = 0.0;
    }
}
// Función para ingresar dinero a la cuenta
bool Cuenta::abonar(double ingreso)
{
  if (ingreso > 0.0)
    {
      saldo_cuenta += ingreso;
      return true;
    }

  else
    {
      cout << "Se requiere una cantidad mayor que cero.\n" << endl;
      return false;
    }
}

// Función para sacar dinero de la cuenta
bool Cuenta::cargar(double cargo)
{
  if (0.0 < cargo and cargo <= saldo_cuenta)
    {
      saldo_cuenta -= cargo;
      return true;
    }

  else if (cargo <= 0.0)
    {
      cout << "Retire una cantidad mayor que cero.\n" << endl;
      return false;
    }

  else if (cargo > saldo_cuenta)
    {
      cout << "El monto a cargar excedio el saldo de la cuenta.\n" << endl;
      return false;
    }
}

// Retorna el saldo actual
double Cuenta::getSaldo() const
{
  return saldo_cuenta;
}
