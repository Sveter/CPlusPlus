#include "Date.hpp"


//日期类
Date::Date(int year, int month,int day)
	:_year(year)
	,_month(month)
	,_day(day)
{
	if (!IsInvalidDate())
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
}

Date Date::operator+ (int days)
{
	if (days < 0)
	{
		return ((*this) - (0 - days));
	}

	Date temp(*this);

	temp._day += days;
	int daysOfMonth = 0;
	while (temp._day > (daysOfMonth = _GetDaysOfMonth(temp._year, temp._month)))
	{
		temp._day -= daysOfMonth;
		++temp._month;

		if (temp._month > 12) 
		{
			temp._year += 1;
			temp._month = 1;
		}
	}

	return temp;
}

Date Date::operator-(int days)
{
	if (days < 0)
	{
		return (*this) + (0 - days);
	}

	Date temp(*this);

	temp._day -= days;
	while (temp._day <= 0)
	{
		temp._month -= 1;
		if (0 == temp._month)
		{
			temp._year -= 1;
			temp._month = 12;
		}
		temp._day += _GetDaysOfMonth(temp._year, temp._month);
	}

	return temp;
}

Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);
	++(*this);
	return temp;
}

Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int)
{
	Date temp(*this);
	--(*this);
	return temp;
}

int Date::operator-(const Date& d)
{
	int days = 0;
	Date max = *this, min = d;
	if (max < min)
	{
		max = d;
		min = *this;
	}
	while (min < max)
	{
		++min;
		++days;
	}
	return days;
}

bool Date::operator==(const Date& d)const
{
	return (d._year == _year) && (d._month == _month) && (d._day == _day);
}

bool Date::operator!=(const Date& d)const
{
	return !((*this) == d);
}

bool Date::operator>(const Date& d)const
{
	if ((_year > d._year) ||
		((_year == d._year) && (_month > d._month)) ||
		((_year == d._year) && (_month == d._month) && (_day > d._day)))
	{
		return true;
	}
	return false;
}

bool Date::operator<(const Date& d)const
{
	if ((_year < d._year) ||
		((_year == d._year) && (_month < d._month)) ||
		((_year == d._year) && (_month == d._month) && (_day < d._day)))
	{
		return true;
	}
	return false;
}


bool Date::IsInvalidDate()
{
	if ((_year > 0) && (_month > 0 && _month < 13) && (_day > 0 && _day <= _GetDaysOfMonth(_year, _month)))
	{
		return true;
	}
	return false;
}

int Date::_GetDaysOfMonth(int year, int month)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (_month == 2 && _IsLeapYear(year))
	{
		days[_month] += 1;
	}
	return days[_month];
}

bool Date::_IsLeapYear(int year)
{
	if ((0 == _year % 4) && (0 != _year % 100) || (0 == _year % 400))
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	if (!d.IsInvalidDate())
	{
		cout << "输入日期错误！" << d <<endl;
	}
	return _cin;
}


//日历类
Calendar::Calendar(int year)
	:_year(year)
{
	if (_year < 1)
	{
		_year = 1900;
	}
}

bool Calendar::IsLeap(int year)
{
	if ((0 == _year % 4) && (0 != _year % 100) || (0 == _year % 400))
	{
		return true;
	}
	return false;
}

int Calendar::GetDaysOfMonth(int year, int month)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && IsLeap(year))
	{
		days[month] += 1;
	}
	return days[month];
}

void Calendar::PrintCalendar()
{
	//1900年是1月1号是周一为基准
	for (int i = 1900; i < _year; i++) {
		//	四年一闰， 百年不闰， 四百年再闰
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
			_totalYear += 366;
		}
		else {
			_totalYear += 365;
		}
	}
	for (int i = 1; i <= 12; i++)
	{
		int days = GetDaysOfMonth(_year, i);
		int day;
		if (i == 1)
		{
			day = 0;
		}
		else
		{
			day = GetDaysOfMonth(_year, i - 1);
		}
		_totalMonth += day;
		_totalDay = _totalYear + _totalMonth;
		//	totalDay根据与7的关系，可以计算出每月1号是礼拜几
		_firstdayOfMonth = _totalDay % 7 + 1;
		//为周日的时候，_firstdayOfMonth应该为0
		_firstdayOfMonth = _firstdayOfMonth == 7 ? 0 : _firstdayOfMonth;

		PrintTitle(i);

		for (int j = 1; j <= _firstdayOfMonth; j++)
		{
			cout << setw(4) << " ";
		}

		for (int d = 1; d <= days; d++) {
			cout  <<  setw(4) << d;

			//	每遇到礼拜六换行
			if ((d + _totalDay) % 7 == 6) {
				cout << endl;
			}
		}
		cout << endl;
	}
}

void Calendar::PrintTitle(int m)
{
	cout << endl; cout << "             " << m << "月             " << endl;
	cout << "-----------------------------" << endl;
	cout << "  日  一  二  三  四  五  六  " << endl;
	cout << "-----------------------------" << endl;
}