#include "game.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;
using std::ifstream;
using std::getline;


/* 
 * Namespace anónimo para aislar las variables que contiene 
 * del resto del código
 */
namespace
{
    /* Imagen por defecto */
    const string imgDefault[] = { 
                                    "|-¬",
                                    "| ", 
                                    "| ",
                                    "| ",
                                    "| ",
                                    "|____"
                                };

    const string FILE_NAME = "list.txt";
}

/* Inicialización de la variable static*/
bool Game::isSeedInit = false;

Game::Game(): img(vector<string>(6))
{
    /* Inicializar la semilla */
    if(!isSeedInit)
    {
        srand(time(NULL));
    }
}

void Game::newGame()
{
    errorcnt = 0;

    /* Inicializar la imagen */
    for(int i=0; i<img.size(); ++i)
        img[i] = imgDefault[i];

    readWord(); //seleccionarla palabra que se va a adivinar
    tryWord = string(word.length(),'*'); //Inicializar con asteríscos 

    printImg(); //Imprimir la imagen inicial
    string temp;

    do
    {
        cout << "Ingerese una letra o la palabra completa: ";
        getline(std::cin,temp);

        if( temp == word)
            /* 
             * Perdón a los puristas, en este caso (este y los 
             * loops anidados de más adelante) es más claro terminar
             * el juego con un goto :)
             */
            goto end_game;

        /* Buscar si el carácter ingresado pertenece a la palabra */
        std::size_t pos = word.find(temp[0], 0);
        if( pos == string::npos || temp.length() > 1 )
            error();
        else
        {
            /* Buscar todas las coincidencias */
            do
            {
                tryWord[pos] = word[pos];

                if(tryWord == word)
                    goto end_game;

            }while((pos = word.find(temp[0], pos+1)) != string::npos);
        }

        printImg(); // Refrescar la imagen

    }while(errorcnt < 7);

end_game:
    if(errorcnt >= 7)
    {
        cout << "Lastima, perdiste el juego :(" << endl;
        cout << "La palabra correcta era: " << word << endl;
    }
    else
        cout << "¡Felicidades! ganaste el juego" << endl;
    
}


int Game::error()
{    
    const int line[]        =  { 1  , 2 ,  2,  2 ,   3,  4,   4};
    const char *select_char[]= {" o","/","|","\\"," |","/"," \\"};

    img[line[errorcnt]] += (select_char[errorcnt]);
    return ++errorcnt;
}

void Game::printImg()
{
    //TODO: Limpiar la pantalla
    for(int i=0; i<6; ++i)
        cout << img[i] << endl;
    cout <<  tryWord << endl;
}

void Game::readWord()
{
    ifstream file;    
    file.open(FILE_NAME);

    if(file.fail())
        throw FILE_NAME;

    /*leer todas las palabras del archivo*/
    vector<string> line;
    string temp;
    while(getline(file,temp))
        line.push_back(temp);

    /* Seleccionar una palabra al azar */
    if(line.size() == 0)
        throw "No existe ninguna palabra que adivinar en el archivo " + FILE_NAME;
    word = line[ rand() % line.size() ]; // line[0] hasta line[line.size() -1]

    file.close();
}