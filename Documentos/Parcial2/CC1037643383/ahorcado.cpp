#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctime>
using namespace std;

string palabra_original;
string palabra_mostrar;
int vidas;

void mostrar();
void ingresar(char x);
void iniciar();




int main()
{
   srand(time(NULL));
   cout << "Bienvenido al juego del ahorcado" << endl;
   cout << "Usted tendrá 7 oportunidades para adivinar la palabra" << endl;
   cout << "en cualquier momento, si cree conocer la palabra, puede arriesgarse y escribirla entera, tal vez gane o no." << endl;
   bool playing = true;
   while(playing){
     palabra_mostrar="";
       iniciar();
       mostrar();
       
       while(vidas>0 && palabra_mostrar!=palabra_original){
            char x;
            cin>>x;
            ingresar(x);
            mostrar();
       }
        if(vidas>0){
            cout << "¿No será usted acaso un diccionario andante? Ganó" << endl;
        }
        else {
            cout << "Qué lástima, se quedó con la soga al cuello, la palabra era: "<<palabra_original<< endl;
        }

        playing = false;
        cout << "¿Desea continuar jugando?: " << endl;
        cout << "0 para no y 1 para si: " << endl;
        cin >> playing;
    }
}


void mostrar(){
    switch(vidas){
    case 0:
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        break;
    case 1:
        cout << "   O   " << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        break;
    case 2:
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        break;
    case 3:
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << " / | \\ " << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        break;
    case 4:
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << " / | \\ " << endl;
        cout << "   |   " << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        break;
    case 5:
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << " / | \\ " << endl;
        cout << "   |   " << endl;
        cout << "  / \\  " << endl;
        cout << "*******" << endl;
        cout << "*******" << endl;
        break;
    case 6:
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << " / | \\ " << endl;
        cout << "   |   " << endl;
        cout << "  / \\  " << endl;
        cout << " /   \\ " << endl;
        cout << "*******" << endl;
        break;
    case 7:
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << " / | \\ " << endl;
        cout << "   |   " << endl;
        cout << "  / \\  " << endl;
        cout << " /   \\ " << endl;
        cout << "/     \\ " << endl;
        break;
    default:
        break;
    }
    
    cout<<"vidas: "<<vidas<<endl;   
    cout<<palabra_mostrar<<endl;

}


string inicializar_palabra(){
  vector <string> palabras_array;
  string palabra_dummy;  
  ifstream palabras_archivo("palabras.txt");

  if (!palabras_archivo.is_open()){ 
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

  while(!palabras_archivo.eof()){ 
    palabras_archivo >> palabra_dummy;
    palabras_array.push_back(palabra_dummy);
}
  int indice_palabra = rand() % palabras_array.size(); 

  return palabras_array.at(indice_palabra); 
}


void iniciar(){
    vidas= 7;
    palabra_original= inicializar_palabra();

    for(int i=0 ; i<palabra_original.length() ; i++){
        if(palabra_original[i]>='A' && palabra_original[i]<='Z'){
            palabra_original[i]+=32;
        }
    }
    for(int i=0 ; i<palabra_original.length();i++){
      if(palabra_original[i]>='a' && palabra_original[i]<='z'){
        palabra_mostrar+='-';
      }else{
        palabra_mostrar +=palabra_original[i];
      }
    }
}

void ingresar(char x){
 bool perdiVidas=true;

    for(int i=0 ; i<palabra_original.length() ; i++){
        if (x == palabra_original[i]){
            perdiVidas=false;
            palabra_mostrar[i]=x;
        }
    }
    if (perdiVidas) {
            vidas = vidas - 1;
    }
}
