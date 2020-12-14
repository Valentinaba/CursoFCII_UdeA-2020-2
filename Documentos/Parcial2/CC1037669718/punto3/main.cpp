#include"ahorcado.h"

using namespace std;

int main(){

  string seguir = "Y";

  while( seguir == string( 1 , 'Y' ) ){

    jugar( "palabras.txt" );

    cout << "Quieres volver a jugar? (y)\n";
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline( cin , seguir );    
    transform(seguir.begin(), seguir.end(), seguir.begin(), ::toupper); //Transformamos a mayusculas
    cout << "\n";
    
  }
  
  return 0;
}
