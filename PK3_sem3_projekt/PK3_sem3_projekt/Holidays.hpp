#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
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
	string city;
	string country;
	int holiday_prize;
	int autocar_prize;
	int plane_prize;
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
	 void setCity(string);
	 void setCountry(string);
	 void setHolidayPrize(int);
	 void setAutocarPrize(int);
	 void setPlanePrize(int);
	 string getName();
	 int getDayStart();
	 int getMonthStart();
	 int getYearStart();
	 int getDuaration();
	 string getCity();
	 string getCountry();
	 int getHolidayPrize();
	 int getAutocarPrize();
	 int getPlanePrize();
	 void toOutputFile(string,int);

	 void pushToVector(string);

	friend ostream&  operator<<(ostream& out, Holidays & a);
		
};

