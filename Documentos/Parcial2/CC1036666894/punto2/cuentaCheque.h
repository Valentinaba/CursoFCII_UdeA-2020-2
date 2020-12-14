#ifndef CUENTACHEQUE_H
#define CUENTACHEQUE_H


class cuentaCheque : public Cuenta // se hereda la clase Cuenta
{
  // funciones de la clase cuentaCheque
  
 public:
  cuentaCheque(double, double);
  void setCuotaTrans(double);

  // funciones abonar y cargar modificadas
  void abonarSaldo(double);
  void cargarSaldo(double);
  
  //dato miembro de la clase cuentaCheque
 private:
  double cuotaTrans;
  
};

#endif
