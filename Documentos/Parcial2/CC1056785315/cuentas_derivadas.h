#include "cuenta_base.h"

//Clases derivadas que representan cuentas de ahorro y cuentas de cheques

class CuentaAhorros : public Cuenta
{
 public:
  CuentaAhorros(double = 0.0, double = 0.0); //Constructor predeterminado
  double calcularInteres() const;

 private:
  double interes;
};

class CuentaCheques : public Cuenta
{
 public:
  CuentaCheques(double = 0.0, double = 0.0);
  
  void abonar(double); //Se redefinen estas 2 funciones de la clase base
  void cargar(double);
  
 private:
  double cuota;
};
