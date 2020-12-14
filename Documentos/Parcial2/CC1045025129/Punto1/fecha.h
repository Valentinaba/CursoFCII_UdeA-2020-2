#ifndef FECHA_H
#define FECHA_H
// definición de la clase Fecha

class Fecha
{
 public:
  Fecha( int = 1, int = 1, int = 2000 ); // constructor predeterminado
  void imprimir();
  void diaSig();
  
 private:
  int dia;
  int mes;
  int anio;
}; 

#endif
