// Función principal de la clase Fecha

#include "Fecha.h"

int main()
{
  Fecha a( 32, 13, 2000 ); //Cambia a fecha predeterminada por entrada incorrecta
  Fecha b( 29, 2, 2020); //Fecha cambio de mes
  Fecha c( 31, 12, 2011 ); //Fecha cambio de anio

  // Fecha particular y día siguiente
  a.mostrarFecha(); 
  a.diaSig();
  b.mostrarFecha();
  b.diaSig();
  c.mostrarFecha();
  c.diaSig();

  return 0;
}
