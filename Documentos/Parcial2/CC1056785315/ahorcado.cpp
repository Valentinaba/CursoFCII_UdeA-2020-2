#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int main()
{
  string opcion = "1"; //Para opciones de respuesta del usuario
  
  string nombre_archivo = "palabras.txt";
  int cantidad_palabras = 6;
  string palabras[cantidad_palabras] = {""};

  //Para comparar la letra del usuario con cada letra de la palabra aleatoria
  string adivinar, letra2;
  char letra;
  
  bool atino_letra, falta_letra;
  int fallidos;
  string palabra_guess;
  string formando_palabra; //La palabra que va adivinando el usuario
  
  fstream archivo_palabras(nombre_archivo.c_str(), ios::in);

  if (archivo_palabras.fail())
    {
      cout << "\nEl archivo no se pudo abrir. Verifique si existe." << endl;
      exit(1);
    }

  int i = 0; //Indice para recorrer el arreglo de palabras

  //Se leen y guardan en un arreglo las primeras n (cantidad_palabras) palabras del archivo
  //Si el archivo tiene menos de n palabras, se guardan todas
  
  while (archivo_palabras.good() and i < cantidad_palabras)
    {
      archivo_palabras >> palabras[i]; //Se guarda cada palabra
      i++;
    }

  int j;

  //Ciclo para saber cuantas palabras se guardaron. Queda registrado en j
  //Por si el archivo tenia menos de n palabras
  
  for (j=0; j<cantidad_palabras; j++)
    {
      if (palabras[j] == "")
	{
	  break;
	}
    }

  srand(time(NULL));

  //Ciclo de juego
  while (opcion == "1")
    {
      cout << "JUEGUE AL AHORCADO\n" << endl;
      
      adivinar = palabras[rand()%j]; //Se escoge aleatoriamente la palabra
      formando_palabra = "";
      fallidos = 0; //Lleva la cuenta de los intentos fallidos

      cout << "Adivine la palabra: ";

      //Ciclo para mostrar cuantas letras tiene la palabra a adivinar
      for (int k=0; k<adivinar.size(); k++)
	{
	  formando_palabra += "-";
	}

      cout << formando_palabra << endl;

      //Ciclo para intentar adivinar la palabra
      while (fallidos < 7)
	{
	  cout << "\nIngrese letra (en minuscula): ";
	  cin >> letra;
	  cout << "\n                    ";

	  //Booleanos para saber si se adivino alguna letra y si quedan letras por adivinar
	  atino_letra = false;
	  falta_letra = false;

	  //Ciclo para poner las letras adivinadas
	  for (int k=0; k<adivinar.size(); k++)
	    {
	      letra2 = adivinar[k];
	      
	      if (letra == *letra2.c_str())
		{
		  formando_palabra[k] = letra;
		  atino_letra = true;
		}
	      
	      else if (formando_palabra[k] == '-')
		{
		  falta_letra = true;
		}
	    }

	  //Lo que se ha formado de la palabra
	  cout << formando_palabra << endl;

	  //Opcion para adivinar la palabra completa si se adivino una letra y faltan mas
	  if (atino_letra and falta_letra)
	    {
	      cout << "\n\nYa que adivino una letra, Quiere adivinar la palabra entera? (Si=1, No=0): " << endl;
	      cin >> opcion;

	      if (opcion == "1")
		{
		  cout << "\nIngrese su palabra (en minusculas): ";
		  cin >> palabra_guess;

		  if (adivinar.compare(palabra_guess) == 0)
		    {
		      cout << "\nEsa era la palabra! HA GANADO!" << endl;
		      break;
		    }

		  else
		    {
		      fallidos++;
		      cout << "\nEsa no es la palabra. Continue adivinando otra letra, le quedan " << (7 - fallidos) << " intentos" << endl;
		    }
		}

	      else // Si no quiere adivinar palabra
		{
		  cout << "\nEntonces adivine otra letra!" << endl;
		}
	    }

	  //En caso de letra incorrecta
	  else if (!atino_letra)
	    {
	      fallidos++;
	      cout << "\n\nLetra incorrecta. Le quedan " << (7 - fallidos) << " intentos!" << endl;
	    }

	  //Si no quedan letras por adivinar, el usuario gano
	  else if (!falta_letra)
	    {
	      cout << "\nCompleto la palabra! HA GANADO!" << endl;
	      break;
	    }
	}

      cout << "\nQuiere volver a jugar? (Si=1, No=0): " << endl;
      cin >> opcion;

      cout << "\n_______________________________________" << endl;
    }

  return 0;
}
