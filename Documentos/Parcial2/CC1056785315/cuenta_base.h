#include <iostream>
#include <iomanip>

using namespace std;

// Clase base para representar cuentas bancarias
class Cuenta
{
 public:
  Cuenta(double = 0.0); //Constructor predeterminado
  void abonar(double);
  void cargar(double);
  double getSaldo() const;

 private:
  double saldo;
};
