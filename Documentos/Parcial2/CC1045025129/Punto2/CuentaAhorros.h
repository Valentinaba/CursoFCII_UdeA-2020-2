#ifndef CUENTAAHORRO_H
#define CUENTAAHORRO_H

using namespace std;

#include "Cuenta.h" //Se incluye la clase base

class CuentaAhorros : public Cuenta //Definición de la clase herencia
{
 public: 
  CuentaAhorros( double = 0.0, double = 0.0 ); //Recibe el saldo de la cuenta y la tasa de interes
   
  double calcularInteres() const; //Función para obtener los intereses correspondientes a la cuenta de ahorros. 
  
 private:
  double Interes; 
}; 
#endif
