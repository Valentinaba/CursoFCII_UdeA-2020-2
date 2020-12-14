#include <iostream>
#include <iomanip>
#include "fecha.h"

using namespace std;

//Constructor
Fecha::Fecha(int d,int m,int a)
{
	setFecha(d,m,a);
}

//Funcion set fecha
void Fecha::setFecha(int d,int m,int a)
{
	setAnio(a);
	setMes(m);
	setDia(d);
}

//Funcion set dia
void Fecha::setDia(int d)
{
	//meses con 31 dias
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	{
		dia = (d > 0 && d <= 31) ? d : 1;
	}
	//meses con 30 dias
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
	{
		dia = (d > 0 && d <= 30) ? d : 1;
	}
	//febrero
	else if (mes == 2)
	{
		//año bisisesto
		if ((anio%4 == 0) && ((anio%100 != 0) || (anio%400 == 0)))
		{
			dia = (d > 0 && d <= 29) ? d : 1;
		}
		//año normal
		else
		{
			dia = (d > 0 && d <= 28) ? d : 1;
		}
	}
}

//Funcion set mes
void Fecha::setMes(int m)
{
	mes = (m > 0 && m <= 12) ? m : 1; 
} 

//Funcion set año (El limite solo esta para no tomar años negativos)
void Fecha::setAnio(int a)
{
  anio = (a >= 0) ? a : 0; 
} 

//Funciones get
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

//Funcion print en formato DD/MM/AAAA
void Fecha::imprimirFecha() const
{
	cout << setfill('0') << setw(2) << dia << "/" << setw(2) << mes << "/" << setw(4) << anio;
}

//Funcion dia siguiente
void Fecha::diaSig()
{
	//cambio de mes 31 dias
	if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10) && (dia == 31))
	{
		dia = 1;
		++mes;
	}
	//cambio de mes 30 dias
	else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia == 30))
	{
		dia = 1;
		++mes;
	}
	//febrero
	else if (mes == 2)
	{
		//cambio de mes año bisisesto
		if (((anio%4 == 0) && ((anio%100 != 0) || (anio%400 == 0))) && (dia == 29))
		{
			dia = 1;
			++mes;
		}
		//cambio de mes año normal
		else if (dia == 28)
		{
			dia = 1;
			++mes;
		}
		//cambio de dia normal
		else
		{
			++dia;
		}
	}
	//cambio de año
	else if ((mes == 12) && (dia == 31))
	{
		dia = 1;
		mes = 1;
		++anio;
		cout << "¡Feliz año nuevo!\n";
	}
	//cambio de dia normal
	else
	{
		++dia;
	}
}
