#include "../Program/stdafx.h"

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue() : container(NULL), capacity(0), index(0) {}
	~PriorityQueue() { delete[] container; }
	void resize(int newSize);
	void push(const T& data);
	void pop();
	int size() const { return index; }
	const T& top() const { return container[0]; }
	bool isEmpty() const { return index == 0; }
private:
	T* container;
	int index;
	int capacity;
};

template<typename T>
void PriorityQueue<T>::resize(int newSize)
{
	capacity = newSize;
	T* newArr = new T[capacity];

	for (int i = 0; i < index && i < capacity; i++)
	{
		newArr[i] = container[i];
	}

	delete[] container;
	container = newArr;
}

template<typename T>
void PriorityQueue<T>::push(const T& data)
{
	if (capacity <= 0)
	{
		resize(1);
	}
	else if (index >= capacity)
	{
		resize(capacity * 2);
	}

	int child = index;
	container[child] = data;

	while (child > 0)
	{
		int parent = (child - 1) / 2;

		if (container[child] > container[parent])
		{
			swap(container[child], container[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}

	index++;
}

template<typename T>
void PriorityQueue<T>::pop()
{
	if (index <= 0)
	{
		cout << "No index" << endl;
		return;
	}

	container[0] = container[--index];

	int parent = 0;
	int child = parent * 2 + 1;

	while (child < index)
	{

		if (child + 1 < index && container[child] < container[child + 1]) child++;

		if (container[child] < container[parent]) break;

		swap(container[child], container[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}

int main()
{
	PriorityQueue<int> queue;

	queue.push(40);
	queue.push(10);
	queue.push(20);
	queue.push(80);

	while (!queue.isEmpty())
	{
		cout << queue.top() << endl;

		queue.pop();
	}

	cout << "size: " << queue.size() << endl;
	return 0;
}