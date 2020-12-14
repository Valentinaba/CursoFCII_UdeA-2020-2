#include"ahorcado.h"

int numPalabras( string nombre_archivo ){
  int num_palabras = 0;
  string dummy;
  
  ifstream archivo_palabras( nombre_archivo );
  if( archivo_palabras.fail() ){
    cout << "No se encontro el archivo de palabras";
    archivo_palabras.close();
    return 0;
  }

  while( getline( archivo_palabras , dummy ) ){
    num_palabras++;
  }

  archivo_palabras.close();
  return num_palabras - 1; // Descontando la linea final
  
}

string leerPalabra( string nombre_archivo ){
  string palabra; // Palabra que devuelve la funcion 
  int indice, num_linea = 0; // Indice aleatorio para seleccionar la palabra para jugar y contador de lineas

  srand(time(NULL));
  indice = rand () % numPalabras( nombre_archivo );
    
  ifstream archivo_palabras( nombre_archivo );
  if( archivo_palabras.fail() ){
    cout << "No se encontro el archivo de palabras";
    archivo_palabras.close();
    return "\n";
  }
  
  while( getline( archivo_palabras , palabra ) ){ // Las palabras deben estar separadas por \n
    num_linea++;

    if( num_linea == indice ){

      archivo_palabras.close();
      return palabra;
      
    }
  }

  archivo_palabras.close();
  return "\n"; // Por si las moscas
}

bool jugar( string nombre_archivo ){

  int intentos = 0; // Numero de intentos fallidos
  
  string palabra = leerPalabra( nombre_archivo );
  transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper); // Convertimos la palabra en mayuscula

  string x =  string( palabra.length() , '_' );

  cout << "Bienvenido a ahorcado! :)\nUsted tiene 7 intentos para adivinar la siguiente palabra:\n";

  while( intentos < 7 ){
    char letra; // Letra a intentar
    int pos; // Posicion de la letra en la palabra
    string intentar; // y/n para saber si se quiere intentar adivinar la palabra
    string intento_palabra = "\n"; // Palabra a intentar 

    cout << x << "\n";
    cout << "Ingrese una letra: ";
    cin >> letra;
    cout << "\n";
    letra = toupper(letra); // Convertimos todo en mayuscula
    pos = palabra.find( letra );

    if( pos == string::npos){
      intentos++;
      cout << "Esa letra no se encuentra en la palabra :(\n";
      print( 'f' , intentos);
    }
    else{
      cout << "Acertaste!\n";
      
      while( pos != string::npos ){
	x.replace( pos , 1 , string( 1, letra ) );
	pos = palabra.find( string( 1, letra ) , pos+1 );
      }

      cout << x << "\n";
      
      if( x == palabra ){
	cout << "Adivinaste la palabra: " << x << "!\nToma este dolar:\n";
	print( 'd' , 0);
	return true;
      }

      cout << "Desea intentar adivinar la palabra? (y)\n";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.clear();
      getline( cin , intentar );
      transform( intentar.begin() , intentar.end() , intentar.begin() , ::toupper);
      if( intentar == string( 1 , 'Y' ) ){
	cout << "Ingrese la palabra:\n";
	cin >> intento_palabra;
	transform( intento_palabra.begin() , intento_palabra.end() , intento_palabra.begin() , ::toupper); // Convertimos todo en mayuscula
	if( intento_palabra == palabra ){
	  cout << "Adivinaste la palabra: " << palabra << "!\nToma este dolar:\n";
	  print( 'd' , 0 );
          return true;
	}
	else{
	  cout << "Que gueva\n";
	  intentos++;
	  print( 'f' , intentos );
	}
      }
    }
  }
  
  cout << "Perdiste jaja\n";
  return false;
}

void print( char opcion , int intentos ){
  if( opcion == 'd' ){
    cout << R"(
||====================================================================||
||//$\\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//$\\||
||(100)==================| FEDERAL RESERVE NOTE |================(100)||
||\\$//        ~         '------========--------'                \\$//||
||<< /        /$\              // ____ \\                         \ >>||
||>>|  12    //L\\            // ///..) \\         L38036133B   12 |<<||
||<<|        \\ //           || <||  >\  ||                        |>>||
||>>|         \$/            ||  $$ --/  ||        One Hundred     |<<||
||<<|      L38036133B        *\\  |\_/  //* series                 |>>||
||>>|  12                     *\\/___\_//*   1989                  |<<||
||<<\      Treasurer     ______/Franklin\________     Secretary 12 />>||
||//$\                 ~|UNITED STATES OF AMERICA|~               /$\\||
||(100)===================  ONE HUNDRED DOLLARS =================(100)||
||\\$//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\$//||
||====================================================================||
)" << "\n";
  }
  else if( opcion == 'f' ){
    cout << R"(
   |/|
   | |
   |/|
   | |
   |/|
  (___)
  (___)
  (___)
  (___)
  (___)
  // \\
 //   \\
||     ||
||     ||
||     ||
 \\___//
  -----
)" << "\n";
    cout << "Usted lleva " << intentos << " de 7 intentos fallidos\n\n";
  }
}
