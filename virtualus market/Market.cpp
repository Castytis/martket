#include "Market.h"

#define UNDEFINED_COMPANY_DATA { }

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD drawing;
meniuInterface meniu;

Market::Market()
{
	companies = UNDEFINED_COMPANY_DATA;
}

Market::~Market()
{
	companies = UNDEFINED_COMPANY_DATA;
}

bool Market::setCompanies(vector<Company> companies) {
	this->companies = companies;
	return true;
}

vector<Company> Market::getCompanies() {
	return companies;
}

bool Market::setCompanyName(string name, int index) {
	this->getCompanies()[index].name = name;
	return true;
}

string Market::getCompanyName(int index) {
	return getCompanies()[index].name;
}

bool Market::setCompanyStock(Stock stock, int index) {
	this->getCompanies()[index].stock = stock;
	return true;
}

Stock Market::getCompanyStock(int index) {
	return getCompanies()[index].stock;
}

bool Market::setCompanyMarketCap(double marketCap, int index) {
	this->getCompanies()[index].marketCap = marketCap;
	return true;
}

double Market::getCompanyMarketCap(int index) {
	return getCompanies()[index].marketCap;
}

double Market::getSumOfCompaniesStocks() {
	double sum = 0;
	int iterator = 0;
	for (Company company :this->getCompanies()) {
		sum += this->getCompanies()[iterator].marketCap / this->getCompanies()[iterator].stock.price ;
		iterator++;
	}
	return sum;
}

void Market::showAllStocks() {
	char userInput;
	for (Company company : this->companies) {
		cout << "Company name: " << company.name << endl;
		cout << "Stock price: " << company.stock.price << endl;
		cout << "Stock price change since last month: " << company.stock.priceChangeBasedOnLastMonth << endl;
		cout << "MarketCap: " << company.marketCap << endl;
		cout << endl;
	}
	cout << endl;
	SetConsoleTextAttribute(console, 0b00001110);
	cout << "Go to back enter Y/N";
	cin >> userInput;
	exitConfirmationControler(userInput);
}

void Market::showOnlyProfitableStocks() {
	char userInput;
	double max = -100;
	std::string name;
	cout << "Profitable stocks" << endl;
	int teigiamas = 0;
	for (Company company : this->companies) {
		if (teigiamas < company.stock.priceChangeBasedOnLastMonth) {
			cout << company.name << " has increased by " << company.stock.priceChangeBasedOnLastMonth << "% since last month" << endl;
		}
		if (company.stock.priceChangeBasedOnLastMonth > max) {
			max = company.stock.priceChangeBasedOnLastMonth;
			name = company.name;
		}
	}
	cout << endl << "Most profitable Stock is " << name << " stock has increased by " << max << "% since last month" << endl << endl;
	SetConsoleTextAttribute(console, 0b00001110);
	cout << "Go to back enter Y/N";
	cin >> userInput;
	exitConfirmationControler(userInput);
}

void Market::showOnlyNonProfitableStocks() {
	char userInput;
	double min = 100;
	std::string name;
	cout << "Not profitable stocks" << endl;
	int teigiamas = 0;
	for (Company company : this->companies) {
		if (teigiamas > company.stock.priceChangeBasedOnLastMonth) {
			cout << company.name << " has decreased by " << company.stock.priceChangeBasedOnLastMonth << "% since last month" << endl;
		}
		if (company.stock.priceChangeBasedOnLastMonth < min) {
			min = company.stock.priceChangeBasedOnLastMonth;
			name = company.name;
		}
	}
	cout << endl << "Least profitable stock is " << name << " stock has decreased by " << min << "% since last month" << endl << endl;
	SetConsoleTextAttribute(console, 0b00001110);
	cout << "Go to back enter Y/N";
	cin >> userInput;
	exitConfirmationControler(userInput);
}

void Market::marketMainMenu() {
	meniu.setCoordinatesXY(20, 10);
	meniu.setColor(0b01001001);
	meniu.setTextColor(0b00000010);
	meniu.setMenuTitle("Main meniu");
	meniu.setMenuChoices({ "1. Show every stock", "2. Profitable stocks", "3. Nonprofitable stocks", "4. Exit" });
}

void Market::marketMainMenuControler() {
	char getInput;
	SetConsoleTextAttribute(console, 0b00001100);
	meniuisvedimas();
	marketMainMenu();
	getInput = meniu.waitForUserInput();
	if (getInput == '1') {
		system("cls");
		SetConsoleTextAttribute(console, 0b00001110);
		showAllStocks();
	}
	else if (getInput == '2') {
		system("cls");
		SetConsoleTextAttribute(console, 0b00001101);
		showOnlyProfitableStocks();
	}
	else if (getInput == '3') {
		system("cls");
		SetConsoleTextAttribute(console, 0b00000101);
		showOnlyNonProfitableStocks();

	}
	else if (getInput == '4') {
		drawing = { DEFAULT_EXIT_MESSAGE_POSITION_X, DEFAULT_EXIT_MESSAGE_POSITION_Y };
		SetConsoleCursorPosition(console, drawing);
		exit(0);
	}
	else {
		errorOutput();
	}
}

void Market::exitConfirmationControler(char userInput) {
	if (userInput == 'Y' || userInput == 'y') {
		system("cls");
		marketMainMenuControler();
	}
	else if (userInput == 'N' || userInput == 'n') {
		system("cls");
		SetConsoleTextAttribute(console, 0b00001011);
		exit(0);
	}
	else {
		system("cls");
		errorOutput();
	}
}

void Market::errorOutput() {
	system("cls");
	SetConsoleTextAttribute(console, 0b00000100);
	cout << "Next time Please enter valid option!..";
	Sleep(DEFAULT_SLEEP_TIME_FOR_MENU * 4);
	marketMainMenuControler();
}

/*-----------------------------------------------------------------------------------------------------------------------------------*/

meniuInterface::meniuInterface()
{
}

meniuInterface::~meniuInterface()
{
}

bool meniuInterface::setCoordinateX(int coodinateX) {
	this->coordinateX = coodinateX;
	return true;
}

int meniuInterface::getCoordinateX() {
	return coordinateX;
}

bool meniuInterface::setCoordinateY(int coodinateY) {
	this->coordinateY = coodinateY;
	return true;
}

int meniuInterface::getCoordinateY() {
	return coordinateY;
}

bool meniuInterface::setCoordinatesXY(int coodinateX, int coodinateY) {
	this->coordinateX = coodinateX;
	this->coordinateY = coodinateY;
	return true;
}

bool meniuInterface::setColor(short color) {
	this->windowColor = color;
	return true;
}

short meniuInterface::getColor() {
	return windowColor;
}

bool meniuInterface::setMenuChoices(vector <string> menuChoices) {
	this->menuChoices = menuChoices;
	return true;
}

vector <string> meniuInterface::getMenuChoices() {
	return menuChoices;
}

bool meniuInterface::setMenuTitle(string menuTitle) {
	this->menuTitle = menuTitle;
	return true;
}

string meniuInterface::getMenuTitle() {
	return menuTitle;
}

bool meniuInterface::setTextColor(short textColor) {
	this->textColor = textColor;
	return true;
}

short meniuInterface::getTextColor() {
	return textColor;
}

void meniuInterface::setWindowColor(short color) {
	SetConsoleTextAttribute(console, color);
}

void meniuInterface::setPrintedTextColor(short color) {
	SetConsoleTextAttribute(console, color);
}

void meniuInterface::setupBorderColorAndPosition(short color, int coordinateX, int coordinateY) {
	setWindowColor(color);
	drawing.X = coordinateX;
	drawing.Y = coordinateY;
	SetConsoleCursorPosition(console, drawing);
};

void meniuInterface::drawBorder() {
	for (int iterateY = this->getCoordinateY(); iterateY < DEFAULT_MENU_SIZE_Y + this->getCoordinateY(); iterateY++) {
		for (int iterateX = this->getCoordinateX(); iterateX < DEFAULT_MENU_SIZE_X + this->getCoordinateX(); iterateX++) {
			setupBorderColorAndPosition(this->getColor(), iterateX, iterateY);
			if (iterateX == this->getCoordinateX() && iterateY == this->getCoordinateY()) {
				cout << TOP_LEFT_CORNER;
			}
			else if (iterateX == DEFAULT_MENU_SIZE_X && iterateY == this->getCoordinateY()) {
				cout << TOP_RIGHT_CORNER;
			}
			else if (iterateX == this->getCoordinateX() && iterateY == DEFAULT_MENU_SIZE_Y) {
				cout << BOTTOM_LEFT_CORNER;
			}
			else if (iterateX == DEFAULT_MENU_SIZE_X && iterateY == DEFAULT_MENU_SIZE_Y) {
				cout << BOTTOM_RIGHT_CORNER;
			}
			else if ((iterateX > this->getCoordinateX() && iterateX < DEFAULT_MENU_SIZE_X) && (iterateY == DEFAULT_MENU_SIZE_Y || iterateY == this->getCoordinateY())) {
				cout << HORIZONTAL_LINE;
			}
			else if ((iterateY > this->getCoordinateY() && iterateY < DEFAULT_MENU_SIZE_Y) && (iterateX == DEFAULT_MENU_SIZE_X || iterateX == this->getCoordinateX())) {
				cout << VERTICAL_LINE;
			}
			drawing.X++;
		}
		drawing.Y++;
	}
}

void meniuInterface::drawTitle() {
	drawBorder();
	setupBorderColorAndPosition(this->getColor(), this->getCoordinateX() + MENU_TITLE_OFFSET + CENTERED_TEXT_OFFSET, this->getCoordinateY() + MENU_TITLE_OFFSET);
	setPrintedTextColor(this->getTextColor());
	cout << this->getMenuTitle();
}

void meniuInterface::drawMenuChoices() {
	drawTitle();
	setupBorderColorAndPosition(this->getColor(), this->getCoordinateX() + CENTERED_TEXT_OFFSET + CHOICES_TEXT_OFFSET, this->getCoordinateY() + MENU_TITLE_OFFSET + CHOICES_TEXT_OFFSET);
	setPrintedTextColor(this->getTextColor());
	for (auto iterator = 0; iterator < this->getMenuChoices().size(); iterator++) {
		drawing.X = this->getCoordinateX() + CENTERED_TEXT_OFFSET + CHOICES_TEXT_OFFSET;
		drawing.Y++;
		SetConsoleCursorPosition(console, drawing);
		cout << this->getMenuChoices()[iterator] << endl;
	}
}

char meniuInterface::waitForUserInput() {
	char choice;
	drawMenuChoices();
	setupBorderColorAndPosition(this->getColor(), this->getCoordinateX() + CENTERED_TEXT_OFFSET + CHOICES_TEXT_OFFSET - INPUT_MESSAGE_OFFSET, this->getCoordinateY() + MENU_TITLE_OFFSET + USER_INPUT_OFFSET);
	setPrintedTextColor(this->getTextColor());
	cout << "Enter your option";
	drawing.Y++;
	SetConsoleCursorPosition(console, drawing);
	cin >> choice;
	return choice;
}

void Company::meniuisvedimas() {
	cout << endl;
	cout << "      /$$    /$$ /$$             /$$                         /$$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     | $$   | $$|__/            | $$                        | $$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     | $$   | $$ /$$  /$$$$$$  /$$$$$$   /$$   /$$  /$$$$$$ | $$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     |  $$ / $$/| $$ /$$__  $$|_  $$_/  | $$  | $$ |____  $$| $$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "       | $$ $$/ | $$| $$   __/  | $$    | $$  | $$  /$$$$$$$| $$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "        | $$$/  | $$| $$        | $$ /$$| $$  | $$ /$$__  $$| $$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "         | $/   | $$| $$        |  $$$$/|  $$$$$$/|  $$$$$$$| $$ " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "          _/    |__/|__/         \___/   \______/  \_______/|__/ " << endl; Sleep(DEFAULT_SLEEP_50);

	cout << endl;
	cout << "      /$$      /$$                     /$$                   /$$    " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     | $$$    /$$$                    | $$                  | $$    " << endl; Sleep(DEFAULT_SLEEP_50 / 2);
	cout << "     | $$$$  /$$$$  /$$$$$$   /$$$$$$ | $$   /$$  /$$$$$$  /$$$$$$  " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     | $$ $$/$$ $$ |____  $$ /$$__  $$| $$  /$$/ /$$__  $$|_  $$_/  " << endl; Sleep(DEFAULT_SLEEP_50 / 2);
	cout << "     | $$  $$$| $$  /$$$$$$$| $$   __/| $$$$$$/ | $$$$$$$$  | $$    " << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     | $$   $ | $$ /$$__  $$| $$      | $$_  $$ | $$_____/  | $$ /$$" << endl; Sleep(DEFAULT_SLEEP_50 / 2);
	cout << "     | $$  /  | $$|  $$$$$$$| $$      | $$    $$|  $$$$$$$  |  $$$$/" << endl; Sleep(DEFAULT_SLEEP_50);
	cout << "     |__/     |__/ |_______/|__/      |__/   __/  _______/   | ___/ " << endl; Sleep(DEFAULT_SLEEP_50 / 2);
	Sleep(DEFAULT_SLEEP_TIME_FOR_MENU);
	system("cls");
}
