/*Para jugar al ahorcado escriba un programa . El programa debe elegir una palabra (que se
lee de un archivo de texto) y mostrar lo siguiente:
adivine la palabra: xxxxx
cada x representa una letra. El usuario tratara de adivinar las letras en la palabra. Debera
mostrarce la respuesta apropiada (si la letra pertenece o no) despues de cada intento. Si la
letra pertenece a la palabra buscada dele la opotunidad de adivinar si el desea. Despues de
siete intentos incorrectos (ya sean palabra o letras) el usuario sera colgado.
Gane o pierda dele la opcion al usuario de jugar de nuevo.
Nota: Si desea hacer su programa mas grafico, después de cada intento incorrecto, muestre
el diagrama con alguna parte del cuerpo incluida
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>      
#include <sstream>   
#include<bits/stdc++.h> 

using namespace std;

namespace Ahorcado
{

// ######### DECLARACIÓN DE FUNCIONES ############## //

string Palabra( string nombre ); 	//Lee un archivo txt (nombre) y toma una palabra aleatoriamente

void visual(int fallos); 		//Esto es para mostrar muñequito en cada fallo

void ahorcado(string pal); 		//El juego.

//######################################//

string Palabra(string nombre){

	ifstream ArchivoIn(nombre);
	if (ArchivoIn.fail()){
		cout << nombre << " No pudo abrirse, revise si existe."<<endl;
		exit(1);}
	string texto;
	getline(ArchivoIn, texto);
	ArchivoIn.close();

	stringstream test(texto);
	string segment;
	vector<string> lista;

	while(getline(test, segment, ',')){
		lista.push_back(segment);}

	int tamanio = lista.size() - 1;

	srand(time(NULL));
	int num = rand() % tamanio;
	return lista[num];
}

void visual( int fallos ){
string bullet;
if(fallos == 7){ bullet = "....../ `---___________----_____|] - 1 - 2 - 3 - 4 - 5 - 6 - 7 - (✖╭╮✖)";}
else if(fallos == 0){ bullet = "....../ `---___________----_____|] - - ░ ▒▓▓█D                      (•̀ᴗ•́)و ̑̑";}
else if(fallos == 1){ bullet = "....../ `---___________----_____|] - 1 - - - - ░ ▒▓▓█D              (•̀ᴗ•́)و ̑̑";}
else if(fallos == 2){ bullet = "....../ `---___________----_____|] - 1 - 2 - - - -  ░ ▒▓▓█D         (•̀ᴗ•́)و ̑̑";}
else if(fallos == 3){ bullet = "....../ `---___________----_____|] - 1 - 2 - 3 - - - - ░ ▒▓▓█D      (•̀ᴗ•́)و ̑̑";}
else if(fallos == 4){ bullet = "....../ `---___________----_____|] - 1 - 2 - 3 - 4 - - - ░ ▒▓▓█D    (•̀ᴗ•́)و ̑̑";}
else if(fallos == 5){ bullet = "....../ `---___________----_____|] - 1 - 2 - 3 - 4 - 5 - - ░ ▒▓▓█D  (•̀ᴗ•́)و ̑̑";}
else if(fallos == 6){ bullet = "....../ `---___________----_____|] - 1 - 2 - 3 - 4 - 5 - 6 - ░ ▒▓▓█D(•̀ᴗ•́)و ̑̑";}
	
cout<<".....____________________ , ,__"<<endl;
cout<<bullet<<endl;
cout<<"...../_==o;;;;;;;;_______.:/"<<endl;
cout<<".....), ---.(_(__) /"<<endl;
cout<<"....// (..) ), ----"<<endl;
cout<<"...//___//"<<endl;
cout<<"..//___//"<<endl;
cout<<".//___//"<<endl;
}


void ahorcado(string pal){

//cout << "La palabra es: "<< pal <<endl;
string equis = string(pal.length(), 'X');
cout<<"Adivine la palabra: "<< equis << endl;

int fallos = 0;
while(fallos != 7){

string tryletra;
string trypalabra;
cout<<"Ingrese una letra: ";
cin>>tryletra;
int pos = pal.find(tryletra);
char P = 'n';

if ( pos != string::npos){
	char P = 'n';
	while ( pos != string::npos ){
		equis.replace( pos, 1, tryletra );
      		pos = pal.find(tryletra, pos + 1 );}

	cout<< equis <<endl;
	if(equis == pal){cout<<"Ganasteeee"<<endl; 
		break;}

	cout << "Quiere intentar adivinar la palabra? (y o n): ";
	cin >> P;

	if(P == 'y'){
		cout<<"¿Cuál es la palabra? ";
		cin>>trypalabra;
		if(trypalabra == pal){cout<<"Ey mk muy bien, ganaste."<<endl;
			break;}
		else{cout<<"Ajajajaj no, esa no es"<<endl;
			fallos++;
			visual(fallos);}
		     }
			   }

else{fallos++;
	visual(fallos);}
		   }


}

}//Fin namespace
