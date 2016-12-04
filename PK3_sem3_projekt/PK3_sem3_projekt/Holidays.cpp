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

 string Holidays::getName()
 {
	 return name;
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

int Holidays::getDayStart()
{
	return day_start;
}

int Holidays::getMonthStart()
{
	return month_start;
}

int Holidays::getYearStart()
{
	return year_start;
}

int Holidays::getDuaration()
{
	return duration;
}

string Holidays::getCity()
{
	return city;
}

string Holidays::getCountry()
{
	return country;
}

int Holidays::getHolidayPrize()
{
	return holiday_prize;
}

int Holidays::getAutocarPrize()
{
	return autocar_prize;
}

int Holidays::getPlanePrize()
{
	return plane_prize;
}

void Holidays::toOutputFile(string filename,int lines)
{
	
	if (lines == 1) { // clear file

		std::ofstream outFile(filename, std::ofstream::trunc);
		if (!outFile.is_open()) {
			cout << "error" << endl;
			exit(1);
		}
		outFile.close();
	}
	
	std::ofstream outFile(filename, std::ofstream::out| std::ofstream::app);
	if (!outFile.is_open()) {
		cout << "error" << endl;
		exit(1);
	}

	else {
		outFile << lines <<". "<< name << endl;
		outFile << "Kraje: " << country << endl;
		outFile << "Miejscowosc: " << city << endl;
		outFile << "Koszt: " << holiday_prize + autocar_prize << " (Autokar)" << endl;
		outFile << "Koszt: " << holiday_prize + plane_prize << " (Plane)" << endl;
		outFile << "Termin: " << year_start << "." << month_start << "." << day_start << endl<<endl;

		outFile.close();
	}
}
