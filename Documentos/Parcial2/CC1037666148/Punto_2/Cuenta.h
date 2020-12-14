#ifndef CUENTA
#define CUENTA

#include <iostream>

using namespace std;

class Cuenta
{
 public:
  Cuenta(const double);
  //~Cuenta();
  void Set_saldo(const double);
  void  abonar(const double);
  void cargar(const double);
  double getSaldo(void) const;
 private:
  double Saldo_cuenta;
  
};

#endif
