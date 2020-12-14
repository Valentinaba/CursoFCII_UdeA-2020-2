#include <iostream>
#include <iomanip>
#include "cuenta.h"
#include "cuentaAhorros.h"
#include "cuentaCheques.h"

using namespace std;


int main()
{
    cout << "===================================" << endl;
    cout << "             Test Cuenta           " << endl;
    cout << "===================================" << endl;

    Cuenta *cuenta = new Cuenta(-1); //valor invalido

    cout << "===================================" << endl;
    cout << "         Test CuentaAhorros        " << endl;
    cout << "===================================" << endl;

    CuentaAhorros ahorros(10, 0.02);
    cout << "saldo actual: " << ahorros.getSaldo() << endl;
    cout << "Calculo del interes: " << ahorros.calcularInteres()<<  endl;
    cout << "Saldo + intereses: " << ahorros.abonar(ahorros.calcularInteres()) << endl;
    ahorros.cargar(ahorros.getSaldo()+1); //valor invalido
    cout << "saldo-retiro: " << ahorros.cargar(ahorros.getSaldo()/2) << endl;


    cout << "===================================" << endl;
    cout << "             Test cheque           " << endl;
    cout << "===================================" << endl;

    CuentaCheques cheques(10,2);
    cout << "saldo actual: " << cheques.getSaldo() << endl;
    cout << "Cuota actual: " << cheques.getCuota()<<  endl;
    cout << "Saldo + abono - cuota: " << cheques.abonar(1) << endl;
    cheques.cargar(cheques.getSaldo()); //valor invalido
    cout << "saldo actual: " << cheques.getSaldo() << endl;
    cout << "saldo-retiro-cuota: " << cheques.cargar(1) << endl;
}