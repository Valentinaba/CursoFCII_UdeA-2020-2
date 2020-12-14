//Clase herencia CuentaAhorros.

#include <string> 
using namespace std;

#include "P2base.h"

class CuentaAhorros : public Cuenta
{
 public:
  CuentaAhorros(double = 0.0, double = 0.01); //Saldo	inicial, tasa de interés.

  double calcularInteres() const; //Devuelve el interés

  void setInteres(double = 0.01);
  
 private:
  double interes;
  double saldo;
  int cuenta; 
}; 
