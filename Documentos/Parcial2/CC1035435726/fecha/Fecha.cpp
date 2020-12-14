#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int dd, int mm, int aa)
{
    setAnio(aa);

    if (mm > 0 && mm <= 12) // valida el mes
        setMes(mm);
    else {
        setMes(1); // mes inválido se establece en 1
        cout << "Mes invalido (" << mm << ") se establecio en 1.\n";
    }
    
    if (dd > 0 && dd <= diaMes(mes, anio))
        setDia(dd);
    else {
        setDia(1);
        cout << "Dia invalido (" << dd << ") se establecio en 1.\n";
    }
}

void Fecha::setDia(int dd)
{
    dia = dd;
}

void Fecha::setMes(int mm)
{
    mes = mm;
}

void Fecha::setAnio(int aa)
{
    anio = aa;
}

int Fecha::getDia() const
{
    return dia;
}

int Fecha::getMes() const
{
    return mes;
}

int Fecha::getAnio() const
{
    return anio;
}

void Fecha::imprimir() const
{
    cout << dia << '/' << mes << '/' << anio;
}

// imprime objeto Fecha para mostrar cuándo se llama a su destructor
Fecha::~Fecha()
{
    cout << "Destructor del objeto Fecha para fecha ";
    imprimir();
    cout << endl;
}

void Fecha::diaSig()
{
    int diaS = getDia() + 1;
    int mesS = getMes();
    int anioS = getAnio();
    //se valida si el dia siguiente excede el numero de dias por es
    if (diaS > diaMes(mesS, anioS)) {
        //si es ai, se pasa al siguiente mes
        diaS = 1;
        mesS += 1;
        //se hace lo mismo para el mes
        if (mesS > 12) {
            mesS = 1;
            anioS += 1;
        }
    }
    setDia(diaS);
    setMes(mesS);
    setAnio(anioS);
};

// función utilitaria para retornar el numero de dias por mes y annio
int Fecha::diaMes(int mes, int anio) const
{
    static const int diasPorMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //cuando es un annio bisiesto, entonces febrero tiene un dia de mas
    int diaAdd = 0;
    if (mes == 2 && (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0)))
        diaAdd = 1;
    return diasPorMes[mes - 1] + diaAdd;
}

