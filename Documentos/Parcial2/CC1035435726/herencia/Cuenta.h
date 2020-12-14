#ifndef CUENTA_H
#define CUENTA_H

class Cuenta {
public:
    Cuenta(double = 0.0);

    void setSaldo(double);
    double getSaldo() const;
    void abonar(double);
    bool cargar(double);
    ~Cuenta();
private:
    double saldo;
};

#endif