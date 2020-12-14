#include <iostream>
using namespace std;


#include "CuentaAhorros.h"

// constructor
CuentaAhorros::CuentaAhorros( double saldo, double interes )
  // llama explícitamente al constructor de la clase base
  : Cuenta( saldo )
{
  Interes = ( interes > 0.0 && interes < 1.0 ) ? interes : 0.0; // valida y almacena el valor del interés
 
}

double CuentaAhorros::calcularInteres() const
{
   return Interes*Cuenta::getSaldo();//Se llama a un atributo de la clase base para usarse en la clase herencia, pues no es posible acceder a las varibales privadas
}

