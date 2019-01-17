#include <iostream>
using namespace std;
#include <string.h>

#pragma warning(disable:4996)

class String
{
public:
	typedef char* Iterator;

public:
	//构造函数
	String()
	{}
	String(const char* str)
	{
		if (nullptr == str)
		{
			str = "";
		}
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;

		strcpy(_str, str);
	}
	String(const char* str, size_t size)
	{
		if (size < 0)
		{
			perror("size error");
			exit(EXIT_SUCCESS);
		}
		_size = size;
		_str = new char[_size + 1];
		_capacity = _size;
		strncpy(_str, str, size);
		if (size < strlen(str))
		{
			_str[_size] = 0;
		}
	}
	//拷贝构造函数
	//采用深拷贝的传统写法
	String(const String& s)
		:_str(new char[s._capacity+1])
		,_capacity(s._capacity)
		,_size(s._size)
	{
		strcpy(_str, s._str);
	}
	//深拷贝的现代版写法
	//String(const String& s)
	//{
	//	String strTmp(s._str);
	//	swap(_str, strTmp);
	//}
	//赋值运算符的重载
	String& operator=(const String& s)
	{
		if (&s != this)
		{
			char* pStr = new char[s._capacity + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	//析构函数
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	//迭代器
	Iterator Begin()
	{
		return _str;
	}
	Iterator End() 
	{
		return _str + _size;
	}
	Iterator RBegin()
	{
		return End();
	}
	Iterator REnd()
	{
		return Begin();
	} 
	//尾插字符
	void PushBack(char c)
	{
		if (_size == _capacity)
			Reserve(_capacity * 2);
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	////尾插字符串，和追加道理相同
	//void PushBack(char* str)
	//{
	//	size_t str_size = strlen(str);
	//	if (_size + str_size + 1 >= _capacity)
	//	{
	//		Reserve(_capacity + str_size);
	//		while (*str != '\0')
	//		{
	//			_str[_size++] = *str++;
	//		}
	//		_str[_size] = '\0';
	//	}
	//}
	//追加字符串
	void Append(const char* str)
	{
		int len = strlen(str);
		while (len > _capacity - _size)
		{
			Reserve(2 * _capacity);
		}
		strcat(_str, str);
		_size += len;
	}

	char& operator[](size_t index)
	{
		return _str[index];
	}
	const char& operator[](size_t index)const
	{
		return _str[index];
	}
	//指定位置插入一个字符
	String& Insert(size_t pos, char c)
	{
		if (_size + 1 >= _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size + 1] = '\0';
		for (int i = _size; i > pos; i--)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = c;
		++_size;
		return *this;
	}
	//在指定位置插入一个字符串
	String& Insert(size_t pos, const char* str)
	{
		int len = strlen(str);
		if (_size + len >= _capacity)
		{
			Reserve(_capacity + len + 1);
		}
		_str[_size + len] = '\0';
		for (int i = _size; i >= pos; i--)
		{
			_str[i + len] = _str[i];
		}
		while (*str != '\0')
		{
			_str[pos++] = *str++;
		}
		_size = _size + len;
		return *this;
	}
	//删除指定位置,指定长度的内容
	String& Erase(size_t pos, size_t len)
	{
		//删除的数据未超过字符串长度
		if (pos + len <= _size)
		{
			while (_str[pos + len] != '\0')
			{
				_str[pos] = _str[pos + len];
				pos++;
			}
			_str[pos] = _str[pos + len];
			_size = strlen(_str);
		}
		else
		{
			_str[pos] = _str[_size];
			_size = strlen(_str);
		}
		return *this;
	}
	//调整大小
	void Resize(size_t newSize, char c = '0')
	{
		if (newSize > _size)
		{
			if (newSize > _capacity)
			{
				Reserve(newSize);
			}
			memset(_str + _size, c, newSize - _size);
		}
		_size = newSize;
		_str[newSize] = '\0';
	}
	//扩容
	void Reserve(size_t newCapacity)
	{
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}
	}

	int Size()const
	{
		return _size;
	}
	int Capacity()const
	{
		return _capacity;
	}
	bool Empty()const
	{
		return (0 == _size);
	}
	void Clear()
	{
		_size = 0;
	}
	int Find(char c, size_t pos = 0)
	{
		for (int i = pos; i < _size; i++)
		{
			if (c == _str[i])
			{
				return i;
			}
		}
		return npos;
	}
	int rFind(char c)
	{
		for (int i = _size - 1; i > 0; i--)
		{
			if (c == _str[i])
			{
				return i;
			}
		}
		return npos;
	}
	const char* C_Str()const
	{
		return _str;
	}
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	String SubStr(size_t pos, size_t size)
	{
		int len = strlen(_str + pos);
		if (size > len)
			size = len;
		return String(_str + pos, size);
	}

	//运算符重载
	bool operator<(const String& s)
	{
		return (!(*this >= s));
	}
	bool operator<=(const String& s)
	{
		return (!(*this > s));
	}
	bool operator>(const String& s)
	{
		int i = 0;
		if (_str[i] == s._str[i] && i < _size)
		{
			i++;
		}
		if (i <= _size)
		{
			return false;
		}
		return _str[i] > s._str[i] ? true : false;
	}
	bool operator>=(const String& s)
	{
		if (*this > s || *this == s)
		{
			return true;
		}
		return false;
	}
	bool operator==(const String& s)
	{
		int i = 0;
		if (_str[i] == s._str[i] && i < _size)
		{
			i++;
		}
		if (i == _size && s._str[i] == '\0')
		{
			return true;
		}
		return false;
	}
	bool operator!=(const String& s)
	{
		return (!(*this == s));
	}
	//+符号的重载
	String operator+(char c)
	{
		String tmp(*this);
		tmp.PushBack(c);
		return tmp;
	}
	String operator+(const char* str)
	{
		String tmp(*this);
		tmp.Append(str);
		return tmp;
	}
	//+=符号的重载
	String operator+=(char c)
	{
		this->PushBack(c);
		return *this;
	}
	String operator+=(const char* str)
	{
		this->Append(str);
		return *this;
	}
	//<<&>>的重载
	friend ostream& operator<<(ostream& _cout, const String& s)
	{
		_cout << s._str;
		return _cout;
	}
	friend istream& operator>>(istream& _cin, String& s)
	{
		_cin >> s._str;
		return _cin;
	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;

	const static int npos;
};

const int String::npos = -1;


void TestString1()
{
	String s1;
	String s2("hello bit");
	String s3(s2);
	s1 = s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}
void TestString2()
{
	String s1("hello");
	s1.PushBack(' ');
	s1.PushBack('b');
	s1.Append("123");
	s1 += 't';
	cout << s1 << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	// 利用迭代器打印string中的元素
	auto it = s1.Begin();
	while (it != s1.End())
	{
		cout << *it++;
	}
	cout << endl;
	String s2("hello world!!!");
	s1.Swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;
}

void TestString3()
{
	String s("hello");
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Resize(10, 'a');
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Resize(20);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Resize(5);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
	s.Reserve(50);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
}

void TestString4()
{
	String s1("abcdefg");
	String s2 = s1;
	cout << s1 << endl;
	s1.Insert(2, 'h');
	cout << s1 << endl;
	s1.Insert(2, "123");
	cout << s1 << endl;
	s2.Erase(2, 5);
	cout << s2 << endl;
}

void TestString5()
{
	String s1 = "abcdef";
	String s2 = "abcdh";
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 <= s2) << endl;
}

int main()
{
	cout << "Test1: 默认成员函数" << endl;
	TestString1();
	cout  << endl;
	cout << "Test2: Iterators + Modifiers" << endl;
	TestString2();
	cout << endl;
	cout << "Test3: Capacity" << endl;
	TestString3();
	cout << endl;
	cout << "Test4: Modifiers" << endl;
	TestString4();
	cout << endl;
	cout << "Test5: 比较" << endl;
	TestString5();
	cout << endl;

	system("pause");
	return 0;
}