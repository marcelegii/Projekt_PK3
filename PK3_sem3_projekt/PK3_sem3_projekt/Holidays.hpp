#pragma once
#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Holidays 
{

private:
	string name;
	int day_start;
	int month_start;
	int year_start;
	int duration;// how long is your holidays?	 
	double holiday_prize;
	double autocar_prize;
	double plane_prize;
	vector<string> dataInObject= vector<string> (20); // data from file holiday.txt

public:


	Holidays();
	/*Holidays(string n, int d, int m, int y, int _dur, double hp, double ap, double pp = 0.0) :
		duration(_dur), holiday_prize(hp), autocar_prize(ap), 
		plane_prize(pp) ,Rest(n, d, m, y) {}*/

	~Holidays();
	
	 void setName(string n);
	 void setDayStart(int);
	 void setMonthStart(int);
	 void setYearStart(int);
	 void setDuaration(int);
	 void setHolidayPrize(int);
	 void setAutocarPrize(int);
	 void setPlanePrize(int);
	 void pushToVector(string);
	friend ostream&  operator<<(ostream& out, Holidays & a);
		
};

