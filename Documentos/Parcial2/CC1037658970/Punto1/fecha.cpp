#include <iostream> 
#include "fecha.h"
using namespace std;

Fecha::Fecha(int m, int d, int y )
{
  setParameters(m, d, y); // Establece los parametros
  fechaValida(); // Valida la fecha

  if (not validez) { cout<<"Su fecha no existe"<<endl; }
}

void Fecha::setParameters( int m, int d, int y )
{
  mes = m;
  dia = d;
  anio = y;
}

void Fecha::fechaValida()
{
  /*Revisa si el anio es menor a 0 o si el dia 0 el mes no son validos*/
  if ( (anio<=0) || not diaValido() ){  validez = false; }
  else validez=true;
}

bool Fecha::diaValido()
{
  switch (mes)
  {
    /*Meses con 31 dias*/
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      if(dia>=1 and dia<=31) return true;
      else return false;
      break;
    
    /*Meses con 30 dias*/
    case 4: case 6: case 9: case 11:
      if(dia>=1 and dia<=30) return true;
      else return false;
      break;

    /*Febrero puede tener 28 o 29 dias dependiendo si es bisiesto*/
    case 2:

      bisiesto = anioBisiesto();
      if ( bisiesto and  (dia>=1 and dia<=29)) return true;
      else if ( not bisiesto and  (dia>=1 and dia<=28)) return true;
      else return false;      
      break;

    // En este caso no se ingreso un mes valido
    default:
      return false;
      break;
  }
}

bool Fecha::anioBisiesto()
{
  if (anio%4==0) // Es bisiesto si es divisible por 4
  {
    if (anio%100==0) // Pero no es bisiesto si es divisible por 100
    {
      if (anio%400==0)  return true; // Pero si es bisiesto si es divisible por 400
      else return false;
    }
    else return true;
  }
  else return false;
}

void Fecha::diaSig()
{ 
  if (validez)
  {
    dia += 1;
    fechaValida(); // Revisa si aumentando un dia la fecha es valida

    if (not validez)
    {
      if (mes!=12)
      {
        mes +=1;
        dia = 1;  
          fechaValida(); // Revisa si aumentando un mes la fecha es valida
        }
        else
        {
          mes =1;
          dia = 1;
          anio += 1;  
          fechaValida(); // Revisa si cambiand el anio la fecha es valida 
        }
      } 
    }
    else cout<<"Recuerde que su fecha no existe, entonces no puede haber dia siguiente"<<endl;
}

void Fecha::imprimir() const
{
  if (validez)
  {
    cout << mes << '/' << dia << '/' << anio<<endl;
  }
}