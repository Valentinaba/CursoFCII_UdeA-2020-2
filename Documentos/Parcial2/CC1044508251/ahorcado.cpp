#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <string.h>

using namespace std;

string elegirPalabra(ifstream &words)
{
  string chosen_one;
  int l, t_size;
  string line;
  
  if (words.is_open())
    {
      l = 0;
      t_size = 0;

      string all_words;
      vector<int> lim;

      lim.push_back(0);
      
      while( getline(words, line))
	  {
	    l++;
	    t_size = t_size + line.length();
	    lim.push_back(t_size-1);
	    all_words.append(line);
	  }  

      srand (time(NULL));

      int rdm = rand()%t_size;
      
      int a, b;
	         
      for(int i=0; i<lim.size()-1; i++)
	if( rdm >= lim[i] && rdm <=lim[i+1])
	  {

	  if(i==0)
	    {
	      a = lim[i];
	      b = lim[i+1];
	    }
	  else
	    {
	      a = lim[i]+1;
	      b = lim[i+1];
	    }
	  }
      
      for(int i = a; i<=b; i++)
	{
	  chosen_one = chosen_one + all_words[i];
	}
    }

  words.close();

  return chosen_one;
}

void dibujar(int n)
{
  if(n==1)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
    }  
  if(n==2)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
      cout << "/" << endl;
    }
  if(n==3)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
      cout << "/" ;
      cout << "|" << endl;
    }
  if(n==4)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
      cout << "/" ;
      cout << "|" ;
      cout << "\\" << endl;
    }
  if(n==5)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
      cout << "/" ;
      cout << "|" ;
      cout << "\\"  << endl;
      cout << " |"  << endl;
    }
  if(n==6)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
      cout << "/" ;
      cout << "|" ;
      cout << "\\" << endl;
      cout << " |" << endl;
      cout << "/" << endl;
    }
  if(n==7)
    {
      cout << "Te equivocaste" << endl;
      cout << "===============" << endl;
      cout << " O" << endl;
      cout << "/" ;
      cout << "|" ;
      cout << "\\" << endl;
      cout << " |" << endl;
      cout << "/" ; 
      cout << " \\" << endl;
    }
}

void ahorcado(ifstream &palabras)
{
  string elegida = elegirPalabra(palabras);
  
  
  string guess;
  
  for(int i=0; i<elegida.length(); i++)
    {
      guess = guess + 'x';
    }
  
  //cout << elegida << endl;
  cout << guess << endl;
  
  int n=1;
  int j=1;
  int trials=8;
  
  while(j<trials)
    {
      string letter_in;
      
      cout << "Ingrese una letra: ";
      cin >> letter_in;      
      
      int found;
      int g_pos;
      
      found = elegida.find(letter_in);
      
      if(found!=std::string::npos)
	{
	  cout << "La letra se encuentra" << endl;
	  int in;
	  cout << "Ingrese 1 para adivinar la palabra completa: ";
	  cin >> in;
	  
	  if(in==1)
	    {
	      cout << "Ingrese la palabra de prueba: ";
	      string word_in;
	      cin >> word_in;
	      int ver = word_in.compare(elegida);
	      if(ver == 0)
		{
		  guess = word_in;
		  cout << "Ganaste!" << endl;
		  j=trials;
		}
	      else
		{
		  dibujar(n);
		  n++;
		  j++;
		}
	    }
	  else
	    {
	      guess.replace(found, 1, letter_in);
	      cout << guess << endl;
	      
	      if(found<elegida.length())
		{
		  string last = elegida;
		  last.replace(found, 1, "0");
		  found = last.find(letter_in);
		  
		  if(found!=std::string::npos)
		    {
		      guess.replace(found, 1, letter_in);
		      cout << guess << endl; 
		    }
		}
	    }
	}
      else
	{
	  cout << "La letra no se encuentra" << endl;
	  dibujar(n);
	  n++;
	  j++;
	}     
    }
  
  cout << "Palabra correcta: ";
  cout << elegida << endl;
  
  cout << "Resultado: " << endl;
  cout << guess << endl;

}


int main () {

  int play = 1;

  while(play==1)
    {
      ifstream palabras ("palabras.dat");  
      ahorcado(palabras);
      cout << "Ingrese 1 si desea volver a jugar: ";
      cin >> play;
    }
  
  return 0;
}
