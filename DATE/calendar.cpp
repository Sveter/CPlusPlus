#include "Date.hpp"

void TestFunc()
{
	int year;
	cout << "请输入你要查看的年份：";
	cin >> year;
	if (year < 1)
	{
		year = 1900;
	}
	cout << year << "年全年日历如下：" << endl;
	Calendar C(year);
	C.PrintCalendar();
}
void DecMenu();
void CalMenu();
void menu()
{
	cout << endl;
	cout << "欢迎使用日历,记录每天的美好生活:)" << endl;
	cout << "************************************" << endl;
	cout << "   1.查看全年日历      2.日期计算   " << endl;
	cout << "   0.退出                           " << endl;
	cout << "************************************" << endl;
	cout << "请选择：";
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
		cout << "输入错误，请重新选择！" << endl;
		menu();
		break;
	}
}

void DecMenu()
{
	cout << endl;
	cout << "********************************" << endl; 
	cout << "      1.日期之间的间隔时间      " << endl; 
	cout << "      2.增加天数                " << endl; 
	cout << "      3.减去天数                " << endl; 
	cout << "      4.返回菜单              " << endl; 
	cout << "********************************" << endl; 
	cout << "请选择："; 
	int i = 0;
	cin >> i; 
	switch (i) 
	{ 
	case 1: 
	{
		Date d1; Date d2; cout << "请输入第一个日期："; 
		cin >> d1; cout << "请输入第二个日期："; 
		cin >> d2; cout << d1 << "与" << d2 << "间隔" << d1 - d2 << "天" << endl; 
		DecMenu();
		break; 
	} 
	case 2: 
	{ 
		Date d1; 
		Date d2; 
		int days; 
		cout << "请输入日期："; 
		cin >> d1; cout << "请输入要增加的天数："; 
		cin >> days; d2 = d1 + days; 
		cout << d1 << "的100天后的日期：" << d2 << endl; 
		DecMenu();
		break; 
	} 
	case 3: 
	{
		Date d1; 
		Date d2; 
		int days; 
		cout << "请输入日期："; 
		cin >> d1; cout << "请输入要减去的天数："; 
		cin >> days; d2 = d1 - days; 
		cout << d1 << "的100天前的日期：" << d2 << endl; 
		DecMenu();
		break; 
	} 
	case 4: 
		menu();
		break; 
	default:
		cout << "输入错误，请重新选择！" << endl;
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

