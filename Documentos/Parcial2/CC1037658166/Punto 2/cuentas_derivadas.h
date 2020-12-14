#include "cuenta_bancaria.h"

//~~~~~ Clase derivada CuentaAhorros ~~~~~//

class CuentaAhorros : public Cuenta
{
public:
    CuentaAhorros(double,double);
    void CalcularIntereses();
    double GetInteres();
    
private:
    const double TasaInteres;
    double Interes;
};

//~~~~~ Clase derivada CuentaCheque ~~~~~//

class CuentaCheque : public Cuenta
{
public:
    CuentaCheque(double,double);
    void Retirar(double);
    
private:
    const double CuotaRetiro;

};




