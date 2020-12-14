#ifndef PALABRA_H
#define PALABRA_H

#include <string>

using namespace std;

class Palabra {
public:
    Palabra(const string &);
    void setP(const string &);
    string getP() const;

    string getPParcial() const;
    void setPParcial(const string &);

    bool adivinarLetra(const char &);

private:
    string p;
    string pparcial;
};

#endif