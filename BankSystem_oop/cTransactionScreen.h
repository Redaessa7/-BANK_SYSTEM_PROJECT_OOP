#pragma once
#include <iostream>
#include <vector>
#include "../Librarys/cInput.h"
#include "../Librarys/cUtil.h"
#include "cScreen.h"
#include "cShowDepositScrren.h"
#include "cShowWithdrawScreen.h"
#include "cTotalBalancesScreen.h"
#include "cTransferScreen.h"
#include "cShowTransferLogsScreen.h"
#include "../Librarys/rMenu.h"

class cTransactionScreen : protected cScreen
{
private:
	enum eTranMenuChoice
	{
		eDeposit = 1, eWithdraw = 2, eTransfer = 3, eTotalBalances = 4, eTrnsferLogs = 5,eMainMenue = 6,
	};

	// screen
	static void _showDepositScreen()
	{
		//system("cls");
		//cout << "\nDeposit Screen ne will here...";
		cShowDepositScrren::showDepositScreen();
	}
	static void _showeWithdrawScreen()
	{
		//system("cls");
		//cout << "\nWithdraw Screen ne will here...";
		cShowWithdrawScreen::showWithdrawScreen();
	}
	static void _showTotalBalancesScreen()
	{
		//system("cls");
		//cout << "\nTotal Balances Screen ne will here...";
		cTotalBalancesScreen::showTotalBalancesScreen();
	}
	static void _showTransferScreen()
	{
		cTransferScreen::showTransferScreen();
	}
	static void _showTransferLogsScreen()
	{
		cShowTransferLogsScreen::showTransferLogsScreen();
	}

	//static short _getUserChoice()
	//{
	//	string tabs = cFormat::tab(5);
	//	return cInput::readNumber(1, 4, tabs + "Invalid choice, Plz enter number between [1 to 4]!: ", tabs + "Choose what do you want to do? [1 to 4]?: ");
	//}
	static void _backTransMenuScreen()
	{
		cout << "\n" + cFormat::tab(5) << "Prass enter key to back Transaction menu screen.... ";
		system("pause>>0");
		showTransactionScreen();
	}
	static void _performTranMenuChoice(eTranMenuChoice menuChoice)
	{
		switch (menuChoice)
		{
		case eTranMenuChoice::eDeposit:
			_showDepositScreen();
			_backTransMenuScreen();
			break;
		case eTranMenuChoice::eWithdraw:
			_showeWithdrawScreen();
			_backTransMenuScreen();
			break;
		case eTranMenuChoice::eTransfer:
			_showTransferScreen();
			_backTransMenuScreen();
			break;
		case eTranMenuChoice::eTotalBalances:
			_showTotalBalancesScreen();
			_backTransMenuScreen();
			break;
		case eTranMenuChoice::eTrnsferLogs:
			_showTransferLogsScreen();
			_backTransMenuScreen();
			break;
		default:
			break;
		}
	}

	static void _showTransactionMenu() 
	{
		vector<string> _itemOfMenu = {
		"Deposit", "Withdraw", "Transfer","Total Balances","Transfer Logs","Main Menue"
		};

		cout << cFormat::tab(5) << "========================================" << endl;
		cout << cFormat::tab(5) << "          Transaction Mnue Screen       " << endl;
		cout << cFormat::tab(5) << "========================================\n" << endl;

		//// print item of menu
		//for (short i = 0; i < _itemOfMenu.size(); i++)
		//{
		//	cout << cFormat::tab(5) << cFormat::spaces(5) << "[" << i + 1 << "]: " << _itemOfMenu[i] << endl;
		//}

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

		_performTranMenuChoice((eTranMenuChoice)(choice+1));
	}
public:

	// show Transaction menu screen
	static void showTransactionScreen()
	{
		system("cls");
		printHeaderOfPage("Transaction Screen","",true);

		// check if user has access to this page or not
		if (checkUserPermission(cUser::pTrnasaction))
		{
			// user has access to this page
			_showTransactionMenu();
		}
	}
};

