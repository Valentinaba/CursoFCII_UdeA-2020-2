#include "cuenta.h"
#include <iostream>

using std::cout;
using std::endl;

Cuenta::Cuenta(double saldo)
{
    if(saldo < 0)
    {
        cout << "Error: El saldo debe ser mayor o igual a cero." << endl;
        cout << "Saldo actual: 0" << endl;
        this->saldo = 0;
    }
    else
        this->saldo = saldo; 
}

double Cuenta::abonar(double toAdd)
{
    if(toAdd < 0)
        cout << "Error: El saldo a abonar debe ser mayor a cero" << endl;
    else
        saldo += toAdd;
    return saldo;        
}

double Cuenta::cargar(double to)
{
    if((to >= 0) && (saldo - to) >= 0)
        saldo -= to;
    else if(saldo - to < 0)
        cout << "Error: El monto a cargar excedio el saldo de la cuenta." << endl;
    else
        cout << "Error: valor invalido" << endl; 
    return saldo;
}

double Cuenta::getSaldo()
{
    return saldo;
}
