/**
 * @author Valentina Roquemen Echeverry
 * @brief  Clase base de la cuenta bancaria, permite ingresar
 *         y retirar dinero.
 */
#ifndef CUENTABASE_H
#define CUENTABASE_H

class CuentaBancaria
{
public:

  /**
   * @param saldo_inicial : Saldo inicial
   */
  CuentaBancaria(double saldoInicial);

  /**
   * @brief Estable el saldo inicial de la cuenta
   * @param saldo_inicial : Saldo inicial
   */
  void setSaldoInicial( double saldoInicial ); 

  /**
   * @brief Agrega un abono la cuenta
   * @param abono : abono
   * @return true si el abono se pudo efectuar
   */
  bool abonar( double abono ); 

  /**
   * @brief Carga un retiro a la cuenta
   * @param retiro : retiro
   * @return true si el retiro se pudo efectuar
   */  
  bool cargar( double retiro ); 
  
  /**
   * @brief Devuelve el saldo en la cuenta
   * @return saldo
   */
  double getSaldo() const;

//private:
  double saldo; 
};
#endif // CUENTABASE_H