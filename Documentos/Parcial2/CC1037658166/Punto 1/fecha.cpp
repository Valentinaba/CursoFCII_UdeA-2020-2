#include "fecha.h"

// Constructor 
Fecha::Fecha(int d, int m, int a)
{
    // Año
    while (a < 0)
    {
        cout << "El año ingresado no es valido. Ingrese uno que si funcione" << endl;
        cout << "Año: ";
        cin >> a;   
    }
    year = a;    
    
    // Determinacion de si el año es bisiesto o no
    
    if (a%4 == 0)
    {
        if (a%100 == 0)
        {
            (a%400 == 0) ? bis = true : bis = false;
        }
        else 
        {
            bis = true;
        }
    }
    else
    {
        bis = false;
    }
        
    // Mes
    
    while ( not(0 < m and m < 13) )
    {
        cout << "El mes ingresado no es valido. Ingrese uno que si funcione" << endl;
        cout << "Mes: ";
        cin >> m;
    }
    month = m;
    
    // Dia
    
        // Mes de 31 dias
    if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12)
    {
        while ( not(0 < d and d < 32) )
        {
            cout << "El día ingresado no es valido. Ingrese uno que si funcione" << endl;
            cout << "Dia: ";
            cin >> d;
        }
        day = d;
    }
        // Mes de 30 dias
    if (m == 4 or m == 6 or m == 9 or m == 11)
    {
        while ( not(0 < d and d < 31) )
        {
            cout << "El día ingresado no es valido. Ingrese uno que si funcione" << endl;
            cout << "Dia: ";
            cin >> d;
        }
        day = d;
        
    }
        // Caso especial: Febrero
    if (m == 2 )
    {
        // Considerando que puede ser bisiesto
        while ( not(0 < d and d < (bis == true ? 30 : 29)) )
        {
            cout << "El día ingresado no es valido. Ingrese uno que si funcione" << endl;
            cout << "Dia: ";
            cin >> d;
        }
        day = d;
    }
    
}

void Fecha::DiaSig()
{
    // Cambio de año
    if (month == 12 and day == 31)
    {
        day = 1;
        month = 1;
        year += 1;
    }
    // Cambio de mes
    
        //Mes de 31 dias
    
    else if ( (month == 1 or month== 3 or month == 5 or month == 7 or month == 8 or month == 10 ) and (day == 31))
    {
        day = 1;
        month += 1;
    }
        //Mes de 30 dias
    else if ((month == 4 or month == 6 or month == 9 or month == 11) and (day == 30) )
    {
        day = 1;
        month += 1;
    }
        // Caso especial: Febrero
    
    else if (month == 2 and (bis == true ? day == 29 : day == 28 ) )
    {
        day = 1;
        month += 1;
    }
    
    // No cambio de mes ni de año
    else
    {
        day += 1;
    }
}
























