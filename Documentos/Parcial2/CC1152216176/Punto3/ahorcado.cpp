#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include "ahorcado.h"
#include<string>

using namespace std;

//Constructor Ahorcado
Ahorcado::Ahorcado()
{
}

//Funcion para seleccionar una palabra aleatoria del texto
void Ahorcado::selecPal(string archivo)
{
	//abrir archivo
	ifstream lista_palabras(archivo.c_str());

	//comprobar que el archivo existe
	if (lista_palabras.fail())
	{
		cout << "El archivo " << archivo 
		<< " no se encuentra disponible por favor compruebe que el archivo se encuentra en la direccion correcta\n" << endl;
		exit(1);
	}

	//se genera un numero aleatorio entre 1 y el numero de palabras que tenga el documento
	srand(time(NULL));
	int selector = rand() % 10;

	//el documento tendra una palabra por linea por lo que se almacena la palabra dada por el selector en el string palabra 
	for (int i = 0; i < selector; i++)
	{
		getline(lista_palabras,palabra);
	}

	//definir el string compuesto de asteriscos
	int longitud = palabra.length();
	string a(longitud,'*');

	palabra_ = a;
}

//Funcion para correr el juego, retorna un entero que define en el main si el juego sigue o no
int Ahorcado::jugar(int i, string archivo)
{
	//se definen los objetos necesarios
	intentos = i;
	int adivinar = 0;
	int longitud = palabra.length();
	char letra;
	string guess;

	//se ingresa la letra que se estima correcta
	cout
	<< "Adivine la palabra: " << palabra_ << "\n\n"
	<< "¿Que letra cree que pertenece a la palabra?\n";

	cin >> letra;

	//si la letra que se adivina se encuentra en la palabra
	if(palabra.find(letra) < palabra.length())
	{
		//se cambia el string de asteriscos para mostrar donde estan las letras adivinadas
		for (int i = 0; i < longitud; i++)
		{
			if (i == palabra.find(letra))
			{
				palabra_[i] = letra;
			}
		}
		//si la letra que se adivina es la ultima se termina el juego
		if (palabra_ == palabra)
		{
			cout << "Felicitaciones usted a ganado\n\n¿Desea jugar nuevamente?\n1. si\n2. no\n";
			cin >> adivinar;

			intentos = 7;
			selecPal(archivo);

			return adivinar;
		}
		//si la letra no es la ultima se da la opcion de adivinar la palabra
		else
		{
			cout
			<< "Felicidades la letra " << letra << " se encuentra en la palabra\n\n"
			<< "¿Desea adivinar la palabra? " << palabra_ << "\n1. Si\n2. no\n";
			cin >> adivinar;
			cout << "\n";

			if (adivinar == 1)
			{
				cout << "Ingrese la palabra que considera correcta: ";
				cin >> guess;
				//si se acierta la palabra completa se termina el juego, se reinician los intentos y selecciona otra palabra
				if (guess == palabra)
				{
					cout << "Felicitaciones usted a ganado\n\n¿Desea jugar nuevamente?\n1. si\n2. no\n";
					cin >> adivinar;

					intentos = 7;
					selecPal(archivo);

					return adivinar;
				}
				//si no se acierta se pierde un intento y retorna un 1 para seguir jugando
				else
				{
					cout << "Lo sentimos palabra incorrecta\n";

					intentos--;

					cout << "Aun le quedan " << intentos << " intentos";

					return 1;
				}
			}
		}
	}
	//si la letra no se adivina se pierde un intento y retorna un 1 para seguir jugando
	else
	{
		cout << "Lo sentimos letra incorrecta\n";
		
		intentos--;

		cout << "Aun le quedan " << intentos << " intentos";

		return 1;
	}
}

//Funcion para obtener el numero de intentos
int Ahorcado::getIntentos()
{
	return intentos;
}
