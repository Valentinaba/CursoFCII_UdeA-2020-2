#include "ahorcado.h"

using namespace std;

string p_ahorcado :: read_word(void) 
{
  n_err = 0;
  fstream in_file;
  in_file.open("words.txt",ios:: in);
  
  if (in_file.fail()) //Comprueba que el archivo fue leído
    {
      cout << "El archivo no se abrió :/"<< endl;
      exit(1);
    }
  string word,line;
  
  vector <string> v_words;
  getline(in_file,line);
  stringstream ss(line);
  while (getline(ss,word,','))//Se obtienen las palabras separadas por coma
    {
      v_words.push_back(word);//Se crea un vector con las palabras del archivo .txt
    }

  int size_v = v_words.size(); 
  int N = rand()%(size_v-1);
  string adivina = v_words[N]; //Se selecciona aleatoreamente una palabra
  return adivina; //Palabra que adivinará el usuario
 
}

void p_ahorcado::play(void)
{
  string w_adivinar = read_word();//Palabra que adivinará el usuario
  int size_w = w_adivinar.size();
  string str(size_w,'x');
  print_word = str;
  cout << "Debe adivinar una palabra de " << size_w << " digitos: " << print_word<<endl;
  cout << "\n ";
  bool is_playing = true;
  int i = 0;
  acierto = 0;
  string answer;
  while (is_playing)
    {
      if (i==0)
	{
	  cout << "Ingrese una letra:" << endl;
	  cin >> letter_player;
	  is_valid_letter(); //Se valida que el usuario ingrese solo un caracter
	  is_letter_in_word(w_adivinar);
	}

      else
	{
	  cout <<"¿Ya sabes la palabra? ¿Deseas ingresarla?(y o n)" << endl;
	  cin >> answer;
	  if (answer =="y")
	    {
	      cout << "Ingresa la palabra: " << endl;
	      cin >> word_player;
	      is_valid_word(size_w); //Se valida que el usuario ingrese el mismo número de caracteres que la palabra a adivinar.
	      is_playing = is_the_word(w_adivinar); //Se verifica que 
	    }
	  else if (answer == "n")
	    {
	      cout << "Ingrese una letra:" << endl;
	      cin >> letter_player;
	      is_valid_letter();
	      is_letter_in_word(w_adivinar);
	    }
	  else
	    {
	      cout << "Warning: No ingreso un n o y. Se tomará su respuesta como un n" << endl;
	      cout << "Ingrese una letra:" << endl;
	      cin >> letter_player;
	      is_valid_letter();
	      is_letter_in_word(w_adivinar);
	    }
	  
	} //fin else
      
      if (acierto==size_w)
	
	{
	  cout << "\n \n";
	  cout<< "Felicidades! Has ganado. " << endl;
	  is_playing = false;
	  cout << "\n \n";
	}
      else if(!is_playing)
	break;
      else if(n_err ==7)
	{
	  cout << "Supero los 7 intentos incorrectos. Ha perdido" << endl;
	  is_playing = false;
	  cout << "\n \n";
	  
	}
      else
	{
	  cout << "\n \n";
	  cout << "Hasta ahora has adivinado:" << print_word <<endl;
	}
      i++;
    } 
  
}
void p_ahorcado:: is_valid_letter(void)
{
  int size_l = letter_player.size();
  while (size_l != 1)
    {
      cout << "Debe ingresar una sola letra. Ingrese el valor de nuevo:" <<endl;
      cin >> letter_player;
      size_l = letter_player.size();
    }
  size_t found = letters_from_player.find(letter_player);
  while (found!=string::npos)
    {
      cout<< "Ya ha ingresado la letra " << letter_player << ". Agregue una nueva." << endl;
      cin >> letter_player;
      found = letters_from_player.find(letter_player);
    }
  letters_from_player.append(letter_player);
  
}

void p_ahorcado:: is_valid_word(const int size_r)
{
  int size_w = word_player.size();
  
  while (size_r != size_w)
    {
      cout << "El número de caracteres no coincide con los de la palabra a adivinar. Ingrese el valor de nuevo :" <<endl;
      cin >> word_player;
      size_w = word_player.size();
    }
  
}
void  p_ahorcado :: is_letter_in_word(const string word)
{
  size_t found = word.find(letter_player);
  if (found==string::npos)
    {
      cout << "\n";
      cout << "Letra equivocada :/" << endl;
      n_err++;
      cout << "Número de errores :" <<n_err << endl;
      encabezado();
    }
  else
    {
      while (found!=string::npos)
	{
	  
	  cout << "\n";
	  int n = found;
	  int size = print_word.size();
	  cout << "Letra correcta!"  << endl;
	  print_word.replace(n,1,letter_player); 
	  found = word.find(letter_player, found+1);
	  acierto++;;
	}
      
    }
}

bool p_ahorcado :: is_the_word(string word)
{
  bool keep_playing;
  if (word_player ==  word)
    {
      keep_playing = false;
      cout << "Felicidades! Adivinaste!" << endl;
    }
  else
    {
      keep_playing = true;
      cout << " Lo sentimos, esa no era la palabra correcta" << endl;
      n_err++;
      cout << "Número de errores :" <<n_err << endl;
      encabezado();
      
      
    }
  return keep_playing;
}

void p_ahorcado:: encabezado(void)const
{ cout << "Estas son las partes del cuerpo que llevas dibujadas hasta ahora: " <<endl;
  switch (n_err){
  case 1:
    cout << " o " <<endl;
    break;
  case 2:
    cout << " o " << "\n"
	 << " | " << endl;
    break;
  case 3:
    cout << " o " << "\n"
	 << "/| " << endl;
    break;
  case 4:
    cout << " o " << "\n"
	 << "/|\\" << endl;
    break;
  case 5:
     cout << " o " << "\n"
	 << "/|\\ " << "\n"
	 << " | " << endl;
    break;
  case 6:
    cout << " o " << "\n"
	 << "/|\\ " << "\n"
	 << " | " << "\n"
	 << "/ " << endl;
    break;
    
  case 7:
    cout << " o " << "\n"
	 << "/|\\ " << "\n"
	 << " | " << "\n"
	 << "/ \\" << endl;
    break;     
  default:
    cout << "This shouldn't be here" << endl;
  }
}
