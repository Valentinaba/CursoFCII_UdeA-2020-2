#include "cuenta_bancaria.h"

//~~~~~ Metodos de la clase base: Cuenta ~~~~~~//

// Constructor 
Cuenta::Cuenta(double saldo_inicial)
{

    if (saldo >= 0)
    {
        saldo = saldo_inicial;
    }
    else
    {
        saldo  = 0; 
        cout << "El saldo ingresado no es valido, se ha establecido su saldo inicial en 0 por esta razón" << endl;
    }
    
    numeroAbonos = 0;
}

void Cuenta::Abonar(double abono)
{
    if (abono > 0)
    {
    cout << "Se ha abonado: " << abono << endl;
    saldo += abono;
    }
    else
    {
        cout << "El abono que se ha ingresado no tiene sentido" << endl;
    }
    
    numeroAbonos += 1;
}

void Cuenta::Retirar(double retiro)
{
    if (retiro > saldo)
    {
        cout << "No se puede retirar mas que " << saldo << "en este momento" << endl;
    }
    else
    {
        cout << "Se ha retirado: " << retiro << endl;
        saldo -= retiro;
    }
    
}

double Cuenta::GetSaldo()
{
    return saldo;
}





