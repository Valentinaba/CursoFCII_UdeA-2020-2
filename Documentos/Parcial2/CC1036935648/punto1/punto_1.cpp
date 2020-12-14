
#include <iostream>
#include "fecha.h"

using namespace std;


int main()
{
    Fecha date;

    cout << "Test de años bisiestos:" << endl;
    cout << "2000:" << (Fecha::isLeapYear(2000) ? "bisiesto" : "regular") << endl; // bisiesto
    cout << "2400:" << (Fecha::isLeapYear(2400) ? "bisiesto" : "regular") << endl; // bisiesto
    cout << "1900:" << (Fecha::isLeapYear(1900) ? "bisiesto" : "regular") << endl; // regular
    cout << "2100:" << (Fecha::isLeapYear(2100) ? "bisiesto" : "regular") << endl; // regular

    cout << endl << "validación de fechas" << endl;
    cout << "29/02/2020:" << (Fecha::validateDate(29,2, 2020) ? "valida" : "invalida") << endl; // bisiesto
    cout << "29/02/2021:" << (Fecha::validateDate(29,2, 2021) ? "valida" : "invalida") << endl; // regular

    cout << endl << "Test de aumento de días:" << endl;

    cout << "desde el 28/02/2020 (bisiesto)" << endl;
    date.setDate(28,02,2020);
    date.diaSig();
    date.print();
    date.diaSig();
    date.print();

    cout << "desde el 27/02/2021 (regular)" << endl;
    date.setDate(27,02,2021);
    date.diaSig();
    date.print();
    date.diaSig();
    date.print();

    cout << "desde el 30/12/2020" << endl;
    date.setDate(30,12,2020);
    date.diaSig();
    date.print();
    date.diaSig();
    date.print();

    return 0;
}