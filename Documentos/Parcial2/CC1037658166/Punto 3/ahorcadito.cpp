#include "ahorcadito.h"

vector<string> Ahorcado::Split(string *chain)
{
    /*
    Toma el valor de memoria de un string y construye recursivamente un vector con las palabras como elementos.
    Para hacerlo, simplemente busca la primera "," en la cadena, toma una substring de la cadena hasta la posicion de "," y lo ingresa como elemento en el vector W y luego elimina de la cadena esa palabra y tambien la primera "," para que en la siguiente busqueda se almacene la siguiente palabra.
    */
    vector<string> W;
    int commaplace = 0;
    
    while (commaplace >= 0 and commaplace < chain -> length())
    {
        commaplace = chain -> find(",");
        W.push_back( chain -> substr(0,commaplace));
        chain -> erase(0,commaplace +1 );
    }
    return W;
}

string Ahorcado::Select_a_Word(vector<string> VS)
{
    /*
    Elige un número entre 0 y en tamaño del array ingresado, luego ingresa al vector y toma ese elemento, aleatoriamente, l función regresa el valor seleccionado aleatoriamente.
    */
    srand(time(NULL));
    int randval = rand() % VS.size();
    
    string selected_word = VS[randval];
    return selected_word;
}

void Ahorcado::make_a_guess(string sw, string *gw, char g, int *fg, int *sg)
{
    /*
    sw: La palabra seleccionada
    gw: El apuntador a la palabra que se adivina recurisivamente "-----"
    g: El caracter que se intenta adivinar
    fg: Apuntador al numero de intentos fallidos
    sg: Apuntador al numero de intentos exitosos
    fg es util para acabar al while principial fg > 7 mientras que sg es util para acabar el while principal si sg >= sw.lenght() es decir, si todos los caracteres han sido adivinados
    */
    
    // Determina todas las posiciones donde esta el char g en la string sw
    vector<int> charLocations;

    for(int i = 0; i < sw.length(); i++)
    {
        if (sw[i] == g)
        {   
            charLocations.push_back(i);
        }
    }
    
    // Si charLocations esta vacio se suma un numero a los intentos fallidos si no, se suma a los itnentos exitosos segun el numero de caractertes que tenga la palabra.
    if (charLocations.size() == 0)
    {
        *fg += 1;
    }
    else
    {
        *sg += charLocations.size();
    }
    
    // Si NO esta vacio se reemplazan los valores en gw
    
    for( auto ind = charLocations.begin() ; ind != charLocations.end() ; ind++)
    {
        gw -> replace(*ind,1,string(1,g));
    }
}

void Ahorcado::try_a_word(string sw, string *gw, string g, int *fg, int *sg)
{
    /*
    sw: La palabra seleccionada
    gw: El apuntador a la palabra que se adivina recurisivamente "-----"
    g: La palabra que se intenta adivinar
    fg: Apuntador al numero de intentos fallidos
    sg: Apuntador al numero de intentos exitosos
    fg es util para acabar al while principial fg > 7 mientras que sg es util para acabar el while principal si sg >= sw.lenght() es decir, si todos los caracteres han sido adivinados
    */
    
    if (g == sw)
    {
        gw -> replace(0,sw.length(),sw);
        *sg += sw.length();
    }
    else
    {
        *fg += 1;
        //cout << "La palabra que has intenado adivinar no es correcta" << endl;
    }
}