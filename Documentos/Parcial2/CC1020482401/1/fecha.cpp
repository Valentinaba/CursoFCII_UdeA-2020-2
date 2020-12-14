#include "fecha.h"


// ------------------------- Constructor ---------------------------------
Fecha::Fecha(int d = 1, int m = 1, int y = 1582){
	/*
	Se chequea que los valores sean adecuados
	 */

	setYear(y);
	setMonth(m);
	setDay(d);

}

// --------------------- Metodos de la clase ------------------------------

void Fecha::setDay(int d){

	if (month == 2){ // si es febrero
		if (isLeapYear()) day = (d > 0 && d < 30)? d : 1; // si es un año bisiesto 
		else day = (d > 0 && d < 29)? d : 1;
	}

	else if(is31days())	day = (d > 0 && d < 32)? d : 1; // si es un mes de 31 dias

	else day = (d > 0 && d < 31)? d : 1; // si es un mes de 30 dias

}


void Fecha::setMonth(int m){	

	month = (m > 0 && m < 13)? m : 1;

}


void Fecha::setYear(int y){
	
	year  = ( y > 1581)? y : 1582 ; //comienzo del calendario gregoriano

}

int Fecha::getDay() const{

	return day;

}


int Fecha::getMonth() const{
	
	return month;

}


int Fecha::getYear() const{

	return year;

}



void Fecha::print(const string format) const {
	/*
	Imprime la fecha segun el formato indicado
	 */

	if (!format.compare(A_M_D_GUION))
		cout << year << '-' << month << '-' << day ;
	
	else if (!format.compare(D_M_A_GUION))
		cout << day << '-' << month << '-' << year;
	
	else if (!format.compare(D_M_A_SLASH))
		cout << day << '/' << month << '/' << year;
	
	else if (!format.compare(D_M_A_COMPLETE)){
		cout << day << " de ";
		monthName();
		cout << " del año " << year ;
	}	
	
	else
		cout << day << '-' << month << '-' << year;
}


void Fecha::diaSig(){
	/*
	Esta funcion avanza un dia la fecha, considera 
	si es fin de mes, fin de año e incluso si es año bisiesto.
	 */
	
	if (month == 2)	{ // si es febrero

		if (isLeapYear()){ // si un año es biciesto
			if (day + 1 == 30 ){ // si es fin de mes
				day = 1;
				month ++;
			}
			else day++;
		}
		else{
			if (day + 1 == 29 ){ // si es fin de mes
				day = 1;
				month ++;
			}
			else day++;
		}
	}

	else if (is31days()){ // si es un mes de 31 dias
		
		if (day + 1 == 32){ // si es fin de mes
			day = 1;
			if(month == 12){ // si es fin de año
				month = 1;
				year++;
			}
			else month++;
		}
		else day++;
	}
	else{ // si es un mes de 30 dias

		if (day + 1 == 31){ // si es fin de mes
			day = 1;
			month++;
		}
		else day++;
	}

}

// ----------------- Funciones Utilitarias -----------------------

bool Fecha::isLeapYear() const{
	/*
	Chequea si el año es bisiesto segun el criterio;
	-- es bisiesto si es divisible entre cuatro y 
	(no es divisible entre 100 o es divisible entre 400).

	 */
	bool p, q, r;
	p = (year % 4 	== 0) ? true : false;
	q = (year % 100 == 0) ? true : false;
	r = (year % 400 == 0) ? true : false;

	return p && (!q || r);
}


bool Fecha::is31days() const{
	/*
	Chequea si el mes es de 31 días
	 */

	if (month == 1 || month == 3 || month == 5 || month == 7 ||
	month == 8 || month == 10 || month == 12) return true;
	
	else return false;
}


void Fecha::monthName() const {
	/*
	imprime el nombre del mes
	 */
	string monthName;

	switch(month){
		case 1:
			monthName = "Enero";
			break;
		case 2:
			monthName = "Febrero";
			break;
		case 3:
			monthName = "Marzo";
			break;
		case 4:
			monthName = "Abril";
			break;
		case 5:
			monthName = "Mayo";
			break;
		case 6:
			monthName = "Junio";
			break;
		case 7:
			monthName = "Julio";
			break;
		case 8:
			monthName = "Agosto";
			break;
		case 9:
			monthName = "Septiembre";
			break;
		case 10:
			monthName = "Octubre";
			break;
		case 11:
			monthName = "Noviembre";
			break;
		case 12:
			monthName = "Diciembre";
			break;
		default:
			monthName = "Enero";
	}	

	cout << monthName ;
}