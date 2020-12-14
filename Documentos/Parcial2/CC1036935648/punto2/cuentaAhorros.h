/**
 *  Clase para el manejo de una cuenta de ahorros que es
 *  derivada de la clase Cuenta 
 */

#ifndef CUENTA_AHORROS
#define CUENTA_AHORROS

#include "cuenta.h"

class CuentaAhorros : public Cuenta
{
public:

    /**
     * @param saldo  Saldo inicial
     * @param interes Tasa de interes inicial
     */
    CuentaAhorros(double saldo, double interes);

    /**
     * Retorna el interes sobre el saldo actual
     */
    double calcularInteres();

    /**
     * Modifica la tasa de interes actual
     */
    void setInteres(double);

private:

    double interes; //tasa de interés

};

#endif //CUENTA_AHORROS