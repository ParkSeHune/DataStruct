#include "../Program/stdafx.h"

using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class List
{
public:
	List() : head(nullptr), count(0) {}
	~List() { clear(); }
	void push_front(T data);
	void push_back(T data);
	void insert(T data, int pos);

	void pop_front();
	void pop_back();
	void remove(int pos);
	void clear();

	void print_forward();

	int getCount() const;
	Node<T>* getHead()const;
	bool isEmpty() const;
private:
	Node<T>* head;
	int count;
};

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (isEmpty())
	{
		head = newNode;
	}
	else
	{

		newNode->next = head;
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
	}
	else
	{
		Node<T>* curNode = head;

		while (curNode->next != nullptr)
		{
			curNode = curNode->next;
		}

		curNode->next = newNode;
	}

	count++;
}

template<typename T>
void List<T>::insert(T data, int pos)
{
	if (pos <= 0 || pos > count + 1)
	{
		cout << "Position is Incorrect" << endl;
		return;
	}

	if (isEmpty())
	{
		if (pos == 1)
		{
			push_front(data);
		}
		else
		{
			cout << "List is empty. Position invalid." << endl;
		}

		return;
	}

	if (pos == 1)
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
		curNode->next = newNode;

		count++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (!isEmpty())
	{
		Node<T>* delNode = head->next;
		delete head;
		head = delNode;

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
	if (isEmpty())
	{
		cout << "Data doesn't exist" << endl;
		return;
	}

	if (count == 1)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node<T>* curNode = nullptr;
		Node<T>* delNode = head;

		while (delNode->next != nullptr)
		{
			curNode = delNode;
			delNode = delNode->next;
		}

		delete delNode;
		curNode->next = nullptr;
	}

	count--;
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
		Node<T>* nextNode = head;

		for (int i = 0; i < pos - 2; i++)
		{
			current = current->next;
		}

		nextNode = current->next;
		current->next = nextNode->next;

		delete nextNode;

		count--;
	}
}

template<typename T>
void List<T>::clear()
{
	if (isEmpty())
	{
		return;
	}

	Node<T>* current = head;

	while (current)
	{
		Node<T>* nextNode = current->next;
		delete current;
		current = nextNode;
	}

	head = nullptr;
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

int main()
{
	List<int> list;

	list.push_front(10);
	list.push_front(20);
	list.push_front(30);

	list.pop_front();
	list.pop_front();
	list.pop_front();

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
