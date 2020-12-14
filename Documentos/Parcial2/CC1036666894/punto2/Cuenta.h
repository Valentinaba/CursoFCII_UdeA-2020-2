#ifndef CUENTA_H
#define CUENTA_h

// clase padre
class Cuenta
{
  // funciones de la clase padre
 public:
  Cuenta(double);
  
  bool abonarSaldo(double);
  bool cargarSaldo(double);
  void setSaldo(double);
  double getSaldo();
  
  // dato miembro
 private:
  double saldoCuenta;
  
};

#endif
