#include "CuentaCheques.h"
#include <iostream>
using namespace std;

CuentaCheques::CuentaCheques(double saldo_ini, double cuota)
    : Cuenta(saldo_ini)
{
    if(cuota>=0.0)
    	setCuota(cuota);
    else
    {
    	cout << "La cuota no es correcta, se tomara como 0.0";
    	setCuota(0.0);
    }
}

void CuentaCheques::setCuota(double c)
{
    cuota = c;
}

double CuentaCheques::getCuota() const
{
    return cuota;
}

void CuentaCheques::abonar(double s)
{
    //se llama a la funcion de Cuenta
    Cuenta::abonar(s - getCuota());
}

void CuentaCheques::cargar(double s)
{
    bool cobrar = Cuenta::cargar(s + cuota);
    //retrocede la transaccion si no es valida
    if (cobrar == false)
    	cout << "No se cobrara cuota";
}
