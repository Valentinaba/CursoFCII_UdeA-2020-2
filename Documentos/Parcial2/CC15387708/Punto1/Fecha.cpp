// Implementación de la clase

#include "Fecha.h"

Fecha::Fecha( int d, int m, int a )
{
  dia = d;
  mes = m;
  anio = a;

  //Condiciones para dirigir a la fecha predeterminada si la fecha de entrada tiene datos no validos
  if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
      if ( dia >= 1 && dia <= 31 )
	{
	  mes = m;
	  dia = d;
	}
      
      else
	{
	  mes = 1;
	  dia = 1;
	}
    }
  
  if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
      if ( dia >= 1 && dia <= 30)
	{
	  mes = m;
	  dia = d;
	}
      
      else
	{
	  mes = 1;
	  dia = 1;
	}
    }

  if ((mes <= 0 || mes > 12) || (dia <= 0 || dia > 31))
    {
      mes = 1;
      dia = 1;
    }
}

void Fecha::mostrarFecha() const
{
  // Se muestra la fecha particular del código principal o la fecha predeterminada
  cout << " \nSe tiene la fecha en formato DD/MM/AAAA: ";
  cout << setfill('0')
       << setw(2) << dia << '/'
       << setw(2) << mes << '/'
       << setw(2) << anio;
  cout << endl;

  return;
}

void Fecha::diaSig()
{

  if (dia > 0 && dia < 28) // Iniciando con los dias entre 1 y 27
    dia += 1;

  // Evaluando la fecha para febrero según el anio
  if (dia == 28)
    {
      if (mes == 2)
	{
	  if (((anio % 4) == 0 && (anio % 100) != 0) || (anio % 400) == 0)
	    {
	      dia = 29;
	    }

	  else
	    {
	      dia = 1;
	      mes = 3;
	    }
	}

      else
	dia += 1;
    }

  if (dia == 29)
    {
      if (mes == 2)
	{
	  dia = 1;
	  mes = 3;
	}

      else
	dia += 1;
    }

  // Evaluando la fecha en meses de 30 y 31 días
  if (dia == 30)
    {
      if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	dia += 1;

      else
	{
	  dia = 1;
	  mes += 1;
	}
    }

  // Para considerar último día del mes y últmo mes del año
  if (dia == 31)
    {
      dia = 1;
      if (mes == 12)
	{
	  anio += 1;
	  mes = 1;
	}

      else
	mes += 1;
    }	  

  // Se imprime la fecha siguiente en el formato especificado
  cout << "Con el formato correcto, la fecha del día siguiente será: ";
  cout << setfill('0')
       << setw(2) << dia << '/'
       << setw(2) << mes << '/'
       << setw(2) << anio;
  cout << endl;
}
