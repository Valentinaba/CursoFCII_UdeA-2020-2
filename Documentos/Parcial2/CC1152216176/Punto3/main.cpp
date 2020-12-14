#include <iostream>
#include <iomanip>
#include<string>
#include "ahorcado.h"

using namespace std;

int main()
{
	//creacion de objetos
	Ahorcado juego1;
	int continuar = 1;
	int intentos = 7;
	int menu;
	string palabras = "palabras.txt";

	juego1.selecPal(palabras);

	//Mensaje inicial
	cout
	<< "Bienbenido al juego del ahorcado\n"
	<< "--------------------------------\n"
	<< "               0                \n"
	<< "              /|\\               \n"
	<< "               |                \n"
	<< "              / \\               \n"
	<< "--------------------------------\n";
	//Menu
	cout
	<< ".....seleccione una opcion......\n\n"
	<< "1. Jugar\n2. Reglas\n3. Salir\n";
	cin >> menu;

	//Ciclo para jugas hasta que se desee salir del juego
	while (continuar == 1)
	{
		//opcion si se desea jugar
		if (menu == 1)
		{
			//si no quedan intentos se escoje otra palabra y se reinician los intentos
			if (intentos <= 0)
			{
				cout << "Lo sentimos se ha quedado sin intentos\n\n¿Desea jugar nuevamente?\n1. si\n2. no\n";
				cin >> continuar;

				intentos = 7;

				juego1.selecPal(palabras);
			}
			//si aun quedan intentos se aplica la funcion jugar del objeto y se actualizan los intentos despues de cada ronda
			else
			{
				continuar = juego1.jugar(intentos,palabras);
				intentos = juego1.getIntentos();
			}
		}
		//opcion si se desean leer las instrucciones
		else if (menu == 2)
		{
			cout << "Reglas: En pantalla aparecera el mensaje 'Adivine la palabra: *****' cada * representa una letra de la palabra a adivinar, cada turno se puede adivinar una letra de la palabra. Si la letra pertenece a la palabra se puede adivinar la palabra completa o pasar al siguiente turno para adivinar otra letra. despues de 7 intentos incorrectos (ya sea al adivinar la letra o la palabra) se pierde el juego.\n";
			cout << "1. Jugar\n2. Reglas\n3. Salir\n";
			cin >> menu;
		}
		//salir del juego
		else if (menu == 3)
		{
			return false;
		}
		//si se ingresa un valor invalido en el menu
		else
		{
			cout << "Por favor ingrse un valor valido\n";
			cout << "1. Jugar\n2. Reglas\n3. Salir\n";
			cin >> menu;
		}

	}

	return 0;
}
