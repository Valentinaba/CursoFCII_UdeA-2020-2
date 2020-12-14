#ifndef FECHA_H
#define FECHA_H

class Fecha
{
 public:
  Fecha( int = 31, int = 10, int = 2020 );
  void checkFecha();
  void imprimir();
  void diaSig();
  int Bisiesto();
  void imprimirBisiesto();
  
 private:
  int mes;
  int dia;
  int anno;
  int bis;
}; 

#endif
