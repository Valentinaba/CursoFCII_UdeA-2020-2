#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H


class cuentaAhorros : public Cuenta // se hereda la clase Cuenta
{
  // funciones de la clase cuentaAhorros
 public:
  cuentaAhorros(double,double);
  void calcularInteres();
  void setInteres(double);
  void sumaInteres();
  
 
  // datos miembro de la clase cuentaAhorros
 private:
  double tasaInteres;
  double interes;
};

















#endif
