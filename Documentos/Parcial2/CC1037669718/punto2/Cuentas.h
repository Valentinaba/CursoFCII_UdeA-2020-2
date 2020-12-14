class Cuenta{
  
 public:
  Cuenta( double );
  void abonar( double );
  bool cargar( double );
  double getSaldo();

 private:
  double saldo = 0.0;
  
};

class CuentaAhorros : public Cuenta {

 public:
  CuentaAhorros( double , double );
  double calcularInteres();

 private:
  double tasa_interes;
  
};

class CuentaCheques : public Cuenta {

 public:
  CuentaCheques( double , double);
  void abonar( double );
  bool cargar( double );
  
 private:
  double cuota;

};
