#ifndef FECHA_H
#define FECHA_H

class Fecha {
public:
    Fecha(int = 1, int = 1, int = 2000); // constructor predeterminado

    void setDia(int);
    void setMes(int);
    void setAnio(int);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void imprimir() const; // imprime la fecha en formato dia/mes/annio

    ~Fecha(); // se proporciona para confirmar el orden de destrucción
    void diaSig();

private:
    int mes; // 1-12 (Enero-Diciembre)
    int dia; // 1-31 con base en el mes
    int anio; // cualquier anio(incluso negativos, pues puede ser que aristoteles use el programa)

    // función utilitaria para retornar el numero de dias por mes y annio
    int diaMes(int, int) const;
};

#endif
