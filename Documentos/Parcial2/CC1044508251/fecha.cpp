#include <iostream>
using namespace std;

#include "fecha.h"

Fecha::Fecha( int d, int m, int y )
{
  mes = m;
  dia = d;
  anno = y;

  checkFecha();
}

void Fecha::checkFecha()
{

  Bisiesto();
  
  while(anno<=0)
    {
      cout << "Anio indeterminado, hagalo nuevamente: " << endl;
      cin >> anno;
    }
  
  while(mes>12 || mes<=0)
    {
      cout << "Mes indeterminado, hagalo nuevamente: " << endl;
      cin >> mes;
    }

  while((dia>31 || dia<=0) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
    {
      cout << "Dia indeterminado, hagalo nuevamente: " << endl;
      cin >> dia;
    }

  while((dia>30 || dia<=0) && (mes == 4 || mes == 6 || mes == 9 || mes == 11 ))
    {
      cout << "Dia indeterminado, hagalo nuevamente: " << endl;
      cin >> dia;
    }

  while(bis == 1 && dia > 29 && mes == 2)
    {
      cout << "Dia indeterminado, hagalo nuevamente: " << endl;
      cin >> dia;
    }
  
  while(bis == 0 && dia > 28 && mes == 2)
    {
      cout << "Dia indeterminado, hagalo nuevamente: " << endl;
      cin >> dia;
    }

  cout << dia << endl;;
}

void Fecha::imprimir()
{
  cout << dia << '/' << mes << '/' << anno;
}

int Fecha::Bisiesto()
{
  if((anno%4==0 && anno%100!=0) || anno%400==0) 
    {
      bis = 1;
    }
  else
    {
      bis = 0;
    }
}


void Fecha::imprimirBisiesto()
{
  if(bis==1) 
    {
      cout << "es bisiesto";
    }
  else
    {
      cout << "no es bisiesto";
    }
}

void Fecha::diaSig()
{  
  dia = dia + 1;

  Bisiesto();
  
  if(dia == 32 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10))
    {
      dia = 1;
      mes = mes + 1;
    }

  if(dia == 32 && mes == 12)
    {
      dia = 1;
      mes = 1;
      anno = anno + 1;
    }

  if(dia == 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11 ))
    {
      dia = 1;
      mes = mes + 1;
    }

  if(bis == 1 && dia == 30 && mes == 2)
    {
      dia = 1;
      mes = mes + 1;
    }
  else if(bis == 0 && dia == 29 && mes == 2)
    {
      dia = 1;
      mes = mes + 1;
    }
  
  cout << dia << '/' << mes << '/' << anno;
}
