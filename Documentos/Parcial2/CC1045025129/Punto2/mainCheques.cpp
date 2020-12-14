#include <iostream>
#include <iomanip>

using namespace std;

#include "CuentaCheques.h"

int main()
{
 
  cout << fixed << setprecision( 2 ); //Precisión de los valores
  
  double saldo = 54237890; //Saldo usuario cuenta de cheques 
  double transaccion; //Valor de la transacción 
  cout << "Buenos días señor(a) usuario(a), nos complace poder servirle";
  cout << "\nUsted maneja una cuenta de cheques, acorde a su tiempo en el banco, le pedimos que ingrese el costo que tiene cada una de las transacciones que haga ";
  cin >> transaccion;
  
  CuentaCheques persona1(saldo, transaccion); //Objeto
  persona1.imprimir();
  
  persona1.setOperacion(); //Decidir operación a realizar 
  int operacion;
  cin >> operacion;
  
  persona1.Operacion(); //Realizar operación
  int valor;
  cin >> valor;

  //Posibilidad sobre las operaciones
  if(operacion == 1){//Abonar
  cout << "Su saldo actual es " << persona1.Abonar(valor) << endl;
  cout << "Muchas gracias por utilizar nuestros servicios, lo esperamos pronto" << endl;
  }
  else if(operacion == 2){//Cargar
  cout << "Saldo actual es " << persona1.Cargar(valor) << endl;
   cout << "Muchas gracias por utilizar nuestros servicios, lo esperamos pronto" << endl;
    }
  else{//Terminar
    cout << "Muchas gracias por utilizar nuestros servicios, lo esperamos pronto" << endl;}
  
 return 0;
}
