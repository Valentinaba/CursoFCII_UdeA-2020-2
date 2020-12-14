//Se cargan librerías
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>

#define WORDS_PATH "palabras.txt" //Camino para cargar el archivo ocn las palabras 

using namespace std;

int juego(string, string); //Función para jugar ahorcado
void cargar_palabras();  //Función para cargar las palabras del archivo de texto
int fracasos = 0; //Contador de los fracasos dentro del juego
string ahorcado;  //String que va a guardar la palabra que el jugador debe adivinar

int main(){

  srand(time(NULL)); //Se inicializa la semilla para tomar al azar la palabra
  cargar_palabras(); //Se carga la palabra que debe adivinar
  string intento;  //String para guardar las letras que se van adivinando
  cout << "Para empezar el juego le daremos una primera pista, su palabra tiene un total de " << ahorcado.length() << " letras." << endl;
  juego(ahorcado, intento);  //Inicio del juego
  string respuesta;  //Respuesta para saber si se juega de nuevo
  cout << "¿Desea jugar de nuevo?" << endl;
  cin >> respuesta;
  if(respuesta == "si"){ //Jugar de nuevo
    cargar_palabras();
     cout << "Para empezar el juego le daremos una primera pista, su palabra tiene un total de " << ahorcado.length() << " letras." << endl;
    juego(ahorcado, intento);
  }
  else{//No jugar más
    cout << "Regresa pronto a jugar" << endl;}
  return 0;}


void cargar_palabras(){

  vector <string> lista_palabras; //Vector para guardar las palabras 
  string palabra_aux;  //String para ir leyendo las palabras del archivo txt
  ifstream archivo_palabras(WORDS_PATH); //Se carga el archivo
	
  if (archivo_palabras.fail()){ //Caso en que el archivo no se puede abrir
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
       
  while(!archivo_palabras.eof()){ //Se guardan las palabras del archivo en el vector
    archivo_palabras >> palabra_aux;
    lista_palabras.push_back(palabra_aux);
}
  int i = rand() % lista_palabras.size(); //Se genera número aleatorio
 
  ahorcado = lista_palabras.at(i); //Se guarda palabra en la variable string
}





int juego(string palabra_ahorcado, string palabra_juego){ //Función del juego
  while(fracasos < 7){ //El juego le permite equivocarse a lo sumo 7 veces
  cout << "Introduzca la letra (recuerde hacerlo en minúscula)" << endl;
  string letra; //Letra que el jugador introduce
  cin >> letra;
  int ganancias = 0; //Variable que determina si el jugador acierta
  int posicion = palabra_ahorcado.find( letra ); //Se usa la función find() para encontrar la letra que el jugador ha escrito en la palabra que está buscando adivinar, dicha función nos entrega
  if(posicion >= 0){
    while ( posicion != string::npos ) //Función para buscar la letra en la palabra, en caso de que esté repetida
      {
	posicion = palabra_ahorcado.find( letra, posicion + 1 );
	palabra_juego.append(letra) ; //Va agregando las letras que va acertando el jugador al string auxiliar
	ganancias = 1;
      
      }
  }
  else{fracasos++;} //De lo contrario cuenta el fracaso
  
  if (ganancias == 1){ //Caso en el que el jugador acierta
      cout << "¿Desea intentar escribir la palabra completa (si/no)?" << endl;
      string respuesta; //Se le permite ingresar la palabra completa
      cin >> respuesta;
       if(respuesta == "si"){
	cout << "Introduzca la palabra" << endl;
	string palabra; //Palabra que escribe el jugador
	cin >> palabra;
	if(palabra_ahorcado == palabra){ //Adivina la palabra completa
	  cout << "Felicitaciones, ganaste" << endl;
	  break;}
	else{ fracasos++;}
      }
       else{}
  }
  else{}

  if(palabra_juego.length() == palabra_ahorcado.length()){ //Caso en el que la persona logra adivinar la palabra
    cout << "Felicitaciones, ganaste" << endl;
    break;
  }
   else{}
  }
 
}
