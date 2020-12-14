#include <iostream>
#include <iomanip>
using namespace std;

#include "CuentaAhorros.h"

int main()
{
 
  cout << fixed << setprecision( 2 ); //Precisión de los datos
  
  double saldo = 3648250; //Saldo inicial cuenta ahorros
  double interes; //Valor del interés
  
  cout << "Buenos días señor(a) usuario(a), nos complace poder servirle";
  cout << "\nUsted maneja una cuenta de ahorros, acorde a su tiempo en el banco, le pedimos que ingrese la tasa de interés que le corresponde ";
  cin >> interes; //Entrada del usuario
  
  CuentaAhorros persona1(saldo, interes); //Objeto
  persona1.imprimir(); //Muestra saldo en pantalla
  cout << "Los intereses que va a recibir este mes son " << persona1.calcularInteres() << endl;
  
  persona1.setOperacion(); //Posibilidad de realizar operación bancaria
  int operacion;
  cin >> operacion;
  persona1.Operacion();
  int valor;
  cin >> valor; //Operación a realizar

  //Posibilidades de las operaciones
  if(operacion == 1){//Abonar
  cout << "Su saldo actual es " << persona1.Abonar(valor) << endl;
  cout << "Muchas gracias por utilizar nuestros servicios, lo esperamos pronto" << endl;
  }
  else if(operacion == 2){//Cargar
  cout << "Saldo actual es " << persona1.Cargar(valor) << endl;
   cout << "Muchas gracias por utilizar nuestros servicios, lo esperamos pronto" << endl;
    }
  else{//Terminar proceso
    cout << "Muchas gracias por utilizar nuestros servicios, lo esperamos pronto" << endl;}
  
 return 0;
}
