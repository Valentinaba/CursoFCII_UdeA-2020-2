#include "fecha.h"

// class constructor that assigns values to the day, month and year variables
fecha::fecha(int d, int m, int y){
		
	month_dic[0] = "January";
	month_dic[1] = "February";
	month_dic[2] = "Mach";
	month_dic[3] = "April";
	month_dic[4] = "May";
	month_dic[5] = "June";
	month_dic[6] = "July";
	month_dic[7] = "August";
	month_dic[8] = "September";
	month_dic[9] = "October";
	month_dic[10] = "November";
	month_dic[11] = "December";

	change_date(d,m,y);	

}

fecha::~fecha(){
	cout << "Class instance destroyed with stored date: ";
	print_date();	
}

// ___________________- PUBLIC FUNCTIONS -__________________________

// functions to change the values of day, month or year
void fecha::change_day(int d){
	check_day(d);

	day = d;	
}

void fecha::change_month(int m){
	check_month(m);

	month = m;
}

void fecha::change_year(int y){
	year = y;
}

// function that prints the date values stored in the class
void fecha::print_date() const{	

	// date wil be printed as year / month / day
	cout << year << "/";
   
	// if month is lesser than 10, print a 0 first
	if (month < 10){
		cout << "0" << month << "/";
	}
	else{
		cout << month << "/";
	}

	// likewise, if the day is lesser than 10, print a 0  before
	if (day < 10){
		cout << "0" << day << endl;
	}
	else{
		cout << day << endl;
	}
}

// now a function is implemented to change the whole date, like in the constructor
void fecha::change_date(int d, int m, int y){
	change_year(y);
	change_month(m);
	change_day(d);

	cout << "Date set to: ";
	print_date();
}

// function that increments the date by day
void fecha::diaSig(){
	// print present date
	cout << "Day date increment. Present date: ";
	print_date();

	// to make the increment, there are spetial cases:
	// 1. The present day is que last of the month
	// 2. The present day is the last of the last month
	
	// last day of 30 days months 
	if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day == 30)){
		month += 1;	
		day = 1;
	}

	// last day of 30 days months (except december) 
	else if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10)) && (day == 31)){
		month += 1;
		day = 1;
	}
	
	// last day of February, it must be taken into account if the present day is leap or not
	else if ((month == 2) && (day >= 28)){
		// if the year is a leap year
		if (((year%4) == 0) && (day == 29)){
			month += 1;
			day = 1;
		}
		// if the year is not a leap year
		else if (((year%4) != 0) && (day == 28)){
			month += 1;
			day = 1;
		}
		else {
			day += 1;
		}
	}

	// last day of December, year must also be incremented by one
	else if ((month == 12) && (day == 31)){
		year += 12;
		month = 1;
		day = 1;
		cout << "Happy new year!" << endl;
	}	

	// if the day is not the last of a month
	else {
		
		day += 1;
	}
	
	// print changed date
	cout << "New date: ";
	print_date();
}

// _____________________- PRIVATE FUNCTIONS -_________________________

// not any possible day number is a valid entry for the date; the following function checks if a day entry is valid and throws an exception otherwise

void fecha::check_day(int d) const{
// throw an error if the day surpases the total days of present month
	try{
		// for months of 30 days	
		if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (d > 31)) throw d;

		if ( month == 2){
			// if the year is a leap year
			if (((year%4) == 0) && (d > 29)) throw d;
			// if the year is not a leap year
			if (((year%4) == 0) && (d > 28)) throw d;
		}

		// for the remaining months
		else if ( d > 31) throw d;
	}
	catch (int d) {
		cout << "Invalid day number (" << d << ") for " << month_dic[month-1];

		if (((year % 4) == 0) && (month == 2)){
			cout << " on a leap year";
		}
		
		cout << endl;

		exit(1);
	}
}

// also, as there is not an infinite amount of months, a function to checck the month number is also necessary

void fecha::check_month(int m) const{
	try{
		if (m > 12) throw m;
	}
	catch (int m){
		cout << "Invalid month number (" << m << ")" << endl;
	
		exit(1);
	}
}

