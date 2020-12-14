#include <iostream>
#include "Ahorcado.h"

using namespace std;

int main()
{
    srand(time(NULL));
    string fname = "palabras.dat";
    Ahorcado ah(fname);
    char answer;

    while (1) {
        cout << "Desea jugar? (y/n): ";
        cin >> answer;
        if (answer == 'y')
            ah.jugar();
        else
            break;
    }
    
    return 0;
}