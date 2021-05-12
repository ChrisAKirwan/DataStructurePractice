#pragma once
#include "linkedlist.h"

template <class T>
class Queue
{
public:
	LinkedList<T> container;

	friend std::ostream& operator<<(std::ostream& os, const Queue<T>& obj)
	{
		os << obj.container;
		return os;
	}

	bool empty() { return container.empty(); }
	int size() { return container.size; }
	T front() { return container.front(); }
	T back() { return container.back(); }
	void push(T val){ container.push_back(val); }
	void pop() { container.pop_front(); }
	void swap(Queue<T>& other) { container.swap(other.container); }
};