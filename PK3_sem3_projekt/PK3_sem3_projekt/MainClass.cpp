#include "MainClass.hpp"

MainClass* MainClass::instance;


MainClass::MainClass()
{
	 holidayInCatalog = 0;
	 tripInCatalog = 0;
	 day = 0; 
	 month = 0;
	 year = 0;
	 type=' ';
	 duartion = 0;;
	 maxPrize = 0;;

}


MainClass::~MainClass()
{
}

MainClass* MainClass::GetInstance() {
	if (!instance) {
		instance = new MainClass();
		atexit(freePointer);
	}

	return instance;
}

void MainClass::freePointer(void)
{
	{

		delete GetInstance();
	}
}

void MainClass::mainLoop(int argc, char  **argv)
{
	string catalogPath = " ";



	const int letterInWord = 1;
	cout << "argc=" << argc << endl;
	if (argc == 13) {

		for (int i = 0; i < argc; i++) {
			if (argv[i][0] == '-') {
				char switcher = argv[i][letterInWord];
				switch (switcher)
				{
				case 'k':
					//catalog
					catalogPath = argv[i + 1]; // catalog path
					

					break;
				case 'o':
					//set output filename


					break;
				case 'r':
					//type of trip
					type = argv[i + 1];
					break;
				case 't':
					//date
					stringToDate(argv[i + 1]);

					break;
				case 'd':
					//lenght of trip
					try {
						duartion = stoi(argv[i + 1]);
					}
					catch (std::invalid_argument&) {
						cout << "error 404!" << endl;
						::exit(1);
					}

					break;
				case 'c':
					//max prize
					try {
						maxPrize = stoi(argv[i + 1]);
					}
					catch (std::invalid_argument&) {
						cout << "error 404!" << endl;
						::exit(1);
					}

					break;


				default:
					cout << "Wrong parametr in main function. ::exit program" << endl;
					::exit(1);
					break;

				}

			}
		}
	}
	else {
		cout << "Wrong parametr in main function. ::exit program" << endl;
		::exit(1);
	}

	howManyfilesInCatalog(catalogPath);
	loadHolidaysFromFile(catalogPath);
	loadTripsFromFile(catalogPath);
	dataValidation();

	/*read from file to array and set objects values
	if WP in name --> Holidays*/


}


void MainClass::stringToDate(string myDate, vector<Holidays>::iterator& it)
{
	string l;
	int counter = 0;
	istringstream iss(myDate); // to getLine from istringstream
	while (getline(iss, l, '.')) { // skip char'.' 
		++counter;
		switch (counter) {
		case 1:
			it->setYearStart(stoi(l));
			break;

		case 2:
			it->setMonthStart(stoi(l));
			break;

		case 3:
			it->setDayStart(stoi(l));
			break;

		default:
			std::cout << "error." << endl;
			break;
		}
		
	
		
	}
}

void MainClass::stringToDate(string myDate, vector<Trip>::iterator & it, int checker)
{
	string l;
	int counter = 0;
	istringstream iss(myDate); // to getLine from istringstream
	if (checker == 0) {
		while (getline(iss, l, '.')) { // skip char'.' 
			++counter;
			switch (counter) {
			case 1:
				it->setYearStart(stoi(l));
				break;

			case 2:
				it->setMonthStart(stoi(l));
				break;

			case 3:
				it->setDayStart(stoi(l));
				break;

			default:
				std::cout << "error." << endl;
				break;
			}



		}
	}



	if (checker == 1) {
		while (getline(iss, l, '.')) { // skip char'.' 
			++counter;
			switch (counter) {
			case 1:
				it->setYearEnd(stoi(l));
				break;

			case 2:
				it->setMonthEnd(stoi(l));
				break;

			case 3:
				it->setDayEnd(stoi(l));
				break;

			default:
				std::cout << "error." << endl;
				break;
			}



		}
	}
}

void MainClass::stringToDate(string myDate)
{
	string l;
	int counter = 0;
	istringstream iss(myDate); // to getLine from istringstream
	while (getline(iss, l, '.')) { // skip char'.' 
		++counter;
		switch (counter) {
		case 1:
			try {
				year = stoi(l);
			}
			catch (std::invalid_argument&) {
				cout << "error. ::exit program" << endl;
				::exit(1);
			}
			break;

		case 2:
			try {
				month = stoi(l);
			}
			catch (std::invalid_argument&) {
				cout << "error. ::exit program" << endl;
				::exit(1);
			}
			break;

		case 3:
			try {
				day = stoi(l);
			}
			catch (std::invalid_argument&) {
				cout << "error. ::exit program" << endl;
				::exit(1);
			}
			break;

		default:
			std::cout << "error." << endl;
			break;
		}



	}
}

void MainClass::howManyfilesInCatalog(string myPath) {

	path p("");
	cout << myPath << endl;
	p += myPath;


	for (auto i = directory_iterator(p); i != directory_iterator(); i++)
	{
		if (!is_directory(i->path())) //we eliminate directories
		{

			cout << i->path().filename().string() << endl;
			if (i->path().filename().string().find("holiday") != string::npos) // if doesn't exist return string::npos
			{
				holidayInCatalog++;
				holidayFiles.push_back(i->path().filename().string());

			}
			else if (i->path().filename().string().find("trip") != string::npos)
			{
				tripInCatalog++;
				tripFiles.push_back(i->path().filename().string());

			}

		}
		else
			continue;
	}
	cout << "holidays=" << holidayInCatalog << endl;
	cout << "trip=" << tripInCatalog << endl;
	//for (auto &h : holiday) cout << h << endl;

}

void MainClass::loadHolidaysFromFile(string myPath)
{
	string _myPath = " ";
	string line;
	std::ifstream ifs;


	_myPath = myPath + "/";
	holiday.reserve(holiday.capacity()); //realocate size of holiday
	for (auto &tab : holidayFiles) holiday.push_back(Holidays()); // fill vector

	std::vector<Holidays>::iterator it = holiday.begin(); //iterator to holiday vector

	for (auto &tab : holidayFiles) {			//reference to, not create a copy

		if (it != holiday.end()) {
			_myPath += tab;				 //path to the tripFile
			ifs.open(_myPath);           // none value to return

			if (!ifs.is_open()) {
				cout << " Failed to open " << tab << endl;
			}
			else {
				int switcher = 0;
				cout << "file " << tab << " is opened ok" << endl;
				while (getline(ifs, line)) {

					it->pushToVector(line);

					switcher++;
					switch (switcher) {
					case 1:
						it->setName(line);
						break;
					case 2:
						stringToDate(line, it); // convert string and set date in object
						break;
					case 3:
						it->setDuaration(stoi(line));
						break;
					case 4:
						it->setCity(line);
						break;
					case 5:
						it->setCountry(line);
						break;
					case 6:
						it->setHolidayPrize(stringToInt(line));
						break;
					case 7:
						it->setAutocarPrize(PrizeToInt(line));
						break;
					case 8:
						it->setPlanePrize(PrizeToInt(line));
						break;
					}

				}

			}
			//cout << *it << endl;
			it++;
		}
		//ifs.close();

	}
	
}


void MainClass::loadTripsFromFile(string myPath)
{
	string _myPath = " ";
	string line;
	std::ifstream ifs;


	_myPath = myPath + "/";
	trip.reserve(trip.capacity()); //realocate size of trip
	for (auto &tab : tripFiles) trip.push_back(Trip()); // fill vector

	std::vector<Trip>::iterator it = trip.begin(); //iterator to trip vector

	for (auto &tab : tripFiles) {			//reference to, not create a copy

		if (it != trip.end()) {
			_myPath += tab;				 //path to the tripsFile
			ifs.open(_myPath);           // none value to return

			if (!ifs.is_open()) {
				cout << " Failed to open " << tab << endl;
			}
			else {
				int switcher = 0;
				cout << "file " << tab << " is opened ok" << endl;
				while (getline(ifs, line)) {

					it->pushToVector(line);

					switcher++;
					switch (switcher) {
					case 1:
						it->setName(line);
						break;
					case 2:
						stringToDate(line, it,0); // convert string and set date in object
						break;
					case 3:
						stringToDate(line, it, 1);
						break;
					case 4:
						it->setPlaceToVisit(line);
						break;
					case 5:
						it->setPrize(stringToInt(line));
						break;
					case 6:
						it->setTransport((line));
						break;

					}

				}

			}
		//	cout << *it << endl;
			it++;
		}
		//ifs.close();

	}


}

bool MainClass::toDataValidation(Trip &it)
{
	
	if (year <= it.getYearStart() && month <= it.getMonthStart() && day <= it.getDayStart()) return true;
	else return false;
	
	
}

bool MainClass::toDataValidation(Holidays &it)
{

	if (year <= it.getYearStart() && month <= it.getMonthStart() && day <= it.getDayStart()) return true;
	else return false;


}

void MainClass::dataValidation()
{
	
	char switcher = type[0];
	switch (switcher) {
	case 'o':
		for (auto & it : trip) {
			if (  ( maxPrize >= it.getPrize()) && toDataValidation(it)==true && ( "WO: Dookola"==it.getName() )  ) {
				std::cout << "Trips: " << endl;
				cout << it << endl;
			}
		}
		
		break;

	case 'p':
		break;

	case 'l':
		break;

	case 'd':
		for (auto & it : trip) {
			if (maxPrize >= it.getPrize() && toDataValidation(it) == true ) {
				std::cout << "Trips: " << endl;
				cout << it << endl;
			}
		}

			for (auto & it : holiday) {
				if (maxPrize >= (it.getAutocarPrize() + it.getHolidayPrize()  )  || maxPrize > (it.getPlanePrize() + it.getHolidayPrize()) && toDataValidation(it) == true) {
					std::cout << "Holidays: " << endl;
					cout << it << endl;
				}
		}
		break;

	default:
		cout << "Wrong parameters. ::exit the program" << endl;
		//::exit(1);
		break;
	}
	
	
	
}

int MainClass::stringToInt(string s)
{
	int d;
	istringstream iss(s);
	string t;
	while (getline(iss, t, 'P')) {// skip char 'P' 
		try {
			
			stoi(t);
			
		}
		catch (std::invalid_argument&) {
			continue;
		}
		d = stoi(t);
		cout << "d=" << d << endl;
	}
	
	return  d;
}

int MainClass::PrizeToInt(string s)
{
	istringstream iss(s);
	string t;
	int d;
	iss >> t >> t; // to get prize from string, e.g. 2000PLN from "Autokar 2000PLN"
	iss.clear();
	iss.str(t);
	while (getline(iss, t, 'P')) {// skip char 'P' 
		try {
			
			stoi(t);

		}
		catch (std::invalid_argument&) {
			continue;
		}
		d = stoi(t);
		
	}

	return  d;
	
}

