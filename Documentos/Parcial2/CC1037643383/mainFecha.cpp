#include<iostream>
#include"fecha.h"

using namespace std;

int main()
{

  Fecha fecha(2, 11, 2020);

  cout << "Este ejercicio se desarrolló en la fecha " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ".\n";

  fecha.diaSig();

  cout << "El día siguiente es " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ".\n";

  fecha.setFecha(31, 12, 2020);
  fecha.diaSig();

  cout << "Cuando el año acabe, la fecha será " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ".\n";

  fecha.setFecha(28, 2, 2021);
  fecha.diaSig();
  cout << "día siguiente al 28 de Febrero en año no bisiesto " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ",";

  fecha.setFecha(28, 2, 2020);
  fecha.diaSig();
  cout << " En año bisiesto " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << ".\n";

  return 0;
}
