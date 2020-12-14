/*
 * El interes se va a sumar cuando se haga un abono a la cuenta, esto se vera en el archivo main.cpp
 */

#include <iostream>

// se incluye la clase Cuenta y la clase CuentaAhorros
#include "Cuenta.h"
#include "cuentaAhorros.h"


using namespace std;

// constructor
cuentaAhorros::cuentaAhorros(double saldoIn, double interesIn)
  :Cuenta(saldoIn) //se llama al constructor de la clase Padre
 
{
  setInteres(interesIn); // se inicializa el interes

}

// establecer interes
void cuentaAhorros::setInteres(double inte){

  // se comprueba que el interes sea correcto (en %)

  if(Cuenta::getSaldo()> 0){ // para que no imprima la tasa de interes si se ingresa un valor invalido de saldo en cuenta
    if(inte <= 0.0){
      cout << "Valor " << inte <<" invalido de interes" << endl;
      tasaInteres = 0.0;
    }
    else{
      tasaInteres = inte;
      cout << "la tasa de interes es de: " << tasaInteres << "%"<< endl;
    }
  }
  
  else{
    cout << " " << endl;
  }
  
}

// se calcula cuanto interes se debe sumar al saldo
void cuentaAhorros::calcularInteres(){
  
  interes = Cuenta::getSaldo() * tasaInteres/100;
   
}

// se suma el interes al saldo usando la funcion de abonarSaldo
void cuentaAhorros::sumaInteres(){
    
  calcularInteres();
  
  cout << "Se va a abonar a su cuenta un valor de: " << interes << " de interes de ahorro" << endl;
  
  Cuenta::abonarSaldo(interes);
}
