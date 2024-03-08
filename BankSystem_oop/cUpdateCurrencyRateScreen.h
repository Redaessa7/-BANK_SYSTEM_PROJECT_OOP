#pragma once
#include "cScreen.h"
#include "../Librarys/cInput.h"
#include "cCurrency.h"

class cUpdateCurrencyRateScreen : protected cScreen
{
private:
	// print currency info
	static void _printCurrency(cCurrency& currency)
	{

		// empty currency
		if (currency.isEmpty())
		{
			cout << "\n" << cFormat::tab(4) + cFormat::color("This currency not have any information to print ):") << endl;
			return;
		}

		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << cFormat::tab(3) << "[" + cFormat::color(currency.currencyName) + "'s Info]              ";
		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << "\n" << cFormat::tab(2) << "Country       " + cFormat::color(": ") << currency.country;
		cout << "\n" << cFormat::tab(2) << "CurrencyCode  " + cFormat::color(": ") << currency.currencyCode;
		cout << "\n" << cFormat::tab(2) << "CurrncyName   " + cFormat::color(": ") << currency.currencyName;
		cout << "\n" << cFormat::tab(2) << "Rate(1$)      " + cFormat::color(": ") << currency.rate << endl;

	}

	static void _showUpdateRate()
	{
		string currencyCode = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter currencyCode");

		while (currencyCode.size() < 1 || !cCurrency::isExistCode(currencyCode))
		{
			if (currencyCode.size() < 1)
			{
				currencyCode = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " CurrencyCode is invalid, Plz enter another one");
				continue;
			}
			currencyCode = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " CurrencyCode is allredy exist, Plz enter another one");
		}

		// find currency
		cCurrency currency = cCurrency::findByCode(currencyCode);
		// print currency
		_printCurrency(currency);

		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Are you sure you want to update this currency"))
		{
			cout << "\n\n" + cFormat::tab(2) + "Update currency rate " << endl;
			currency.updateRate(cInput::readDlNumber(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter New Rate: "));

			cout << endl << cFormat::tab(4) + cFormat::color("Update Succefully\n", cFormat::txGreen);
				// print currency
			_printCurrency(currency);

		}
	}
public:
	// show update Currency Rate info screen
	static void showUpdateRateScreen()
	{
		system("cls");
		printHeaderOfPage("Update Currency Rate Screen");
		_showUpdateRate();
	}
};

