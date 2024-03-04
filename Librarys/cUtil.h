#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Librarys/cDate.h"

class cUtil
{
public:
	/*---------------------{Static Methods}------------------------*/

	//-----------[Random Methods]--------------------//
	
	// seed of rand function to generate random numbers
	static void seed()
	{
		srand((unsigned)time(0));
	}
	//return random integer number
	static int random()
	{
		return rand();
	}
	//return ranged random integer numbers 
	static int randomInt(int from, int to)
	{
		return (rand() % (to - from + 1) + from);  // ranged from num to num
	}
	//// return random floating number
	//static double randomf(double from, double to)
	//{
	//	return (rand() % (int)(to - from + 1) + from);  // ranged from num to num
	//}
	
	// return random character
	static enum enCharType
	{
		SmallLetter = 1,
		CapitalLetter = 2,
		SpecialChar = 3,
		Digit = 4,
		MixChar = 5
	};
	static char randomChar(enCharType charType = SmallLetter)
	{

		switch (charType)
		{
		case enCharType::SmallLetter:
			return char(randomInt(97, 122));
		case enCharType::CapitalLetter:
			return char(randomInt(65, 90));
		case enCharType::SpecialChar:
			return char(randomInt(33, 47));
		case enCharType::Digit:
			return char(randomInt(48, 57));
		default: // mix char
			return char(randomInt(33,122));
		}
	}

	//------------------------------------------------// 

	//-----------[Generation Methods]--------------------//
	
	// return generated word
	static string gen(short len, enCharType charType = SmallLetter)
	{
		string word = "";

		for (short i = 0; i < len; i++)
		{
			word += randomChar(charType);
		}
		return word;
	}
	// return generated key
	static string genKey(short lenKey,enCharType charType,char sep)
	{
		string key("");

		for (short i = 1; i <= lenKey; i++)
		{
			key += gen(lenKey, charType);
			if (i != lenKey)
			{
				key += sep;
			}
		}
		return key;
	}
	static string genKey(short lenKey)
	{
		return genKey(lenKey, CapitalLetter, '-');
	}
	
	//------[Generation Array Methods]-------://

	// return array of random numbers
	static void genArray(int arr[], short len, short from = 1, short to = 1000)
	{
		for (short i = 0; i < len; i++)
		{
			arr[i] = randomInt(from, to);
		}
	}
	// return array of generated words
	static void genArray(string arr[], short len ,enCharType charType, short lenWord = 4)
	{
		for (short i = 0; i < len; i++)
		{
			arr[i] = gen(lenWord, charType);
		}
	}
	// return array of generated keys
	static void genArray(string arr[], short len, short lenKay)
	{
		for (short i = 0; i < len; i++)
		{
			arr[i] = genKey(lenKay);
		}
	}

	//------[Generation Vector Methods]-------://
	
	// return vector of random numbers
	static vector<int> genVector(short len,short from, short to)
	{
		vector<int> numbers;
		for (short i = 0; i < len; i++)
		{
			numbers.push_back(randomInt(from, to));
		}
		return numbers;
	}
	// return vector of generated words
	static vector<string> genVector(short len, enCharType charType, short lenWord)
	{
		vector<string> words;
		for (short i = 0; i < len; i++)
		{
			words.push_back(gen(lenWord, charType));
		}
		return words;
	}
	// return vector of generated keys
	static vector<string> genVector(short len, short lenKay)
	{
		vector<string> keys;
		for (short i = 0; i < len; i++)
		{
			keys.push_back(genKey(lenKay));
		}
		return keys;
	}


	//------------------------------------------------// 
	
   //-----------[Swap Methods]--------------------//
	
	// swaping two integer numbers
	static void swap(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	// swaping two floating numbers
	static void swap(double& num1, double& num2)
	{
		double temp = num1;
		num1 = num2;
		num2 = temp;
	}
	// swaping strings
	static void swap(string& str1, string& str2)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}
	// swaping two characters
	static void swap(char& char1, char& char2)
	{
		char temp = char1;
		char1 = char2;
		char2 = temp;
	}
	// swaping two booleans
	static void swap(bool& bool1, bool& bool2)
	{
		bool temp = bool1;
		bool1 = bool2;
		bool2 = temp;
	}
	// swaping two dates
	static void swap(cDate& date1, cDate& date2)
	{
		cDate temp = date1;
		date1 = date2;
		date2 = temp;
	}

	//------------------------------------------------// 

   //-----------[Shuffle Methods]--------------------//

   // Shuffling array of numbers
	static void shuffle(int arr[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			swap(arr[(randomInt(1,len)-1)], arr[(randomInt(1,len)-1)]);
		}
	}
	// Shuffling array of string
	static void shuffle(string arr[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			swap(arr[(randomInt(1,len)-1)], arr[(randomInt(1,len)-1)]);
		}
	}
	// Shuffling vector of numbers
	static void shuffle(vector<int> &arr)
	{
		int len = arr.size();
		for (int i = 0; i < len; i++)
		{
			swap(arr[(randomInt(1,len)-1)], arr[(randomInt(1,len)-1)]);
		}
	}
	// Shuffling vector of string
	static void shuffle(vector<string> &arr)
	{
		int len = arr.size();
		for (int i = 0; i < len; i++)
		{
			swap(arr[(randomInt(1,len)-1)], arr[(randomInt(1,len)-1)]);
		}
	}

	//------------------------------------------------//  

   //-----------[Encryption Methods]--------------------//
   
    // return encryption text
	static string encrypt(string text, short encryptionKey)
	{
		for (char& letter : text)
		{
			letter += encryptionKey;
		}
		return text;
	}
    // return encryption text
	static string decrypt(string encryptionText, short encryptionKey)
	{
		for (char& letter : encryptionText)
		{
			letter -= encryptionKey;
		}
		return encryptionText;
	}

	
   //------------------------------------------------//
   
   //-----------[Methods]--------------------//
	// return number converted to text
	static string numbertoText(int number)
	{
		if (number == 0)
		{
			return "";
		}

		if (number >= 1 && number <= 19)
		{
			string arrNum[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
			return arrNum[number - 1];
		}
		else if (number >= 20 && number <= 99)
		{
			string arrNum[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
			return arrNum[(number / 10) - 2] + " " + numbertoText(number % 10);
		}
		else if (number >= 100 && number <= 199)
		{
			return "One Hundred " + numbertoText(number % 100);
		}
		else if (number >= 200 && number <= 999)
		{
			return numbertoText(number / 100) + " Hundred " + numbertoText(number % 100);
		}
		else if (number >= 1000 && number <= 1999)
		{
			return "One Thousand " + numbertoText(number % 1000);
		}
		else if (number >= 2000 && number <= 999999)
		{
			return numbertoText(number / 1000) + " Thousand " + numbertoText(number % 1000);
		}
		else if (number >= 1000000 && number <= 1999999)
		{
			return "One Million " + numbertoText(number % 1000000);
		}
		else if (number >= 2000000 && number <= 999999999)
		{
			return numbertoText(number / 1000000) + " Million " + numbertoText(number % 1000000);
		}
		else if (number >= 1000000000 && number <= 1999999999)
		{
			return "One Billion " + numbertoText(number % 1000000000);
		}
		else
		{
			return numbertoText(number / 1000000000) + " Billion " + numbertoText(number % 1000000000);
		}
	}

	//------------------------------------------------// 
	
	//-----------[Printing Methods]--------------------//
	
	// print array of number
	static void print(int arr[], short len, bool horizontal = false)
	{
		for (short i = 0; i < len; i++)
		{
			if (horizontal)
			{
				cout << arr[i] << "  ";
			}
			else
			{
				cout << arr[i] << endl;
			}
		}
		cout << endl;
	}
	// print array of string
	static void print(string arr[], short len, bool horizontal = false)
	{
		for (short i = 0; i < len; i++)
		{
			if (horizontal)
			{
				cout << arr[i] << "  ";
			}
			else
			{
				cout << arr[i] << endl;
			}
		}
		cout << endl;
	}
	// print vector of string
	static void print(const vector<string> &vectorItems,bool horizontal = false)
	{
		for (const string & item : vectorItems)
		{
			if (horizontal)
			{
				cout << item << "  ";
			}
			else
			{
				cout << item << endl;
			}
		}
		cout << endl;
	}
	// print vector of numbers
	static void print(const vector<int> &vectorItems, bool horizontal = false)
	{
		for (const int & item : vectorItems)
		{
			if (horizontal)
			{
				cout << item << "  ";
			}
			else
			{
				cout << item << endl;
			}
		}
		cout << endl;
	}

	//------------------------------------------------// 
};

