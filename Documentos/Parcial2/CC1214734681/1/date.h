// Johan Alexis Carrillo Toro - 1214734681
// Declaration of the class Date
#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <iomanip>

using namespace std;


class DateClass
{
public:
	DateClass( int, int, int ); // constructor (month, day, year)
	~DateClass(); // destructor

	// functions that change the date
	void SetDay( int );
	void SetMonth( int );
	void SetYear( int );
	void NextDay();  // change the date to the next day

	// functions that returns the date. const because returns nothing
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	void ShowDate() const; // prints the date in format month/day/year

 
private:
	int month;
	int day;
	int year;

	static const int days_per_month[ 13 ];
	bool CheckLeapYear() const;  // this function checks if it is a leap year
};

#endif