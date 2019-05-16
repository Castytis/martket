#include "Stock.h"

#define DEFAULT_PRICE 0

Stock::Stock()
{
	price = DEFAULT_PRICE;
	priceChangeBasedOnLastMonth = DEFAULT_PRICE;
}

Stock::~Stock()
{
	price = DEFAULT_PRICE;
	priceChangeBasedOnLastMonth = DEFAULT_PRICE;
}
