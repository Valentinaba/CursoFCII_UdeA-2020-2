#include <iostream>
using namespace std;

#include "fecha.h"

Fecha::Fecha( int d, int m, int y )
{
  dia = d;
  mes = m;
  anio = y;
}

void Fecha::diaSig()
{
  if(dia <= 29 and mes != 2){
  cout << dia+1 << '/' << mes << '/' << anio;
  }
  else if(mes == 2){
    if(dia < 28){
      cout << dia+1 << '/' << mes << '/' << anio;
    }
    else if(dia == 28 and anio % 4 == 0 and anio % 1000 != 0){
       cout << dia+1 << '/' << mes << '/' << anio;
      }
    else{
       cout << 1 << '/' << 3 << '/' << anio;
      }
   }
  else if(dia == 31 and mes == 12){
      cout << 1 << '/' << 1 << '/' << anio+1;
  }
  else if(mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10 or mes == 12 ){
    if(dia == 30){
       cout << dia+1 << '/' << mes << '/' << anio;
    }
     else{
       cout << 1 << '/' << mes+1 << '/' << anio;
    }
  }
  else if((mes == 4 or mes == 6 or mes == 9 or mes == 11) and dia == 30){
      cout << 1 << '/' << mes+1 << '/' << anio;
  }
}


// imprime la Fecha en el formato mm/dd/aaaa
void Fecha::imprimir()
{
  cout << dia << '/' << mes << '/' << anio;
}


