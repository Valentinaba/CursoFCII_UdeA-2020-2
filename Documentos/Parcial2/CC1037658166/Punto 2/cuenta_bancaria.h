#include <iostream>
using namespace std;


class Cuenta
{
public:
    // Constructor
    Cuenta(double);
    
    //Funciones miembro
    void Abonar(double);
    void Retirar(double);
    double GetSaldo();
    
/*    
Se estable saldo como privado dado que el usuario no deberia poder modificarlo sino a traves de los metodos Abonar y Retirar o, si se quiere ver entocnes se usa GetSaldo
*/

protected:
    double saldo;
    int numeroAbonos;
};




