#include <iostream>
#include "cheque.h"

using namespace std;

CuentaCheques::CuentaCheques(double Saldo, double Cuota )
	
	: Cuenta(Saldo)
{
	setCuota(Cuota); //se valida la cuota por transacción
}

void CuentaCheques::setCuota(double Cuota_n) //se fija la cuota por transacción
{
  cuota = (Cuota_n < 0.0 ) ? 0.0: Cuota_n; //se verifica que la cuota a fijar sea mayor que cero 
  cout << "La cuota que ha sido fijada es: " << cuota << endl; 
}

void CuentaCheques::abonar(double abono)  //función que modifica la función de abono
{
	bool estado; 
	estado = Cuenta::abonar(abono);

	if (estado)  
	{
	  cout << "Recuerde que hay una cuota por transacción " << endl;  //se resta la cuota
	  Cuenta::cargar(cuota);
	}
}

void CuentaCheques::cargar(double retiro) //función que modifica la función retiro
{
	bool estado;
	estado = Cuenta::cargar(retiro);

	if (estado)  
	{
	  cout << "\nPero recuerde que se cobra además una cuota por transacción" << endl;  //se resta la cuota
	  Cuenta::cargar(cuota);	
	}
} 
