#include "fecha.h"

Fecha::Fecha(int dd, int mm, int yy)
{
  setFecha(dd,mm,yy);
}

// Funcion para establecer una fecha, sea en el constructor al crear el objeto o despues como uno de sus metodos
void Fecha::setFecha(int d, int m, int y)
{
  switch(m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: //Meses con 31 dias
      if (d>=1 && d<=31)
	{
	  mes = m;
	  dia = d;
	}

      else
	{
	  mes = 1; // Se establece enero 1 en caso de dia invalido
	  dia = 1;
	  cout << "Su dia o mes es invalido. Se establecen como enero 1 por defecto." << endl;
	}
      break;
      
    case 4: case 6: case 9: case 11:
      if (d>=1 && d<=30)
	{
	  mes = m;
	  dia = d;
	}

      else
	{
	  mes = 1; // Se establece enero 1 en caso de dia invalido
	  dia = 1;
	  cout << "Su dia o mes es invalido. Se establecen como enero 1 por defecto." << endl;
	}
      break;
      
    case 2: // 28 o 29 dias para febrero segun si es anio bisiesto
      if (((y%4)==0 && (y%100)!=0) or (y%400)==0)
	{
	  bisiesto = true;
	  if (d>=1 && d<=29)
	    {
	      mes = m;
	      dia = d;
	    }

	  else
	    {
	      mes = 1; // Se establece enero 1 en caso de dia invalido
	      dia = 1;
	      cout << "Su dia o mes es invalido. Se establecen como enero 1 por defecto." << endl;
	    }
	}
      
      else
	{
	  if (d>=1 && d<=28)
	    {
	      mes = m;
	      dia = d;
	    }

	  else
	    {
	      mes = 1; // Se establece enero 1 en caso de dia invalido
	      dia = 1;
	      cout << "Su dia o mes es invalido. Se establecen como enero 1 por defecto." << endl;
	    }
	}
      break;
      
    default: // 1 de enero por defecto
      mes = 1;
      dia = 1;
      cout << "Su dia o mes es invalido. Se establecen como enero 1 por defecto." << endl;
    }

  if (y>=1) // Solo se aceptan años mayores que 0
    {
      anio = y;
    }
  
  else
    {
      anio = 2000;
      cout << "Su anio es invalido. Se establece como el anio 2000 por defecto." << endl;
    } 

  //En caso de entradas invalidas, el dia por defecto es 1, el mes es enero y el año es el 2000, segun el caso. Es decir, si el mes o el dia es invalido pero el año es valido, se deja el año ingresado y se guarda el dia y mes como enero 1
}

// Imprime la fecha en el formato dd/mm/aaaa
void Fecha::imprimir() const
{
  cout << dia << '/' << mes << '/' << anio << endl;
}

// Aumenta en un dia la fecha establecida, teniendo en cuenta todos los casos
void Fecha::diaSig()
{
switch(mes)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: // Meses con 31 dias, excepto diciembre
      if (dia == 31)
	{
	  mes++;
	  dia = 1;
	}
      else
	{
	  dia++;
	}
      break;
      
    case 12: // Se tiene en cuenta el caso 31 de diciembre
      if (dia == 31)
	{
	  anio++;
	  mes = 1;
	  dia = 1;
	}
      else
	{
	  dia++;
	}
      break;
	
    case 4: case 6: case 9: case 11: // Meses con 30 dias
      if (dia == 30)
	{
	  mes++;
	  dia = 1;
	}
      else
	{
	  dia++;
	}
      break;
      
    case 2: // Identifica si es el ultimo dia de febrero para pasar a marzo 1, segun si el año es bisiesto
      if (bisiesto)
	{
	  if (dia == 29)
	    {
	      mes++;
	      dia = 1;
	    }

	  else
	    {
	      dia++;
	    }
	}
      
      else
	{
	  if (dia == 28)
	    {
	      mes++;
	      dia = 1;
	    }

	  else
	    {
	      dia++;
	    }
	}
      break;
      
    default:
      break;
    }
}

