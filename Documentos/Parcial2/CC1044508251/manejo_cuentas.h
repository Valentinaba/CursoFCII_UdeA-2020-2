
#include <string> 
using namespace std;

class Cuenta
{
 public:
  Cuenta( const string &, double = 0.0);

  void checkSaldoInicial();
  void getSaldo();
  void abonar( double ); 
  void cargar( double ); 
  
 protected:
  string nombreCuenta;
  double saldo; 
};


class CuentaAhorros : public Cuenta
{
 public:
  CuentaAhorros( const string &, double = 0.0, double = 0.04 );
  
  double calcularInteres();  
  void addInteres();
  
 private:
  double interes; 
};


class CuentaCheques : public Cuenta  
{
 public:
  CuentaCheques( const string &, double = 0.0, double = 6 );

  void cobrarTransaccion();
  void abonar( double ); 
  void cargar( double ); 
  
  
 private:
  double trans; 
};

