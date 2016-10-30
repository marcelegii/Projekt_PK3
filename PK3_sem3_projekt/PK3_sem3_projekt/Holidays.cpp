#include "Holidays.hpp"





Holidays::Holidays()
{
	string name=" ";
	int day_start=0;
	int month_start=0;
	int yea_start=0;
	int duration=0;// how long is your holidays?	 
	double holiday_prize=0.0;
	double autocar_prize=0.0;
	double plane_prize=0.0;
}

Holidays::~Holidays()
{
}

 void Holidays::setName(string n)
{ 
	name = n;
}

 void Holidays::setDayStart(int d)
{
	day_start = d;

}

 void Holidays::setMonthStart(int m)
{
	month_start = m;
}

 void Holidays::setYearStart(int y)
{
	year_start = y;

}

 void Holidays::setDuaration(int d)
{
	duration = d;
}

 void Holidays::setHolidayPrize(int h)
{
	holiday_prize = h;
}

 void Holidays::setAutocarPrize(int a)
{
	autocar_prize = a;
}

 void Holidays::setPlanePrize(int p)
{
	plane_prize = p;
}

 void Holidays::pushToVector(string s)
 {
	 dataInObject.push_back(s);
 }

ostream & operator<<(ostream & out, Holidays & a)
{
	out << a.name << endl;
	out << a.day_start << endl;
	out << a.month_start<<endl;
	out << a.year_start << endl;
	return out;
}
