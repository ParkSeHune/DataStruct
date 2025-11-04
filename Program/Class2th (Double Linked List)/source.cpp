#include "../Program/stdafx.h"

using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node* prev;

	Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template<typename T>
class List
{
public:
	List() : head(nullptr), tail(nullptr), count(0) {}
	~List() { clear(); }
	void push_front(T data);
	void push_back(T data);
	void insert(T data, int pos);

	void pop_front();
	void pop_back();
	void remove(int pos);
	void clear();

	void print_forward();
	void print_backward();

	int getCount() const;
	Node<T>* getHead()const;
	bool isEmpty() const;
private:
	Node<T>* head;
	Node<T>* tail;
	int count;
};

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	count++;
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	count++;
}

template<typename T>
void List<T>::insert(T data, int pos)
{
	if (pos <= 0 || pos > count + 1)
	{
		cout << "Invalid position" << endl;
		return;
	}

	if (isEmpty() || pos == 1)
	{
		push_front(data);
		return;
	}
	else if (pos == count + 1)
	{
		push_back(data);
		return;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* curNode = head;

		for (int i = 0; i < pos - 2; i++)
		{
			curNode = curNode->next;
		}

		newNode->next = curNode->next;
		newNode->prev = curNode;
		curNode->next->prev = newNode;
		curNode->next = newNode;

		count++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (!isEmpty())
	{
		Node<T>* delNode = head;

		if (count == 1)
		{
			head = tail = nullptr;
		}
		else
		{

			head = head->next;
			head->prev = nullptr;

		}

		delete delNode;
		count--;
	}
	else
	{
		cout << "Data dosen't exist" << endl;
	}
}

template<typename T>
void List<T>::pop_back()
{
	if (!isEmpty())
	{
		Node<T>* delNode = tail;

		if (count == 1)
		{
			head = tail = nullptr;
		}
		else
		{

			tail = tail->prev;
			tail->next = nullptr;
		}

		delete delNode;
		count--;
	}
	else
	{
		cout << "Data dosen't exsit" << endl;
	}
}

template<typename T>
void List<T>::remove(int pos)
{
	if (isEmpty() || pos <= 0 || pos > count)
	{
		return;
	}

	if (pos == 1)
	{
		pop_front();
	}
	else if (pos == count)
	{
		pop_back();
	}
	else
	{
		Node<T>* current = head;
		Node<T>* delNode = nullptr;

		for (int i = 0; i < pos - 2; i++)
		{
			current = current->next;
		}

		delNode = current->next;
		current->next = delNode->next;
		delNode->next->prev = current;

		delete delNode;

		count--;
	}
}

template<typename T>
void List<T>::clear()
{
	Node<T>* current = head;

	while (current)
	{
		Node<T>* nextNode = current->next;
		delete current;
		current = nextNode;
	}

	head = nullptr;
	tail = nullptr;
	count = 0;
}

template<typename T>
void List<T>::print_forward()
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}

	Node<T>* printNode = head;

	while (printNode != nullptr)
	{
		cout << printNode->data;
		if (printNode->next != nullptr)
		{
			cout << "->";
		}
		printNode = printNode->next;
	}

	cout << endl;
}

template<typename T>
void List<T>::print_backward()
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}

	Node<T>* printNode = tail;

	while (printNode != nullptr)
	{
		cout << printNode->data;
		if (printNode->prev != nullptr)
		{
			cout << "->";
		}
		printNode = printNode->prev;
	}

	cout << endl;
}

int main()
{
	List<int> list;

	list.push_front(10);
	list.push_front(20);
	list.push_front(30);

	list.print_forward();
	list.print_backward();

	list.pop_front();
	list.pop_front();
	list.pop_front();
	list.pop_front();

	list.print_forward();

	return 0;
}

template<typename T>
int List<T>::getCount() const
{
	return count;
}

template<typename T>
Node<T>* List<T>::getHead() const
{
	return head;
}

template<typename T>
bool List<T>::isEmpty() const
{
	return count == 0;
}
