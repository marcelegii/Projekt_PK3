#include "Holidays.hpp"





Holidays::Holidays()
{
	 name="empty";
	 day_start=0;
	 month_start=0;
	 year_start=0;
	 duration=0;// how long is your holidays?	
	 city = "empty";
	 country = "empty";
	 holiday_prize=0;
	 autocar_prize=0;
	 plane_prize=0;
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

 void Holidays::setCity(string c)
 {
	 city = c;
 }

 void Holidays::setCountry(string c)
 {
	 country = c;
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
	out << a.year_start <<"."<< a.month_start <<"."<<a.day_start << endl;
	out << a.duration << endl;
	out << a.city << endl;
	out << a.country << endl;
	out << "Holiday prize: "<<a.holiday_prize << endl;
	out << "Autocar prize: " << a.autocar_prize << endl;
	out << "Plane prize: " << a.plane_prize << endl;
	return out;
}
