
#include "fecha.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;


/**
 * namespace anónimo para "encapsular" las variables que contiene
 * solo en este archivo.
 */
namespace 
{
    const unsigned  N_MONTHS = 12;  // Número de meses en el año
    
    // Número de días permitidos en un año regular
    const short ndays_reg_year[N_MONTHS] =  {31,28,31,30,31,30,31,31,30,31,30,31};

    // Número de días permitidos en un año bisiesto
    const short ndays_leap_year[N_MONTHS] = {31,29,31,30,31,30,31,31,30,31,30,31};
}

Fecha::Fecha()
{
    time_t now = time(NULL); // tiempo transcurrido desde 1970
    tm *gtm = gmtime(&now); // conversion de a UTC

    year = gtm->tm_year + 1900; /* tm_year: The number of years since 1900 */
    month = gtm->tm_mon + 1;    /* tm_mon: month, range 0 to 11 */
    day = gtm->tm_mday;         /* tm_mday: day of the month, range 1 to 31 */
}


Fecha::Fecha(unsigned int day, unsigned int month, unsigned int year)
{

    if(validateDate(day, month, year))
    {
        this->day;
        this->month;
        this->year;
    }
    else
    {
        /* Primer día de cuarentena por COVID en colombia :P */
        this->day = 25;
        this->month = 03;
        this->year = 2020;
    }
}


void Fecha::print()
{
    cout << year << "/" << month << "/" << day << endl;
}


void Fecha::diaSig()
{
    /* verificar si es un año regular o bisiesto */
    const short *n_days = isLeapYear(year)? ndays_leap_year : ndays_reg_year;
    
    /* Verificar que el día no sobrepase el número permitido por el mes actual */
    day = (day+1 <= n_days[month-1])? day + 1 : 1;
    
    if( day == 1)
    {
        month = (month + 1 <= N_MONTHS)? month + 1 : 1;

        /* Aumentar el año */
        if(month == 1)
            year ++;
    }
}

bool Fecha::setDate(unsigned int day, unsigned int month, unsigned int year)
{
    /* Validar la fecha */
    if(!validateDate(day, month, year))
        return false;

    this->day = day;
    this->month = month;
    this->year = year;
    return true;
}

bool Fecha::validateDate(unsigned int day, unsigned int month, unsigned int year)
{
    if(month > 0 && month <= N_MONTHS)
    {
        /* Verificar si es un año regular o uno bisiesto */
        const short *n_days = isLeapYear(year)? ndays_leap_year : ndays_reg_year; 
        
        /* Verificar si el día está en el rango que permite el mes */
        if(day > 0 && day <= n_days[month - 1])
            return true;
    }

    return false;
}

bool Fecha::isLeapYear(unsigned int year)
{
    //Referencia: https://es.wikipedia.org/wiki/Año_bisiesto

    if((year % 4) == 0)
    {
        if((year%100 != 0) || (year%400 == 0))
            return true;
    }

    return false;
}