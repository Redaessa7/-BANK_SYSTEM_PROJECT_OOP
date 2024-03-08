#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "cScreen.h"
#include "cCurrency.h"

class cListOfCurrencies : protected cScreen
{
private:
	static void _printCurrencyList(vector<cCurrency>& CurrencyList)
	{
		//check if list of clients is empty
		if (CurrencyList.empty())
		{
			cout << "\nNo found any currency to display it on screen, plz add some." << endl;
			return;
		}

		cout << "\n\n" << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(2) << "\t\t\t\tNumber Of Currencies (" << cFormat::colorbg(to_string(CurrencyList.size()), cFormat::txBlack, cFormat::bgYellow) << ") currency(s)\t\t\t\t" << endl;
		cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(2) << cFormat::color("|Country                    |CurrencyCode       |CurrencyName                 |Rate         |") << endl;
		cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;

		for (cCurrency& currency : CurrencyList)
		{
			cout << cFormat::tab(2) << cFormat::color("|") << left << setw(27) << currency.country << cFormat::color("|") << left << setw(19) << currency.currencyCode;
			cout << cFormat::color("|") << left << setw(29) << currency.currencyName << cFormat::color("|") << left << setw(13) << currency.rate << cFormat::color("|\n");
			cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		}
		cout << endl;
	}
public:

	// show list of currency screen
	static void showListOfCurrencyScreen()
	{
		system("cls");
		vector<cCurrency> CurrencyList = cCurrency::getAllCurrencies();
		string title = "List OF Currencies Screen", subTitle = "Number Of Currencies (" + to_string(CurrencyList.size()) + ") Currency(s).";
		printHeaderOfPage(title, subTitle);
		_printCurrencyList(CurrencyList);
	}
};

