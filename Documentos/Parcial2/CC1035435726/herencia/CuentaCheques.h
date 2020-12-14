#ifndef CUENTACHEQUES_H
#define CUENTACHEQUES_H
#include "Cuenta.h"

class CuentaCheques : public Cuenta //herencia
{
public:
    CuentaCheques(double = 0.0, double = 0.0);

    void setCuota(double);
    double getCuota() const;
    void abonar(double);
    void cargar(double);

private:
    double cuota;
};

#endif