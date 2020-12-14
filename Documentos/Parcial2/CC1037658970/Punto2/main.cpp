/**
 * @brief Se prueba la clase CuentaAhorros y Cuenta Cheques
 *        ambos derivados de la CuentaBase. Se hacen diversas
 *        transacciones y se imprime en pantalla.
 * @author Valentina Roquemen Echeverry
 */

#include <iostream> 
#include "Cuenta/CuentaBase.h"
#include "Cuenta/CuentaAhorros.h"
#include "Cuenta/CuentaCheques.h"

using namespace std;

int main()
{
  /***************************************/
  /*Transacciones en la cuenta de ahorros*/
  /***************************************/
  cout<<"\n CUENTA DE AHORROS \n"<<endl;

  CuentaAhorros miCuentaAhorros(10,3);

  cout<<"Saldo inicial: "<< miCuentaAhorros.getSaldo()<<endl; // Imprime saldo inicial

  miCuentaAhorros.abonar(22); // Abona
  miCuentaAhorros.cargar(55); // Retira un valor invalido
  miCuentaAhorros.cargar(5.5); // Retira un valor valido

  cout<<"Saldo actual: "<< miCuentaAhorros.getSaldo()<<endl; // Imprime saldo actual
  cout<<"Interes del saldo actual: "<< miCuentaAhorros.calculoInteres()<<endl; // Imprime interes actual

  miCuentaAhorros.abonar(miCuentaAhorros.calculoInteres()); // Abona el interes

  cout<<"Saldo con el interes: "<<miCuentaAhorros.getSaldo()<<endl; // Imprime saldo con el interes


  /***********************************/
  /*Transacciones en la cuenta cheque*/
  /***********************************/
  cout<<"\n CUENTA CHEQUE \n"<<endl;

  CuentaCheques miCuentaCheque(10,3);
  
  cout<<"Saldo inicial: "<< miCuentaCheque.getSaldo()<<endl; // Imprime saldo inicial

  miCuentaCheque.abonar(22); // Abona
  cout<<"Saldo actual: "<< miCuentaCheque.getSaldo()<<endl; // Imprime saldo

  miCuentaCheque.cargar(55); // Retira un valor invalido
  cout<<"Saldo actual: "<< miCuentaCheque.getSaldo()<<endl; // Como se retiro un valor invalido no costo la transaccion
  
  miCuentaCheque.cargar(5.5); // Retira un valor valido
  cout<<"Saldo actual: "<< miCuentaCheque.getSaldo()<<endl; // Imprime saldo actual

  return 0; 
}