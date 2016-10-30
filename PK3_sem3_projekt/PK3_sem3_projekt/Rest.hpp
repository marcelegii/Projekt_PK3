#pragma once
#include<iostream>
#include<string>


using namespace std;


class Rest
{
protected:
	string name;
	int day_start;
	int month_start;
	int yead_start;




public:
	Rest();
	Rest(string n, int d, int m, int y) : name(n), day_start(d), month_start(m), yead_start(y) {}
	virtual ~Rest();

protected:
	void readFromFile();
};

