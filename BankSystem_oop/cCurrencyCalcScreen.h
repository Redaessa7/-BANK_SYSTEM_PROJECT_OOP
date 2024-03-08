#pragma once
#include "cScreen.h"
class cCurrencyCalcScreen : protected cScreen
{
private:

	static float _calcRate(float currencyRateform, float currencyRateto, float amount)
	{
		return ((1 / currencyRateform) * amount) * currencyRateto;
	}
	
	static void _showCurrencyCalc()
	{
		cout << cFormat::tab(5) << "===============================================" << endl;
		cout << cFormat::tab(5) << "=      =      Currency Calculator      =      =" << endl;
		cout << cFormat::tab(5) << "=      =================================      =" << endl;
		
		for (short i = 0; i < 10; i++)
		{
			cout << cFormat::tab(5)<< "=		                              =" << endl;
		}

		cout << cFormat::tab(5) << "===============================================" << endl;

		
		string currencyCode1, currencyCode2;
		float amount(0);

		cFormat::cursPosition(45, 10);
		cout << "* From CCode: ";

		cFormat::cursPosition(45, 12);
		cout << "* To CCode: ";
		
		cFormat::cursPosition(45, 14);
		cout << "* Amount: ";

		cFormat::cursPosition(55, 16);
		cout << "* Result: ";

		cFormat::cursPosition(59, 10);
		cin >> currencyCode1;
		
		cFormat::cursPosition(59, 12);
		cin >> currencyCode2;

		cFormat::cursPosition(59, 14);
		cin >> amount;

		// calculator
		cCurrency cur1 = cCurrency::findByCode(currencyCode1);
		cCurrency cur2 = cCurrency::findByCode(currencyCode2);
		// check if user enter invalid currency code
		if (cur1.isEmpty() || cur2.isEmpty())
		{
			cFormat::cursPosition(28, 20);
			cout << "This Currency not found, plz try again with enter invalid currency code" << endl;
			return;
		}


		cFormat::cursPosition(65, 16);
		cout << _calcRate(cur1.rate, cur2.rate, amount);

		cFormat::cursPosition(0, 20);


	}

public:
	
	static void showCurrencyCalcScreen()
	{
		system("cls");
		printHeaderOfPage("Currency Calculator Screen");
		_showCurrencyCalc();
	}
};

