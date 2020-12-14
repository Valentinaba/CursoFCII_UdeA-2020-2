#include "Cuenta.h"
#include "CuentaAhorros.h"
#include "CuentaCheques.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//funcion para ahorrar lineas en imprimir
void imprimirSaldo(double saldo)
{
    cout << setprecision(2) << saldo;
}
int main()
{
    //prueba clase Cuenta
    cout << fixed;
    cout << "---------------------------------" << endl;
    cout << "Prueba clase Cuenta" << endl;
    cout << "---------------------------------" << endl;
    //valor invalido en la inicializacion
    cout << "Se inicializa con -10.0:" << endl;
    Cuenta cu(-10.0);
    cout << endl;
    
    cout << "Se abona 100.0: " << endl;
    cout << "Saldo antes: ";
    imprimirSaldo(cu.getSaldo());
    cu.abonar(100.0);
    cout << " | Saldo despues: ";
    imprimirSaldo(cu.getSaldo());
    cout << endl << endl;

    //valor invalido
    cout << "Se carga 1000.0: " << endl;
    cu.cargar(1000.0);
    
    cout << endl;
    
    cout << "Se carga 50.0" << endl;
    cout << "Saldo antes: ";
    imprimirSaldo(cu.getSaldo());
    cu.cargar(50.0);
    cout << " | Saldo despues: ";
    imprimirSaldo(cu.getSaldo());
    
    cout << endl;

    cout << "---------------------------------" << endl;
    cout << "Prueba clase CuentaAhorros" << endl;
    cout << "---------------------------------" << endl;
    cout << "Saldo inicial = 100.20, t.i. = 0.05" << endl;
    CuentaAhorros ca(100.2, 0.05);
    cout << endl;
    
    cout << "Se agrega el interes" << endl;
    cout << "Saldo antes: ";
    imprimirSaldo(ca.getSaldo());
    //uso del interes
    ca.abonar(ca.calcularInteres());
    cout << " | Saldo despues: ";
    imprimirSaldo(ca.getSaldo());

    cout << endl;
    CuentaCheques cc(100.2, 50.0);
    
    cout << "---------------------------------" << endl;
    cout << "Prueba clase CuentaCheques" << endl;
    cout << "---------------------------------" << endl;
    cout << "Saldo inicial = 100.20, cuota = 50.0" << endl << endl;
    
    cout << "Se abona 100.0: " << endl;
    cout << "Saldo antes: ";
    imprimirSaldo(cc.getSaldo());
    cc.abonar(100.0);
    cout << " | Saldo despues: ";
    imprimirSaldo(cc.getSaldo());
    cout << endl << endl;
    
    //valor invalido
    cout << "Se carga 150.20" << endl;
    cc.cargar(150.20);
    
    //valor valido
    cout << endl << endl;
    cout << "Se carga 50.0" << endl;
    cout << "Saldo antes: ";
    imprimirSaldo(cc.getSaldo());
    cc.cargar(50.0);
    cout << " | Saldo despues: ";
    imprimirSaldo(cc.getSaldo());
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "Destructores" << endl;
    cout << "---------------------------------" << endl;
    return 0;
}
