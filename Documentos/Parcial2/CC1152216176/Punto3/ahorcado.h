#ifndef AHORCADO_H
#define AHORCADO_H

#include<string>

using namespace std;

class Ahorcado
{

	public:
	//constructor
	Ahorcado();

	//funciones
	void selecPal(string);
	int jugar(int, string);
	int getIntentos();

	private:
	int intentos;
	string archivo;
	string palabra;
	string palabra_;
  
};

#endif
