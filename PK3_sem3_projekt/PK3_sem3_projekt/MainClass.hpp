#pragma once
#include <windows.h>
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include<boost/filesystem.hpp>
#include <fstream>
#include"./Holidays.hpp"
#include"./Trip.hpp"


using namespace std;
using namespace boost::filesystem;


class MainClass
{
private:
	static MainClass* instance;
	int holidayInCatalog; 
	int tripInCatalog;
	vector<string> tripFiles; // names of tripFiles
	vector<string> holidayFiles;// names of holidayFiles
	vector<Holidays> holiday;
	vector<Trip> trip; 
	vector<string> linesFromFile;

	void stringToDate(string, vector<Holidays>::iterator&);
	void stringToDate(string, vector<Trip>::iterator&,int);
	void howManyfilesInCatalog(string);
	void loadHolidaysFromFile(string);
	void loadTripsFromFile(string);
	int stringToInt(string);

	int PrizeToInt(string);

public:
	MainClass();
	~MainClass();
	static MainClass* GetInstance();
	static void MainClass::freePointer(void); //to delete static *GetInstance
	void mainLoop(int argc, char** argv);

};

