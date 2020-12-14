#include <iostream>
#include <iomanip>

// se incluyen las clases Cuenta y cuentaCheque
#include "Cuenta.h"
#include "cuentaCheque.h"


using namespace std;

// constructor
cuentaCheque::cuentaCheque(double saldoIn, double cuotaIn)
  : Cuenta(saldoIn) // se llama el constructor de la clase Padre
{
  
  setCuotaTrans(cuotaIn); // se inicializa la cuota de transaccion

}

// establece la cuota de transaccion
void cuentaCheque::setCuotaTrans(double cuota){

  // se comprueba que el valor de cuota sea correcto
  if(Cuenta::getSaldo()>0){ // para que no imprima el valor de la cuota si se ingresa un valor invalido de saldo en cuenta
    
    if(cuota <= 0.0 ){
      cout << "La cuota fijada en " << cuota << " no es permitida" << endl;
      cuotaTrans = 0.0;
    }
    
    else{
      cuotaTrans = cuota;
    }
    
    cout << "Cuota fijada en: " << cuotaTrans <<  endl;
    
  }
  
  else {
    cout << " " << endl;
  }

}
// funcion modificada de abonarSaldo
void cuentaCheque::abonarSaldo(double abonar){

  // se comprueba que haya habido un abono efectivo
  // y se cobra la cuota por esta transaccion
  
  if(Cuenta::abonarSaldo(abonar)){ // comprueba abono efectivo

    cout << "Se cobrara una cuota de transaccion de: " << cuotaTrans << endl;
    Cuenta::cargarSaldo(cuotaTrans); // se cobra por la transaccion
  }
  
}

// funcion modificada de cargarSaldo
void cuentaCheque::cargarSaldo(double cargar){

  // se combrueba un retiro efectivo de saldo
  // y se cobra la cuota por esta transaccion
  
  if(Cuenta::cargarSaldo(cargar)){ // comprueba retiro efectivo
    
    cout << "Se cobrara una cuota de transaccion de: " << cuotaTrans << endl;
    Cuenta::cargarSaldo(cuotaTrans); // se cobra por la transaccion
  }
  
}
