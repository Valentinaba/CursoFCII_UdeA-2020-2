/**
 * @brief Punto 3 - parcial 2: Juego del "ahorcado"
 * @author Santiago Duque
 */

#include <iostream>
#include <string>
#include "game.h"

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;


int main()
{
    string option;
    Game game;
    
    for(;;)
    {
        cout << endl;
        cout << "Juego del ahorcado" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1) Jugar nueva partida" << endl;
        cout << "2) Salir" << endl;

        getline(cin,option);
        switch(option[0])
        {
        case '1':
            game.newGame();
            break;
        case '2':
            cout << "Vuelve pronto" << endl;
            return 0; // finalizar el programa
        default:
            cout << "Opcion invalida" << endl;
        }
    }
    return 0; //Núnca debería llegar hasta este punto
}
