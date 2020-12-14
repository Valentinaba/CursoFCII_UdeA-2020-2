//Interfaz del constructor base del punto 2

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "P2base.h"

Cuenta::Cuenta( double Csaldo ){
	setSaldo(Csaldo);
}

double Cuenta::getSaldo() const{	
cout<<"Saldo: "<< saldo << "$" <<endl;
return saldo;
}

void Cuenta::setSaldo(double Csaldo){
	if(Csaldo < 0.0){
		cout<<"Error en el saldo de la cuenta " << cuenta << ". Redefiniendo a cero."<<endl;
		saldo = 0.0;
			}
	else{saldo = Csaldo;}
}

double Cuenta::Abonar( double abono){
	saldo = saldo + abs(abono);
	//El abs es porque como se está abonando, si se comete algun error de meter un número negativo, igual se abona.
}

bool Cuenta::Cargar(double retiro){
	if(retiro > saldo){
		cout<<"El monto a cargar excedió el saldo de la cuenta."<<endl;
		return 0;
			}
	else{
		saldo = saldo - abs(retiro);
		return 1;
		}
}

