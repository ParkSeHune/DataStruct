#include "../Program/stdafx.h"

template <typename T>
class Stack
{
public:
	Stack() : container(nullptr), highset(-1), capacity(0) {}
	~Stack();
	void resize(int newSize);
	void push(T data);
	void pop();
	const bool& empty() { return highset <= -1; }
	const int& size() { return highset + 1; }
	const T& top() { return container[highset]; }
private:
	T* container;
	int highset;
	int capacity;
};

template<typename T>
Stack<T>::~Stack()
{
	if (container != nullptr)
	{
		delete[] container;
	}
}

template <typename T>
void Stack<T>::resize(int newSize)
{
	capacity = newSize;

	T* newArr = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		newArr[i] = T();
	}

	for (int i = 0; i < highset + 1 && i < capacity; i++)
	{
		newArr[i] = container[i];
	}

	delete[] container;

	container = newArr;
}

template <typename T>
void Stack<T>::push(T data)
{
	if (capacity <= 0)
	{
		resize(1);
	}
	else if (highset + 1 >= capacity)
	{
		resize(capacity * 2);
	}

	highset++;
	container[highset] = data;
}

template<typename T>
void Stack<T>::pop()
{
	if (empty())
	{
		cout << "Stack is Empty" << endl;
	}
	else
	{
		container[highset] = T();
		highset--;
	}
}

int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	while (stack.empty() == false)
	{
		cout << stack.top() << endl;

		stack.pop();
	}

	cout << "Size:" << stack.size();

	return 0;
}