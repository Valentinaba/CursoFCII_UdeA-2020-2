/**
 * @author Valentina Roquemen Echeverry
 * @brief  La clase JuegoAhorcado programa el juego de Ahorcado
 *         eligiendo la palabra de forma aleatoria de un archivo
 *         de texto que es proporcionado por el usuario.
 */

#include <fstream>
#include <vector>

using namespace std;

class JuegoAhorcado
{
public :

  /**
   * @param file : Puntero al archivo con las palabras para el juego 
   */
  JuegoAhorcado(ifstream& ); 

  /**
   * @brief Obtiene del archivo las palabras para el juego y las almacena en 
            un vector de strings
   * @param file : Puntero al archivo con las palabras para el juego 
   */ 
  void getWords(ifstream&);

  /**
   * @brief Imprime las reglas del juego
   */
  void reglasJuego() const;

  /**
   * @brief Ejecuta el juego
   */  
  void play();

  /**
   * @brief Menu en el que el usario puede decidir jugar, salirse o leer las reglas
   */
  void mainMenu();

private :   

  vector<string> words; // Vector con las posibles palabras para jugar
  string ahorcado_draw[8] = {" "," o "," o \n/"," o \n/|"," o \n/|\\"," o \n/|\\\n | "," o \n/|\\\n | \n/","|¬ o \n|/|\\\n| | \n|/ \\\n|_"}; // Dibujo del ahorcado

};