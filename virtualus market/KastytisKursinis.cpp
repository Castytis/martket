#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <sstream>
#include <vector>
#include <list>
#include "./MarketReader.h"
#include "./Date.h"

int main()
{
	Market market;
	ifstream myfile("Market.txt");
	market = MarketReader::readMarket(myfile);
	//cout << market.getSumOfCompaniesStocks();
	//market.showAllStocks();
	//market.showOnlyProfitableStocks();
	market.marketMainMenuControler();
	//system("pause");

	return 0;
}







