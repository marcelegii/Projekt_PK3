#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Trip
{

private:
	string name;
	int day_start;
	int month_start;
	int year_start;
	int day_end; // trip end;
	int month_end;
	int year_end;
	int prize;
	string place;
	vector<string> countryToVisit ;
	vector<string> cityToVisit;
	string transport;
	
	vector<string> dataInObject = vector<string>(20); //without vector toVisit
public:
	Trip();
	~Trip();

	void setName(string n);
	void setDayStart(int);
	void setMonthStart(int);
	void setYearStart(int);

	void setDayEnd(int);
	void setMonthEnd(int);
	void setYearEnd(int);
	void setPrize(int);
	void setTransport(string);
	void pushToVector(string);
	void setPlaceToVisit(string);
	string getName();
	int getDayStart();
	int getMonthStart();
	int getYearStart();
	int getDayEnd();
	int getMonthEnd();
	int getYearEnd();

	int getPrize();
	friend ostream&  operator<<(ostream& out, Trip & a);
};

