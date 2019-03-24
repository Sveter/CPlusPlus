#include <iostream>
#include <iomanip>
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1);
	//���㵱ǰ�������days�������
	Date operator+ (int days);
	//���㵱ǰ������ǰdays�������
	Date operator-(int days);
	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);
	//�������������������
	int operator-(const Date& d);
	//�����ж�
	bool operator==(const Date& d)const;

	bool operator!=(const Date& d)const;

	bool operator>(const Date& d)const;

	bool operator<(const Date& d)const;


private:
	//�����Ƿ�Ϸ�
	bool IsInvalidDate();
	//��ȡ�·ݶ�Ӧ������
	int _GetDaysOfMonth(int year, int month);
	//�ж��Ƿ�������
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
	//�ж��Ƿ�������
	bool IsLeap(int year); 
	//�õ���������
	int GetDaysOfMonth(int year, int month); 
	//��ӡȫ�������
	void PrintCalendar();
	//��ӡ��ͷ
	void PrintTitle(int m);

private:
	int _year;
	int _firstdayOfMonth;
	int _totalYear = 0;
	int _totalMonth = 0;
	int _totalDay = 0;
};