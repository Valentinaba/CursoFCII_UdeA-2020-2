#include"fecha.h"

Fecha::Fecha(int d, int m, int a) //formato día, mes, año
{
  setFecha(d, m, a);
}

void Fecha::setFecha(int d, int m, int a)
{
  dia = d;
  mes = m;
  anio = a;
}

void Fecha::diaSig()
{
  dia++; //aumenta un día
  if(mes == 2) //analizamos para febrero
    { 
      if(anio % 4 == 0) //caso bisiesto
      { 
	dia = dia % 30;
      }
      else
	{
	  dia = dia % 29;
	}
  }
  else if(mes == 4 or mes == 6 or mes == 9 or mes == 11) //meses de 30 días
    {
      dia = dia % 31;
    }
  else
    {
      dia = dia % 32;  //meses de 31 días
    }

  if( dia == 0 ) //condición de cambio de mes
    {
      dia++;
      mes++;
      mes = mes % 13;
    }

  if( mes == 0 ) //condición de cambio de año
    { 
      mes++;
      anio++;
    }
}
