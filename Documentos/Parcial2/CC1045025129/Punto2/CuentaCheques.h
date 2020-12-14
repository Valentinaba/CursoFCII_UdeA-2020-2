#ifndef CUENTACHEQUES_H
#define CUENTACHEQUES_H

using namespace std;

#include "Cuenta.h" //Se incluye la clase base 

class CuentaCheques : public Cuenta //Definición de la clase herencia 
{
 public:
  CuentaCheques( double = 0.0, double = 0.0 ); //Recibe el saldo y el valor que se le cobra al usuario por cada transferencia

  //Se redefinen las funciones Abonar y Cargar de la clase base
  double Abonar(double);  
  double Cargar(double); 
  
 private:
  double Transaccion; //Valor de la operación
}; 
#endif
