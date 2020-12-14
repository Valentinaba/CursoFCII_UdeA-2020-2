// Johan Alexis Carrillo Toro - 1214734681
#include "date.h"


const int DateClass::days_per_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Definition of the functions of the class
DateClass::DateClass(int mm=1, int dd=1, int yr=1582){
	// initialize the date

	SetMonth(mm);
	SetYear(yr);
	SetDay(dd);
}

DateClass::~DateClass(){
	// destructor of the class

	cout << "Se procede a eliminar la fecha: ";
	ShowDate();
}

// The SetDate functions check the validity of the date and set it
void DateClass::SetMonth(int mm){
	// the default month is january (1)

	if (mm > 0 && mm < 13) month = mm;
	else{
		cout << "mes invalido, establecido a 1 por defecto" << endl;
		month = 1;
	}
}

void DateClass::SetYear(int yr){
	// the default year is 1592, the start of gregorian calendar

	if (yr > 1591) year = yr;
	else{
		cout << "año invalido, establecido a 1592 por defecto" << endl;
		year = 1592;
	}
}

void DateClass::SetDay(int dd){
	// the default day is 1
  
  	// if it is not a leap year
  	if ( dd > 0 && dd <= days_per_month[ month ] ) day = dd;

  	// check if it is 02/29 for a leap year
  	else if ( month == 2 && dd == 29 && CheckLeapYear() ) day = dd;

	// in any other case
	else{
		cout << "dia invalido, establecido a 1 por defecto" << endl;
		day = 1;
	}
}

// the GetDate functions return the date
int DateClass::GetDay() const{

	return day;
}

int DateClass::GetMonth() const{

	return month;
}

int DateClass::GetYear() const{

	return year;
}

void DateClass::ShowDate() const{
	cout << setfill( '0' ) << setw( 2 ) << GetDay() << "/" 
			<< setw( 2 ) << GetMonth() << "/" << GetYear() << endl;
}

bool DateClass::CheckLeapYear() const{
	// this algorithm was taken from wikipedia xd

	bool p, q, r;
	p = (year % 4 == 0) ? true : false;
	q = (year % 100 == 0) ? true : false;
	r = (year % 400 == 0) ? true : false;

	return p && (!q || r);
}

void DateClass::NextDay(){
	// this function change the date to the next day

	// check if it is 31/12
	if ( day==31 && month==12){
		SetDay(1);
		SetMonth(1);
		SetYear(++year);
	}
	// check it is 29/02 for a leap year
	else if ( day==29 && month==2 && CheckLeapYear() ){
		SetDay(1);
		SetMonth(3);
	}
	// check if is the last day of the month
	else if( day == days_per_month[ month ] ){
		SetDay(1);
		SetMonth(++month);
	}
	else SetDay(++day);
}

