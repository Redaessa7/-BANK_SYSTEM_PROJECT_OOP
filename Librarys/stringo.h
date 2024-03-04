#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class stringo
{
private:
	string _data;
public:

	// default constructor
	stringo() {}
	// parameterized constructor
	stringo(string value)
	{
		_data = value;
	}

	// porpetries setters
	void setData(string value)
	{
		_data = value;
	}
	// porpetries getters
	string data()
	{
		return _data;
	}

	// properties
	__declspec(property(get = data, put = setData)) string value;


	
	// static methods:
	// function return a title string , title the first letter each of word convert it tp upper.
	static string title(string text)
	{
		bool isFirstLetter = true;
		for (char& letter : text)
		{
			if (letter != ' ' && isFirstLetter)
			{
				letter = toupper(letter);
			}
			isFirstLetter = (letter == ' ' ? true : false);
		}
		return text;
	}
	// Return a capitalized version of the string.
	static string capitalize(string text)
	{
		text[0] = toupper(text[0]);
		return text;
	}
	//Return a copy of the string converted to lowercase.
	static string lower(string text)
	{
		for (char& letter : text)
		{
			if (islower(letter))
			{
				continue;
			}
			letter = tolower(letter);
		}
		return text;
	}
	//Return a copy of the string converted to uppercase.
	static string upper(string text)
	{
		for (char& letter : text)
		{
			if (isupper(letter))
			{
				continue;
			}
			letter = toupper(letter);
		}
		return text;
	}
	/*
	 Return a list of the substrings in the string, using sep as the separator string.

	 sep:
			The separator used to split the string.
	*/
	static vector<string> split(string text, string sep = " ")
	{
		vector<string> words;

		// check if str or delimiter is empty or no
		if (text.empty() || sep.empty())
		{
			return words; // return empty vector
		}

		short posDelim(0), startWord(0), lenDelim = sep.length();
		string word = "";
		/*
			[1]: Take part of the string [posDelim: str.length()] using substr function.
			[2]: searching for the delimiter in the part that was taken in the first step using find function.
			[3]: increment the index to return from step 2 by lenDelim (to ignore delimiter position).
			[4]: add The index to return from step 3  to posDelim.
			[5]: increment the increase at 4 steps above to std::string::npos For comparison between posDelim and npos
		*/

		while ((posDelim += (text.substr(posDelim, text.length()).find(sep)) + lenDelim) != std::string::npos + (startWord + lenDelim))
		{
			// store the word
			word = text.substr(startWord, posDelim - (startWord + lenDelim));

			if (!word.empty()) // case if word not empty
			{
				words.push_back(word);
			}
			startWord = posDelim;
		}

		// last word in string and add in vector
		word = text.substr(startWord, text.length());
		if (!word.empty())
		{
			words.push_back(word);
		}

		return words;
	}
	//Return a string of join elements in vector.
	static string join(const vector<string>& list, string sep = " ", char c = ' ')
	{
		string str = "";

		// check if strList is empty.
		if (list.empty())
			return str;

		for (const string& word : list)
			str += (word + sep);
		// remove last delimiter
		return str.substr(0, (str.length() - sep.length()));
	}
	//Return a copy of the string with leading whitespace removed
	static string lstrip(string text)
	{
		// from first index to the first Letter not equal space and tap[\t]. delete it
		for (char letter : text)
		{
			// check if letter not equal space and \t.
			if (letter != ' ' && letter != '\t')
			{
				// remove from 0 to letter not equal space and \t.
				text.erase(0, text.find(letter));
				break; // stop loop
			}
		}
		return text;
	}
	//Return a copy of the string with trailing whitespace removed.
	static string rstrip(string text)
	{
		// from last index to the first Letter not equal space and tap[\t]. delete it
		for (short letter = text.length() - 1; letter >= 0; letter--)
		{
			// check if letter not equal space and \t.
			if (text[letter] != ' ' && text[letter] != '\t')
			{
				// remove from letter + 1 not equal space and \t. to end str
				text.erase(letter + 1, text.length());
				break; // stop loop
			}
		}
		return text;
	}
	//Return a copy of the string with leading and trailing whitespace removed.
	static string strip(string text)
	{
		return rstrip(lstrip(text));
	}
	/*
	Return a centered string of length width.
		Padding is done using the specified fill character (default is a space).
	*/
	static string center(string text, int len, string sep = " ")
	{
		if (len <= text.size())
		{
			return text;
		}

		string lenSep;
		for (int i = 0; i < (len - text.size()) / 2; i++)
		{
			lenSep += sep;
		}
		return lenSep + text + lenSep;
	}
	// Retrun number of repeating str in string
	static int count(string text, string key)
	{
		int counter = 0;
		vector<string> list = split(text, " ");
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == key)
			{
				counter++;
			}
		}
		return counter;
	}
	// Return index of key if found, if not found return large  number
	static int find(string text, string key)
	{
		vector<string> list = split(text, " ");
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == key)
			{
				return i;
			}
		}
		return INT_MAX;
	}
	//Return a copy string with replace a specific word
	static string replace(const string& text, string oldValue, string newValue, bool matchCase = true, string sep = " ")
	{
		// split string to words
		vector<string> words = split(text, sep);

		// replace old value by new value.
		for (string& word : words)
		{
			if (matchCase)
			{
				if (word == oldValue)
					word = newValue;
			}
			else if (lower(word) == lower(oldValue))
			{
				word = newValue;
			}
		}

		// join words in vector at string and return it.
		return join(words, sep,' ');
	}
	// Return a copy reversed string
	static string reverse(string text, string sep = " ")
	{
		string reversedStr = "";
		vector<string> words = split(text, sep);
		vector<string>::iterator itr = words.end();

		// reverse words elements
		while (itr != words.begin())
		{
			--itr;
			reversedStr += (*itr + sep);
		}
		return reversedStr.substr(0, (reversedStr.length() - sep.length()));
	}

	// methods
	string title()
	{
		return title(_data);
	}
	string capitalize()
	{
		return capitalize(_data);
	}
	string lower()
	{
		return lower(_data);
	}
	string upper()
	{
		return upper(_data);
	}
	vector<string> split(string sep = " ")
	{
		return split(_data, sep);
	}
	string join(vector<string> &list, string sep = " ")
	{
		return _data + sep + join(list, sep,' ');
	}
	string strip()
	{
		return strip(_data);
	}
	string rstrip()
	{
		return rstrip(_data);
	}
	string lstrip()
	{
		return lstrip(_data);
	}
	string center(int len, string sep = " ")
	{
		return center(_data, len, sep);
	}
	int count(string key)
	{
		return count(_data, key);
	}
	int find(string key)
	{
		return find(_data, key);
	}
	string reverse(string sep = " ")
	{
		return reverse(_data, sep);
	}
	string replace(string oldValue, string newValue, bool matchCase = true)
	{
		return replace(_data, oldValue, newValue, matchCase, " ");
	}
	
};

