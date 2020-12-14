#include "ahorcadito.h"


int main ()
{
    string words;
    ifstream file("Palabras.txt"); //Lectura
    
    getline(file, words);   // words guarda todas las palabras
    file.close();
    
    vector<string> Words = Ahorcado::Split(&words);
    
    //~~ Codigo del juego ~~//
    
    int fg = 0;  // Failed Guesses
    int sg = 0;  // Successfull Guesses
    
    string selected_word = Ahorcado::Select_a_Word(Words);
    
    // cout << "La palabra es: " << selected_word << endl; // Descomentar para ver la palabra
    
    // Creacion de guess
    string guess = "";  
    string x = "-";
    
    for (int i = 0; i < selected_word.length(); i++)
    {
        guess.append(x);
    }
    
    int choice;
    char play = 'y';
    
    while (play == 'y')
    {
        cout << "¿Desea jugar Ahorcadito? (y/n) ";
        cin >> play;
        if (play == 'n')
        {
            break;
        }
    
        cout << "La longitud de la palabra es de " << selected_word.length() <<" letras."<< endl;
    
        while (fg < 7)
        {
			bool bad_choice = true;

			while(bad_choice)
			{
            	cout << "¿Deseas apostar un caracter (escriba 1) o la palabra entera (escriba 2)? ";
            	cin >> choice; 
       
            	if (choice == 1)
            	{
               	 	char g;
					cout << "Apuesta un caracter: ";
                	cin >> g;
                	Ahorcado::make_a_guess(selected_word, &guess, g, &fg, &sg);
					bad_choice = false;
            	}
            	else if (choice == 2)
            	{
                	string g;
                	cout << "Apuesta una palabra: ";
                	cin >> g;
                	Ahorcado::try_a_word(selected_word, &guess,g, &fg, &sg);
					bad_choice = false;
            	}
				else
				{
					cout << "La opcion elegida no es valida" << endl;
				}
        	}

            cout << "Quedan " << 7 - fg << " intentos restantes" << endl;
            cout << guess << endl;

            if (selected_word.length() == sg)
            {
                cout << "Ganaste" << endl;
                break;
            }
            if (fg == 7)
            {
                cout << "Perdiste. La palabra era: " << selected_word << endl;
            }
        }
    }

    return 0;
}
    

