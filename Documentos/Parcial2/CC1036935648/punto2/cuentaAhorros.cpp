
#include "cuentaAhorros.h"
#include <iostream>

using std::cout;
using std::endl;

CuentaAhorros::CuentaAhorros(double saldo, double interes) : Cuenta(saldo)
{
    setInteres(interes);
}

double CuentaAhorros::calcularInteres()
{
    return saldo * interes;
}

void CuentaAhorros::setInteres(double interes)
{
    if(interes < 0)
        cout << "Error: La tasa de interes debe ser mayor o igual a cero" << endl;
    else
        this->interes = interes;
}