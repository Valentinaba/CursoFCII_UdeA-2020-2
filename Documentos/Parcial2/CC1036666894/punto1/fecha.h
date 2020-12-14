#ifndef FECHA_H
#define FECHA_H

//Definicion de la clase
class Fecha
{
 public:
  Fecha();
  void imprimirFecha();
  int getFecha();
  void diaSiguiente();

  
 private:
  int d;
  int m;
  int a;
}; 

#endif
