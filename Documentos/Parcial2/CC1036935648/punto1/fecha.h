/**
 *  Clase para el manejo de la fecha
 */

#ifndef FECHA
#define FECHA

class Fecha
{
public:

    /**
     * Inicializa con la fecha actual
     */
    Fecha();

    /**
     * Inicializa con una fecha específica
     */
    Fecha(unsigned int day, unsigned int month, unsigned int year);

    /**
     * Imprime la fechar     */
    void print();

    /**
     * Incrementa la fecha en un día
     */
    void diaSig();

    /**
     * Fija una fecha siempre y cuando esta sea válida.
     * @return true si la fecha es valida, false en otro caso.
     */
    bool setDate(unsigned int day, unsigned int month, unsigned int year);

    /**
     * Returna true si se ingresa una fecha válida, false en otro caso
     */
    static bool validateDate(unsigned int day, unsigned int month, unsigned int year);

    /**
     * valida si un año es bisiesto
     */
    static bool isLeapYear(unsigned int year);

private:
    unsigned int day, month, year; //Elementos de la fecha

};

#endif // FECHA