#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include "Cuenta.h"

class CuentaAhorros : public Cuenta {
public:
    CuentaAhorros(double = 0.0, double = 0.0);
    void setTasaI(double);
    double getTasaI() const;
    double calcularInteres() const; //const porque no modifica ningun atributo

private:
    double tasa_i;
};

#endif