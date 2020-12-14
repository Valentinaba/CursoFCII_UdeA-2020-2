#ifndef CUENTA_H
#define CUENTA_H

// Se define una clase base para las cuentas bancarias
class Cuenta
{
 public:
  Cuenta(double = 0.0); //Constructor

// Funciones para abonar o retirar dinero de la cuenta
  bool abonar(double);
  bool cargar(double);
  double getSaldo() const;

 private:
  double saldo_cuenta;
};

#endif
