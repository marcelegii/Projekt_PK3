#pragma once
#include<iostream>
#include<string>
#include<time.h>
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
	vector<string> toVisit; // place to visit
	string transport;
	int prize;
	
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
	friend ostream&  operator<<(ostream& out, Trip & a);
};

