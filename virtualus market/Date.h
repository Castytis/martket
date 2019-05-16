#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <sstream>
#include <list>
#include "./Stock.h"

using namespace std;

#define DEFAULT_SLEEP_50 75
#define UNDEFINED_STOCK_DATA { }
#define DEFAULT_SLEEP_TIME_FOR_MENU 500
#define DEFAULT_NAME "No_Name"
#define DEFAULT_MARKET_CAP 0

class Company{
public:
	string name;
	Stock stock;
	double marketCap;
	void meniuisvedimas();

	Company();
	~Company();
};

#endif