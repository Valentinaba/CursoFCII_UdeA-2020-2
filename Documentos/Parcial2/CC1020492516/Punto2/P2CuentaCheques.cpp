//interfaz de la división Cuenta Cheques

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "P2CuentaCheques.h"

CuentaCheques::CuentaCheques(double CCsaldo, double CCcuota){
	setSaldo(CCsaldo);
	setCuota(CCcuota);
}

void CuentaCheques::setCuota(double CCcuota){
	cuota = CCcuota;
}

double CuentaCheques::Abonar(double abono){
	Cuenta::Abonar(abono - cuota);
}
bool CuentaCheques::Cargar(double retiro){
	bool P;
	P = Cuenta::Cargar(retiro + cuota);
	/*if(P == 1){
		Cuenta::Cargar(cuota);
		}
	else{cout<<"Hubo un error con su transacción, por ende no se le cobró cuota."<<endl;}*/
}
					
