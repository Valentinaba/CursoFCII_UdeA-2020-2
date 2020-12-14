/*
Prototipo de la clase ahorcado
*/

#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>

using namespace std;

class Ahorcado
{
public:
	Ahorcado( void ); //constructor 
	void initGame( void ) const; //mensaje inicial
	void getWord( void ); //obtiene palabra para jugar
	bool gessWord( string ); //evalúa si acierta
	void showMessage( bool ) const; //mensaje de ganar o perder
	void showHanged( void ) const; //muestra el ahorcado

	void toPlay( void ); //estructura todo el juego
	void continueGame( char ); //sigue jugando?

private:
	string trueWord; //palabra que debe adivinar
	string currWord; //progreso del usuario
	int nError;  //numero de errores 

};

#endif