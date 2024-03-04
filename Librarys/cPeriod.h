#pragma once
#include <iostream>
#include "cDate.h"
using namespace std;


class cPeriod
{
private:

	cDate _start;
	cDate _end;

public:
	// parameterized constructor
	cPeriod(cDate startDate, cDate endDate): _start(startDate), _end(endDate)
	{}

	// properties setters/ getters
	void setStart(cDate start)
	{
		_start = start;
	}
	void setEnd(cDate end)
	{
		_end = end;
	}

	cDate getStart()
	{
		return _start;
	}
	cDate getEnd()
	{
		return _end;
	}

	__declspec(property(get = getStart, put = setStart)) cDate startDate;
	__declspec(property(get = getEnd, put = setEnd)) cDate endDate;

	// static methods:
	
	// return true if two periods are overlap or false are not.
	static bool isOverLap(cPeriod peroid1, cPeriod peroid2)
	{
		return !(cDate::isAfterDate(peroid2.startDate, peroid1.endDate) || cDate::isBeforeDate(peroid2.endDate, peroid1.startDate));
	}
	// return true if date in period or false if not.
	static bool isDateInPeriod(cDate date, cPeriod period)
	{
		return !(cDate::compareDates(date, period.startDate) == cDate::compareResult::before || cDate::compareDates(date, period.endDate) == cDate::compareResult::after);
	}
	// return days different between period start and end
	static short getPeroidLength(cPeriod period, bool includeEndDate)
	{
		return cDate::getDifferentBetweenDates(period.startDate, period.endDate, includeEndDate);
	}

	//public methods:

	// print period
	void print()
	{
		cout << "Period Start: ";
		_start.print();
		cout << "Period End: ";
		_end.print();
	}
	// return true if two periods are overlap or false are not.
	bool isOverLap(cPeriod peroid)
	{
		return isOverLap(*this, peroid);
	}
	// return true if date in period or false if not.
	bool isDateInPeriod(cDate date)
	{
		return isDateInPeriod(date, *this);
	}
	// return days different between period start and end
	short getLength(bool includeEndDate = false)
	{
		return getPeroidLength(*this, includeEndDate);
	}

};

