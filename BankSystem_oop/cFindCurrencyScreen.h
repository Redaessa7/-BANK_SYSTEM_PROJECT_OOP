#pragma once
#include "cScreen.h"
#include "../Librarys/cInput.h"
#include "cCurrency.h"
#include "../Librarys/rMenu.h"
class cFindCurrencyScreen : protected cScreen
{
private:

	enum findway{efindByCode = 1, efindByCountrty = 2};

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
	
	static string _findByCodeOrCountry(bool findbyCode = true)
	{
		system("cls");
		cout << endl;
		string input;
		if (findbyCode)
		{
			input = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter currencyCode");

			while (input.size() < 1 || !cCurrency::isExistCode(input))
			{
				if (input.size() < 1)
				{
					input = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " CurrencyCode is invalid, Plz enter another one");
					continue;
				}
				input = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " CurrencyCode is not exist, Plz enter another one");
			}
		}
		else
		{
			input = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter Country");

			while (input.size() < 3 || !cCurrency::isExist(input))
			{
				if (input.size() < 3)
				{
					input = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Country is invalid, Plz enter another one");
					continue;
				}
				input = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Country is not exist, Plz enter another one");
			}
		}

		return input;
	}
	
	static cCurrency _performFindCurrency(findway choiceway)
	{
		switch (choiceway)
		{
		case cFindCurrencyScreen::efindByCode:
			return cCurrency::findByCode(_findByCodeOrCountry());
			break;
		case cFindCurrencyScreen::efindByCountrty:
			return cCurrency::findByCountry(_findByCodeOrCountry(false));
			break;
		default:
			break;
		}

	}

	static void _showFindCurrency()
	{
		vector<string> _items = { "* Currency Code", "* Country" };

		cFormat::cursPosition(45, 7);
		cout << "Find By :\n";
		// draw item menu
		rMenu mainMenu;
		mainMenu.set_xy(48, 9);
		mainMenu.color(7, 6);

		short choice = mainMenu.menu(_items);
		// find currency
		cCurrency currency = _performFindCurrency(findway(choice+1));
		if (!currency.isEmpty())
		{
			// print currency
			cout << endl << cFormat::tab(2) << cFormat::color("Found Currency (^_^)", cFormat::txGreen) << endl;
			_printCurrency(currency);
		}
		else
		{
			cout << endl << cFormat::tab(2) << cFormat::color("Not Found Currency (X_X)") << endl;
		}

	}

public:
	// show find currency screen
	static void showFindCurrencyScreen()
	{
		system("cls");
		printHeaderOfPage("Find Currency Screen");
		_showFindCurrency();
	}
};

