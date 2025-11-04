#include "../Program/stdafx.h"

template <typename T>
class Vector
{
public:
	Vector() : pointer(nullptr), count(0), capacity(0) {}
	~Vector() { delete[] pointer; }
	void resize(int newSize);
	void push_back(T data);
	void pop_back();
	const int& size() { return count; }
	T& operator[] (const int& index) const;
private:
	T* pointer;
	int count;
	int capacity;
};

template<typename T>
void Vector<T>::resize(int newSize)
{
	capacity = newSize; //capacity에 새로운 size값을 저장

	T* newArr = new T[capacity]; //새로운 포인터 변수 생성, 새롭게 만들어진 메모리 공간을 가리킴

	//새로운 메모리 공간의 값 초기화
	for (int i = 0; i < capacity; i++)
	{
		newArr[i] = T();
	}

	//기존 배열에 있는 값을 복사해서 새로운 배열에 넣는다
	for (int i = 0; i < count && i < newSize; i++)
	{
		newArr[i] = pointer[i];
	}

	//기존 배열의 메모리 해제
	delete[] pointer;

	pointer = newArr;
}

template<typename T>
void Vector<T>::push_back(T data)
{
	if (capacity == 0)
	{
		resize(1);
	}
	else if (count >= capacity)
	{
		resize(capacity * 2);
	}

	pointer[count] = data;
	count++;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (count == 0)
	{
		cout << "Vector is already Empty" << endl;
		return;
	}

	count--;
	pointer[count] = T();
	if (count == 0)
	{
		cout << "Vector is Empty" << endl;
	}
}

template<typename T>
T& Vector<T>::operator[](const int& index) const
{
	return pointer[index];
}

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);

	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}

	vector.pop_back();
	vector.pop_back();
	vector.pop_back();
	return 0;
}