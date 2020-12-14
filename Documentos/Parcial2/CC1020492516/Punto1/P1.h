//Clase del parcial2 punto1

//########### CLASE #####################

#include <cstring>
#include <string>
using namespace std;

class Fecha
{
 public:
  Fecha( int = 1, int = 1, int = 2000 ); // constructor predeterminado
  string nombremes(int = 1); 		//Esto da el nombre del mes dado el número, Enero por defecto
  void imprimir();	     		//Imprime la fecha en el formato " (dia) de (mes) del (año) "
  int diasDelMes(int = 1, int = 2000); 	//Nos da la cantidad de días que tiene un mes teniendo en cuenta si el año es biciesto o no
  void diaSig();			//Avanza un día

 private:
  int mes;
  int dia;
  int anio;
};
