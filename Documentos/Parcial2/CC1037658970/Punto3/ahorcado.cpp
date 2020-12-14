#include <time.h>
#include <iostream> 

#include "ahorcado.h"

using namespace std;

JuegoAhorcado::JuegoAhorcado(ifstream& file)
{
  getWords(file); // Pasa las palabras del archivo al vector
  srand(time(NULL));
}

void JuegoAhorcado::getWords(ifstream& file)
{
  string str;
  while (getline(file,str)){ words.push_back(str);} // Recorre cada fila del archivo obteniendo las palabras
}

void JuegoAhorcado::reglasJuego() const
{
  cout<<"\n El juego elige una palabra al azar de un banco de datos. En pantalla aparece una x por cada caracter de\n";
  cout<<"la palabra correspondiente. El jugador tiene 7 oportunidades, en las que puede ingresar una leta o la \n";
  cout<<"palabra. Cada vez que acierta, las x se reemplazan por la letra acertada. Cada vez que se equivoca\n";
  cout<<"se agrega una parte del cuerpo de la persona, hasta que en el septimo intento, si falla, aparece ahorcado.\n";
}

void JuegoAhorcado::play()
{
  int intento = 0; // Se inicializa el numero de intentos efectuados
  int pos_random = (rand()%words.size()); // Elige la posicion al azar
  string word = words[pos_random]; // Guarda la palabra de dicha posicion
  string word_temp = word; // Crea una copia de la palabra
  string word_guess( word.size(),'x'); // Crea un string de x con la longitud de la palabra que debe de ser adivinada
  string guess_temp; // String que alberga la entrada del usuario

  cin.clear(); // Se limpia lo que pueda haber en el buffer
  cin.ignore(10000, '\n');

  while (intento<7)
    {
      cout<<"Adivine la palabra: "<<word_guess<<endl;
      cout<<"Ingrese una letra o palabra(si te arriesgas)"<<endl;
      getline(cin, guess_temp); // Usuario ingreda la palabra

      /*Revisa si ingreso la palabra correcta*/
      if (guess_temp == word)
      {
        cout<<"Ganaste!"<<endl;
        break;
      }
    
      int n = 0;

      /*Se hace un ciclo para revisar si el caracter ingresado por el usuario aparece mas de una vez*/
      while(true)
      { 
        size_t found = word_temp.find(guess_temp); // Busca la posicion en la que se encuentra el caracter.
                                                   // En caso de que no este devuelve un numero diferente a
                                                   // cualquiera de las posiciones posibles de la palabra.    
        if( found>=0 && found<word.size() )
        {
          word_guess.replace(found,guess_temp.length(),guess_temp); //Cambia la x por la letra adivinada
          word_temp.replace(found,guess_temp.length(),"x"); // Cambia la letra por la x, en caso de que vuelva
                                                            // a poner la letra, saldrá un error.

          if(n==0) // Entra solo una vez para avisar al usuario que su eleccion estuvo bien.
          {
            cout<<"Bien jugado"<<endl;
            cout<<ahorcado_draw[intento]<<"\n\n"<<endl;
            n = 1;
          }
        }
      
        else
        {
          if(n==1){break;} // Para el caso en el que la palabra tiene varias veces el mismo caracter, luego de
                           // haber reemplazado todos los caracteres, debe de entrar aca para salir del while, pero
                           // sin contarlo como un error.

          intento += 1; // Suma el error
          if (intento<7) { cout<<"Perdiste un intento, te quedan: "<<7-intento<<endl;  }
          else { cout<<"Te ahorcaron!"<<endl;} // Para el caso en el que ya agoto todos los intentos

          cout<<ahorcado_draw[intento]<<"\n\n"<<endl; // Imprime la evoluciondel ahorcado
          break;
        }
      }
    } 
}

void JuegoAhorcado::mainMenu()
{
  char choose='1';

  while(choose!='4')
  {
    cout<<"--------------------------------------------\n";
    cout<<"--------------------------------------------\n";

    cout<<"¿Quieres jugar ahorcado? (elige una opcion)\n";
    cout<<"1. Deseas jugar.\n";
    cout<<"2. Deseas salir de aca.\n";
    cout<<"3. Deseas conocer las reglas del juego.\n";
    cin>>choose;
    cout<<"--------------------------------------------\n";
    cout<<"--------------------------------------------\n";

    switch (choose)
    {
      case '1':
        play();
        break;

      case '2':
        cout<<"Espero que juguemos en otra ocasion\n";
        choose='4';
        break;
      
      case '3':
        reglasJuego();
        break;

      default:
        cout<<"Por favor ingresa una opcion valida\n";
    }
  }
} 