#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <time.h>

#include "Ahorcado.h"
#include "Palabra.h"

using namespace std;

Ahorcado::Ahorcado()
    : intentos(7)
{
    palabras = new vector<Palabra>;
}

Ahorcado::Ahorcado(string & fname)
    : intentos(7)
{
    palabras = new vector<Palabra>;
    cargarPalabras(fname);
}

void Ahorcado::setIntentos(int i)
{
    intentos = (i < 0) ? 0 : i;
}

int Ahorcado::getIntentos() const
{
    return intentos;
}

void Ahorcado::setPalabras(vector<Palabra>* p)
{
    palabras = p;
}

vector<Palabra>* Ahorcado::getPalabras() const
{
    return palabras;
}

void Ahorcado::cargarPalabras(string & fname)
{
    ifstream palabrasFile(fname.c_str());

    if (palabrasFile.fail()) {
        cout << "No se pueden cargar las palabras" << endl;
        exit(1);
    }

    while (!palabrasFile.eof()) {
        string linea = "";
        palabrasFile >> linea;
        Palabra p(linea);
        getPalabras()->push_back(p);
    }

    palabrasFile.close();
}

void Ahorcado::jugar()
{
    int r = rand() % getPalabras()->size();
    Palabra *p = &(getPalabras()->at(r));

    while (getIntentos() > 0) {
        cout << "Intentos disponibles: " << getIntentos() << endl;
        char c;
        while (1) {
            cout << "Ingrese una letra para adivinar la palabra " << p->getPParcial() << ": ";
            cin >> c;
            if (isalpha(c))
                break;
            cout << "Solo se permiten letras." << endl;
        }
        if (p->adivinarLetra(c) == true) {

            if (p->getPParcial() == p->getP()) {
                cout << "En hora buena, ganaste! La palabra era " << p->getP() << endl;
                break;
            }
            else {
                cout << "Has adivinado, deseas tratar de adivinar la palabra completa: " << p->getPParcial() << " ? (y/n) ";

                char answer;
                cin >> answer;
                if (answer == 'y') {
                    cout << "Ingrese la palabra: " << endl;
                    string p_adi;
                    cin >> p_adi;
                    if (p->getP() == p_adi) {
                        cout << "La palabra es correcta, has ganado." << endl;
                        break;
                    }
                    else {
                        cout << "La palabra no es correcta, perdiste un intento." << endl;
                        setIntentos(getIntentos() - 1);
                        imprimirAhorcado();
                    }
                }
            }
        }
        else {
            cout << "La letra no es correcta, perdiste un intento." << endl;
            setIntentos(getIntentos() - 1);
            imprimirAhorcado();
        }
    }

    if (getIntentos() == 0) {
        cout << "Lo sentimos, has perdido el juego." << endl;
        cout << "La palabra era: " << p->getP() << endl;
    }
    setIntentos(7);
}

void Ahorcado::imprimirAhorcado()
{
    for (int i = 0; i < (7 - getIntentos()); i++) {
        cout << body[i];
    }
    cout << endl;
}

Ahorcado::~Ahorcado()
{
    delete palabras;
}