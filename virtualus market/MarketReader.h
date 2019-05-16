#pragma once
#include "Market.h"

static class MarketReader : public Market
{
public:
	
	static Market readMarket(ifstream& myfile);
	
	static Company readCompany(ifstream& myfile, int);

	static Stock readStock(ifstream& myfile);

	MarketReader();
	~MarketReader();
};