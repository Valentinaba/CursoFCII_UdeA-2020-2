#include "Cuenta.h"
#include <iostream>

using namespace std;

Cuenta::Cuenta(double saldo_ini)
{
    if (saldo_ini >= 0) {
        setSaldo(saldo_ini);
    }
    else {
        cout << "Saldo inicial es invalido, se tomara como 0.0" << endl;
        setSaldo(0.0);
    }
}

void Cuenta::setSaldo(double s)
{
    saldo = s;
}

double Cuenta::getSaldo() const
{
    return saldo;
}

void Cuenta::abonar(double s)
{
    setSaldo(getSaldo() + s);
}

bool Cuenta::cargar(double s)
{
    if (s > getSaldo()) {
        cout << "El monto a cargar excedio el saldo de la cuenta" << endl;
        return false;
    }
    else {
        abonar(-s);
        return true;
    }
}

Cuenta::~Cuenta()
{
    cout << "Destructor de la cuenta con saldo: " << getSaldo() << endl;
}
