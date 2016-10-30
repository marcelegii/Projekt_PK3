#include "MainClass.hpp"

MainClass* MainClass::instance;


MainClass::MainClass()
{
	holidayInCatalog = 0;
	tripInCatalog = 0;
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

					break;
				case 't':
					//date


					break;
				case 'd':
					//lenght of trip


					break;
				case 'c':
					//max prize

					break;


				default:
					cout << "Wrong parametr in main function. Exit program" << endl;
					exit(1);
					break;

				}

			}
		}
	}
	else {
		cout << "Wrong parametr in main function. Exit program" << endl;
		exit(1);
	}

	howManyfilesInCatalog(catalogPath);
	loadFromFile(catalogPath);


	/*read from file to array and set objects values
	if WP in name --> Holidays*/


}


void MainClass::stringToDate(string myDate, vector<Holidays>::iterator& it)
{
	string l;
	int counter = 0;
	istringstream iss(myDate); // to getLine from istringstream
	while (getline(iss, l, '.')) {
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

void MainClass::loadFromFile(string myPath)
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
			_myPath += tab;				 //path to the holidaysFile
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
						cout << *it << endl;
						break;
					case 3:
						it->sstoi(line);
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:
						break;
					}
				}
				
			}
			it++;
		}
		//ifs.close();
	}

}

