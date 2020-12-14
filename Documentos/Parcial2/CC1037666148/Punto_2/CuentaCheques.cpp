#include "CuentaCheques.h"

CuentaCheques :: CuentaCheques(const double init_saldo, const double cuota)
  : Cuenta(init_saldo) //Inicializa el constructor de la clase Cuenta
{
  Set_cuota(cuota);
}

//Verfica que la tasa de interés este en los valores adecuados (0,100)
void CuentaCheques :: Set_cuota(const double cuota) 
{
  tasa_cuota = ( cuota >= 0.0) ?  cuota: 0; 
}

//Calcula la cantidad de dinero debida al interés
void CuentaCheques :: cargar(const double carga) 
{
  cout << "Saldo antes de carga: " <<getSaldo() << endl;
  Cuenta::cargar(carga+tasa_cuota);
  cout <<"Saldo antes de carga: " << getSaldo() << endl;
}
void CuentaCheques :: abonar(const double abono) 
{
  cout << "Saldo antes de abono: " << getSaldo() << endl;
  Cuenta::abonar(abono-tasa_cuota);
  cout << "Saldo después abono: "<< getSaldo() << endl;
}
