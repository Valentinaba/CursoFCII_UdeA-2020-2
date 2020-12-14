#include "CuentaAhorros.h"
#include <iostream>
using namespace std;

CuentaAhorros::CuentaAhorros(double saldo_ini, double t_i)
    : Cuenta(saldo_ini)
{//no tiene sentido que una cuenta de "ahorros" tenga una tasa negativa, porque entonces no se ganaria dinero
    if(t_i>=0)
    	setTasaI(t_i);
    else
    {
    	cout << "La tasa de interes no es correcta, se tomara como 0.0";
    	setTasaI(0.0);
    }
}

void CuentaAhorros::setTasaI(double t_i)
{
    tasa_i = t_i;
}

double CuentaAhorros::getTasaI() const
{
    return tasa_i;
}

double CuentaAhorros::calcularInteres() const
{
    return getSaldo() * getTasaI();
}

