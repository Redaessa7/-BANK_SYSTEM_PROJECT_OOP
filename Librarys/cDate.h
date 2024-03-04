#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;


class cDate
{

private:
	short _day;
	short _month;
	int _year;

// Private Methods:
private:

	void getSystemDate()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		_day = Time->tm_mday;
		_month = Time->tm_mon + 1;
		_year = Time->tm_year + 1900;
	}
	void convertStringToDate(string date_str, char sep)
	{
		// split by separator
		stringstream S(date_str);
		string token;

		int arr[3] = { 0,0,0 }, i = 0;
		while (getline(S, token, sep))
		{
			arr[i] = stoi(token);
			i++;
		}

		// convert date string to date properties
		_day = arr[0];
		_month = arr[1];
		_year = arr[2];
	}

	/*---------------Increased Date-------------------*/
	// return date increased it by one date
	static cDate increaseDateByOneDay(cDate& date)
	{
		if (isLastDayInMonth(date.day, date.month, date.year))
		{
			date.day = 1;
			if (isLastMonthInYear(date.month))
			{
				date.month = 1;
				date.year++;
			}
			else
				date.month++;
		}
		else
		{
			date.day++;
		}
		return date;
	}
	// return date increased it by x days
	cDate increaseDateByXDays(short numberOfDays, cDate& date)
	{
		for (short i = 1; i <= numberOfDays; i++)
			date = increaseDateByOneDay(date);
		return date;
	}
	// return date increased it by one week
	cDate increaseDateByOneWeek(cDate date)
	{
		return date = increaseDateByXDays(7, date);
	}
	// return date increased it by x weeks
	cDate increaseDateByXWeeks(short numberOfWeeks, cDate date)
	{
		for (short i = 1; i <= numberOfWeeks; i++)
			date = increaseDateByOneWeek(date);
		return date;
	}
	// return date increased it by one month
	cDate increaseDateByOneMonth(cDate date)
	{
		if (isLastMonthInYear(date.month))
		{
			date.month = 1;
			date.year++;
		}
		else
		{
			date.month++;
		}

		short currentDaysInMonth = getNumberOfDaysInMonth(date.month, date.year);
		if (date.day > currentDaysInMonth)
		{
			date.day = currentDaysInMonth;
		}

		return date;
	}
	// return date increased it by x months
	cDate increaseDateByXMonths(short numberOfMonths, cDate date)
	{
		for (short i = 1; i <= numberOfMonths; i++)
			date = increaseDateByOneMonth(date);
		return date;
	}
	// return date increased it by one year
	cDate increaseDateByOneYear(cDate date)
	{
		date.year++;
		return date;
	}
	// return date increased it by x years
	cDate increaseDateByXYears(short numberOfYears, cDate date)
	{
		date.year += numberOfYears;
		return date;
	}
	// return date increased it by one decade
	cDate increaseDateByOneDecade(cDate date)
	{
		// decades = 10 years
		date.year += 10;
		return date;
	}
	// return date increased it by x decades
	cDate increaseDateByXDecades(short numberOfDecades, cDate date)
	{
		date.year += (10 * numberOfDecades);
		return date;
	}
	// return date increased it by one century
	cDate increaseDateByOneCentury(cDate date)
	{
		// century = 100 years.
		date.year += 100;
		return date;
	}
	// return date increased it by one millennium
	cDate increaseDateByOneMillennium(cDate date)
	{
		// millennium = 1000 years
		date.year += 1000;
		return date;
	}

	/*---------------Decreased Date-------------------*/
	// return date decreased it by one day
	cDate decreaseDateByOneDay(cDate date)
	{
		if (isFirstDayInMonth(date.day))
		{
			if (isFirstMonthInYear(date.month))
			{
				date.month = 12;
				date.year--;
				date.day = getNumberOfDaysInMonth(date.month, date.year);
			}
			else
			{
				date.month--;
				date.day = getNumberOfDaysInMonth(date.month, date.year);
			}
		}
		else
		{
			date.day--;
		}
		return date;
	}
	// return date decreased it by x day
	cDate decreaseDateByXDays(short numberOfDays, cDate date)
	{
		for (short i = numberOfDays; i > 0; i--)
			date = decreaseDateByOneDay(date);
		return date;
	}
	// return date decreased it by one week
	cDate decreaseDateByOneWeek(cDate date)
	{
		return date = decreaseDateByXDays(7, date);
	}
	// return date decreased it by x weeks
	cDate decreaseDateByXWeeks(short numberOfWeeks, cDate date)
	{
		for (short i = numberOfWeeks; i > 0; i--)
			date = decreaseDateByOneWeek(date);
		return date;
	}
	// return date decreased it by one month
	cDate decreaseDateByOneMonth(cDate date)
	{
		if (isFirstMonthInYear(date.month))
		{
			date.month = 12;
			date.year--;
		}
		else
		{
			date.month--;
		}

		short currentDaysInMonth = getNumberOfDaysInMonth(date.month, date.year);
		if (date.day > currentDaysInMonth)
		{
			date.day = currentDaysInMonth;
		}

		return date;
	}
	// return date decreased it by x months
	cDate decreaseDateByXMonths(short numberOfMonths, cDate date)
	{
		for (short i = numberOfMonths; i > 0; i--)
			date = decreaseDateByOneMonth(date);
		return date;
	}
	// return date decreased it by one year
	cDate decreaseDateByOneYear(cDate date)
	{
		date.year--;
		return date;
	}
	// return date decreased it by x years
	cDate decreaseDateByXYears(short numberOfYears, cDate date)
	{
		date.year -= numberOfYears;
		return date;
	}
	// return date decreased it by one decade
	cDate decreaseDateByOneDecade(cDate date)
	{
		// decade = 10 years
		date.year -= 10;
		return date;
	}
	// return date decreased it by x decades
	cDate decreaseDateByXDecades(short numberOfDecades, cDate date)
	{
		// decade = 10 years.
		date.year -= (10 * numberOfDecades);
		return date;
	}
	// return date decreased it by one century
	cDate decreaseDateByOneCentury(cDate date)
	{
		// century = 100 years
		date.year -= 100;
		return date;
	}
	// return date decreased it by one millennium
	cDate decreaseDateByOneMillennium(cDate date)
	{
		// millennium = 1000 years
		date.year -= 1000;
		return date;
	}


	// return number of day in week.
	static short getIndexOfDay(cDate date)
	{
		short a(0), y(0), m(0), d(0);

		a = (14 - date.month) / 12;  // step [1]
		y = date.year - a;           // step [2]
		m = date.month + 12 * a - 2; // step [3]
		// For the Gregorian calendar:
		d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}
	// return number of spaces needs to ignore days.
	static string ignoreDays(short indexDay)
	{
		if (indexDay <= 0)
		{
			return "";
		}
		return "     " + ignoreDays(--indexDay);
	}

public:

	/*---------------Constructors Methods-------------------*/
	
	// default constructor, initialize properties by system date
	cDate()
	{
		getSystemDate();
	}
	// parameterized constructor one, initialize properties by string parameter
	cDate(string date, char sep = '/')
	{
		if (date.length() <= 10 && date.length() > 5)
		{
			convertStringToDate(date, sep);
		}
		else // if user pass invalid parameter
		{
			getSystemDate(); // call current system date
		}
	}
	// parameterized constructor two, initialize properties by normal pass 3 parameters
	cDate(short day, short month, int year) : _day(day), _month(month), _year(year) {}
	// parameterized constructor three, initialize properties by pass 2 parameters
	cDate(short days, int year)
	{
		this->day = 1;
		this->month = 1;
		this->year = year;

		*this = increaseDateByXDays(days, *this);
	}


	/*---------------Properties Setters/Getters-------------------*/

	// properties setters
	void setDay(short day)
	{
		_day = day;
	}
	void setMonth(short month)
	{
		_month = month;
	}
	void setYear(int year)
	{
		_year = year;
	}

	// properties getters 
	short getDay() { return _day; }
	short getMonth() { return _month; }
	int getYear() { return _year; }

	__declspec(property(get = getDay, put = setDay)) short day;
	__declspec(property(get = getMonth, put = setMonth)) short month;
	__declspec(property(get = getYear, put = setYear)) int year;


	/*---------------Static Methods-------------------*/

	// check if year is leap year or not
	static bool isLeapYear(int year)
	{
		return (year % 400 == 0 ? true : (year % 4 == 0 && year % 100 != 0 ? true : false));
	}
	// return number of days in month
	static short getNumberOfDaysInMonth(short month, int year)
	{
		short daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (month == 2 && isLeapYear(year) ? 29 : (daysInMonths[month - 1]));
	}
	// return true if is first day in month
	static bool isLastDayInMonth(short day, short month, int year)
	{
		return (day == getNumberOfDaysInMonth(month, year));
	}
	// return true if last day in date or false is not.
	static bool isLastMonthInYear(short month)
	{
		return (month == 12);
	}
	// return true if day is first day in month
	static bool isFirstDayInMonth(short day)
	{
		return (day == 1);
	}
	// return true if first month in date or false is not.
	static bool isFirstMonthInYear(short month)
	{
		return (month == 1);
	}
	// return true if date 1 get before date 2 or false if not.
	static bool isBeforeDate(cDate date1, cDate date2)
	{
		return (date1.year < date2.year ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false));
	}
	// return true if two dates equal them or false are not.
	static bool isSameDate(cDate date1, cDate date2)
	{
		return (date1.year == date2.year ? (date1.month == date2.month ? (date1.day == date2.day) : false) : false);
	}
	// return true if date 1 get after date 2 or false if not.
	static bool isAfterDate(cDate date1, cDate date2)
	{
		return (!isBeforeDate(date1, date2) && !isSameDate(date1, date2));
	}
	// return day short name
	static string getDayName(cDate date)
	{
		// shorts of days name in week
		string arr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arr[getIndexOfDay(date)]; // return day name.
	}
	// return month short name.
	static string getMonthName(short month)
	{
		string monthsName[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return monthsName[month - 1];
	}
	// return number of days until the end of week.
	static short getDaysUntilTheEndOfWeek(cDate& date)
	{
		// sat = 6 last day in week.
		return (6 - getIndexOfDay(date));
	}
	// return number of days until the end of month.
	static short getDaysUntilTheEndOfMonth(cDate& date)
	{
		return (getNumberOfDaysInMonth(date.month, date.year) - date.day);
	}
	// return number of days until the end of year.
	static short getDaysUntilTheEndOfYear(cDate date)
	{
		short daysUntilEndYear = getDaysUntilTheEndOfMonth(date);
		for (short i = date.month + 1; i <= 12; i++)
			daysUntilEndYear += getNumberOfDaysInMonth(i, date.year);
		return daysUntilEndYear;
	}
	// return days Different Between Two Dates.
	static short getDifferentBetweenDates(cDate date1, cDate date2, bool includeEndDay = false)
	{
		int days = 0;

		if (isAfterDate(date1, date2))
		{
			while (isBeforeDate(date2, date1))
			{
				days++;
				date2 = increaseDateByOneDay(date2);
			}
		}
		else 
		{
			while (isBeforeDate(date1, date2))
			{
				days++;
				date1 = increaseDateByOneDay(date1);
			}
		}
		return includeEndDay ? ++days : days;
	}

	// compare result
	static enum compareResult
	{
		before = -1,
		equal = 0,
		after = 1
	};
	// return -1 if date 1 before date2 or return 0 if date 1 equal date 2 or return 1 if date 1 after date 2
	static compareResult compareDates(cDate date1, cDate date2)
	{
		if (isBeforeDate(date1, date2))
		{
			return compareResult::before;
		}
		else if (isSameDate(date1, date2))
		{
			return compareResult::equal;
		}
		else
		{
			return compareResult::after;
		}
	}

	// return true if day is last day in week and false if not.
	static bool isEndOfWeek(const cDate& date)
	{
		// "Sun" = 0, "Mon" = 1, "Tue" = 2, "Wed" = 3, "Thu" = 4, "Fri" = 5, "Sat" = 6
		return (getIndexOfDay(date) == 6); // end of week is : sat.
	}
	// return true if day is weekend day and false if not.
	static bool isWeekEnd(const cDate& date)
	{
		// "Sun" = 0, "Mon" = 1, "Tue" = 2, "Wed" = 3, "Thu" = 4, "Fri" = 5, "Sat" = 6
		short indexOfDay = getIndexOfDay(date);

		return (indexOfDay == 5 || indexOfDay == 6); 
		// weekend is :  fri or sat. arab
		// weekend is :  sun or sat. europe

	}
	// return true if day is business day and false if not.
	static bool isBusinessDay(const cDate& date)
	{
		// "Sun" = 0, "Mon" = 1, "Tue" = 2, "Wed" = 3, "Thu" = 4, "Fri" = 5, "Sat" = 6
		/*   short indexOfDay = getIndexOfDay(date);
		return (indexOfDay != 5 && indexOfDay != 6);
		*/

		// Business Day is : any day from (Sun to Thu).
		return !isWeekEnd(date);
	}
	// return true if date is valid date or false is not
	static bool isValidDate(cDate date)
	{
		if (date.day > 0 && date.day <= getNumberOfDaysInMonth(date.month, date.year))
		{
			if (date.month > 0 && date.month <= 12)
			{
				if (date.year >= 1)
					return true;
			}
		}
		else
			return false;
	}
	
	// print month calendar on screen
	static void printCalendar(short day,short month, short year)
	{
		short daysInMonth = getNumberOfDaysInMonth(month, year); // get number of days in month
		short newLineAfter7Days(0);  // new line after 7 days.

		cDate startDate(1,month,year);

		short startDay = getIndexOfDay(startDate);          // get start day in month.

		cout << "\n_______________[" + getMonthName(month) + "]_______________" << endl;
		cout << "\n Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

		for (short i = 1; i <= daysInMonth; i++)
		{
			if (newLineAfter7Days == 7)
			{
				cout << endl;
				newLineAfter7Days = 0;
			}
			else if (i == 1)
			{
				cout << ignoreDays(startDay);
				newLineAfter7Days += startDay;
			}

			//printf("\033[3;43;30mTexting\033[0m");
			if (i == day)
				cout <<  (i < 10 ? "   " : "  ") << "\033[3;43;30m" + to_string(i) + "\033[0m ";
			else
				cout << setw(4) << i << " ";

			newLineAfter7Days++;
		}

		cout << "\n___________________________________" << endl;
	}
	// print year calendare on screen
	static void printYearCalendar(short year)
	{
		cout << "\n__________________________________________Year " << year << " Calendar__________________________________________" << endl;
		for (short month = 1; month <= 12; month++)
		{
			printCalendar(0,month, year);
		}
	}

	// return clock
	static string getClock()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		int hour, minutes, seconds;
		hour = Time->tm_hour;
		minutes = Time->tm_min;
		seconds = Time->tm_sec;
		
		return ((hour < 10 ? "0" : "") + to_string((hour > 12 ? hour - 12 : hour)) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + to_string(seconds));
	}

	// convert data to string
	static string convertDatetoString(cDate date, string sep = "/")
	{
		return (to_string(date.day) + sep + to_string(date.month) + sep + to_string(date.year));
	}
	
	
	
	/*---------------Public Methods-------------------*/

	// check if year is leap year or not
	bool isLeapYear()
	{
		return isLeapYear(_year);
	}
	// return number of days in month
	short getNumberOfDaysInMonth()
	{
		return getNumberOfDaysInMonth(_month, _year);
	}
	// return true if is first day in month
	bool isLastDayInMonth()
	{
		return isLastDayInMonth(_day, _month, _year);
	}
	// return true if last day in date or false is not.
	bool isLastMonthInYear()
	{
		return isLastMonthInYear(_month);
	}
	// return true if day is first day in month
	bool isFirstDayInMonth()
	{
		return (_day == 1);
	}
	// return true if first month in date or false is not.
	bool isFirstMonthInYear()
	{
		return (_month == 1);
	}
	// return true if current date get before date 2 or false if not.
	bool isBeforeDate(cDate date)
	{
		return isBeforeDate(*this, date);
	}
	// return true if two dates equal them or false are not.
	bool isSameDate(cDate date)
	{
		return isSameDate(*this, date);
	}
	// return true if current date get after date 2 or false if not.
	bool isAfterDate(cDate& date)
	{
		return isAfterDate(*this, date);
	}
	// return true if date is valid date or false is not
	bool isValidDate()
	{
		return isValidDate(*this);
	}

	/*---------------Increased Date-------------------*/
	// return date increased it by one date
	void increaseDateByOneDay()
	{
		*this = increaseDateByOneDay(*this);
	}
	// return date increased it by x days
	void increaseDateByXDays(short days)
	{
		*this = increaseDateByXDays(days, *this);
	}
	// return date increased it by one week
	void increaseDateByOneWeek()
	{
		*this = increaseDateByOneWeek(*this);
	}
	// return date increased it by x weeks
	void increaseDateByXWeeks(short numberOfWeeks)
	{
		*this = increaseDateByXWeeks(numberOfWeeks,*this);
	}
	// return date increased it by one month
	void increaseDateByOneMonth()
	{
		*this = increaseDateByOneMonth(*this);
	}
	// return date increased it by x months
	void increaseDateByXMonths(short numberOfMonths)
	{
		*this = increaseDateByXMonths(numberOfMonths, *this);
	}
	// return date increased it by one year
	void increaseDateByOneYear()
	{
		*this = increaseDateByOneYear(*this);
	}
	// return date increased it by x years
	void increaseDateByXYears(short numberOfYears)
	{
		*this = increaseDateByXYears(numberOfYears, *this);
	}
	// return date increased it by one decade
	void increaseDateByOneDecade()
	{
		*this = increaseDateByOneDecade(*this);
	}
	// return date increased it by x decades
	void increaseDateByXDecades(short numberOfDecades)
	{
		*this = increaseDateByXDecades(numberOfDecades, *this);
	}
	// return date increased it by one century
	void increaseDateByOneCentury()
	{
		*this = increaseDateByOneCentury(*this);
	}
	// return date increased it by one millennium
	void increaseDateByOneMillennium()
	{
		*this = increaseDateByOneMillennium(*this);
	}

	/*---------------Decreased Date-------------------*/
	// return date decreased it by one day
	void decreaseDateByOneDay()
	{
		*this = decreaseDateByOneDay(*this);
	}
	// return date decreased it by x day
	void decreaseDateByXDays(short numberOfDays)
	{
		*this = decreaseDateByXDays(numberOfDays, *this);
	}
	// return date decreased it by one week
	void decreaseDateByOneWeek()
	{
		*this = decreaseDateByOneWeek(*this);
	}
	// return date decreased it by x weeks
	void decreaseDateByXWeeks(short numberOfWeeks)
	{
		*this = decreaseDateByXWeeks(numberOfWeeks, *this);
	}
	// return date decreased it by one month
	void decreaseDateByOneMonth()
	{
		*this = decreaseDateByOneMonth(*this);
	}
	// return date decreased it by x months
	void decreaseDateByXMonths(short numberOfMonths)
	{
		*this = decreaseDateByXMonths(numberOfMonths, *this);
	}
	// return date decreased it by one year
	void decreaseDateByOneYear()
	{
		*this = decreaseDateByOneYear(*this);
	}
	// return date decreased it by x years
	void decreaseDateByXYears(short numberOfYears)
	{
		*this = decreaseDateByXYears(numberOfYears, *this);
	}
	// return date decreased it by one decade
	void decreaseDateByOneDecade()
	{
		*this = decreaseDateByOneDecade(*this);
	}
	// return date decreased it by x decades
	void decreaseDateByXDecades(short numberOfDecades)
	{
		*this = decreaseDateByXDecades(numberOfDecades, *this);
	}
	// return date decreased it by one century
	void decreaseDateByOneCentury()
	{
		*this = decreaseDateByOneCentury(*this);
	}
	// return date decreased it by one millennium
	void decreaseDateByOneMillennium()
	{
		*this = decreaseDateByOneMillennium(*this);
	}


	// return day short name
	string getDayName()
	{
		return getDayName(*this);
	}
	// return number of days until the end of week.
	short getDaysUntilTheEndOfWeek()
	{
		return getDaysUntilTheEndOfWeek(*this);
	}
	// return number of days until the end of month.
	short getDaysUntilTheEndOfMonth()
	{
		return getDaysUntilTheEndOfMonth(*this);
	}
	// return number of days until the end of year.
	short getDaysUntilTheEndOfYear()
	{
		return getDaysUntilTheEndOfYear(*this);
	}
	// return days Different Between Two Dates.
	short getDifferentBetweenDates(cDate date, bool includeEndDay = false)
	{
		return getDifferentBetweenDates(*this, date, includeEndDay);
	}
	//// return -1 if date 1 before date2 or return 0 if date 1 equal date 2 or return 1 if date 1 after date 2
	//short compareDates(cDate date)
	//{
	//	return compareDates(*this, date);
	//}
	
	// return true if day is last day in week and false if not.
	bool isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}
	// return true if day is weekend day and false if not.
	bool isWeekEnd()
	{
		return isWeekEnd(*this);
	}
	// return true if day is business day and false if not.
	bool isBusinessDay()
	{
		return isBusinessDay(*this);
	}
	// return month short name.
	string getMonthName()
	{
		return getMonthName(_month);
	}


	/*---------------Print Date-------------------*/

	// print date
	void print()
	{
		cout << _day << "/" << _month << "/" << _year << endl;
	}
	// print month calendar on screen
	void printCalendar()
	{
		printCalendar(_day, _month, _year);
	}
	// print year calendare on screen
	void printYearCalendar()
	{
		printYearCalendar(_year);
	}

};

