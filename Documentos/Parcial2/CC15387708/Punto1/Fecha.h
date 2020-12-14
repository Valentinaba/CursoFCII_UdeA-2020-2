// Definición de la clase Fecha

#include <iostream>
#include <iomanip>

using namespace std;

class Fecha
{
 public:
  Fecha( int = 1, int = 1, int = 2000 ); // Constructor con fecha predeterminada
  void mostrarFecha() const; // Función miembro que despliega la fecha
  void diaSig(); // Función miembro que incrementa la fecha en un día

 private:
  int dia;
  int mes;
  int anio;
};

