#include "cuentas_derivadas.h"

// Implementacion de la clase CuentaAhorros
CuentaAhorros::CuentaAhorros(double inicial, double porcentaje)
  : Cuenta(inicial) //Constructor de la clase base
{
  //Condiciones para un porcentaje valido
  if (porcentaje >= 0.0 and porcentaje <= 100.0)
    {
      interes = porcentaje;
      cout << "Establecio un porcentaje de interes del " << interes << "%\n" << endl;
    }
  
  else
    {
      cout << "El porcentaje de interes debe estar entre 0 y 100. Se establece en 1.00% por defecto.\n" << endl;
      interes = 1;
    }
}

// Calcula interes sobre el saldo actual
double CuentaAhorros::calcularInteres() const
{
  return interes*Cuenta::getSaldo()/100;
}

// Implementacion de la clase CuentaCheques
CuentaCheques::CuentaCheques(double inicial, double transaccion)
  : Cuenta(inicial) //Constructor de la clase base
{
  //Condiciones para una cuota de transaccion valida
  if (transaccion > 0.0)
    {
      cuota = transaccion;
      cout << "Establecio una cuota por transaccion de " << cuota << " pesos\n" << endl;
    }
  
  else
    {
      cout << "La cuota de transaccion debe ser mayor que cero. Se establece por defecto en 10000 pesos\n" << endl;
      cuota = 10000.0;
    }
}

void CuentaCheques::abonar(double abono)
{
  double saldo_antes = Cuenta::getSaldo();
  Cuenta::abonar(abono); //Se realiza el abono con la funcion abonar de la clase base
      
  //Si el abono es valido, que cobre la cuota de transaccion si queda suficiente dinero; si no alcanza para la cuota, que deshaga el abono
  
  if (saldo_antes < Cuenta::getSaldo()) //Revisa si el abono fue valido comparando el saldo antes y despues
    {
      //Revisa si alcanza para pagar la cuota. Seria raro que no alcance despues de un abono, pero puede pasar
      if (Cuenta::getSaldo() >= cuota)
	{
	  Cuenta::cargar(cuota);
	  cout << "Se han abonado " << abono << " pesos a su cuenta y se ha cobrado una cuota de " << cuota << " pesos por la transaccion. Con esto, su saldo actual es de " << Cuenta::getSaldo() << " pesos.\n" << endl;
	}

      else
	{
	  Cuenta::cargar(abono); //Se deshace el abono porque no alcanzo para pagar la cuota
	  cout << "Ni siquiera con el abono le alcanza para pagar la cuota de transaccion. Recuerde que la cuota es de " << cuota << " pesos y su saldo es de " << saldo_antes << " pesos. Intente abonando una cantidad mayor.\n" << endl;
	}
    }
}

void CuentaCheques::cargar(double retiro)
{
  double saldo_antes = Cuenta::getSaldo();
  Cuenta::cargar(retiro); //Se realiza el retiro con la funcion cargar de la clase base

  //Si el retiro es valido, que cobre la cuota de transaccion si queda suficiente dinero; si no alcanza para la cuota, que deshaga el retiro
  if (saldo_antes > Cuenta::getSaldo())
    {
      if (Cuenta::getSaldo() >= cuota)
	{
	  Cuenta::cargar(cuota);
	  cout << "Se han retirado " << retiro << " pesos de su cuenta y se ha cobrado una cuota de " << cuota << " pesos por la transaccion. Con esto, su saldo actual es de " << Cuenta::getSaldo() << " pesos.\n" << endl;
	}

      else
	{
	  Cuenta::abonar(retiro); //Se deshace la transaccion porque no alcanzo para la cuota
	  cout << "Transaccion rechazada. No quedaria con suficiente saldo para pagar la cuota de transaccion. Recuerde que la cuota es de " << cuota << " pesos y su saldo es de " << saldo_antes << " pesos\n" << endl;
	}
    }
}
