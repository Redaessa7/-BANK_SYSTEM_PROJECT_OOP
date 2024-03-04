#pragma once
#include <iostream>
#include "cScreen.h"
#include "cClient.h"
#include "../Librarys/cInput.h"

class cShowDepositScrren : protected cScreen
{
private:

	// print client info
	static void _printClient(cClient& client)
	{

		// empty client
		if (client.isEmpty())
		{
			cout << "\n" << cFormat::tab(4) + cFormat::color("This client not have any information to print ):") << endl;
			return;
		}

		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << cFormat::tab(3) << "[" + cFormat::color(client.fullName()) + "'s Info]              ";
		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << "\n" << cFormat::tab(2) << "FirstName   " + cFormat::color(": ") << client.firstName;
		cout << "\n" << cFormat::tab(2) << "LastName    " + cFormat::color(": ") << client.lastName;
		cout << "\n" << cFormat::tab(2) << "FullName    " + cFormat::color(": ") << client.fullName();
		cout << "\n" << cFormat::tab(2) << "Email       " + cFormat::color(": ") << client.email;
		cout << "\n" << cFormat::tab(2) << "Phone       " + cFormat::color(": ") << client.phone;
		cout << "\n" << cFormat::tab(2) << "Account No  " + cFormat::color(": ") << client.accountNumber;
		cout << "\n" << cFormat::tab(2) << "PinCode     " + cFormat::color(": ") << client.pinCode;
		cout << "\n" << cFormat::tab(2) << "Balance     " + cFormat::color(": ") << client.balance << endl;
	}
	static void _showDeposit()
	{
		string accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter account number");

		while (accountNum.size() < 3 || !cClient::isClientExist(accountNum))
		{
			if (accountNum.size() < 3)
			{
				accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is invalid, Plz enter another one");
				continue;
			}
			accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is not exist, Plz enter another one");
		}

		// find client
		cClient client = cClient::find(accountNum);
		_printClient(client);

		// amount from user 
		cout << endl;
		double amount = cInput::readDlNumber(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter amount: ", cFormat::tab(2) + cFormat::color(("(*)")) + " Invalid amount, Plz enter another anmout: ");
		while (amount <= 0)
		{
			cout << cFormat::tab(2) + cFormat::color(("(*)")) + " Invalid amount, Plz enter another anmout: ";
			amount = cInput::readDlNumber("");
		}

		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Are you sure you want to confirm this operation"))
		{
			// deopsit operation
			client.deposit(amount);
			cout << endl << cFormat::tab(2) << cFormat::color("Deposit Operation Successfully ^_^", cFormat::txGreen) << endl;
			cout << endl << cFormat::tab(2) << "New Balance Is: " << cFormat::color(to_string(client.balance), cFormat::txBrightYellow) + cFormat::color(" $",cFormat::txGreen) << endl;
		}
		else
		{
			cout << endl << cFormat::tab(2) << cFormat::color("Deposit Operation Canceled (X_X)") << endl;
		}
	}

public:
	// show deposit screen
	static void showDepositScreen()
	{
		system("cls");
		printHeaderOfPage("Deposit Screen");
		_showDeposit();
	}
};

