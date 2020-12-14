#include <iostream>
using namespace std;

class Fecha
{
public:

    Fecha(int, int, int);
    void DiaSig();
    int day;
    int month;
    int year;
    
private:

    bool bis;
};