/**
 * @brief Se prueba la clase JuegoAhorcado
 * @author Valentina Roquemen Echeverry
 */
#include <iostream>
#include <fstream>

using namespace std;
#include "ahorcado.h" 

int main()
{
  string nombre_archivo = "palabras.txt"; // Nombre del archivo con las palabras para jugar

  // Se revisa si el archivo existe 
  /*-------------------------------*/
  ifstream archivo_entr(nombre_archivo.c_str());
  
  if(archivo_entr.fail())
  {
    cout << "El archivo no existe"<< endl;
    exit(1);
  }
  /*-------------------------------*/

  JuegoAhorcado myGame(archivo_entr);

  myGame.mainMenu(); // Se empieza el juego

  return 0; 
}