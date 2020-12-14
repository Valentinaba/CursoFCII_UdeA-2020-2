/**
 *  Clase para el manejo de una cuenta de cheques que es
 *  derivada de la clase Cuenta 
 */

#ifndef CUENTA_CHEQUES
#define CUENTA_CHEQUES

#include "cuenta.h"

class CuentaCheques : public Cuenta
{

public:
    
    /**
     * @param saldo  Saldo inicial
     * @param cuota  Cuota por transacción
     */
    CuentaCheques(double saldo, double cuota);

    /**
     * @brief Suma un valor al saldo
     * @return saldo actual
     */
    double abonar(double);

    /**
     * @brief Retira un valor al saldo, siempre y cuando, el saldo
     *        no quede con un valor negativo
     * @return saldo actual. 
     */
    double cargar(double);

    /**
     * Retorna la cuota por transacción actual 
     */
    double getCuota();

private:

    double cuota; //Cuota por transacción
};


#endif // CUENTA_CHEQUES