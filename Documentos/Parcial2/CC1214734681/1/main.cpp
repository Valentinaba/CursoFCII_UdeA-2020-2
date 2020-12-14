// Johan Alexis Carrillo Toro - 1214734681
// The dates are in format month/day/year
#include "date.h"

// main function of the program
int main(){
	// try different cases or the date to check if the class works fine

	DateClass try_date2(6, 1, 1996);  // my birthday =D
	cout << "Se aumenta un dia la fecha: ";
	try_date2.ShowDate(); 
	cout << endl;
	try_date2.NextDay();
	cout << "La nueva fecha es: ";
	try_date2.ShowDate();
	cout << "\n" << endl;

	DateClass try_date3(2, 29, 2020);
	cout << "Se aumento en un dia la fecha: ";
	try_date3.ShowDate();
	cout << endl;
	try_date3.NextDay();
	cout << "La nueva fecha es: ";
	try_date3.ShowDate();
	cout << "\n" << endl;

	DateClass try_date4(12, 31, 2019);
	cout << "Se aumento en un dia la fecha: ";
	try_date4.ShowDate();
	cout << endl;
	try_date4.NextDay();
	cout << "La nueva fecha es: ";
	try_date4.ShowDate();
	cout << "\n" << endl;

	cout << "se ingresa un fecha invalida 02/29/2021" << endl;
	DateClass try_date(2, 29, 2021);
	cout << endl;

	return 0;
}