#include "fecha.h"

int main()
{
    int d; int m; int a;
    int time;
    
    cout << "Dia: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Año: ";
    cin >> a;
    
    Fecha fecha1(d,m,a);
    cout << "Hoy es el dia " << fecha1.day << " del mes " << fecha1.month << " del año " << fecha1.year << endl;
    
    cout << "¿Cuantos dias deseas adelantar? ";
    cin >> time;
    
    for (int i = 0; i < time; i++)
    {
        fecha1.DiaSig();
    }
    
    cout << "Ahora es el dia " << fecha1.day << " del mes " << fecha1.month << " del año " << fecha1.year << endl;
    
    return 0;
}