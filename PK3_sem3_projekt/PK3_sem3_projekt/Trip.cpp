#include "Trip.hpp"



Trip::Trip()
{
	name = "empty";
	day_start = 0;
	month_start = 0;
	year_start = 0;
	day_end = 0;
	month_end = 0;
	year_end = 0;
	prize= 0;
}


Trip::~Trip()
{
}
void Trip::setName(string n)
{
	name = n;
}

void Trip::setDayStart(int d)
{
	day_start = d;

}

void Trip::setMonthStart(int m)
{
	month_start = m;
}

void Trip::setYearStart(int y)
{
	year_start = y;

}



void Trip::setDayEnd(int d)
{
	day_end = d;

}

void Trip::setMonthEnd(int m)
{
	month_end = m;
}

void Trip::setYearEnd(int y)
{
	year_end = y;

}

void Trip::setPrize(int p)
{
	prize = p;
}
void Trip::setTransport(string t)
{
	transport = t;
}
void Trip::pushToVector(string s)
{
	dataInObject.push_back(s);
}

ostream & operator<<(ostream & out, Trip & a)
{
	out << a.name << endl;
	out << a.year_start << "." << a.month_start << "." << a.day_start << endl;
	out << "prize: " << a.prize << endl;
	out << "transport: " << a.transport << endl;
	return out;
}

