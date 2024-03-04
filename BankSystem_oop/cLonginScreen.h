#pragma once
#include "cScreen.h"
#include "cGlobal.h"
#include "cUser.h"
#include "cMainScreen.h"

class cLonginScreen : protected cScreen
{
private:
	// create faild scrren and correct screen
	static void _faildOrcorrectScreen(short tries ,bool longinResult = false)
	{
		// clear scren
		system("cls");
		if (!longinResult)
		{
			system("COLOR 4F");
			cout << "\a";
			cFormat::cursPosition(44, 12);
			cout <<"Tries: " << tries;

			cFormat::cursPosition(44, 14);
			cout <<"LOGIN FAILD!";
			cFormat::cursPosition(44, 15);
			cout << "PLEASE ENTER ANY KEY TO TRY AGAIN...";
			system("pause>0");
			// return defualt console color
			cFormat::reastColor();
			system("cls");
		}
	}
	// cheak if userName and password is correct
	static bool _cheakLoginOperation(string userName, string password)
	{
		currentUser = cUser::find(userName, password);
		return !currentUser.isEmpty();
	}
	// show longin screen
	static bool _showLoginScreen()
	{

		bool faildLogin = false;
		short tries = 3;
		string userName, password;
		do
		{
			if (faildLogin)
			{
				_faildOrcorrectScreen(tries);
				printHeaderOfPage("Login Screen");
			}

			if (tries == 0)
			{
				return false;
			}
			//userName = cInput::readStr(cFormat::tab(2) + "UserName");
			//password = cInput::readStr(cFormat::tab(2) + "Password");

			userName = cFormat::inField("USERNAME", 40, 10);
			password = cFormat::inField("PASSWORD", 40, 14);

			faildLogin = !_cheakLoginOperation(userName, password);
			tries--;

		} while (faildLogin);
		
		// success login
		currentUser.registerLogin();
		cMainScreen::showMainScreen ();
		return true;

	}

public:
	// show main menu screen
	static bool showLoginScreen()
	{
		system("cls");
		printHeaderOfPage("Login Screen");
		return _showLoginScreen();
	}
};

