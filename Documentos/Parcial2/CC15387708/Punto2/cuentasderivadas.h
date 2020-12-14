#include "cuentabase.h"

//Se define una clase para las cuentas de ahorro

class CuentaAhorros: public Cuenta //Herencia de la cuenta base
{
 public:
  CuentaAhorros(double = 0.0, double = 0.0);

  //Funcion para calcular el valor del interes sobre el saldo
  double CalcularInteres();

 private:
  double tasa_interes;
};

//Se define una clase para las cuentas de cheques

class CuentaCheques: public Cuenta //Herencia
{
 public:
  CuentaCheques(double = 0.0, double = 0.0);

  //Redefinicion de las funciones para abonar y retirar segun lo pedido
  void abonar(double);
  void cargar(double);
  
 private:
  double cuota_transaccion;
};
