#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "fecha.h"

Fecha::Fecha( const int m,const int d, const int y )
{
  Set_fecha(m,d,y);
}
void Fecha::Set_fecha(const int  m, const int d, const int an)
{
  Set_mes(m);
  Set_anio(an);
  Set_dia(d);
  
}

void Fecha::Set_mes(const int m)
{
  mes = ( m >= 1 && m < 12 ) ? m : 1;
}

void Fecha::Set_anio(const int an)
{
  anio = ( an >= 0) ? an : 0;
}

void Fecha::Set_dia(const int d)
{ //Se verifica que el día no se pasa del máximo de días del mes
  switch(mes)
    {
    case 1:
      dia = (d>=1 && d <=31)? d:31;
      break;
    case 2:
      if (anio%4==0) //Se mira si el año es bisiesto 
	dia = (d>=1 && d <=29)? d:29;
      else
	dia = (d>=1 && d <=28)? d:28;
      break;
   case 3:
      dia = (d>=1 && d <=31)? d:31;
      break;
   case 4:
      dia = (d>=1 && d <=30)? d:30;
      break;
   case 5:
      dia = (d>=1 && d <=31)? d:31;
      break;
   case 6:
      dia = (d>=1 && d <=30)? d:30;
      break;
    case 7:
      dia = (d>=1 && d <=31)? d:31;
      break;
    case 8:
      dia = (d>=1 && d <=31)? d:31;
      break;
    case 9:
      dia = (d>=1 && d <=30)? d:30;
      break;
    case 10:
      dia = (d>=1 && d <=31)? d:31;
      break;
    case 11:
      dia = (d>=1 && d <=30)? d:30;
      break;
    case 12:
      dia = (d>=1 && d <=31)? d:31;
      break;
    default:
      cout << "This shouldn't be here" <<endl;
    }
}
// imprime la Fecha en el formato mm/dd/aaaa
void Fecha::imprimir() const 
{
  cout << mes << '/' << dia << '/' << anio;
}

void Fecha::diaSig(void)
{
  vector <int> m_30_d {4,6,9,11};
  vector <int> m_31_d {1,3,5,7,8,10};
  bool d_30 = false;
  bool d_31 = false;

  if(find(m_30_d.begin(), m_30_d.end(), mes) != m_30_d.end())
    d_30 = true;
  else if (find(m_31_d.begin(), m_31_d.end(), mes) != m_31_d.end())
    d_31 = true;

  
  if (mes==12 && dia ==31)
    {
      mes = 1;
      dia = 1;
      anio++;
    }
  else if(dia == 30 && d_30)
    {
      mes++; dia = 1;
    }
  
  else if(dia == 31 && d_31)
    {
      mes++; dia = 1; 
    }
  else if (mes==2 && dia== 29)
    {
      mes++; dia = 1; 
    }
  else if ( mes==2 && dia==28)
    {
      mes++; dia = 1 ;
    }
  else
     dia++;  
    
    
}
