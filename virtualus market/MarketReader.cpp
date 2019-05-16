#include "MarketReader.h"

MarketReader::MarketReader()
{
}

MarketReader::~MarketReader()
{
}

Company MarketReader::readCompany(ifstream& myfile, int index) {
	Company company;
	myfile >> company.name;
	company.stock = readStock(myfile);
	myfile >> company.marketCap;
	return company;
}

Stock MarketReader::readStock(ifstream& myfile) {
	Stock stock;
	myfile >> stock.price;
	myfile >> stock.priceChangeBasedOnLastMonth;
	return stock;
}

  Market MarketReader::readMarket(ifstream& myfile) {
	  Market market;
	  vector <Company> temporaryInput;
	  int index = 0;
	while (!myfile.eof()) {
		temporaryInput.push_back(readCompany(myfile, index));
		index++;
	}
	market.setCompanies(temporaryInput);
	return market;
}