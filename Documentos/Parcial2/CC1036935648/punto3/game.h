#include <string>
#include <vector>

using std::string;
using std::vector;

class Game
{
public:
  Game();
  void newGame();

private:
  static bool isSeedInit; // Se usa para inicializar la semilla de los vaoler aleatorio una única vez
  int errorcnt = 0; //Contador de errores
  vector<string> img; //Vector de string que representará la imagen
  string word; //Palabra que el jugador trata de adivinar
  string tryWord; //cadena con los caracteres que han sido adivinados
  int error();
  void printImg(); //Imprime a imagen y el estado actual de la palabra
  void readWord(); //Lee la palabra a adivinar desde un documento de texto
};