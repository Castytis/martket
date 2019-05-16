#pragma once
#include <vector>
#include "./Date.h"

#define VERTICAL_LINE char(179)
#define HORIZONTAL_LINE char(196)
#define TOP_LEFT_CORNER char(218)
#define TOP_RIGHT_CORNER char(191)
#define BOTTOM_LEFT_CORNER char(192)
#define BOTTOM_RIGHT_CORNER char(217)
#define MENU_TITLE_OFFSET 2
#define CENTERED_TEXT_OFFSET 10
#define CHOICES_TEXT_OFFSET 2
#define USER_INPUT_OFFSET 9
#define INPUT_MESSAGE_OFFSET 4

#define DEFAULT_MENU_SIZE_X 60
#define DEFAULT_MENU_SIZE_Y 24

#define DEFAULT_EXIT_MESSAGE_POSITION_X 0
#define DEFAULT_EXIT_MESSAGE_POSITION_Y 25

class Market : public Company
{
private:
	std::vector<Company> companies;
public:
	bool setCompanies(vector<Company>);
	vector<Company> getCompanies();
	bool setCompanyName(string, int);
	string getCompanyName(int);
	bool setCompanyStock(Stock, int);
	Stock getCompanyStock(int);
	bool setCompanyMarketCap(double, int);
	double getCompanyMarketCap(int);

	double getSumOfCompaniesStocks();
	void showAllStocks();
	void showOnlyProfitableStocks();
	void showOnlyNonProfitableStocks();

	void marketMainMenu();
	void marketMainMenuControler();
	void exitConfirmationControler(char);
	void errorOutput();
	


	Market();
	~Market();
};

class meniuInterface : public Market
{
private:
	int coordinateX, coordinateY;
	short windowColor, textColor;
	vector <string> menuChoices;
	string menuTitle;

public:
	bool setCoordinateX(int);
	int getCoordinateX();
	bool setCoordinateY(int);
	int getCoordinateY();
	bool setCoordinatesXY(int, int);
	bool setColor(short);
	short getColor();
	bool setMenuChoices(vector <string>);
	vector <string> getMenuChoices();
	bool setMenuTitle(string);
	string getMenuTitle();

	bool setTextColor(short);
	short getTextColor();
	
	void setupBorderColorAndPosition(short, int, int);
	void setWindowColor(short);
	void setPrintedTextColor(short);
	void drawBorder();
	void drawTitle();
	void drawMenuChoices();
	char waitForUserInput();

	meniuInterface();
	~meniuInterface();
};