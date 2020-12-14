#include "cuentas_derivadas.h"

int main()
{
    
    //~~ Preba de la clase base Cuenta ~~//
    
    cout << "~~ Prueba de la clase base Cuenta ~~" << endl;
    
    Cuenta cuenta1(100);
    
    cout << "Saldo inicial: " << cuenta1.GetSaldo() << endl;
    
    cuenta1.Retirar(10); // Retiremos $10
    
    cout << "Saldo actual: " << cuenta1.GetSaldo() << endl;
    
    cuenta1.Abonar(30); // Abonemos $30
    
    cout << "Saldo actual: " << cuenta1.GetSaldo() << endl;
    
    cout << endl;
    
    //~~ Prueba de la clase derivada CuentaAhorros ~~//
    
    /*
    Para esta clase se considera que cada que el usuario introduce dinero, parte de ese dinero se multiplica segun la tasa de interes. Sin embargo, dado que los bancos son como son, únicamente se cargarán los interes si el usuario lo solicita después de haber hecho un abono mediante el método CalcularIntereses()
    */
    
    cout << "~~ Prueba de la clase derivada CuentaAhorros ~~" << endl;
    
    CuentaAhorros cuenta2(100,0.05); // 5% de interes
    
    cout << "Saldo inicial: " << cuenta2.GetSaldo() << endl;
    cout << "Interes inicial: " << cuenta2.GetInteres() << endl;
    cout << endl;
    
    cuenta2.Retirar(10); // Retiremos $10
    
    cout << "Saldo actual: " << cuenta2.GetSaldo() << endl;
    cout << "Interes actual: " << cuenta2.GetInteres() << endl;
    cout << endl;
    
    cuenta2.Abonar(30); // Abonemos $30
    cuenta2.CalcularIntereses();
    
    cout << "Saldo actual: " << cuenta2.GetSaldo() << endl;
    cout << "Interes actual: " << cuenta2.GetInteres() << endl;
    cout << endl;
    
    //~~ Prueba de la clase derivada CuentaCheque ~~//
    
    /*
    En este caso, cada que se retira se cobrara una cuota fija que se establece como entrada en el constructor de la clase. 
    */
    
    cout << "~~ Prueba de la clase base CuentaCheque ~~" << endl;
    
    CuentaCheque cuenta3(100,6.4); // 6.4 de cuota de retiro
    
    cout << "Saldo inicial: " << cuenta3.GetSaldo() << endl;
    
    cuenta3.Retirar(10); // Retiremos $10
    
    // El codigo mostrara no solo el valor retirado sino que le sumara el valor de la cuota
    
    cout << "Saldo actual: " << cuenta3.GetSaldo() << endl;

    cuenta3.Abonar(30); // Abonemos $30
    
    cout << "Saldo actual: " << cuenta3.GetSaldo() << endl;
    
    
    return 0;
}