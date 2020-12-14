#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#ifndef FECHA_H
#define FECHA_H

class fecha{
	public:
	// class constructor initializes variable values by default
	fecha(int d=1,int m=1,int y=2000);
	// classs destructor
	~fecha();		

	// print date function
	void print_date() const;
	void diaSig();

	// change day, month or year
	void change_day(int);
	void change_month(int);
	void change_year(int);

	// change date function
	void change_date(int,int,int);

	private:
	int day,month,year;
	string month_dic[12];  

	void check_day(int) const;
	void check_month(int) const;
};

#endif
