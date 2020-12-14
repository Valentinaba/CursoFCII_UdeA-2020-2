/**
 * @author Valentina Roquemen Echeverry
 * @brief  Clase derivada de CuentaBase. Es una cuenta tipo cheque
 *         es decir que genera cobro al realizar transacciones.
 */
#ifndef CUENTACHEQUE_H
#define CUENTACHEQUE_H

#include "CuentaBase.h"

class CuentaCheques : public CuentaBancaria
{

public:

  /**
   * @param saldo_inicial : Saldo inicial
   * @param costoTransaccion : Costo de la transaccion 
   */
  CuentaCheques( double, double );

  /**
   * @brief Agrega un abono la cuenta realizando el cobro de la transaccion
   * @param abono : abono
   */
  void abonar( double abono ); 
  
  /**
   * @brief Carga un retiro a la cuenta realizando el cobro de la transaccion
   * @param retiro : retiro
   */
  void cargar( double retiro ); 
  
private:
  double costoTransaccion; // Costo de la trnasaccion

}; 
#endif // CUENTACHEQUE_H
