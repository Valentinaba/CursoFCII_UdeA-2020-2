#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int intentos = 7;
int entrada( char, string, string& ); // Funciń que lee y procesa datos
void enunciado(); // Mostrar el estado del juego en pantalla
string mensaje = "Inicia el juego. Descubre el nombre de un animal!";

// Función primaria

int main()
{
  string nombre;
  char letra;
  string animal;
  
  // Arreglo de palabras para el juego
  string animales[] =
    {
     "gato",
     "perro",
     "pato",
     "elefante",
     "jirafa",
     "conejo",
     "tortuga",
     "caballo",
     "pez",
     "lagartija",
     "serpiente",
     "higuana"
    };

  // Elección aleatoria de una palabra
  srand(time(NULL));
  int n = rand()% 12;
  animal = animales[n];
  
  // Longitud de carácteres de la palabra elegida
  string cantidad( animal.length(),'X' );
  
  // Condiciones que definen el estado del juego
        
  while ( intentos!=0 )
    {
      enunciado();
      cout << "\n\n\t\t\t\t" << cantidad;
      cout << "\n\n\t\tIngresa la letra que quieres adivinar: ";
      cin >> letra;
      
      if ( entrada(letra, animal, cantidad)==0 )
	{
	  mensaje = "La letra no pertenece a la palabra.";
	  intentos = intentos - 1;
	}

      else
	{
	  mensaje = "Adivinaste una letra. Te podrias SALVAR!";
	}
      
      if ( animal==cantidad )
	{
	  mensaje = "Lo lograste!";
	  enunciado();
	  cout << "\n\t\t\tEl nombre del animal es: " << animal << endl;
	  break;
	}
    }

  if( intentos == 0 )
    {
      mensaje = "Te has echado la soga al cuello. Quedas AHORCADO!";
      enunciado();
      cout << "\n\t\t\tEl nombre del animal es: " << animal << endl;	
    }
  
  cin.ignore();
  cin.get();
  return 0;
}

// Funciones secundarias

int entrada ( char adivinar, string oculto, string &adivinaranimal )
{
  int i;
  int coincide = 0;
  int len = oculto.length();
  for ( i = 0; i< len; i++ )
    {
      
      if ( adivinar == adivinaranimal[i] )
	return 0;
      
      if ( adivinar == oculto[i] )
	{
	  adivinaranimal[i] = adivinar;
	  coincide++;
	}
    }
  return coincide;
}

void enunciado()
{
  
  cout<<"\t--------------------------------------------------------";
  cout<<"\n\t\t\tJuego del AHORCADO!";
  cout << "\n\tLa cantidad de intentos disponibles es " << intentos << ":";
  cout<<"\n\n\t\t"+mensaje;
  cout<<"\n\t--------------------------------------------------------\n";
  
}
