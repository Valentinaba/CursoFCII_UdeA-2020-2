#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#include "fecha.h"

Fecha::Fecha() //constructor
{
  getFecha(); //inicializa las variables en los valores ingresados por el usuario
}

int Fecha::getFecha(){

  
  // se ingresa el dia y se comprueba validez
  cout << "Ingrese el dia " << endl;
  cin >> d;
  
  if (d < 1 || d >31){
    cout << "Valor de dia ingresado invalido" << endl;
    exit(0);
  }

  // se ingresa el mes y se comprueba validez
  cout << "Ingrese el mes " << endl;
  cin >> m;
  if (m < 1 || m > 12){
    cout << "Valor de mes ingresado invalido" << endl;
    exit(0);
  }
  // ingresa el anio y se comprueba validez
  cout << "Ingrese el anio " << endl;
  cin >> a;
  
  if (a < 1){
    cout << "Valor de anio ingresado invalido" << endl;
    exit(0);
  }

  // se analizan diferentes casos especificos que no se pueden dar

  // cuando el dia ingresado es 31 y el mes es de 30 dias
  if (d == 31 and ( m == 4 or m == 6 or m == 9 or m == 11)){
    cout << "Valor de dia ingresado invalido" << endl;
    exit(0);
      }

  
  // se analiza el mes de febrero incluyendo los anios bisiestos
  if (m == 2 and a%4 == 0 and d > 29 ){
    cout << "Valor de dia ingresado invalido" << endl;
    exit(0);
  }
  
  
  // mes de febrero cuando el anio no es bisiesto
  if (m == 2 and a%4 != 0 and d > 28 ){
    cout << "Valor de dia ingresado invalido" << endl;
    exit(0);
  }


  return d,m,a;
}


// imprime la fecha ingresada en el formato dd/mm/aaaa
void Fecha::imprimirFecha(){
  cout <<"La fecha indicada en formato dd/mm/aaaa es: " << endl;
  cout << setw(2)  << setfill('0') << d  << '/' << setw(2)  << setfill('0' )<<  m << '/' <<setw(4)  << setfill('0') << a << endl;
}

// imprime el dia siguiente a la fecha indicada
void Fecha::diaSiguiente(){

  // se analizan diferentes casos especificos

  // cuando el dia es 30 y el mes es de 30 dias
  // se debe pasar al dia 1 del siguiente mes
  if(d == 30 and (m == 4 or m == 6 or m == 9 or m == 11)){
    d = 1;
    m += 1;
  }

  // cuando el dia es 31 y el mes es de 31 dias
  // se debe pasar al dia 1 del siguiente mes
  else if(d == 31 and (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m ==10)){
    d = 1;
    m += 1;
  }

  
  // dia 31 del mes de diciembre
  // se debe pasar al dia 1, mes 1 del anio siguiente
  else if(d == 31 and m==12){
    d = 1;
    m = 1;
    a += 1;
  }

  // en febrero cuando el anio es bisiesto
  // se debe pasar al dia 1 de marzo(mes 3)
  else if(m == 2 and d == 29 and a%4 == 0){
    d = 1;
    m = 3;
  }

  // en febrero cuando el anio no es bisiesto
  // se debe pasar al dia 1 de marzo(mes 3)
  else if(m == 2 and d == 28 and a%4 != 0){
    d = 1;
    m = 3;
    }

  // si no es ninguno de los casos especificos anteriores
  // simplemente se aumenta 1 dia a la fecha ingresada
  else {
    d++;
  }

  // se imprime la fecha del dia siguiente al ingresado
  // en formato dd/mm/aaaa
  cout << " " << endl;
  cout << "La fecha del dia siguiente al indicado en formato dd/mm/aaaa es: " << endl;
  cout << setw(2)  << setfill('0') << d  << '/' << setw(2)  << setfill('0' ) <<  m << '/' <<setw(4)  << setfill('0') << a << endl;

}
