#include <iostream>
#include <iomanip>
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1);
	//计算当前日期向后days天的日期
	Date operator+ (int days);
	//计算当前日期向前days天的日期
	Date operator-(int days);
	//前置++
	Date& operator++();
	//后置++
	Date operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);
	//计算两个日期相差天数
	int operator-(const Date& d);
	//日期判断
	bool operator==(const Date& d)const;

	bool operator!=(const Date& d)const;

	bool operator>(const Date& d)const;

	bool operator<(const Date& d)const;


private:
	//日期是否合法
	bool IsInvalidDate();
	//获取月份对应的天数
	int _GetDaysOfMonth(int year, int month);
	//判断是否是闰年
	bool _IsLeapYear(int year);

	friend ostream& operator<<(ostream& _cout, const Date& d);

	friend istream& operator>>(istream& _cin, Date& d);

private:
	int _year;
	int _month;
	int _day;
};


class Calendar
{
public:

	Calendar(int year = 1900); 
	//判断是否是闰年
	bool IsLeap(int year); 
	//得到当月天数
	int GetDaysOfMonth(int year, int month); 
	//打印全年的日历
	void PrintCalendar();
	//打印表头
	void PrintTitle(int m);

private:
	int _year;
	int _firstdayOfMonth;
	int _totalYear = 0;
	int _totalMonth = 0;
	int _totalDay = 0;
};