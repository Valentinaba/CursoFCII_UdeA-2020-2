#include <iostream> //Librería

using namespace std;

#include "Cuenta.h" //Clase base

Cuenta::Cuenta( double saldo ){ //Constructor de la clase
  if(saldo < 0.0){ //Verificación de la validez del saldo 
    cout << "El saldo inicial es inválido" << endl;
    SaldoInicial = ( saldo < 0.0 ) ? 0.0 : saldo; //Se redefine el saldo inicial en caso de no ser correcto
  }
}

double Cuenta::Abonar( double abono ){//Función del abono
  SaldoInicial = SaldoInicial + abono; //Nuevo saldo
  return SaldoInicial;
}

double Cuenta::Cargar( double retiro ){//Función del retiro
  if(retiro <= SaldoInicial){
    SaldoInicial = SaldoInicial - retiro; //Nuevo saldo
    return SaldoInicial; }
  else {//Saldo insuficiente para retiro
    cout << "Lo sentimos, usted no tiene dinero suficiente para realizar esta transacción" << endl;}
 
}

double Cuenta::getSaldo() const //Obtener valor del saldo
{
  return SaldoInicial;
}

void Cuenta::setOperacion(){ //Posibilidades de operaciones bancarias
  cout << "Para continuar con el proceso, presione:" << endl;
  cout << "1 para abonar " << endl;
  cout << "2 para retirar " << endl;
  cout << "3 para terminar la transacción " << endl;
}

void Cuenta::Operacion(){//Valor con el que se trabaja la transacción
  cout << "Ingrese el valor que desea consignar o retirar " << endl;
}


void Cuenta::imprimir() const{//Mostrar saldo
  cout << "Su saldo actual es " << getSaldo() << endl;
    }


