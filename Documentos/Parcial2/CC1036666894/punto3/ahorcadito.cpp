#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>


using namespace std;

// variables globales
string wordGuess;
string word;
int tries = 7;

// prototipo de funciones
void game();
void intento();
void play();

int main()
{
  srand(time(NULL));  // para numeros aleatorios
  
  cout << "¡Juego del ahorcado!" << endl;
  cout << "Debe adivinar la palabra." << endl;
  cout << "La palabra esta relacionada con un color, sentimiento o animal. " << endl;
  cout << "Si cree saber la palabra, puede arriesgarse en cualquier intento." << endl;
  cout << "¡Mucho cuidado! " << endl;
  cout << "Solo tiene 7 INTENTOS. ¡Qué empeiece el juego!" << endl;
  cout << "\n\n " << endl;
    

  
  bool playing = true; 

  // ciclo global para volver a jugar
  while(playing){
    word = ""; // se restablece word
    play();
    game();

    // ciclo para cada juego
    while(tries > 0 && word != wordGuess){ 
      intento();
      game();
    }

    // comprueba si se adivina la palabra
    if(word == wordGuess)
      {
	cout << " " << endl;
	cout << "!Felicidades¡ \n¡¡Acabas de ganar el juego!!" << endl;
	cout << " " << endl;
      }

    // si no se adivina la palabra
    else
      {
	cout << " " << endl;
	cout << "Te has quedado sin intentos, acabas de perder... La palabra era: " << wordGuess << endl;
	cout << " " << endl;
      }
    
    playing = false;
    cin.clear();
    cout << "¿Quiere intentar de nuevo?\n " ;
    cout << "Ingresa 1 para seguir, otra letra para salir" << endl; // para volver a jugar
    cin >> playing;
  }
}




void game(){

  // mientras va jugando, se comprueba cada intento
  switch(tries){
    
  case 0:
    cout << "___________" << endl;
    cout << "    }      " << endl;
    cout << "    O     " << endl;
    cout << "   /|\\  " << endl;
    cout << "  / | \\ " << endl;
    cout << "    |   " << endl;
    cout << "   / \\  " << endl;
    cout << "  /   \\ " << endl;
    cout << " /     \\ " << endl;
    cout << "___________" << endl;
    cout << "GAME OVER!!!!!" << endl;
    break;
  case 1:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "    O     " << endl;
    cout << "   /|\\  " << endl;
    cout << "  / | \\ " << endl;
    cout << "    |   " << endl;
    cout << "   / \\  " << endl;
    cout << "  /   \\ " << endl;
    cout << "       " << endl;
    cout << "___________" << endl;
    break;
  case 2:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "    O   " << endl;
    cout << "   /|\\  " << endl;
    cout << "  / | \\ " << endl;
    cout << "    |    " << endl;
    cout << "   / \\  " << endl;
    cout << "         " << endl;
    cout << "         " << endl;
    cout << "___________" << endl;
    break;
  case 3:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "    O   " << endl;
    cout << "   /|\\  " << endl;
    cout << "  / | \\ " << endl;
    cout << "    |   " << endl;
    cout << "    |   " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "___________" << endl;
    break;
  case 4:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "    O   " << endl;
    cout << "   /|\\  " << endl;
    cout << "  / | \\ " << endl;
    cout << "       " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "___________" << endl;
    break;
  case 5:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "    O   " << endl;
    cout << "   /|\\  " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "___________" << endl;
    break;
  case 6:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "    O   " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "___________" << endl;
    break;
  case 7:
    cout << "_________" << endl;
    cout << "    }     " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "___________" << endl;
    break;
  default:
    cout << "Si aparece esto, hay un error en el codigo" << endl; // no debe aparecer esto
    break;
  }
  
  cout << "Tiene: " << tries<< " intentos" << endl;   // Intentos que quedan
  cout << word << endl;  // se imprime la palabra en ****
  
}

// funcion para obtener la palabra desde el archivo de texto
string getWord(){
  
  vector <string> wordsVect;  // vector para almacenar las palabras del archivo
  string wordsList;

  ifstream randomWord;

  randomWord.open("palabras.txt");  // se abre el archivo

  // se comprueba que se abra con exito
  if (randomWord.fail()){ 
      cout << "Ocurrio un error al intentar abrir el archivo" << endl;
      exit(1);
    }

  // se envia cada palabra del archivo a la lista y luego al vector
  while(!randomWord.eof()){ 
    randomWord >> wordsList; // se envia lo del archivo al string
    wordsVect.push_back(wordsList);  // se envia cada palabra al vector
}
  int indWord = rand() % wordsVect.size(); // numero aleatorio del tamaño del vector con las palabras (cantidad de palabras)
  
  return wordsVect.at(indWord); // se retorna la palabra que hay en el indice aleatorio generado
}


void play(){
  tries = 7; // numero de intentos iniciales
  wordGuess = getWord();  // se obtiene una palabra aleatoria
  
  //cout << wordGuess << endl; // para mirar la palabra que se debe adivinar (trampa)

  // cambiar cada letra por * excepto las que se adivinan
  for(int i=0 ; i<wordGuess.length();i++){
    if(wordGuess[i]>='a' && wordGuess[i]<='z')
      word+='*';
   
    else
      {
	word += wordGuess[i];
      }
  }
  
}


// se comprueba cada ingreso de letra/palabra
void intento(){
  
  bool fail = true;
  
  char letra;
  cout << "\n" << endl;
  cout << "Ingrese letra o palabra: " << endl;
  cin >> letra;

  // se comprueba si la letra o palabra ingresada es acertada o no
  for(int i=0;i<wordGuess.length();i++){
    if (letra == wordGuess[i]){
      fail = false;
      word[i]=letra;
    }
  }

  // se resta intentos si la letra o palabra no coincide
  if (fail) {
    tries--;
  }
}
