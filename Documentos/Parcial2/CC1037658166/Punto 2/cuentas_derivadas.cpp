#include "cuentas_derivadas.h"

//~~~~~ Metodos de la clase derivada: CuentaAhorros ~~~~~~//

CuentaAhorros::CuentaAhorros(double saldo_inicial, double tasa)
    
    : Cuenta(saldo_inicial), TasaInteres(tasa) , Interes(0)
{}

void CuentaAhorros::CalcularIntereses()
{
    if (numeroAbonos >= 1)
    {
    Interes += saldo*TasaInteres;
    numeroAbonos = 0;
    }
    else
    {
        cout << "No ha habido abonos de modo que no hay aumento de tasa de Interes" << endl;
    }
}

double CuentaAhorros::GetInteres()
{
    return Interes;
}

//~~~~~ Metodos de la clase derivada: CuentaCheque ~~~~~~//

CuentaCheque::CuentaCheque(double saldo_inicial, double cuota)
    
    : Cuenta(saldo_inicial), CuotaRetiro(cuota)
{}

void CuentaCheque::Retirar(double retiro)
{

    if (retiro <= saldo + CuotaRetiro)
    {
        Cuenta::Retirar(retiro + CuotaRetiro);
    }
    else
    {
        cout << "No hay saldo suficiente para cubrir el retiro y la cuota" << endl;
    }
}














