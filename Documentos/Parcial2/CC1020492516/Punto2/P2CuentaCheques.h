//Clase derivada de Cuenta, cuenta cheques

//Clase herencia CuentaAhorros.

#include <string> 
using namespace std;

#include "P2CuentaAhorros.h"
//#include "P2base.h"

class CuentaCheques : public Cuenta
{
 public:
  CuentaCheques(double = 0.0, double = 10.0); //Cuenta, Saldo inicial, Cuota

  double Abonar( double = 0.0 );
  bool Cargar( double = 0.0 ); //Default 0
  void setCuota(double = 1.0 );
  
  
 private:
  double cuota;
  double saldo;
  int cuenta; 
};
