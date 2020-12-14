// Johan Alexis Carrillo Toro - 1214734681
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// Prototypes of the functions
string ChooseWord( string );  // selects a random word from a file
void round(string, string&, int& ,vector<int>&);
void play();
void findLocation( string, char, vector<int>&);  // find a letter inside the word
void replaceChar( string&, string, vector<int>&);  // replace a char in the hidden word
void AskToGess( string, int& );  // ask the player if wants to guess what is the word
void print_mistake( int );  // shows in screen the picture


// main function of the program
int main(){

	srand(time(NULL));
	string word;
	int answer=1;

	cout << "Bienvenido al juego Ahorcado!" << endl;

	while(answer != 0){  // if the user sets 0 in answer the game stops
	
	play();

	cout << "Ingresa 0 (cero) si deseas salir u otra tecla para jugar de nuevo\n";
	cin >> answer;

	}
	
	cout << "Gracias por jugar!" << endl;


	return 0;
}


// Definition of functions
void findLocation(string sample, char findIt, vector<int>& characterLocations){
	// modifies a vector with the location of the char in the word

    //vector<int> characterLocations;
    for(int i = 0; i < sample.size(); i++)
        if(sample[i] == findIt)
            characterLocations.push_back(i);
}

void replaceChar(string& hidden_word, string replaceIt, vector<int>& pos){
	// replace one char in the hidden word at the given positions

	for (int i=0; i<pos.size(); i++) hidden_word.replace(pos[i], 1, replaceIt);
}

void AskToGess(string true_word, int& num_tries){
	// used to ask the users if wants to guess what is the hidden word

	char answer;
	string guess_word;

	cout << "Desea adivinar cual es la palabra? (y/n)" << endl;
	cin >> answer;
	tolower(answer);

	if (answer == 'y'){
		cout << "Ingrese la palabra que usted cree que es: " << endl;
		cin >> guess_word;
		cout << true_word << guess_word << endl;
		if ( guess_word == true_word){
			cout << "Felicidades! Adivinaste la palabra" << endl;
			num_tries = 7;  // the game ends
		}
		else{
			cout << "Ufff, que mal, esa no era la palabra" << endl;
			num_tries++;
			print_mistake(num_tries);
			if (num_tries == 7) cout << "Te ahorcaste!" << endl;
		}
	}
	else return;
}



string ChooseWord( string file_path ){
	// This function reads a file and return a random word from it

	vector <string> WordsList;  // used to read the file
	int i = 0;
	string aux;

	ifstream WORD_FILE;
	WORD_FILE.open(file_path.c_str());

	// check if the fail was succesfully opened
	if (WORD_FILE.fail()){
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
    cout << "Se cargo el archivo de forma exitosa" << endl;
    // now put the words inside a vector
    while(WORD_FILE >> aux ){
    	WordsList.push_back(aux);
    	i++;
    }
    WORD_FILE.close();
    
    // select a random word from the vector
    aux = WordsList[rand() % WordsList.size()];
    
    return aux;
}

void play(){
	// play one game

	string word;
	int num_tries=0;  // used to ask the user if wants to play again

	// choose a random word from the file
	word = ChooseWord("list.txt");
	cout << "La palabra es: " << word << endl;
	cout << "Tu palabra esta lista para que empieces a jugar\n";
	cout << "La palabra tiene " << word.length() << " letras\n";
	cout << "Tienes 7 oportunidades de equivocarte"  << endl;

	// create a word to hide the choosen one
	string hidden(word.length(), 'X');
	vector<int> positions;  // used to save the position of the char in the word

	while (num_tries < 7){  // After 7 tries the game ends

		round(word, hidden, num_tries, positions);
	}
}

void round(string true_word, string& hidden_word, int& num_tries, vector<int>& positions){
	// play a round of the game

	char guess_char;

	cout << "Ingresa una letra para ver si esta en la palabra" << endl;
	cin >> guess_char;

	findLocation(true_word, guess_char, positions);

	if (positions.size() != 0){  // the char is in the word
		string guess_str(1, guess_char);  // convert guess_char to string
		replaceChar(hidden_word, guess_str, positions);  // replace the char in the hidden word
		cout << "Felicidades, le atinaste a una" << endl;
		cout << hidden_word << endl;

		// check if the word is completed
		if (hidden_word == true_word){
			cout << "Felicidades! Adivinaste la palabra" << endl;
			num_tries = 7;
		}
	}
	else{  // the char is not inside the word
		cout << "Fallaste! Esa letra no esta en la palabra" << endl;
		num_tries++;

		// show the figure
		print_mistake(num_tries);
		cout << "\nTe quedan " << 7-num_tries << " intentos" << endl;
		if(num_tries == 7) cout << "Te ahorcaste!"<< endl;
	}

	if (num_tries < 7) AskToGess( true_word, num_tries);  // ask to guess what is the word
	else cout << "Juego terminado" << endl;

	positions.clear();
}

void print_mistake(int i){
	switch (i){
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
	}
}
