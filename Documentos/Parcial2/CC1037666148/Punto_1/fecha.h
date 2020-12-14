#ifndef FECHA_H
#define FECHA_H
// definición de la clase Fecha

class Fecha
{
 public:
  Fecha(const int = 1,const int = 1,const int = 2000 ); // constructor predeterminado
  void imprimir() const ;
  void diaSig();
  
 private:
  int mes;
  int dia;
  int anio;
  void Set_fecha(const int,const int,const int);
  void Set_mes(const int);
  void Set_dia(const int);
  void Set_anio(const int);
}; 

#endif
