//Punto 2, qué carreta tan hpta, no la voy a pegar aquí

#include <string> 
using namespace std;

class Cuenta
{
 public:
  Cuenta( double = 0.0 ); //Constructor: Saldo
  
  double Abonar( double = 0.0 ); //Default es 0

  bool Cargar( double = 0.0 ); //Default 0

  //void Set(); //Setea todo

  double getSaldo() const;

  void setSaldo(double = 0.0);


  private:
  int cuenta;
  double saldo;
};
