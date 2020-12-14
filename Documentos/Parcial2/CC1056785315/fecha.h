#include <iostream>

using namespace std;

//Clase para establecer una fecha, imprimirla y aumentarla en un dia
class Fecha
{
 public:
  Fecha(int = 1, int = 1, int = 2000); //Constructor predeterminado
  void setFecha(int = 1, int = 1, int = 2000); //Se establece la fecha 1/1/2000 si el usuario no ingresa nada
  void imprimir() const;
  void diaSig();
  
 private:
  int mes;
  int dia;
  int anio;
  bool bisiesto = false; //Para saber si el anio es bisiesto o no
}; 
