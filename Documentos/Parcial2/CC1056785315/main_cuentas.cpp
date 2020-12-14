#include "cuentas_derivadas.h"

int main()
{
  // Primero se prueba la clase base Cuenta
  
  cout << "PRUEBA CLASE BASE CUENTA" << endl;

  cout << "Cuenta base1:" << endl;
  Cuenta base1(1000000);

  cout << "Cuenta base2:" << endl;
  Cuenta base2(-100000); //Saldo inicial invalido

  cout << "ABONOS\n" << endl;

  cout << "Cuenta base1:" << endl;
  base1.abonar(-100000); //Abono invalido

  cout << "Cuenta base2:" << endl;
  base2.abonar(100000); //Abono valido
  cout << "El saldo despues de la transferencia es: " << base2.getSaldo() << " pesos\n" << endl;

  cout << "RETIROS\n" << endl;

  cout << "Cuenta base1:" << endl;
  base1.cargar(50000); //Retiro valido
  cout << "El saldo despues de la transferencia es: " << base1.getSaldo() << " pesos\n" << endl;

  cout << "Cuenta base2:" << endl;
  base2.cargar(150000); //Retiro invalido

  // Luego se prueba la clase derivada CuentaAhorros
  
  cout << "---------------------------------------" << endl;
  cout << "PRUEBA CLASE CUENTAAHORROS\n" << endl;

  cout << "Cuenta ahorros1:" << endl;
  CuentaAhorros ahorros1(500000, 2);

  cout << "Cuenta ahorros2:" << endl;
  CuentaAhorros ahorros2(400000, 200); //Interes invalido

  ahorros1.abonar(100000);
  ahorros2.cargar(150000);

  //Como se hizo un abono en la cuenta ahorros1, se suma el interes por ser cuenta de ahorros
  cout << "Cuenta ahorros1:" << endl;
  ahorros1.abonar(ahorros1.calcularInteres());
  cout << "Despues del abono y el monto de interes, el nuevo saldo es: " << ahorros1.getSaldo() << " pesos\n" << endl;

  //No se esta sumando interes por retirar dinero
  cout << "Cuenta ahorros2:" << endl;
  cout << "El saldo despues de la transferencia es: " << ahorros2.getSaldo() << " pesos\n" << endl;

  // Por ultimo, se prueba la clase derivada CuentaCheques
  
  cout << "---------------------------------------" << endl;
  cout << "PRUEBA CLASE CUENTACHEQUES\n" << endl;

  cout << "Cuenta cheques1:" << endl;
  CuentaCheques cheques1(300000, 5000);
  
  cout << "Cuenta cheques2:" << endl;
  CuentaCheques cheques2(600000, -5000); //Cuota invalida

  cout << "ABONOS\n" << endl;

  cout << "Cuenta cheques1:" << endl;
  cheques1.abonar(150000);

  cout << "Cuenta cheques2:" << endl;
  cheques2.abonar(-150000); //Abono invalido

  cout << "RETIROS\n" << endl;

  cout << "Cuenta cheques1:" << endl;
  cheques1.cargar(100000);

  cout << "Cuenta cheques2:" << endl;
  cheques2.cargar(598000); //Se intenta cargar de forma que no alcance dinero para la cuota
  
  return 0;
}
