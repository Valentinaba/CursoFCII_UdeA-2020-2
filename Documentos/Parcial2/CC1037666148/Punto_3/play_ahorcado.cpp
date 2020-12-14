#include <iostream>
#include "ahorcado.h"
#include <string>
using namespace std;

int main()
{
  bool keep_playing = true;
  string answer;
  cout << "Bienvenido al juego de ahorcado! "<< endl;
  while (keep_playing)
    { 
      p_ahorcado playing;
      srand(time(NULL));
      playing.play();
      cout << "¿Desea seguir jugando?(y o n)" << endl;
      cin >> answer;
      if (answer == "y")
	keep_playing = true;
      else if (answer == "n")
	keep_playing = false;
      else
	keep_playing = false;
    }
	
  return 0;
}
