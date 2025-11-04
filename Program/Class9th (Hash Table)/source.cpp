#include "../Program/stdafx.h"

template<typename KEY, typename VALUE>
class HashTable
{
public:
	HashTable();
	~HashTable();
	template<typename KEY>

	unsigned int hash_funtion(KEY key) { return (unsigned int)key % capacity; }
	unsigned int hash_funtion(const char* key)
	{
		unsigned int sum = 0;
		for (int i = 0; key[i] != '\0'; i++)
			sum += key[i];
		return sum % capacity;
	}

	void insert(KEY key, VALUE value);
	void erase(KEY key);
	const int& bucket_count() const { return capacity; }
	const float& load_factor() { return (float)size / capacity; }
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};

	struct Bucket
	{
		Node* head;
		int count;

		Bucket() : head(nullptr), count(0) {}
	};

	int size;
	int capacity;
	Bucket* bucket;
};

template<typename KEY, typename VALUE>
HashTable<KEY, VALUE>::HashTable() : size(0), capacity(8)
{
	bucket = new Bucket[capacity];

	for (int i = 0; i < capacity; i++)
	{
		bucket[i].head = nullptr;
		bucket[i].count = 0;
	}
}

template<typename KEY, typename VALUE>
HashTable<KEY, VALUE>::~HashTable()
{
	for (int i = 0; i < capacity; i++)
	{
		Node* delNode = bucket[i].head;
		Node* nextNode = bucket[i].head;

		if (bucket[i].head == nullptr)
		{
			continue;
		}
		else
		{
			while (nextNode != nullptr)
			{
				nextNode = delNode->next;
				delete delNode;
				delNode = nextNode;
			}
		}
	}
	delete[] bucket;
}

template<typename KEY, typename VALUE>
void HashTable<KEY, VALUE>::insert(KEY key, VALUE value)
{
	int hashIndex = hash_funtion(key); //hash함수를 통해서 값을 받는 임시 변수

	//새로운 노드 생성
	Node* newNode = new Node;
	newNode->key = key;
	newNode->value = value;
	newNode->next = nullptr;

	//노드가 1개라도 존재하지 않는다면
	if (bucket[hashIndex].count == 0)
	{
		bucket[hashIndex].head = newNode; //bucket[hshIndex]의 head 포인터가 newNode를 가리키도록
	}
	else
	{
		newNode->next = bucket[hashIndex].head;
		bucket[hashIndex].head = newNode;
	}

	//bucket[hashIndex]의 count증가
	bucket[hashIndex].count++;
	size++;
}

template<typename KEY, typename VALUE>
void HashTable<KEY, VALUE>::erase(KEY key)
{
	int hashIndex = hash_funtion(key); //hash함수를 통해서 값을 받는 임시 변수
	Node* curNode = bucket[hashIndex].head; //Node를 탐색할 수 있는 포인터 변수
	Node* prevNode = nullptr; //이전 Node를 지정할 수 있는 포인터 변수

	if (curNode == nullptr) return;
	else
	{
		//curNode를 이용하여 내가 찾고자 하는 key값을 찾기
		while (curNode != nullptr)
		{
			if (curNode->key == key)
			{
				if (prevNode == nullptr) bucket[hashIndex].head = curNode->next;
				else prevNode->next = curNode->next;

				size--;
				bucket[hashIndex].count--;

				delete curNode;
				return;
			}
			else
			{
				prevNode = curNode;
				curNode = curNode->next;
			}
		}

		cout << "Not Key Found" << endl;
	}

}

int main()
{
	HashTable<const char*, int> hashTable;

	hashTable.insert("뺴빼로", 2000);
	hashTable.insert("커피", 1700);
	hashTable.insert("이어폰", 200000);
	hashTable.insert("마우스", 20000);

	hashTable.erase("커피");
	hashTable.erase("커어피");

	cout << hashTable.load_factor() << endl;
	cout << hashTable.bucket_count() << endl;

	return 0;
}