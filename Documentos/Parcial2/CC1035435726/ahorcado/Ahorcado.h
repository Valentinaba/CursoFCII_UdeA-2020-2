#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>
#include <vector>
#include "Palabra.h"

using namespace std;

class Ahorcado {
public:
    Ahorcado();
    Ahorcado(string &);

    void setIntentos(int);
    int getIntentos() const;

    void setPalabras(vector<Palabra>*);
    vector<Palabra>* getPalabras() const;

    void cargarPalabras(string &);
    void jugar();
    void imprimirAhorcado();
    
    ~Ahorcado();

private:
    int intentos;
    vector<Palabra>* palabras;
    const string body[7] = { " O \n", "/", "|", "\\\n", " | \n", "/ ", "\\\n" };
};

#endif
