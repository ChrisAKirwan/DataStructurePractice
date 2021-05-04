#pragma once
#include "linkedlist.h"

template <class T>
class Queue
{
public:
	LinkedList<T> container;

	friend std::ostream& operator<<(std::ostream& os, const Queue<int>& obj)
	{
		os << obj.container;
		return os;
	}

	bool empty() { return container.empty(); }
	int size() { return container.size; }
	T top()
	{
		if (!empty())
			return container.front();
		else
			return T{};
	}

	void push(T val)
	{
		container.push_front(val);
	}

	void pop()
	{
		container.erase(0);
	}

	void swap(Stack<T>& other)
	{
		container.swap(other.container);
	}
};