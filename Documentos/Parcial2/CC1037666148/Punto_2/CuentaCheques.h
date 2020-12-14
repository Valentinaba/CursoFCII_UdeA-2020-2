#ifndef CUENTA_CH
#define CUENTA_CH

#include <iostream>
#include "Cuenta.h"

class CuentaCheques : public Cuenta
{
 public:
  CuentaCheques(const double, const double);
  void Cargar_Cheques(const double);
  void abonar(const double);
  void cargar(const double);
 private:
  double tasa_cuota;
  void Set_cuota(const double);
};

#endif
