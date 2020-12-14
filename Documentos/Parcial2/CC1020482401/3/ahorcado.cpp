#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>  
#include <fstream>

#define WORDS_PATH "palabras.txt" // archivo que contiene las palabras para jugar


using namespace std;


//===== metodos y funciones =====
void escoger_palabra(int *);
void jugar(void);
int turno(int *, string *);
int numero_de_letras(void);
void mostrar_palabra_parcial(string);
void render(int*, string*);
void presentar(void);
void dibujar(int);

//===== la palabra para jugar ====
string palabra;



int main(int argc, char const *argv[])
{
	int play = 1; // centinela para fin del juego
	int nivel; // dificultad de la palabra 

	srand(time(NULL));

	while(play != -1){
		system("clear");
		presentar();
		cout << "Bienvenido jugador,";
		cout << "selecciona la dificultad para continuar: \n" << endl;
		cout << "1. Facil" << endl;
		cout << "2. Medio" << endl;
		cout << "3. Dificil" << endl;
		cout << "4. exit" << endl;
		cin >> nivel;
	
		if(nivel == 4) break ; // terminacion voluntaria

		escoger_palabra(&nivel); // selecciona la palabra
		jugar(); // comienza el ciclo del juego

		cout << "Bien jugado! Presiona cualquier tecla para volver a jugar o -1 para salir" << endl; //reinicio o termincion voluntaria
		cin >> play;
	}

	return 0;
}


//=========================== Metodos para la dinamica del juego ===========================

//escoger_palabra -> seleciona aleatoriamente una 
//					 palabra del archivo WORDS_PAHT 
//					 para iniciar el juego
// jugar -> controla el  desarrollo del juego segun
// 			adivine o no letras en cada turno
// turno -> determina si el usuario adivina o no las
// 			letras en cada intento, no puede fallar mas
// 			de 7 veces.


void escoger_palabra(int *nivel){

	vector <string> lista_palabras; // para cargar las palabras segun la dificultad
	string palabra_aux; // para ir leyendo las palabras del archivo
	ifstream archivo_palabras(WORDS_PATH);

	if (archivo_palabras.fail()){
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    while(archivo_palabras >> palabra_aux){
    	
    	switch(*nivel){
    		case 1:// dificultad 1 : menos de 7 letras
    			if (palabra_aux.length() <= 7 ) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    		case 2:// dificultad 2 : entre 7 y 11 letras
    			if (palabra_aux.length() > 7  && palabra_aux.length() <= 11) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    		case 3:// dificultad 3 : mas de 11 letras
    			if (palabra_aux.length() > 11 ) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    		default:// por defecto dificultad 1
    			if (palabra_aux.length() <= 7 ) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    	}
    }

    int i = rand() % lista_palabras.size(); 

    palabra = lista_palabras.at(i); // escoge la palabra al azar
}

//===============================================================================

void jugar(void){ // ciclo de juego

	int intento = 0; // numero de fallos 
	int numero_de_letras_restantes = numero_de_letras(); // numero de letras diferentes en la palabra
	bool winner = false; // estado del jugador
	string letras_adivinadas = " "; 

	while(1){ // mientras no gane o pierda

		// cada turno pide una letra y determina si adivino o no
		numero_de_letras_restantes += turno(&intento, &letras_adivinadas); 
		
		if(intento == 7){ // si completa el ahorcado pierde
			render(&intento, &letras_adivinadas);
			break;
		} 

		if (numero_de_letras_restantes <= 0){ // si adivina todas las letras gana
			winner = true;
			break;
		}
	}

	if(winner){ //mensaje de ganador
		intento = -1;
		render(&intento, &letras_adivinadas);
		cout << "FELICITACIONES USTED GANO" << endl;	
	}
	else{ // mensaje de perdedor
		cout << "YA SE MURIO, la palabra era: " << palabra << endl;
		cout << "MEJOR SUERTE PARA LA PROXIMA." << endl; 
	}

}

//===============================================================================

int turno(int *intento, string *letras_adivinadas){
	string letra;
	char arriesgar;
	string palabra_aux;

	render(intento, letras_adivinadas); // muestra el estado de la partida

	cout << "\nLetra: "; 
	cin >> letra;


	if (palabra.find(letra) != string::npos){ 
		// si adivino la letra la guarda y resta uno al numero de letras faltantes
		letras_adivinadas->append(letra);

		render(intento, letras_adivinadas);
		// oportunidad de adivinar
		cout << "\nAcerto! desea arriesgarse a adivinar la palabra completa ? (y/n)" << endl;
		cin >> arriesgar;

		if (arriesgar == 'y'){
			// si adivina la palabra Gana, sino
			// le suma un fallo y descuenta una letra restante
			cout << "Palabra: " ;
			cin >> palabra_aux;

			if (palabra_aux == palabra){
				*letras_adivinadas = palabra;
				return -1 * palabra.length();
			}
			else{
				cout << "Fallo!" << endl;
				*intento += 1; 
			}
		}
		
		else return -1;
	}

	else *intento += 1; // si no adivina le suma un fallo

	return 0;

}


//================================= Metodos utilitarios ===================================

// numero_de_letras -> determina cuantas letras distintas tiene 
// 					   la palabra en cada partida para controlar 
// 					   cuando gana
// 					   
// mostrar_palabra_parcial -> muestra parcialmente la palabra 
// 							  chequeando cuales se han adivinado ya
// 
// render -> muestra el estado de la partida, tanto el avance del
// 			 ahorcado como lo intentos y las letras adivinadas
// 			
// dibujar -> dibuja en pantalla el avance del ahorcado segun los fallos
// 
// presentar -> muestra el arreglo de caracteres que forma el nombre del juego


int numero_de_letras(void){
	// Esta funcion cuenta las letras distintas 
	// que tiene la palabra

	int contador = 0; // numero de letras distintas
	int k = 0; // comienza por la primer letra
	int i;
	string palabra_aux = palabra; 
	string letra;
	
	while(k != string::npos){

		contador++; // cada ciclo de k es una letra distinta entonces se suma 1
		
		letra = palabra_aux[k];
		palabra_aux.replace(k, 1, "."); // se eliminan las letras repetidas para no sobrecontar

		i = palabra_aux.find(letra);

		while(i != string::npos){
			palabra_aux.replace(i, 1, ".");
			i = palabra_aux.find(letra);
		}

		k = palabra_aux.find_first_not_of("."); //se mira si quedan mas letras que tener en cuenta
	}

	return contador;
}

//===============================================================================

void mostrar_palabra_parcial(string letras_adivinadas){
	// Esta funcion muestra parcialmente la palabra segun
	// las letras que ya se hayan adivinado
	
	string palabra_aux(palabra.length(), '-'); // se rellena la palabra con -

	int i = palabra.find_first_of(letras_adivinadas);

	while(i != string::npos){ // si adivina alguna palabra se muestra en que ubicacion estan
		palabra_aux.replace(i, 1, string(1,palabra[i]));
		i = palabra.find_first_of(letras_adivinadas, i + 1);
	}

	cout << palabra_aux;
}

//===============================================================================

void render(int *intento, string *letras_adivinadas){
	// muestra en pantalla el estado de la partida 
	system("clear");
	presentar();
	cout << "intento: " << *intento <<endl;
	cout << "Palabra: " ;
	mostrar_palabra_parcial(*letras_adivinadas);
	cout << "\n" << endl;
	dibujar(*intento);

}

//===============================================================================

void dibujar(int intento){ // dibujos del ahorcado segun los fallos que tenga
    switch (intento){
	    case 0:
	        cout << "__________\n|         |\n|\n|\n|\n|\n|\n|";
	        break;
	    case 1:
	        cout << "__________\n|         |\n|         0\n|\n|\n|\n|\n|";
	        break;
	    case 2:
	        cout << "__________\n|         |\n|         0\n|         |\n|\n|\n|\n|";
	        break;
	    case 3:
	        cout << "__________\n|         |\n|         0\n|         |\n|         |\n|\n|\n|";
	        break;
	    case 4:
	        cout << "__________\n|         |\n|         0\n|        /|\n|         |\n|\n|\n|";
	        break;
	    case 5:
	        cout << "__________\n|         |\n|         0\n|        /|\\\n|         |\n|\n|\n|";
	        break;
	    case 6:
	        cout << "__________\n|         |\n|         0\n|        /|\\\n|         |\n|        /\n|\n|";
	        break;
	    case 7: // PERDEDOR
	        cout << " _________\n|         |\n|         0\n|        /|\\\n|         |\n|        / \\\n|\n|\n";
	        break;
	    case -1: //GANADOR
	        cout << "__________\n|         |\n|         \n|      0\n|     \\|/\n|      |\n|     / \\\n";
	        break;
	    default:
	    	break;
    }
    cout << endl;
}

//===============================================================================

void presentar(){
	cout << R"(
	                 8888888888 888
	                 888        888                     __________
	                 888        888                    |         |
	                 8888888    888                    |         0
	                 888        888                    |        /|\
	                 888        888                    |        / \
	                 888        888                    |
	                 8888888888 888                    |



	                          888                                             888
	                          888                                             888
	                          888                                             888
	                  8888b.  88888b.   .d88b.  888d888 .d8888b  8888b.   .d88888  .d88b.
	                     "88b 888 "88b d88""88b 888P"  d88P"        "88b d88" 888 d88""88b
	                 .d888888 888  888 888  888 888    888      .d888888 888  888 888  888
	                 888  888 888  888 Y88..88P 888    Y88b.    888  888 Y88b 888 Y88..88P
	                 "Y888888 888  888  "Y88P"  888     "Y8888P" Y888888  "Y88888  "Y88P"
	    )" << endl;//'\n';
}