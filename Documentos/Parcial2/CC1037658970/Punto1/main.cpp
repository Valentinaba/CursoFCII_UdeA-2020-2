/**
 * @brief Se prueba la clase Fecha
 * @author Valentina Roquemen Echeverry
 */

#include "fecha.h" 

int main()
{
  Fecha myDate(12,30,2019); // Fecha inicial, formato: mm/dd/yyyy
  
  myDate.imprimir(); // Imprime la fecha si es valida

  /*Se evoluciona la fecha por 7 dias*/
    
  for (int i = 0; i < 7; ++i)
  {
    myDate.diaSig();
    myDate.imprimir();
  }

  return 0;
}