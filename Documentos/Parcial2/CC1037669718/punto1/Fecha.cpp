#include"Fecha.h"

Fecha::Fecha(int d, int m, int a){
  set(d, m, a);
}

void Fecha::set(int d, int m, int a){
  dia = d;
  mes = m;
  anio = a;
}

void Fecha::diaSig(){
  dia++; // Aumenta el dia en 1
  if( mes == 2 ){ // Si es febrero
    if( anio % 4 == 0 ){ // Si es bisiesto
      dia = dia % 30;
    }else{
      dia = dia % 29;
    }
  }
  else if( mes == 4 || mes == 6 || mes == 9 || mes == 11 ){
      dia = dia % 31;
  }
  else{
    dia = dia % 32;
  }
  
  if( dia == 0 ){ // Si el dia ahora es cero significa que aumento el mes
    dia++;
    mes++;
    mes = mes % 13;
  }
  
  if( mes == 0 ){ // Si el mes ahora es cero significa que aumento el anio
    mes++;
    anio++;
  }
}
