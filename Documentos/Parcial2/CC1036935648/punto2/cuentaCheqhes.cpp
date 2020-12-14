
#include "cuentaCheques.h"
#include <iostream>

using std::cout;
using std::endl;

CuentaCheques::CuentaCheques(double saldo, double cuota) : Cuenta(saldo)
{
    if(cuota < 0)
        cout << "Error: La cuota por transacción debe ser mayor o igual a cero" << endl;
    else
        this->cuota = cuota;
}

double CuentaCheques::abonar(double to_add)
{
    if(saldo + to_add - cuota < 0)
        cout << "Error: El saldo actual es muy bajo para realizar esta transaccion." << endl;
    else if( saldo < Cuenta::abonar(to_add) ) //Verificar si se agregó dinero al saldo
        saldo -= cuota; //Cobrar la cuota por la transacción
    return saldo;
}

double CuentaCheques::cargar(double to)
{
    if( saldo - to - cuota < 0 )
        cout << "Error: El saldo actual es muy bajo para realizar esta transaccion." << endl;
    else if( saldo > Cuenta::cargar(to)) //Verificar que se realice el retiro
        saldo -= cuota;
    return saldo;
}

double CuentaCheques::getCuota()
{
    return cuota;
}
