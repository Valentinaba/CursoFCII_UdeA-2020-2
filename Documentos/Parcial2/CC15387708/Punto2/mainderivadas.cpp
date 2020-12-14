#include <iostream>
#include "cuentasderivadas.h"

using namespace std;

int main()
{
  cout << "Para la cuenta de ahorros:\n" << endl;
  CuentaAhorros Ahorro(650000, 1.0);
  
  Ahorro.abonar(250000); //Se realiza un abono exitoso

  cout << "\nAl hacer un abono valido de 250 mil pesos, se suman los " << Ahorro.CalcularInteres() << " pesos de la tasa de interes. ";

  //Se suma el interes sobre el saldo por haber realizado un abono a la cuenta de ahorros
  Ahorro.abonar(Ahorro.CalcularInteres());
  
  cout << "El saldo actual es: " << Ahorro.getSaldo() << " pesos.\n" << endl;

  cout << "_________________" << endl;
  cout << "Para las cuentas de cheques:\n" << endl;
  
  CuentaCheques Cheque1(200000, 7000);
  cout << endl;
  CuentaCheques Cheque2(350000, 5000);

  cout << "\nCheque 1:" << endl;
  Cheque1.abonar(350000);

  //Al abonarse 350 mil pesos a la cuenta Cheque1, debe haberse cobrado la cuota de 7 mil pesos
  //Así el nuevo  saldo debe ser 200 mil + 350 mil - 7 mil = 543 mil
  
  cout << "Se ha efectuado el abono y se ha cobrado la cuota de transaccion. El saldo actual es: " << Cheque1.getSaldo() << " pesos\n" << endl;

  //Aqui se intenta retirar una cantidad tal que el saldo restante no alcance para pagar la cuota

  cout << "Cheque 2:" << endl;
  Cheque2.cargar(348000);

  return 0;
}
