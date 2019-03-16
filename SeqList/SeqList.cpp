#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~Vector();

	void PushBack(const T& data)
	{
		//_CheckCapacity();
		_pData[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	size_t Front()
	{
		return _pData[0];
	}

	size_t Back()
	{
		return _pData[_size - 1];
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}
	
	bool IsEmpty()
	{
		return 0 == _size;
	}

	void Clear()
	{
		size = 0;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);

		return _pData[pos];
	}
private:
	T * _pData;
	size_t _size;
	size_t _capacity;
};
template<class T>
Vector<T>::~Vector()
{
	if (nullptr == _pData)
	{
		delete[] _pData;
	}
	_size = 0;
	_capacity = 0;
}

int main()
{
	Vector<int> s1;

	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	cout << s1.Size() << endl;
	cout << s1.Front() << endl;
	cout << s1.Back() << endl;
	cout << s1.IsEmpty() << endl;
	s1.PopBack();
	s1[0] = 10;
	cout << s1.Front() << endl;
	cout << s1.Back() << endl;
	cout << s1.Capacity() << endl;

	system("pause");
	return 0;
}