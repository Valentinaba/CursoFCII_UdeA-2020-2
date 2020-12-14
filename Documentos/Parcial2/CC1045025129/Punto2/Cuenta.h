#ifndef CUENTA_H
#define CUENTA_H
 
using namespace std;

class Cuenta //Clase base
{
 public: //Variables públicas de la clase
 Cuenta(double = 0.0 ); //Recibe el saldo 
 double Abonar(double); //Función que recibe el valor a abonar y devuelve el saldo que queda en la cuenta
 double Cargar(double); //Función que recibe el valor a retirar y devuelve el saldo que queda en la cuenta
 double getSaldo() const; //Obtener el saldo
 void setOperacion();  //Mostrar posibilidades de operaciones bancarias
 void Operacion();  //Decidir qué operación realizar
 void imprimir() const;  //Mostrar saldo
  
 private: //variables privadas
 double SaldoInicial;  
};

#endif
