#pragma once
#include <iostream>
//#include <limits>
#include "cDate.h"
#include "cUtil.h"
#include "cPeriod.h"
using namespace std;

class cInput
{   // to not show msg
	static int _readNumbernoMsg(bool apperMasg, string msg = "Plz enter number", string errorMsg = "Invalid Number, Enter again")
	{
		return (apperMasg ? readNumber(msg, errorMsg): readNumber("", ""));
	} // to not show msg
	static int _readDbNumbernoMsg(bool apperMasg, string msg = "Plz enter number", string errorMsg = "Invalid Number, Enter again")
	{
		return (apperMasg ? readDlNumber(msg, errorMsg): readDlNumber("", ""));
	}
public:

	//--------------------[Static Methods]--------------------------//
	
	// return true if number between sepcific range
	static bool isNumberBetween(short num, short from, short to)
	{
		return (num >= from && num <= to);
	}
	// return true if number between sepcific range
	static bool isNumberBetween(int num, int from, int to)
	{
		return (num >= from && num <= to);
	}
	// return true if number between sepcific range
	static bool isNumberBetween(float num, float from, float to)
	{
		return (num >= from && num <= to);
	}
	// return true if number between sepcific range
	static bool isNumberBetween(double num, double from, double to)
	{
		return (num >= from && num <= to);
	}
	// return true if date between sepcific range
	static bool isDateBetween(cDate date, cDate from, cDate to)
	{
		if (!from.isBeforeDate(to))
		{
			cUtil::swap(from, to);
		}
		cPeriod period(from, to);
		return (period.isDateInPeriod(date));
	}

	//---------[Input Methods]--------------//

	// read invalid int number from user
	static int readNumber(string msg = "Plz enter number:", string errorMsg = "Invalid Number, Enter again: ")
	{
		int num(0);
		cout << msg;
		cin >> num;

		while((cin.fail()))
		{
			cin.clear();
			cin.ignore(80, '\n'); // for this is error : std::numeric_limits<std::streamsize>::max()
			cout << errorMsg;
			cin >> num;
		}
		return num;
	}
	// read invalid int ranged number from user
	static int readNumber(int rangeFrom, int rangeTo,string errorMsg = "Number is not within range, Enter again: ",string msg = "Plz enter number: ")
	{
		int number = readNumber(msg, errorMsg);
		while (!isNumberBetween(number, rangeFrom, rangeTo))
		{
			cout << errorMsg;
			number = _readNumbernoMsg(false);
		}
		return number;
	}	
	/*
	// read number of choice from userand return it
	static short readchoice(short xPos, short yPos, short rangeFrom, short rangeTo,string msg = "Plz enter number:", string errorMsg = "Invalid Number, Enter again: ")
	{
		short num(0);

		// read number of choice
		cFormat::cursPosition(xPos, yPos);
		cout << msg;
		cin >> num;
		// ensure is number 
		while ((cin.fail()))
		{
			cin.clear();
			cin.ignore(80, '\n'); // for this is error : std::numeric_limits<std::streamsize>::max()
			cFormat::cursPosition(xPos, yPos);
			cout << errorMsg;
			cin >> num;
		}
		// ensure range
		while (!isNumberBetween(num, rangeFrom, rangeTo))
		{
			cFormat::cursPosition(xPos, yPos);
			cout << errorMsg;
			cin >> num;
		}
		return num;
	}
	*/
	
	// read invalid double number from user
	static double readDlNumber(string msg = "Plz Enter Floating Number: ",string errorMsg = "Invalid Number, Enter again: ")
	{
		double num(0);
		cout << msg;
		cin >> num;

		while((cin.fail()))
		{
			cin.clear();
			cin.ignore(80, '\n'); // for this is error : std::numeric_limits<std::streamsize>::max()
			cout << errorMsg;
			cin >> num;
		}
		return num;
	}
	// read invalid double ranged number from user
	static int readDlNumber(double rangeFrom, double rangeTo, string msg = "Plz Enter Floating Number: ",string errorMsg = "Number is not within range, Enter again")
	{
		double number = readDlNumber(msg, errorMsg);
		while (!isNumberBetween(number, rangeFrom, rangeTo))
		{
			cout << errorMsg;
			number = _readDbNumbernoMsg(false);
		}
		return number;
	}
	// read a character from user
	static char readChar()
	{
		char ch  = ' ';
		cout << "Plz Enter Character: ";
		cin >> ch;

		return ch;
	}
	// read string from user
	static string readStr(string msg = "Plz Enter string")
	{
		string str("");
		cout << msg << ": ";
		cin >> str;

		return str;
	}
	// ask user and return answer from user
	static bool askUser(string askMsg = "Do you want add more")
	{
		char answer;
		cout << askMsg << "(Y/N): ";
		cin >> answer;

		return (answer == 'Y' || answer == 'y' ? true : false);
	}
};