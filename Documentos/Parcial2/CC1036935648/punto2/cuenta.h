

#ifndef CUENTA_H
#define CUENTA_H


class Cuenta
{
public:

    /**
     * Recibe el saldo inicial
     */
    Cuenta(double saldo=0);

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
     * Retorna el saldo actual
     */
    double getSaldo();

protected:
    double saldo;

};

#endif // CUENTA_H
