#include "Date.hpp"

void TestFunc()
{
	int year;
	cout << "��������Ҫ�鿴����ݣ�";
	cin >> year;
	if (year < 1)
	{
		year = 1900;
	}
	cout << year << "��ȫ���������£�" << endl;
	Calendar C(year);
	C.PrintCalendar();
}
void DecMenu();
void CalMenu();
void menu()
{
	cout << endl;
	cout << "��ӭʹ������,��¼ÿ�����������:)" << endl;
	cout << "************************************" << endl;
	cout << "   1.�鿴ȫ������      2.���ڼ���   " << endl;
	cout << "   0.�˳�                           " << endl;
	cout << "************************************" << endl;
	cout << "��ѡ��";
	int input = 0;
	cin >> input;
	switch (input)
	{
	case 1:
		CalMenu();
		break;
	case 2:
		DecMenu();
		break;
	case 0:
		return;
		break;
	default:
		cout << "�������������ѡ��" << endl;
		menu();
		break;
	}
}

void DecMenu()
{
	cout << endl;
	cout << "********************************" << endl; 
	cout << "      1.����֮��ļ��ʱ��      " << endl; 
	cout << "      2.��������                " << endl; 
	cout << "      3.��ȥ����                " << endl; 
	cout << "      4.���ز˵�              " << endl; 
	cout << "********************************" << endl; 
	cout << "��ѡ��"; 
	int i = 0;
	cin >> i; 
	switch (i) 
	{ 
	case 1: 
	{
		Date d1; Date d2; cout << "�������һ�����ڣ�"; 
		cin >> d1; cout << "������ڶ������ڣ�"; 
		cin >> d2; cout << d1 << "��" << d2 << "���" << d1 - d2 << "��" << endl; 
		DecMenu();
		break; 
	} 
	case 2: 
	{ 
		Date d1; 
		Date d2; 
		int days; 
		cout << "���������ڣ�"; 
		cin >> d1; cout << "������Ҫ���ӵ�������"; 
		cin >> days; d2 = d1 + days; 
		cout << d1 << "��100�������ڣ�" << d2 << endl; 
		DecMenu();
		break; 
	} 
	case 3: 
	{
		Date d1; 
		Date d2; 
		int days; 
		cout << "���������ڣ�"; 
		cin >> d1; cout << "������Ҫ��ȥ��������"; 
		cin >> days; d2 = d1 - days; 
		cout << d1 << "��100��ǰ�����ڣ�" << d2 << endl; 
		DecMenu();
		break; 
	} 
	case 4: 
		menu();
		break; 
	default:
		cout << "�������������ѡ��" << endl;
		DecMenu();
		break;
	}

}

void CalMenu()
{
	TestFunc();
	menu();
}

int main()
{
	menu();
	system("pause");
	return 0;
}

