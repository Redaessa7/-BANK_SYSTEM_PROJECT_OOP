#pragma once
#include <iostream>
#include "cScreen.h"
#include "../Librarys/rMenu.h"
#include "cListOfCurrencies.h"
#include "cFindCurrencyScreen.h"
#include "cUpdateCurrencyRateScreen.h"
#include "cCurrencyCalcScreen.h"

class cCurrencyScreen : protected cScreen
{
	enum eCurrecnyMenuChoice
	{
		eListOfCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculate = 4, eMainMenue = 5,
	};

	// screen
	static void _showListOfCurrenciesScreen()
	{
		cListOfCurrencies::showListOfCurrencyScreen();
	}
	static void _showFindCurrencyScreen()
	{
		cFindCurrencyScreen::showFindCurrencyScreen();
	}
	static void _showUpdateRateScreen()
	{
		cUpdateCurrencyRateScreen::showUpdateRateScreen();
	}
	static void _showCurrencyCalcScreen()
	{
		cCurrencyCalcScreen::showCurrencyCalcScreen();
	}

	static void _backCurrencyMenuScreen()
	{
		cout << "\n" + cFormat::tab(5) << "Prass enter key to back Currency menu screen.... ";
		system("pause>>0");
		showCurrencyScreen();
	}

	static void _performCurrencyChoice(eCurrecnyMenuChoice menuChoice)
	{
		switch (menuChoice)
		{
		case eCurrecnyMenuChoice::eListOfCurrencies:
			_showListOfCurrenciesScreen();
			_backCurrencyMenuScreen();
			break;
		case eCurrecnyMenuChoice::eFindCurrency:
			_showFindCurrencyScreen();
			_backCurrencyMenuScreen();
			break;
		case eCurrecnyMenuChoice::eUpdateRate:
			_showUpdateRateScreen();
			_backCurrencyMenuScreen();
			break;
		case eCurrecnyMenuChoice::eCurrencyCalculate:
			_showCurrencyCalcScreen();
			_backCurrencyMenuScreen();
			break;
		default:
			break;
		}
	}

	static void _showCurrencyMenu()
	{
		vector<string> _itemOfMenu = {
		"List Of Currencies", "Find Currency", "Update Rate","Currency Calculator","Main Menue"
		};

		cout << cFormat::tab(5) << "========================================" << endl;
		cout << cFormat::tab(5) << "          Currency Mnue Screen       " << endl;
		cout << cFormat::tab(5) << "========================================\n" << endl;

		for (short i = 0; i < _itemOfMenu.size(); i++)
		{
			cout << cFormat::tab(5) << "==                                    ==" << endl;
		}

		cout << "\n" << cFormat::tab(5) << "========================================" << endl;

		// draw item menu
		rMenu mainMenu;
		mainMenu.set_xy(48, 9);
		mainMenu.color(7, 6);

		short choice = mainMenu.menu(_itemOfMenu);

		_performCurrencyChoice((eCurrecnyMenuChoice)(choice + 1));
	}
public:

	// show Currency menu screen
	static void showCurrencyScreen()
	{
		system("cls");
		printHeaderOfPage("Currency Screen", "", true);
		_showCurrencyMenu();
	}


};

