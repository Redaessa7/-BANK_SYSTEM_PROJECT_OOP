#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "cScreen.h"
#include "cClient.h"
class cShowTransferLogsScreen : protected cScreen
{
private:

	static void _printTransferLogs(vector<cClient::stTransfer> & transLogs)
	{
		//check if list of clients is empty
		if (transLogs.empty())
		{
			cout << "\nNo found any transfer to display it on screen, plz add some." << endl;
			return;
		}

		cout << "\n\n" << cFormat::tab(1) << cFormat::color("--------------------------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(1) << "\t\t\t\t\t Number Of Transfer (" << cFormat::colorbg(to_string(transLogs.size()), cFormat::txBlack, cFormat::bgYellow) << ") Trans(s)\t\t\t\t\t" << endl;
		cout << cFormat::tab(1) << cFormat::color("--------------------------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(1) << cFormat::color("|Date                  |FromAccount     |ToAccount     |Amount     |F.A.Balance    |T.A.Balance    |User     |") << endl;
		cout << cFormat::tab(1) << cFormat::color("--------------------------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;

		for (cClient::stTransfer& tranLog : transLogs)
		{
			cout << cFormat::tab(1) << cFormat::color("|") << left << setw(22) << tranLog.date << cFormat::color("|") << left << setw(16) << tranLog.clientFrom.accountNum;
			cout << cFormat::color("|") << left << setw(14) << tranLog.clientTo.accountNum << cFormat::color("|") << left << setw(11) << tranLog.amount;
			cout << cFormat::color("|") << left << setw(15) << tranLog.clientFrom.balance << cFormat::color("|") << left << setw(15) << tranLog.clientTo.balance << cFormat::color("|") << left << setw(9) << tranLog.user << cFormat::color("|\n");
			cout << cFormat::tab(1) << cFormat::color("--------------------------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		}
		cout << endl;
	}

public:

	static void showTransferLogsScreen()
	{
		system("cls");
		vector<cClient::stTransfer> transList = cClient::getTransferLogs();
		string title = "List OF Transfer Logs Screen", subTitle = "Number Of Transfer (" + to_string(transList.size()) + ") trans(s).";
		printHeaderOfPage(title, subTitle);
		_printTransferLogs(transList);
	}
};

