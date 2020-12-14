/*
Implementación de la clase ahorcado
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>

#include "ahorcado.h"

using namespace std;

//constructor
Ahorcado::Ahorcado( void )
{
	srand( time(NULL) ); //semilla numero aleatorio

	initGame(); //despliega mensaje de bienvenida 
}

void Ahorcado::initGame( void ) const
{
	cout << "\n  BIENVENIDO AL JUEGO AHORCADO  \n" << endl;
	cout << "Usted cuenta con 7 intentos para adivinar la palabra" 
	<< " que se seleccione aleatoriamente del banco de palabras. \n" << endl;
	cout << "Por favor tenga en cuenta que:"<< endl;
	cout << "1. Solo se permite jugar adivinando letra por letra o la palabra completa, "
	<< "si ingresa grupos diferentes de palabras, perderá inmediatamente. " << endl;
	cout << "2. Debe ingresar sus respuestas en minuscula" << endl;
	cout << "\nLe deseamos mucha suerte  ( ^ ᗜ ^ )\n" << endl;
}

//función para definir la palabra que debe adivinar el usuario
void Ahorcado::getWord( void )
{
	int nWord = rand() % 10; //número aleatorio entre 1 y 10

	ifstream docWords; //documento
	string nombre_archivo="Palabras.txt"; //archivo con palabras
	string word; 

	docWords.open(nombre_archivo.c_str()); // abre el archivo

	if (docWords.fail()) // comprueba una apertura con exito
	{
		cout << "\nEl archivo " << nombre_archivo << " no se abrió con éxito"
		<< "\nPor favor compruebe que el archivo existe en realidad." << endl;
		exit(1);
	}
	//cout << "\nEl archivo se ha abierto con éxito para lectura.\n";

	int contar = 0; 
	while (docWords >> word) //recorre el archivo
	{
		if ( contar == nWord ) //al llegar a la posicion aleatoria 
		{
			break; //deja de recorrer el archivo
		}

		contar++;
	}

	trueWord = word; //fija palabra seleccionada 
	currWord = word; //copia para mostrar al usuario

	//modifica string para registrar el avance del usuario
	currWord.replace( currWord.begin(), currWord.end(), currWord.length(), '_');
}

//funcion para evaluar si acerto adivinando
bool Ahorcado::gessWord( string inWord )
{
	if ( inWord.length() == trueWord.length())
	{
		// comparar palabras completas
		if (trueWord.compare(inWord) == 0)
		{
			//acierta la palabra completa 
			currWord = trueWord;
			return true;
		}
		else
		{
			//se equivoca
			nError++; //suma al contador de errores
			return false;
		}
	}
	else if ( inWord.length() == 1 )
	{
		// evaluar letras individuales
		size_t found  = trueWord.find(inWord); //busca letra ingresada en la palabra 
		int contL = 0;
		int pt = 0; //contador de aciertos

		while ( contL == 0 )
		{
			if (found == string::npos)
			{
				//no hay más coincidencias
				//cout << "interrupt" << endl;
				contL = 1;
			}
			else
			{
				//hay alguna coincidencia
				currWord.replace(found, 1, inWord); //muestra acierto
				pt++; //suma acierto
				found = trueWord.find(inWord, found+1); //busca otra coincidencia
			}
		}

		if ( pt > 0)
		{
			//acertó en alguna letra
			return true;
		}
		else
		{
			//no acertó ninguna letra
			nError++; //suma al contador de errores
			return false;
		}
		
	}
	else
	{
		// pierde inmediatamente 
		nError = 7; //error máximo
		return false;
	}

}

//funcion que corre todo el juego 
void Ahorcado::toPlay( void )
{
	nError = 0; //inicializa el número de errores
	getWord(); //inicializa las palabras

	string userW; //string que ingresa el usuario
	bool userA; 
	char at;

	while ( nError >=0 && nError < 7 )
	{
		//mientras tenga intentos corre el juego
		showHanged();
		cout << "\nIngrese la letra/palabra que cree es correcta ٩(͡๏̯͡๏)۶ \n" << endl;
		cin >> userW; 

		userA = gessWord(userW); //evalua letra/palabra ingresada por el usuario

		if (userA) //aciertos
		{
			cout << "\nUsted acertó (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧\n" << endl;

			if ( trueWord.compare(currWord) == 0) //si tiene la palabra completa
			{
				//gana y pregunta si desea volver a jugar
				showMessage( true ); 
				cout << "¿Desea volver a jugar? (y/n) " << endl;
				cin >> at;
				continueGame(at);
				break;
			}
		}
		else //errores
		{
			cout << "\nSe ha equivocado (ｏ・_・)ノ”(ᴗ_ ᴗ。) \n" << endl;
		}
	}

	if (nError == 7 ) //si número de errores es máximo
	{
		//pierde y pregunta si desea volver a jugar
		showMessage( false );
		cout << "¿Desea volver a jugar? (y/n)" << endl;
		cin >> at;
		continueGame(at);
	}
}

//funcion que reinicia o finaliza el juego 
void Ahorcado::continueGame( char aa2 )
{
	// Se despide del usuario si no quiere jugar más
	if( aa2 == 'n')
	{
		cout << "Se ha terminado el juego (╥_╥)" << endl;
		cout << "Esperamos vuelva pronto" << endl;
	}
	// Reinicia el juego 
	else if( aa2 == 'y')
	{
		cout << "¡ESO! Sigamos jugando ｡◕‿◕｡" << endl;
		toPlay();
	}
}

//despliegue de mensajes si el usuario gana o pierde
void Ahorcado::showMessage( bool asw ) const
{
	if (asw)
	{
		cout << "\nPalabra: " << trueWord << "\n" << endl;
		cout << " " << endl;
		cout << "/\\_/\\                " << endl;
		cout << "(=' ᴗ' )     ¡GANASTE! " << endl;
		cout << "(, ('') ('')           " << endl;		
	}
	else
	{
		cout << "\nPalabra: " << trueWord << "\n" << endl;
		cout << " " << endl; 
		cout << "{\\__/}                 " << endl;
		cout << "( 0 -0)      ¡PERDISTE! " << endl;
		cout << "|¬    |¬                " << endl;
	}
}

//despliegue de ilustraciones del ahorcado
void Ahorcado::showHanged( void ) const
{
	if ( nError == 0)
	{
		cout << " " << endl; 
   		cout <<"   +----+  "<< endl; 
   		cout <<"   |       "<< endl; 
   		cout <<"   |       "<< endl; 
   		cout <<"   |       "<< endl; 
   		cout <<"   |       "<< endl; 
   		cout <<"   |       "<< endl; 
   		cout <<"  =============" << endl; 

   		cout << setw(30) << currWord << endl;
	}

	else if ( nError == 1)
	{
		cout << " " << endl; 
   		cout <<"   +----+  " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |    O  " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"  =============" << endl; 

   		cout << setw(30) << currWord << endl;
	}

	else if ( nError == 2)
	{
		cout << " " << endl; 
   		cout <<"   +----+  " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |    O  " << endl; 
   		cout <<"   |    |  " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"  =============" << endl; 

   		cout << setw(30) << currWord << endl;
	}

	else if ( nError == 3)
	{
		cout << " " << endl; 
   		cout <<"   +----+  " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |    O  " << endl; 
   		cout <<"   |   /|  " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"   |       " << endl; 
   		cout <<"  =============" << endl;

   		cout << setw(30) << currWord << endl; 
	}

	else if ( nError == 4)
	{
		cout << " " << endl; 
   		cout <<"   +----+   " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"   |    O   " << endl; 
   		cout <<"   |   /|\\ " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"  =============" << endl; 

   		cout << setw(30) << currWord << endl;
	}

	else if ( nError == 5)
	{
		cout << " " << endl; 
   		cout <<"   +----+   " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"   |    O   " << endl; 
   		cout <<"   |   /|\\ " << endl; 
   		cout <<"   |   /    " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"  =============" << endl;

   		cout << setw(30) << currWord << endl;
	}

	else if ( nError == 6)
	{
		cout << " " << endl; 
   		cout <<"   +----+   " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"   |    O   " << endl; 
   		cout <<"   |   /|\\ " << endl; 
   		cout <<"   |   / \\ " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"  =============" << endl; 

   		cout << setw(30) << currWord << endl;
	}

	else if ( nError == 7)
	{
		cout << " " << endl; 
   		cout <<"   +----+   " << endl; 
   		cout <<"   |    |   " << endl; 
   		cout <<"   |    O   " << endl; 
   		cout <<"   |   /|\\ " << endl; 
   		cout <<"   |   / \\ " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"  =============" << endl; 

   		cout << setw(30) << currWord << endl;
	}
}

