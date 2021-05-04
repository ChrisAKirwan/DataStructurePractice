#pragma once
#include <iostream>

template <class T>
class LinkedList
{
public:
	struct Node
	{
		Node* previous;
		T data;
		Node* next;

		Node(T val) : previous(nullptr), data(val), next(nullptr) {}
	};

	LinkedList() : head(nullptr), tail(nullptr), size(0) { std::cout << "Default Constructor Called" << std::endl; }

	LinkedList(int size, T fill_val) : size(0), head(nullptr), tail(nullptr)
	{
		std::cout << "Non-Default Constructor Called" << std::endl;
		resize(size, fill_val);
	}

	LinkedList(const LinkedList<T>& other) : size(other.size)
	{
		std::cout << "Copy Constructor Called" << std::endl;
		// Copy
		if (other.empty())
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->size = 0;
		}
		else
		{
			Node* newNode = nullptr;
			Node* prev = nullptr;
			Node* currentNode = other.head;
			
			while (currentNode)
			{
				newNode = new Node(currentNode->data);
				newNode->previous = prev;

				if (prev)
					prev->next = newNode;
				else
					head = newNode;

				currentNode = currentNode->next;
				prev = newNode;
			}

			tail = newNode;
		}
	}

	LinkedList(LinkedList<T>&& other): head(other.head), tail(other.tail), size(other.size)
	{
		std::cout << "Move Constructor Called" << std::endl;
		// Move
		other.head = nullptr;
		other.tail = nullptr;
	}

	~LinkedList() { std::cout << "Destructor Called" << std::endl; clear(); }


	// Properties
	Node* head;
	Node* tail;
	int size;


	// Overloads
	LinkedList<T>& operator=(const LinkedList<T>& other) noexcept
	{
		std::cout << "Assignment Overload Called" << std::endl;
		this->clear();

		Node* newNode = nullptr;
		Node* currentNode = other.head;
		Node* prev = nullptr;

		while (currentNode)
		{
			newNode = new Node(currentNode->data);
			if (prev)
				prev->next = newNode;
			else
				this->head = newNode;

			currentNode = currentNode->next;
			newNode->previous = prev;
			prev = newNode;
			this->size++;
		}

		this->tail = newNode;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList<int>& obj)
	{
		os << "Size: " << obj.size << std::endl;

		if(obj.head)
			os << "Head: " << obj.head->data << std::endl;
		else
			os << "Head: " << "NULL" << std::endl;

		if(obj.tail)
			os << "Tail: " << obj.tail->data << std::endl;
		else
			os << "Tail: " << "NULL" << std::endl;

		os << "Contents: " << std::endl;
		Node* currentNode = obj.head;
		while (currentNode)
		{
			os << "[";
			if (currentNode->previous)
				os << currentNode->previous->data << ", ";
			else
				os << "X, ";
			
			os << currentNode->data << ", ";

			if (currentNode->next)
				os << currentNode->next->data << "]";
			else
				os << "X]" << std::endl;

			currentNode = currentNode->next;
		}

		return os;
	}

	T operator[](int i)
	{
		Node* currentNode = head;
		while (i-- > 0)
		{
			if(!currentNode)
				return T{};

			currentNode = currentNode->next;
		}

		return currentNode->data;
	}

	// Capacity
	bool empty() const { return (size > 0 ? false : true); }

	// Element Access
	T front() const { return (size ? head->data : T{}); }
	T back() const { return (size ? tail->data : T{}); }

	// Modifiers
	void push_front(T val)
	{
		Node* newNode = new Node(val);
		if (!head)
			head = tail = newNode;
		else
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}

		size++;
	}

	void pop_back()
	{
		if (size == 0)
			return;

		Node* oldNode = tail;
		tail = tail->previous;
		if (tail)
			tail->next = nullptr;
		else
			head = tail;

		size--;

		delete oldNode;
	}

	void insert(int idx, T val)
	{
		if (idx == size)
		{
			push_back(val);
			return;
		}

		if (idx == 0)
		{
			push_front(val);
			return;
		}

		Node* currentNode = head;
		while (idx-- > 0)
		{
			if (!currentNode)
				return;

			currentNode = currentNode->next;
		}

		Node* previousNode = currentNode->previous;
		Node* newNode = new Node(val);
		previousNode->next = newNode;
		newNode->previous = previousNode;
		newNode->next = currentNode;
		currentNode->previous = newNode;

		size++;
	}

	void erase(int idx)
	{
		if (idx == size - 1)
		{
			pop_back();
			return;
		}

		if (idx == 0)
		{
			pop_front();
			return;
		}

		Node* currentNode = head;
		while (idx-- > 0)
		{
			if (!currentNode)
				return;

			currentNode = currentNode->next;
		}

		Node* previousNode = currentNode->previous;
		Node* nextNode = currentNode->next;
		previousNode->next = nextNode;
		nextNode->previous = previousNode;

		delete currentNode;
		size--;		
	}

	void erase(int start_idx, int end_idx)
	{
		if ((start_idx >= 0 && start_idx < end_idx) && end_idx < size)
		{
			Node* currentNode = head;
			Node* startNode = nullptr;
			Node* endNode = nullptr;
			for (int i = 0; i <= end_idx; i++, currentNode = currentNode->next)
			{
				if (i == start_idx)
					startNode = currentNode;

				if (i == end_idx)
					endNode = currentNode;
			}
			Node* prev = startNode->previous;
			Node* next = endNode->next;

			if (!prev)
				head = next;
			else
				prev->next = next;

			if(!next)
				tail = prev;
			else
				next->previous = prev;

			endNode->next = nullptr;
			while (startNode)
			{
				endNode = startNode->next;
				delete startNode;
				startNode = endNode;

				size--;
			}
		}
	}

	void swap(LinkedList<T>& other)
	{
		Node* tempNode = this->head;
		this->head = other.head;
		other.head = tempNode;

		tempNode = this->tail;
		this->tail = other.tail;
		other.tail = tempNode;

		int tempSize = other.size;
		other.size = this->size;
		this->size = tempSize;
	}

	void resize(int new_size, T fill_val)
	{
		if (new_size <= this->size)
			return;

		while (this->size < new_size)
			push_back(fill_val);
	}

	void clear()
	{
		this->tail = nullptr;

		Node* temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}

		size = 0;
	}

	// Operations
	void splice(int idx, LinkedList<T>& other)
	{
		if (idx < 0 || idx > this->size)
			return;

		Node* currentNode = this->head;
		for (int i = 0; i < idx; i++)
			currentNode = currentNode->next;

		if (!currentNode->previous)
		{
			// Insert Front
			other.tail->next = currentNode;
			currentNode->previous = other.tail;
			this->head = other.head;
		}
		else if (!currentNode)
		{
			// Insert End
			this->tail->next = other.head;
			other.head->previous = this->tail;
			this->tail = other.tail;
		}
		else
		{
			// Insert Middle
			Node* prevNode = currentNode->previous;

			prevNode->next = other.head;
			other.tail->next = currentNode;
			other.head->previous = prevNode;
			currentNode->previous = other.tail;
		}

		this->size += other.size;

		other.head = other.tail = nullptr;
		other.size = 0;
	}

	void splice(int idx, LinkedList<T>& other, int other_idx)
	{
		if ((idx < 0 || idx > this->size) ||
			(other_idx < 0 || other_idx >= other.size))
			return;

		Node* otherNode = other.head;
		for (int i = 0; i < other_idx; i++)
			otherNode = otherNode->next;

		Node* otherPrevNode = otherNode->previous;
		Node* otherNextNode = otherNode->next;
		otherPrevNode->next = otherNextNode;
		otherNextNode->previous = otherPrevNode;
		other.size--;

		Node* thisNode = this->head;
		for (int i = 0; i < idx; i++)
			thisNode = thisNode->next;

		if (!thisNode->previous)
		{
			// Insert at head
			otherNode->previous = nullptr;
			otherNode->next = this->head;
			this->head->previous = otherNode;
			this->head = otherNode;
		}
		else if (!thisNode)
		{
			// Insert at end
			otherNode->previous = this->tail;
			otherNode->next = nullptr;
			this->tail = otherNode;
		}
		else
		{
			// Insert in middle
			otherNode->previous = thisNode->previous;
			otherNode->next = thisNode;
			thisNode->previous->next = otherNode;
			thisNode->previous = otherNode;
		}

		this->size++;
	}

	void splice(int idx, LinkedList<T>& other, int start_idx, int end_idx)
	{
		// Check invalid indices
		if ((idx < 0 || idx > this->size) ||
			(start_idx < 0 || start_idx >= end_idx) ||
			(end_idx >= other.size))
			return;
		
		// Check if the entire list is requested
		if (start_idx == 0 && end_idx == other.size - 1)
		{
			splice(idx, other);
			return;
		}

		// Separate list segment from other list and fix other list.
		Node* otherNodeStart = other.head;
		Node* otherNodeEnd = other.head;
		for (int i = 0; i < end_idx; i++)
		{
			if (i == start_idx)
				otherNodeStart = otherNodeEnd;

			otherNodeEnd = otherNodeEnd->next;
		}

		Node* otherPreviousNode = otherNodeStart->previous;
		Node* otherNextNode = otherNodeEnd->next;

		if (otherPreviousNode)
			otherPreviousNode->next = otherNextNode;
		else
			other.head = otherNextNode;

		if (otherNextNode)
			otherNextNode->previous = otherPreviousNode;
		else
			other.tail = otherPreviousNode;

		other.size -= (end_idx + 1) - start_idx;

		// Locate idx in this list and insert segment
		Node* thisNode = this->head;
		for (int i = 0; i < idx; i++)
			thisNode = thisNode->next;

		if (!thisNode->previous)
		{
			// Insert at head
			otherNodeEnd->next = thisNode;
			thisNode->previous = otherNodeEnd;
			this->head = otherNodeStart;
			this->head->previous = nullptr;
		}
		else if (!thisNode)
		{
			// Insert at tail
			this->tail->next = otherNodeStart;
			otherNodeStart->previous = this->tail;
			this->tail = otherNodeEnd;
			this->tail->next = nullptr;
		}
		else
		{
			// Insert in middle
			otherNodeStart->previous = thisNode->previous;
			otherNodeEnd->next = thisNode;
			thisNode->previous->next = otherNodeStart;
			thisNode->previous = otherNodeEnd;
		}

		this->size += (end_idx + 1) - start_idx;
	}

	void remove(T val)
	{
		Node* currentNode = head;
		while (currentNode)
		{
			if (currentNode->data == val)
			{
				Node* nextNode = currentNode->next;
				if (nextNode)
					nextNode->previous = currentNode->previous;
				else
					tail = currentNode->previous;

				if (currentNode->previous)
					currentNode->previous->next = nextNode;
				else
					head = nextNode;

				delete currentNode;
				currentNode = nextNode;
				size--;
				continue;
			}

			currentNode = currentNode->next;
		}
	}

	void merge(LinkedList<int>& other)
	{
		Node* thisNode = this->head;
		Node* otherNode = other.head;

		while (thisNode)
		{
			if (otherNode->data < thisNode->data)
			{
				Node* otherNodeNext = otherNode->next;
				if (!thisNode->previous)
				{
					// insert at head
					otherNode->previous = nullptr;
					otherNode->next = thisNode;
					thisNode->previous = otherNode;
				}
				else
				{
					thisNode->previous->next = otherNode;
					otherNode->previous = thisNode->previous;
					otherNode->next = thisNode;
					thisNode->previous = otherNode;
				}

				otherNode = otherNodeNext;
				if (!otherNode)
					return;

				continue;
			}
			thisNode = thisNode->next;
		}

		// all remaininig values in other are larger than the ones in this list.
		otherNode->previous = this->tail;
		this->tail->next = otherNode;
		this->tail = other.tail;

		this->size += other.size;
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	void reverse()
	{
		Node* currentNode = head;
		tail = head;
		while (currentNode)
		{
			Node* temp = currentNode->next;
			currentNode->next = currentNode->previous;
			currentNode->previous = temp;

			if (!temp)
				head = currentNode;

			currentNode = temp;
		}
	}

	void push_back(T val)
	{
		Node* newNode = new Node(val);
		if (!tail)
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (size == 0)
			return;

		Node* oldNode = head;
		head = head->next;
		if (head)
			head->previous = nullptr;
		else
			tail = head;

		delete oldNode;
		size--;
	}
};