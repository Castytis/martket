#include "Date.h"
#include "Market.h"
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


Company::Company() 
{
	name = DEFAULT_NAME;
	stock = UNDEFINED_STOCK_DATA;
	marketCap = DEFAULT_MARKET_CAP;
}

Company::~Company()
{
	name = DEFAULT_NAME;
	stock = UNDEFINED_STOCK_DATA;
	marketCap = DEFAULT_MARKET_CAP;
}