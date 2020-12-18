#ifndef CUENTA
#define CUENTA

#include <iostream>

using namespace std;
 //Creacion de la clase base
class Cuenta
{
 public:
  Cuenta(const double);
  //definicion funciones 
  void  abonar(const double);
  void cargar(const double);
  double getSaldo(void) const;
  void setSaldo(const double);
 private:
  double saldoCuenta;
  
};

#endif 
