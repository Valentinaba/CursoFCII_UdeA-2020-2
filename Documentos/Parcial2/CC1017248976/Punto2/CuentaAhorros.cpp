#include "CuentaAhorros.h"

CuentaAhorros :: CuentaAhorros(const double saldoInicial, const double interes)
  : Cuenta(saldoInicial) //Inicializa el constructor de la clase Cuenta
{
  fijarTasa(interes);//inicializa el valor del interes
}

//
void CuentaAhorros :: fijarTasa(const double interes) 
{
  tasaInteres = ( interes >= 0.0 && interes <=100.0 ) ?  interes: 3.0; //Verfica que la tasa de interés este en los valores adecuados (0,100)
}

//Calcula el dinero generado por al interés
double CuentaAhorros :: calcularInteres(void) 
{ 
  return getSaldo()*tasaInteres/100.0;
} 
