/**
 * @author Valentina Roquemen Echeverry
 * @brief  Clase derivada de CuentaBase. Es una cuenta de ahorros
 *         es decir que tiene un metodo que calcula intereses.
 */
#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H

#include "CuentaBase.h"

class CuentaAhorros : public CuentaBancaria
{

public:

  /**
   * @param saldo_inicial : Saldo inicial
   * @param tasaInteres : Tasa de interes porcentual 
   */
  CuentaAhorros( double, double );
  
  /**
   * @brief Calcula el interes acumulado por el saldo
   *        que se tiene en el banco. 
   */
  double calculoInteres();
  
private:
  double tasaInteres; //Tasa de interes porcentual 

}; 
#endif // CUENTAAHORROS_H
