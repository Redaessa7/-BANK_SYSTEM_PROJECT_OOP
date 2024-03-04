#pragma once
#include "cScreen.h"
#include "cClient.h"
#include "../Librarys/cInput.h"

class cTransferScreen : protected cScreen
{
private:
	// read account number from user and check if find or not
	static string _readAndCheckAccountNum(bool from = true)
	{
		string accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter account number to transfer " + (from? "from" : "to"));

		while (accountNum.size() < 3 || !cClient::isClientExist(accountNum))
		{
			if (accountNum.size() < 3)
			{
				accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is invalid, Plz enter another one");
				continue;
			}
			accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is not exist, Plz enter another one");
		}
		return accountNum;
	}

	// print short client info
	static void _printClientInfo(cClient &client)
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
		cout << "\n" << cFormat::tab(2) << "FullName    " + cFormat::color(": ") << client.fullName();
		cout << "\n" << cFormat::tab(2) << "Account No  " + cFormat::color(": ") << client.accountNumber;
		cout << "\n" << cFormat::tab(2) << "Balance     " + cFormat::color(": ") << client.balance << endl;
		cout << endl;

	}

	static void _showTransferScreen()
	{
		// client transfer from
		cClient clientTranFrom = cClient::find(_readAndCheckAccountNum());
		// print client info
		_printClientInfo(clientTranFrom);

		// client transfer to
		cClient clientTranTo = cClient::find(_readAndCheckAccountNum(false));
		// print client info
		_printClientInfo(clientTranTo);


		cout << endl;
		// read amount
		double amount = cInput::readDlNumber(5,clientTranFrom.balance, cFormat::tab(2) + cFormat::color(("(*)"))+ " Plz enter transfer amount: ", cFormat::tab(2) + cFormat::color(("(*)"))+ " Amount Exceeds the available Balance, Enter another Amount: ");

		// transfer operatations
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Are you sure you want to complete this transfer"))
		{
			if (clientTranFrom.transfer(amount,clientTranTo))
			{
				cout << endl << cFormat::tab(2) << cFormat::color("Transfer Operation Successfully ^_^", cFormat::txGreen) << endl;
				
				// print client info
				_printClientInfo(clientTranFrom);
				_printClientInfo(clientTranTo);

			}
			else
			{
				cout << endl <<cFormat::tab(2) + cFormat::color("Transfer Faild X_X\n");

			}
		}
		else
		{
			cout << endl<<cFormat::tab(2) + cFormat::color("Transfer operation canceled\n");
		}

	}

public:
	static void showTransferScreen()
	{
		system("cls");
		printHeaderOfPage("Transfer Screen");
		_showTransferScreen();
	}
};

