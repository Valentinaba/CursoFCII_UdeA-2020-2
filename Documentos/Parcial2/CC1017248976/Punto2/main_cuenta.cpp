#include <iostream>
#include "Cuenta.h"
#include "CuentaAhorros.h"
#include "CuentaCheques.h"

using namespace std;

int main()
{
  //Test para la cuenta
cout<<"___________CUENTA__________________"<<"\n";
  Cuenta cuentaPrueba(10); 
  cout<<"El saldo inicial es: "<<cuentaPrueba.getSaldo()<<"\n";
  cuentaPrueba.abonar(600);
  cout << " Su saldo despues del abono es:" << cuentaPrueba.getSaldo()<<"\n";
  cuentaPrueba.cargar(104);
  cout << " Su saldo despues del cargo es:" <<cuentaPrueba.getSaldo()<<"\n";



  //Test para la cuenta de ahorros
  cout<<"_______CUENTA AHORRO_____________"<<"\n";
  CuentaAhorros PruebaCuentaAhorros(cuentaPrueba.getSaldo(), 0.002);
  double interes = PruebaCuentaAhorros.calcularInteres();
  cout << "El interes de la cuenta de ahorros es: "<< interes << endl;


  //Test para la cuenta de Cheques
  cout<<"_______CUENTA CHEQUES_____________"<<"\n";
  CuentaCheques PruebaCuentaCheques(cuentaPrueba.getSaldo(),0.5);
  PruebaCuentaCheques.cargar(200);
  PruebaCuentaCheques.abonar(800);
  
  
  return 0;

} 
