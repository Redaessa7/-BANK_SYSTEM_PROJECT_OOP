#pragma once
#include <iostream>
#include "../Librarys/cFormat.h"
#include "cGlobal.h"
#include "cUser.h"
#include "../Librarys/cDate.h"

using namespace std;

class cScreen
{
private:
	// secreen access denied
	static void _accessDeniedScreen()
	{
		system("cls");
		system("COLOR 4F");
		cout << "\a";
		//draw frame
		cFormat::frame(30, 10, 60, 6,false,'#','+');

		// text
		cFormat::cursPosition(52, 13);
		cout << "Access Denied!";
		cFormat::cursPosition(34, 14);
		cout << "You not have access to this page, Please contact admin";
		// go curser out the frame
		cFormat::cursPosition(60, 17);
	}
	// getLoginInfo
	static void _userLoginInfo()
	{
		if (!currentUser.isEmpty())
		{
			//// user info
			cFormat::cursPosition(18,26);
			cout << cFormat::colorbg(cFormat::spaces(89), cFormat::txBlack, cFormat::bgYellow);
			cFormat::cursPosition(20,26);
			cout << cFormat::colorbg("User: " + currentUser.userName, cFormat::txBlack,cFormat::bgYellow);
			
			cFormat::cursPosition(48,26);
			cout << cFormat::colorbg("Permissions: "+to_string(currentUser.permissions), cFormat::txBlack,cFormat::bgYellow);
			// login date
			cDate currentLoginData;
			cFormat::cursPosition(80,26);
			string date = to_string(currentLoginData.day) + "/" + to_string(currentLoginData.month) + "/" + to_string(currentLoginData.year) + " " + cDate::getClock();
			cout << cFormat::colorbg("LogDate: " + date, cFormat::txBlack,cFormat::bgYellow);
			cFormat::cursPosition(0, 0);

			//cout << cFormat::tab(4)<< cFormat::spaces(2) << cFormat::color("(O_O) LastUser: ", cFormat::txYellow) << currentUser.userName;
			//// login date
			//cDate currentLoginData;
			//cout << cFormat::spaces(5) << cFormat::color("[<- LoginDate: ", cFormat::txYellow) << currentLoginData.day << "/" << currentLoginData.month << "/" << currentLoginData.year << " " + cDate::getClock() << endl;

		}
	}

public:
	// draw header of page 
	static void printHeaderOfPage(string header, string slogan = "", bool showMoreinfo = false)
	{
		if (showMoreinfo)
		{
			_userLoginInfo();
		}
		// change color of all screen
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		//system("COLOR C6");
		cout << cFormat::tab(4) << "---------------------------------------------------------" << endl;
		// to centerized header => (size of hearde text + spaces) = 58 
		short numberOfSpaces;
		string spaces;

		numberOfSpaces = (58 - header.size());
		spaces = cFormat::spaces(numberOfSpaces / 2);

		cout << cFormat::tab(4) << cFormat::colorbg(spaces + header + spaces,cFormat::txBlack,cFormat::bgYellow) << endl;
		//cout << cFormat::tab(4) << spaces + header + spaces << endl;
		
		if (!slogan.empty())
		{
			numberOfSpaces = (58 - slogan.size()-1);
			spaces = cFormat::spaces(numberOfSpaces / 2);

			cout << cFormat::tab(4) << cFormat::colorbg(spaces + slogan + spaces, cFormat::txBlack, cFormat::bgYellow) << endl;
		}
		
		cout << cFormat::tab(4)<< "---------------------------------------------------------\n"<< endl;
		cout << endl;
	}

	// check user permissions
	static bool checkUserPermission(cUser::ePermissions pagePermission)
	{
		// draw faild access page
		if (!currentUser.checkPermissions(pagePermission))
		{
			_accessDeniedScreen();
			return false;
		}
		else
		{
			return true;
		}
	}
};

