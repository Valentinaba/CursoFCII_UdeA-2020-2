#include <iostream>

using namespace std;

#include "Fecha.h"

int main()
{
    //valor invalido
    Fecha fecha1(34, 13, 2004);
    cout << "Fecha inicial: ";
    fecha1.imprimir();
    fecha1.diaSig();
    cout << endl;
    cout << "Dia siguiente: ";
    fecha1.imprimir();
    cout << endl;
    cout << endl;

    //fecha normal, solo cambia de dia
    Fecha fecha2(10, 3, 2017);
    cout << "Fecha inicial: ";
    fecha2.imprimir();
    fecha2.diaSig();
    cout << endl;
    cout << "Dia siguiente: ";
    fecha2.imprimir();
    cout << endl;
    cout << endl;

    //fecha en annio bisiesto y cambia de mes
    Fecha fecha3(28, 2, 2020);
    cout << "Fecha inicial: ";
    fecha3.imprimir();
    cout << endl;
    cout << "Dia siguiente: ";
    fecha3.diaSig();
    fecha3.imprimir();
    cout << endl;
    cout << "Dia siguiente: ";
    fecha3.diaSig();
    fecha3.imprimir();
    cout << endl;
    cout << endl;

    //fecha para cambiar de annio
    Fecha fecha4(31, 12, 2020);
    cout << "Fecha inicial: ";
    fecha4.imprimir();
    cout << endl;
    cout << "Dia siguiente: ";
    fecha4.diaSig();
    fecha4.imprimir();
    cout << endl;
    cout << endl;

    return 0;
}
