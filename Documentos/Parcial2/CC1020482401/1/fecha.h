#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <iostream>

// ------ Formatos de fecha -------
#define A_M_D_GUION 	"AAAA-MM-DD"
#define D_M_A_GUION 	"DD-MM-AAAA"
#define D_M_A_SLASH   	"DD/MM/AAAA"
#define D_M_A_COMPLETE  "D de M del año AAAA"
// --------------------------------

using namespace std;

class Fecha
{
public:
	Fecha(int, int, int);
	
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay(void) const;
	int getMonth(void) const;
	int getYear(void) const;

	void print(const string) const; 
	void diaSig(void);

private:
	int day;
	int month;
	int year;

	bool isLeapYear(void) const;
	bool is31days(void) const;
	void monthName(void) const;
};


#endif