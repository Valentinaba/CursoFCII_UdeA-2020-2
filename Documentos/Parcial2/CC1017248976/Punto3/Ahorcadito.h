#include <string>
#include <vector>
//leer datos de un archivo
#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <algorithm>
 

using std::rand;
using std::setw;
using namespace std;

#ifndef AHORCADITO_H
#define AHORCADITO_H

// definición de la clase Ahorcadito
class AhorcaditoGame
{
 public:
  AhorcaditoGame(); // constructor predeterminado
  void play(); //Funcion para jugar
  
 private:
  //declaración variables relevantes
    string word; //este string guarda la informacion de la palabra selesccionada del archivo de texto
    string comword; // este tring guarda las modificaciones que se hacen en el string word
    ifstream list;
    int Rnum;//random number
    int lives;//vidas del jugador
    bool cont;// el juego funciona mientras sea true
//Funciones privadas
    string GetWord(int);// Selecciona la palabra aleatoriamente del archivo de text
    void Welcome(); // Da la bienvenida 
    //void Rules(); // funcion para hacer mostrar las reglas 
    int RandomNumber(); //funcion para generar numeros aleatorios
    string ToX(string); //funcion que cambias las letras por x
    void Turn(); //funcion turno
    int FindLetter(char);//funcion para ver si la letra ingresada esta en la palabra
    string Lower(string); //funcion para pasar un string a minusculas
    void Man(int); //Funcion que muestra al man
  
};

#endif
