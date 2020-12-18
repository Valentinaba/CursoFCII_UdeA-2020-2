#ifndef CUENTA_CH
#define CUENTA_CH

#include <iostream>
#include "Cuenta.h"

class CuentaCheques : public Cuenta
{
 public:
  CuentaCheques(const double, const double);
  void cargarCheques(const double);
  void abonar(const double);
  void cargar(const double);
 private:
  double tasaCuota;
  void fijarCuota(const double);
};

#endif 
