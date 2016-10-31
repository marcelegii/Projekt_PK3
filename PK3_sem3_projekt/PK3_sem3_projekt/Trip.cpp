#include "Trip.hpp"



Trip::Trip()
{
	name = "empty";
	place = "emoty";
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

void Trip::setPlaceToVisit(string s)
{
	place = s;
	istringstream iss(s);
	istringstream iss_temp;
	string t="";
	string d = "";
	while (getline(iss, t, ',')) {
		iss_temp.clear();
		iss_temp.str(t);
			
			iss_temp >> d;
			countryToVisit.push_back(d);
			iss_temp >> d;
			d.erase(0, 1); // erase '['
			d.erase(d.size()-1, 1); // erase ']'
			cityToVisit.push_back(d);
			


		
		
		
	}

	

}

string Trip::getName()
{
	return name;
}

int Trip::getDayStart()
{
	return day_start;
}

int Trip::getMonthStart()
{
	return month_start;
}

int Trip::getYearStart()
{
	return year_start;
}

int Trip::getDayEnd()
{
	return day_end;
}

int Trip::getMonthEnd()
{
	return month_end;
}

int Trip::getYearEnd()
{
	return year_end;
}

int Trip::getPrize()
{
	return prize;
}

ostream & operator<<(ostream & out, Trip & a)
{
	out << a.name << endl;
	out << a.year_start << "." << a.month_start << "." << a.day_start << endl;
	out << a.place << endl;
	out << "prize: " << a.prize << endl;
	out << "transport: " << a.transport << endl;
	return out;
}

