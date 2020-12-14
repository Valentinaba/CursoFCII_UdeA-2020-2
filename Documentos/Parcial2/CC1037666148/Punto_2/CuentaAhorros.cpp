#include "CuentaAhorros.h"

CuentaAhorros :: CuentaAhorros(const double init_saldo, const double Interes)
  : Cuenta(init_saldo) //Inicializa el constructor de la clase Cuenta
{
  Set_tasa(Interes);
}

//Verfica que la tasa de interés este en los valores adecuados (0,100)
void CuentaAhorros :: Set_tasa(const double interes) 
{
  tasa_interes = ( interes >= 0.0 && interes <=100.0 ) ?  interes: 3.0; 
}

//Calcula la cantidad de dinero debida al interés
double CuentaAhorros :: calcularInteres(void) 
{ 
  return getSaldo()*tasa_interes/100.0;
}
