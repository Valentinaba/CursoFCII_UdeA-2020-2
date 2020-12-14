#include <iostream>
#include <iomanip>
#include "cuentasderivadas.h"

using namespace std;

// Clase derivada CuentaAhorros

//Constructor
CuentaAhorros::CuentaAhorros(double saldo_ini, double tasa)
  : Cuenta(saldo_ini) //Constructor de la clase base Cuenta
{
  //Si la tasa de interes es un porcentaje valido, la guarda
  if (0.0 <= tasa and tasa <= 100.0)
    {
      tasa_interes = tasa;
      cout << "Su cuenta tendra una tasa de interes del " << tasa_interes << " %" << endl;
    }

  //De lo contrario, toma un valor por defecto
  else
    {
      tasa_interes = 1.0;
      cout << "Tasa invalida. Ingrese un porcentaje de interes entre 0 y 100 %. Se establece en 1.0 %" << endl;
    }
}

// Funcion para calcular el valor del interes sobre el saldo
double CuentaAhorros::CalcularInteres()
{
  double interes_total = (tasa_interes/100.0)*Cuenta::getSaldo();
  return interes_total;
}

// Clase derivada CuentaCheques

// Constructor
CuentaCheques::CuentaCheques(double saldo_ini, double cuota)
  : Cuenta(saldo_ini) // Constructor de la clase base Cuenta
{
  //Si la cuota de transaccion es positiva, se guarda
  if (cuota > 0.0)
    {
      cuota_transaccion = cuota;
      cout << "Su cuenta tiene una cuota de transaccion de " << cuota_transaccion << " pesos." << endl;
    }

  //De lo contrario, se establece en 8000 pesos
  else
    {
      cuota = 8000.0;
      cout << "Cuota de transaccion invalida, debe ser una cantidad positiva. Se guarda en 8000 pesos." << endl;
    }
}

//Modificaciones a la funcion abonar original

void CuentaCheques::abonar(double ingreso)
{
  bool abono = Cuenta::abonar(ingreso); //Verifica la validez del abono

  //Si el abono es valido, que se cobre la cuota de transaccion
  if (abono)
    {
      Cuenta::cargar(cuota_transaccion);
    }
}

//Modificaciones a la funcion cargar original

void CuentaCheques::cargar(double cargo)
{
  bool retirar = Cuenta::cargar(cargo); //Verifica la validez del retiro

  //Si el retiro es valido y con el saldo restante se alcanza a pagar la cuota, que se cobre la cuota de transaccion
  if (retirar and Cuenta::getSaldo() >= cuota_transaccion)
    {
      Cuenta::cargar(cuota_transaccion);
    }

  //Si el saldo restante no es suficiente para cobrar la cuota de transaccion, se cancela el retiro
  else if (Cuenta::getSaldo() < cuota_transaccion)
    {
      Cuenta::abonar(cargo);
      cout << "Con el retiro de esa cantidad no queda dinero para cobrar la cuota de transaccion, por lo que el retiro no es valido. Recuerde que su saldo es " << Cuenta::getSaldo() << " pesos y la cuota vale " << cuota_transaccion << " pesos." << endl;
    }
}
