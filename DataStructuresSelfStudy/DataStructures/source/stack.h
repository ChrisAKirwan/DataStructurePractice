#pragma once
#include "linkedlist.h"

template <class T>
class Stack
{
public:
	LinkedList<T> container;

	friend std::ostream& operator<<(std::ostream& os, const Stack<int>& obj)
	{
		os << obj.container;
		return os;
	}

	bool empty() { return container.empty(); }
	int size() { return container.size; }
	T top()	{ return container.front(); }
	void push(T val){ container.push_front(val); }
	void pop(){ container.pop_front(); }
	void swap(Stack<T>& other){ container.swap(other.container); }
};