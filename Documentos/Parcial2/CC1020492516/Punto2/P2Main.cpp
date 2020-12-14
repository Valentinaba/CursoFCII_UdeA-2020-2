//Main del base para probar jeje 

#include <iostream>

using namespace std;

//#include "P2base.h"
//#include "P2CuentaAhorros.h"
#include "P2CuentaCheques.h"

int main()
{
  cout<<"\nCuenta: "<<endl;
  Cuenta cuenta1(10.0);		//Saldo 
  cuenta1.getSaldo();		//Mostrar
  cuenta1.Abonar(200.0);	//Abonamos 200
  cuenta1.getSaldo();		//Deberían haber 210
  cuenta1.Cargar(210.0);	
  cuenta1.getSaldo();		//0
  cuenta1.Cargar(1.0); 		//Muestra el mensaje de que no puede realizarse el retiro.

  cout<<"\nCuenta Ahorros: "<<endl;
  CuentaAhorros cuentaA1(10.0,0.1);	//Saldo e interés
  cuentaA1.getSaldo();			//10
  cuentaA1.Abonar(200.0);		//210
  cuentaA1.Abonar( cuentaA1.calcularInteres() );   //Muestra el interés (21) y lo abona
  cuentaA1.getSaldo();				   //231
  cuentaA1.Cargar(235);				   //No deja cargar 235 y muestra el mensaje
  cuentaA1.getSaldo();				   //Mantiene el 231

  cout<<"\nCuenta Cheque: "<<endl;
  CuentaCheques cuentaC1(10.0,1);	//Saldo y cuota
  cuentaC1.getSaldo();			//10
  cuentaC1.Abonar(100.0);		//Abonamos 100
  cuentaC1.getSaldo();			//109 porque la cuota es 1
  cuentaC1.Cargar(50.0);		
  cuentaC1.getSaldo();			//58, restó nuevamente 1
  cuentaC1.Cargar(58);			//no deja cargar los 58, pues no alcanza con la cuota		
  cuentaC1.getSaldo();			//Conserva los 58
  return 0;
}
