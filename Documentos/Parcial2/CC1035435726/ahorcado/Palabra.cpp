#include <string>
#include "Palabra.h"
#include <iostream>

using namespace std;

Palabra::Palabra(const string & p_)
{
    setP(p_);
    setPParcial(string(p.length(), 'x'));
}

void Palabra::setP(const string & p_)
{
    p = p_;
}

string Palabra::getP() const
{
    return p;
}

void Palabra::setPParcial(const string & p_)
{
    pparcial = p_;
}

string Palabra::getPParcial() const
{
    return pparcial;
}

bool Palabra::adivinarLetra(const char & c)
{
    bool correcto = false;
    for (int i = 0; i < getP().length(); i++) {
        if (c == getP().at(i)) {
            pparcial.at(i) = c;
            if (correcto != true) //para que no establezca el valor de correcto más de una vez
                correcto = true;
        }
    }
    return correcto;
}