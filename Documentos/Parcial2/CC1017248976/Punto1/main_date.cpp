//Librerias
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//incluir la clase
#include "date.h"

int main()
{ //vamos a probar la clase creada con este Script
  
  //creacion objetos de la clase Date  
  Date Date1( 31, 2, 2004); //se crea un objeto con dia=31 mes=febrero año=2004 que es bisiesto
  Date Date2(29, 02, 2000); //se crea un objeto con dia=29 mes=febrero año=2000 que es bisiesto
  Date Date3(28, 02, 2007); //se crea un objeto con dia=28 mes=febrero año=2007 que no es bisiesto
  Date Date4(33,6,2003); //se crea un objeto con una fecha sin sentido
  
  //ejemplos para ver si las fechas si son correctas
  cout<<"--------------------------------------------------------------\n";
  cout<<"1. Veámos si sí se está verificando la validez de las fechas\n"<<"\n";
  Date1.PrintDate();//se imprime la fecha proporcioanda
  cout<<"Después de validar: ";
  Date1.SetDate();// debido a que febrero no puede tener 31 dias no pasara la prueba de verificacion
  
  Date2.PrintDate();//se imprime la fecha proporcioanda
  cout<<"Después de validar: ";
  Date2.SetDate();// debido a que febrero puede tener 29 dias si el año es bisiesto pasara la prueba de verificacion
  
  Date3.PrintDate();//se imprime la fecha proporcioanda
  cout<<"Después de validar: ";
  Date3.SetDate();// debido a que febrero  puede tener 28 dias siempre pasara la prueba de verificacion independiente de si el año es o no bisiesto
  
  Date4.PrintDate();//se imprime la fecha proporcioanda
  cout<<"Después de validar: ";
  Date4.SetDate();
  
  cout<<"--------------------------------------------------------------\n";
  
  cout<<"2. Veámos cómo se comporta la función diaSig()\n"<<"\n";
  
  Date Date5( 31, 12, 2004); //comprobar el paso de año
  Date Date6( 31, 5, 2005); //caso convencional mes con 31 dias
  Date Date7( 30, 4, 2005); //caso convencional mes con 30 dias
  Date Date8( 29, 2, 2004); // paso mes febrero año bisisesto
  Date Date9( 28, 2, 2005); // paso mes febrero año no bisisesto
  

  Date5.PrintDate();
  cout<<"Después de la función diaSig() ";
  Date5.diaSig();
  
  Date6.PrintDate();
  cout<<"Después de la función diaSig() ";
  Date6.diaSig();

  Date7.PrintDate();
  cout<<"Después de la función diaSig() ";
  Date7.diaSig();

  Date8.PrintDate();
  cout<<"Después de la función diaSig() ";
  Date8.diaSig();
  
  Date9.PrintDate();
  cout<<"Después de la función diaSig() ";
  Date9.diaSig();  
  
  return 0;
}
