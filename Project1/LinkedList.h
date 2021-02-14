#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
public:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};


	/*==== Construction / Destruction ==== */
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();
	/*==== XXXXXXXXXX ==== */

	/*==== Operators ==== */
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);
	/*==== XXXXXXXXXX ==== */

	/*==== Accessors ==== */
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	const Node* GetNodeV2(unsigned int index) const;
	Node* GetNodeV2(unsigned int index);
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;
	/*==== XXXXXXXXXX ==== */

	/*==== Removal ==== */
	void ResetPointers();
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(int index);
	void Clear();
	/*==== XXXXXXXXXX ==== */

	/*==== Insertion ==== */
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);
	/*==== XXXXXXXXXX ==== */

	/*==== Behaviors ==== */
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;
	/*==== XXXXXXXXXX ==== */

private:
	unsigned int size;
	Node* head;
	Node* tail;
};

/*==== Behaviors ==== */
template <class T>
void LinkedList<T>::PrintForward() const
{
	Node* curr = head;

	while (curr != nullptr)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

template <class T>
void LinkedList<T>::PrintReverse() const
{
	Node* curr = tail;

	while (curr != nullptr)
	{
		cout << curr->data << endl;
		curr = curr->prev;
	}
}

template <class T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	if (node != nullptr)
	{
		cout << node->data << endl;
		PrintForwardRecursive(node->next);
	}
}

template <class T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	if (node != nullptr)
	{
		cout << node->data << endl;
		PrintReverseRecursive(node->prev);
	}
}
/*==== XXXXXXXXXX ==== */

/*==== Accessors ==== */
template<typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	return size;
}

template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* curr = head;

	while (curr != nullptr)
	{
		if (curr->data == value)
		{
			outData.push_back(curr);
		}
		curr = curr->next;
	}
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	int match = 0;
	Node* curr = head;

	while (curr != nullptr)
	{
		if (curr->data == data)
		{
			match++;
			return curr;
		}
		curr = curr->next;
	}

	if (match == 0)
	{
		return nullptr;
	}
	return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	int match = 0;
	Node* curr = head;

	while (curr != nullptr)
	{
		if (curr->data == data)
		{
			match++;
			return curr;
		}
		curr = curr->next;
	}

	if (match == 0)
	{
		return nullptr;
	}
	return nullptr;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	Node* curr = head;

	if (index < size)
	{
		for (unsigned int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
	}

	else
	{
		throw runtime_error("An error has occurred.");

	}
	return curr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	Node* curr;

	if (index < size)
	{
		curr = head;
		for (unsigned int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
	}

	else
	{
		throw runtime_error("An error has occurred.");

	}
	return curr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return head;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return tail;
}
/*==== XXXXXXXXXX ==== */

/*==== Insertion ==== */
template <class T>
void LinkedList<T>::AddHead(const T& data)
{
	Node* curr;

	if (head != nullptr)
	{
		curr = new Node();
		curr->data = data;
		head->prev = curr;
		curr->next = head;
		head = curr;
	}
	else
	{
		head = new Node();
		head->data = data;
		tail = head;
	}
	size++;
}

template <class T>
void LinkedList<T>::AddTail(const T& data)
{
	Node* curr;

	if (tail != nullptr)
	{
		curr = new Node();
		curr->data = data;
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
	}
	else
	{
		tail = new Node();
		tail->data = data;
		head = tail;
	}
	size++;
}


template <class T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	for (int i = count - 1; i >= 0; i--)
	{
		AddHead(data[i]);
	}
}

template <class T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		AddTail(data[i]);
	}
}

template <class T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	Node* curr;

	if (size == 0)
	{
		AddHead(data);
	}
	else if (node == nullptr)
	{
		throw runtime_error("An error has occurred.");
	}
	else
	{
		curr = new Node();
		curr->data = data;
		curr->next = node->next;
		node->next = curr;
		curr->prev = node;
	}
	size++;
}

template <class T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* curr;

	if (size == 0)
	{
		AddHead(data);
	}
	else if (node == nullptr)
	{
		throw runtime_error("An error has occurred.");
	}
	else
	{
		curr = new Node();
		curr->data = data;
		curr->prev = node->prev;
		node->prev = curr;
		curr->next = node;
		if (curr->prev != nullptr)
		{
			curr->prev->next = curr;
		}
	}
	size++;
}

template <class T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	Node* node;

	if (index == 0)
	{
		AddHead(data);
	}
	else if (index == size - 1)
	{
		AddTail(data);
	}
	else if (index > size)
	{
		throw runtime_error("An error has occurred.");
	}
	else
	{
		node = GetNode(index - 1);
		InsertAfter(node, data);
	}
}
/*==== XXXXXXXXXX ==== */

/*==== Removal ==== */
template <class T>
void LinkedList<T>::ResetPointers()
{
	head = nullptr;
	tail = nullptr;
}
template <class T>
bool  LinkedList<T>::RemoveHead()
{
	Node* curr;

	if (head == nullptr || size == 0)
	{
		return false;
	}
	else if (head->next == nullptr)
	{
		delete head;
		ResetPointers();
	}
	else
	{
		curr = head;
		head = head->next;
		delete curr;
	}

	size--;
	return true;
}

template <class T>
bool LinkedList<T>::RemoveTail()
{
	Node* curr;

	if (tail == nullptr || size == 0)
	{
		return false;
	}
	else if (tail->prev == nullptr)
	{
		delete tail;
		ResetPointers();
	}
	else
	{
		curr = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete curr;

	}
	size--;
	return true;
}

template <class T>
unsigned int  LinkedList<T>::Remove(const T& data)
{
	Node* temp;
	Node* curr = head;
	int removedCount = 0;

	if (size == 0)
	{
		return removedCount;
	}
	else
	{
		while (curr != nullptr)
		{
			if (curr->data == data)
			{
				temp = curr;
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				curr = curr->next;
				delete temp;
				size--;
				removedCount++;
			}
			else
			{
				curr = curr->next;
			}
		}
	}
	return removedCount;
}

template <class T>
bool  LinkedList<T>::RemoveAt(int index)
{
	Node* temp;
	Node* curr = head;

	if (index >= static_cast<int>(size) || index < 0)
	{
		return false;
	}

	else
	{
		while (curr != nullptr)
		{
			if (index < static_cast<int>(size))
			{
				for (int i = 0; i < index; i++)
				{
					curr = curr->next;
				}
				temp = curr;
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				curr = curr->next;
				delete temp;
				size--;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
/*==== XXXXXXXXXX ==== */

/*==== Operators ==== */
template <class T>
const T& LinkedList<T>::operator[](unsigned int index) const
{
	Node* curr;

	if (index >= size)
	{
		throw runtime_error("An error has occurred.");
	}
	else
	{
		curr = head;
		for (unsigned int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
	}
	return curr->data;
}

template <class T>
T& LinkedList<T>::operator[](unsigned int index)
{
	Node* curr;

	if (index >= size)
	{
		throw runtime_error("An error has occurred.");

	}
	else
	{
		curr = head;
		for (unsigned int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
	}
	return curr->data;
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{

	Node* listA = head;
	Node* listB = rhs.head;

	if (size != rhs.size)
	{
		return false;
	}

	else if (head == nullptr && rhs.head == nullptr)
	{
		return true;
	}
	else
	{
		while (listA != nullptr)
		{
			if (listA->data == listB->data)
			{
				listA = listA->next;
				listB = listB->next;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

template <class T>
void  LinkedList<T>::Clear()
{
	Node* temp;
	Node* curr = head;

	while (curr != nullptr)
	{
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	size = 0;
	ResetPointers();
	curr = nullptr;
	temp = nullptr;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	Clear();
	Node* curr;

	curr = rhs.head;
	while (curr != nullptr)
	{
		AddTail(curr->data);
		curr = curr->next;
	}

	return *this;
}
/*==== XXXXXXXXXX ==== */

/*==== Construction / Destruction ==== */

template <class T>
LinkedList<T>::LinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	Clear();
	Node* curr = list.head;
	while (curr != nullptr)
	{
		this->AddTail(curr->data);
		curr = curr->next;
	}

}

template <class T>
LinkedList<T>::~LinkedList()
{
	Clear();
}
/*==== XXXXXXXXXX ==== */

