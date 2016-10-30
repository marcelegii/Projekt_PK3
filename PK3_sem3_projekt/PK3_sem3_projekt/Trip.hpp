#pragma once
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Trip
{

private:
	string name;
	int day_start;
	int month_start;
	int yead_start;
	int day_end; // trip end;
	int month_end;
	int year_end;
	int prize;
	string* toVisit; // place to visit
	size_t arraySize;
public:
	Trip();
	~Trip();
};

