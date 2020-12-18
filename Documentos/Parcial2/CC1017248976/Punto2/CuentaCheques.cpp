#include "CuentaCheques.h"

CuentaCheques :: CuentaCheques(const double saldoInicial, const double cuota)
  : Cuenta(saldoInicial) //Inicializa el constructor de la clase Cuenta
{
  fijarCuota(cuota);
}


void CuentaCheques :: fijarCuota(const double cuota) 
{
  tasaCuota = ( cuota >= 0.0) ?  cuota: 0; //Verfica que la tasa de interés este en los valores adecuados (0,100)
}

//Calcula la cantidad de dinero por el interés
void CuentaCheques :: cargar(const double carga) 
{
  cout << "Su saldo antes de cargar: " <<getSaldo() << endl;
  Cuenta::cargar(carga + tasaCuota);
  cout <<"Su Saldo después de cargar: " << getSaldo() << endl;
}
void CuentaCheques :: abonar(const double Abono) 
{
  cout << "Saldo antes de abono: " << getSaldo() << endl;
  Cuenta::abonar(Abono-tasaCuota);
  cout << "Saldo después abono: "<< getSaldo() << endl;
} 
