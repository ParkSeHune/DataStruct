#include "../Program/stdafx.h"

#define SIZE 5


template <typename T>
class Queue
{
public:
	Queue();
	void push(T data);
	void pop();
	const bool& empty() { return front == rear; }
	const T& peek()
	{
		if (empty())
			exit(1);
		else
			return container[front];
	}
	const int& size() { return rear - front; }
private:
	T container[SIZE];
	int rear;
	int front;
};

template<typename T>
Queue<T>::Queue()
{
	rear = 0;
	front = 0;

	for (int i = 0; i < SIZE; i++)
	{
		container[i] = NULL;
	}
}

template<typename T>
void Queue<T>::push(T data)
{
	if (rear >= SIZE)
	{
		cout << "Linear queue overflow" << endl;
	}
	else
	{
		container[rear++] = data;
	}
}

template<typename T>
void Queue<T>::pop()
{
	if (empty())
	{
		cout << "Linear queue is empty" << endl;
	}
	else
	{
		container[front++] = NULL;
	}
}

int main()
{
	Queue<int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);

	while (!queue.empty())
	{
		cout << queue.peek() << endl;
		queue.pop();
	}

	cout << "Size: " << queue.size() << endl;

	return 0;
}