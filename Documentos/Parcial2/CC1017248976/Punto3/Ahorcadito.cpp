#include "Ahorcadito.h"

 

//Inicializacion 
AhorcaditoGame::AhorcaditoGame(){
    srand(time(NULL));
    string word;
    string comword;
    int Rnum=0;
    bool cont = true;
    int lives=7;
}

//Esta funcion da un mensaje de bienvenida al iniciar el juego
void AhorcaditoGame::Welcome(){
    cout<<"     -----------------------------------------------"<<"\n";
    cout<<"     -------------    BIENVENIDO      --------------"<<"\n";
    cout<<"     ---------- AL JUEGO DE AHORCADITO -------------"<<"\n";
    cout<<"     ----- Version el Zoologico de particulas ------"<<"\n";
    cout<<"     -----------------------------------------------"<<"\n";
    cout<<"     ---electron----------up--------------quark-----"<<"\n";
    cout<<"     --------------down---------tau-----------------"<<"\n";
    cout<<"     -----------------------------------------------"<<"\n";
    cout<<"     ----                _____         axion    ----"<<"\n";
    cout<<"     ----     axino      |   |                  ----"<<"\n";
    cout<<"     ----                |   o/                 ----"<<"\n";
    cout<<"     ----                |  /|       fotino     ----"<<"\n";
    cout<<"     ----                |   |                  ----"<<"\n";
    cout<<"     ----    gravitino   |  _|_                 ----"<<"\n";
    cout<<"     -----------------------------------------------"<<"\n";
}
//funcion para generar un numero aleatorio entre las palabras del txt
int AhorcaditoGame::RandomNumber(){
    return 1 + rand() % 48;
    
}
//con esta funcion se extrae la palabra con el nombre de la particula del archivo txt
string AhorcaditoGame::GetWord(int line) {

	string file = "ParticlesZoo.txt";
	list.open(file);
	string word_line;

	for (int i = 0; i < line; i++ ){
		getline(list,word_line);
	}
	list.close();
    word=word_line;
	return word;
}

//convierte la palabra en su equivalente con X
string AhorcaditoGame::ToX(string str){
    str.replace(str.begin(),str.end(),str.size(),'X');
    return str;
}

//funcion para convertir las palabras en minuscula
string AhorcaditoGame::Lower(string data){
    for_each(data.begin(), data.end(), [](char & c){
    c = ::tolower(c);});
    return data;
}
//esta funcion selecciona la palabra a partir de un numero aleatorio    
void AhorcaditoGame::Turn(){
    Rnum = RandomNumber(); //genera numero aleatorio
    GetWord(Rnum); //extrae la palabra
    //cout<< word; // en caso de querer ver la palabra en consola se descomenta
}

//con esta funcion se determina si la letra ingresada pertenece o no
int AhorcaditoGame::FindLetter(char Letter){ //recibe la letra del usuario
    string str=word;
    Letter=tolower(Letter); //en caso de que se ingrese una letra mayuscula
    cout<<"Letra ingresada fue "<<Letter<<"\n";
    size_t found = str.find(Letter); //busca de adelante hacia atras la letra en la palabra y arroja su posicion
    size_t rfound = str.rfind(Letter);//busca de atras hacia adelante la letra en la palabra y arroja su posicion
    if(found<20){ //como found y rfound siempre son numeros entonces se limita su longitus asi se puede estar seguro de que si encontraron algo
        cout<<" Adivinaste!!! \n";
        //cout << " Se encontro en la posicion: " << found <<" y "<< rfound <<'\n';
        str=ToX(str);//se convierte la palabra en su equivalente en X
        comword.at(found)=Letter; //se sustituye las letras encontrdas en la palabra acumulada
        comword.at(rfound)=Letter;
        if(comword==word){//en caso de que la persona adivine por letras
            cout<<"GANASTE!!!";
            cout<<"\nLa particula era: "<<word;
            lives=0;}//acaba el juego
        }
    
    else{cout<<"No adivinaste \n";
        lives=lives-1;
        Man(lives);
        if(lives==0){
            cout<<"PERDISTE!!";
            cout<<"\nLa particula era: "<<word;
            }
    }
return lives;
}
//funcion que muestra el mancito ahorcadito dependiendo de las vidas
void AhorcaditoGame::Man(int live){
        if(live== 0){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|  -|- \n";
            cout<< "|   |  \n";
            cout<< "|  _|_ \n";}
        else if(live== 1){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|  -|- \n";
            cout<< "|   |  \n";
            cout<< "|  _| \n";}
        else if(live== 2){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|  -|- \n";
            cout<< "|   |  \n";
            cout<< "|      \n";}
        else if(live== 3){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|  -|- \n";
            cout<< "|      \n";
            cout<< "|      \n";}
        else if(live==4){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|  -| \n";
            cout<< "|      \n";
            cout<< "|      \n";}
        else if(live== 5){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|   |  \n";
            cout<< "|      \n";
            cout<< "|      \n";}
        else if(live== 6){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|   o \n";
            cout<< "|     \n";
            cout<< "|      \n";
            cout<< "|      \n";}
            
        else if(live== 7){
            cout<< "\n_____ \n";
            cout<< "|   | \n";
            cout<< "|     \n";
            cout<< "|     \n";
            cout<< "|      \n";
            cout<< "|      \n";}
   }
    



//funcion que permite que se lleve a cabo el juego
void AhorcaditoGame::play(){
    Welcome();//bienvenida
    //inicializacion variables
    char q='c';
    char option;
    char letter;
    string guessword;
    cont=true;
    lives=7;
  while (cont){
    if ((q == 'C') or (q == 'c')){// permite que el jugador vuelva a jugar
    Turn();//elige la palabra aleatoriamente
    cout<<"\n"<<"Adivine la particula: "<<ToX(word);
    comword=ToX(word);//crea la copia que se ira modificando en la medida que el jugador avance
    while(lives > 0){//la ronda va hasta donde el jugador tenga vidas
        cout<<"\nVidas disponibles: "<<lives<<"\n";
        cout<<"\nSi desea proponer una letra presiona L o si desea adivinar presione A\n";
        cin >> option;
        if ((option == 'L') or (option == 'l')){
            cout<<"Elige una letra \n";
            cin >> letter;
            FindLetter(letter);//mira si la letra esta en la palabra
            cout<<"\nLa palabra queda: "<<comword<<"\n";
            }
            
        else if ((option == 'A') or (option == 'a')){ //con esta opcion el jugador decide adivinar, decir toda la palabra si adivina gana sino pierde automaticamente
            cout<<"Elige una palabra \n";
            cin>> guessword;
            guessword=Lower(guessword);//en caso de que hayan mayusculas
            cout<<"\nLa palabra ingresada fue: "<<guessword;
            if(guessword==word){
                cout<<"\nGANASTE!!!\n";
                cout<<"\nLa particula era: "<<word;
                lives=0;}//acaba la ronda
            else{cout<<"\nPERDISTE!!\n";
                cout<<"\nLa particula era: "<<word;
                lives=0;//acaba la ronda
                Man(0); //pone al ahorcadito muerto
            }
            }
            
        else{
            cout << "Esta opción no es válida, bai\n";
            lives=0;//acaba la ronda 
        }
    
    }
    }
    else{
	cout << "Esta opción no es válida, bai\n";
	break;//acaba el juego
    }
    cout<<"\nSi deseas volver a jugar presiona C \n";//permite volver a jugar
    cin>>q;
    if ((q =='c') or (q=='C')) {cont=true;//reinicia las vidas
        lives=7;
    }
    else {cont=false;cout<<"\nbai bai :(\n";}
    
  }

}
/*

*/
