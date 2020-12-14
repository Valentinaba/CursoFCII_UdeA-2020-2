#include<iostream>
#include"Fecha.h"

using namespace std;

int main(){

  Fecha fecha(3, 11, 2020);

  cout << "El parcial debe entregarse antes del día " << fecha.dia << " del mes " << fecha.mes << " del año " << fecha.anio << ".\n";

  fecha.diaSig();

  cout << "El día siguiente es " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ".\n";

  fecha.set(31, 12, 2020);
  fecha.diaSig();

  cout << "Luego del fin de este año la fecha será " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ".\n";

  fecha.set(28, 2, 2019);
  fecha.diaSig();
  cout << "La fecha siguiente al 28 de febrero del 2019 es " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ",";
  
  fecha.set(28, 2, 2020);
  fecha.diaSig();
  cout << " pero la de este año es " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << " ya que este año es bisiesto.\n";

  return 0;
}
