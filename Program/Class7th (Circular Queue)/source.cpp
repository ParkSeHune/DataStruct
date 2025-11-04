#include "../Program/stdafx.h"

constexpr int SIZE = 4;


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
		{
			exit(1);
		}
		else
		{
			return container[(front + 1) % SIZE];
		}
	}
private:
	T container[SIZE];
	int rear;
	int front;
};

template<typename T>
Queue<T>::Queue()
{
	rear = SIZE - 1;
	front = SIZE - 1;

	for (int i = 0; i < SIZE; i++)
	{
		container[i] = NULL;
	}
}

template<typename T>
void Queue<T>::push(T data)
{
	if (front == (rear + 1) % SIZE)
	{
		cout << "Circle queue overflow " << endl;
	}
	else
	{
		rear = (rear + 1) % SIZE;

		container[rear] = data;
	}
}

template<typename T>
void Queue<T>::pop()
{
	if (empty())
	{
		cout << "Circle queue empty " << endl;
	}
	else
	{
		front = (front + 1) % SIZE;

		container[front] = NULL;
	}
}

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);

	while (!queue.empty())
	{
		cout << queue.peek() << endl;
		queue.pop();
	}

	queue.push(40);
	queue.push(50);
	queue.push(60);
	queue.push(70);

	while (!queue.empty())
	{
		cout << queue.peek() << endl;
		queue.pop();
	}

	return 0;
}