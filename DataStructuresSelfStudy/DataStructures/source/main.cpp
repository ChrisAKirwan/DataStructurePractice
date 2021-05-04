#include "linkedlist.h"
#include "vector.h"
#include "stack.h"
#include <iostream>


void VectorTest();
void LinkedListTest();
void bubble_sort(LinkedList<int>& list);
void StackTest();

int main()
{
	//VectorTest();
	//LinkedListTest();
	//StackTest();

	return 0;
}


void VectorTest()
{
	std::cout << "VECTOR TESTING BEGIN:" << std::endl;

	Vector<int> vec1;
	std::cout << "vec1 (default) created." << std::endl;
	std::cout << vec1;

	Vector<int> vec2(10);
	std::cout << "vec2 (default) created." << std::endl;
	std::cout << vec2;

	std::cout << std::endl << "Beginning push_back tests..." << std::endl;
	for (int i = 0; i < 20; i++)
		vec1.push_back(i);

	for (int i = 0; i < 5; i++)
		vec2.push_back(i);

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning pop_back tests..." << std::endl;
	for(int i = 0; i < 5; i++)
		vec1.pop_back();

	for (int i = 0; i < 2; i++)
		vec2.pop_back();

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning insert tests..." << std::endl;
	for (int i = 0; i < 5; i++)
		vec1.insert(i, i);

	for (int i = 0; i < 2; i++)
		vec2.insert(i, i);

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning shrink_to_fit tests..." << std::endl;
	vec1.shrink_to_fit();
	vec2.shrink_to_fit();

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning at tests..." << std::endl;
	std::cout << "vec1.at(3): " << vec1.at(3) << std::endl;
	std::cout << "vec2.at(3): " << vec2.at(3) << std::endl;


	std::cout << std::endl << "Beginning [] tests..." << std::endl;
	std::cout << "vec1[3]: " << vec1[3] << std::endl;
	std::cout << "vec2[3]: " << vec2[3] << std::endl;


	std::cout << std::endl << "Beginning front tests..." << std::endl;
	std::cout << "vec1: " << vec1.front() << std::endl;
	std::cout << "vec2: " << vec2.front() << std::endl;


	std::cout << std::endl << "Beginning back tests..." << std::endl;
	std::cout << "vec1: " << vec1.back() << std::endl;
	std::cout << "vec2: " << vec2.back() << std::endl;


	std::cout << std::endl << "Beginning assign tests..." << std::endl;
	for (int i = 0; i < 5; i++)
		vec1.assign(i, i);

	for (int i = 0; i < 2; i++)
		vec2.assign(i, i);

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning erase(1/2) tests..." << std::endl;
	for (int i = 0; i < 5; i++)
		vec1.erase(i);

	for (int i = 0; i < 2; i++)
		vec2.erase(i);

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning erase(2/2) tests..." << std::endl;
	vec1.erase(2, 4);
	vec2.erase(0, 1);

	std::cout << "vec1 (erased 2-4):" << std::endl;
	std::cout << vec1;

	std::cout << "vec2 (erased 0-1):" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning swap tests..." << std::endl;
	vec1.swap(vec2);

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;


	std::cout << std::endl << "Beginning assignment tests..." << std::endl;
	std::cout << "vec3 (default) created, assigned to vec1." << std::endl;
	Vector<int> vec3;
	vec3 = vec1;


	std::cout << "vec1:" << std::endl;
	std::cout << vec1;

	std::cout << "vec2:" << std::endl;
	std::cout << vec2;

	std::cout << "vec3" << std::endl;
	std::cout << vec3;


	std::cout << std::endl << "Beginning clear tests..." << std::endl;
	vec1.clear();

	std::cout << "vec1:" << std::endl;
	std::cout << vec1;
}

void LinkedListTest()
{
	std::cout << "LINKEDLIST TESTING BEGIN:" << std::endl;
	LinkedList<int> list1;
	list1.resize(5, 0);

	std::cout << "list1 created." << std::endl;
	std::cout << list1 << std::endl;

	LinkedList<int> list2(list1);
	std::cout << "list2 created from copy of list1." << std::endl;
	std::cout << list2 << std::endl;

	LinkedList<int> list3(LinkedList<int>(3, 1));
	std::cout << "list3 created from move of non-default temp list [1, 1, 1] ([X, 1, 1], [1, 1, 1], [1, 1, X])." << std::endl;
	std::cout << list3 << std::endl;
	list3 = LinkedList<int>(3, 1);
	std::cout << "list3 recreated from assignment" << std::endl;
	std::cout << list3 << std::endl;

	std::cout << "list1[1] (Expected: 0)" << std::endl;
	std::cout << list1[1] << std::endl;

	std::cout << "list3[2] (Expected: 1)" << std::endl;
	std::cout << list3[2] << std::endl;

	std::cout << "list2[0] (Expected: 0)" << std::endl;
	std::cout << list2[0] << std::endl;

	std::cout << "list1.front(): " << list1.front() << " (Expected: 0)" << std::endl;
	std::cout << "list3.front(): " << list3.front() << " (Expected: 1)" << std::endl;

	std::cout << "list1.back(): " << list1.back() << " (Expected: 0)" << std::endl;
	std::cout << "list3.back(): " << list3.back() << " (Expected: 1)" << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "LINKEDLIST METHOD TESTS" << std::endl;
	std::cout << "EMPTY()" << std::endl;

	LinkedList<int> list4;
	std::cout << "empty list4 created." << std::endl;
	std::cout << list4 << std::endl;

	std::cout << "list4.empty(): " << (list4.empty() ? "true" : "false") << " (Expected: \"true\")" << std::endl;


	std::cout << "PUSH_FRONT() (Expected: 5, 0, 0, 0, 0, 0)" << std::endl;
	list1.push_front(5);
	std::cout << list1 << std::endl;

	std::cout << "POP_BACK() (Expected: 5, 0, 0, 0, 0)" << std::endl;
	list1.pop_back();
	std::cout << list1 << std::endl;


	std::cout << "INSERT(2, 1) (Expected: 5, 0, 1, 0, 0, 0)" << std::endl;
	list1.insert(2, 1);
	std::cout << list1 << std::endl;


	std::cout << "ERASE(int idx) (Expected: 5, 1, 0, 0, 0)" << std::endl;
	list1.erase(1);
	std::cout << list1 << std::endl;


	std::cout << "ERASE(int start_idx, int end_idx) (Expected: 5, 1, 0)" << std::endl;
	list1.erase(2, 3);
	std::cout << list1 << std::endl;

	std::cout << std::endl;
	std::cout << "list1: " << std::endl << list1;
	std::cout << "list2: " << std::endl << list2;
	std::cout << "SWAP()" << std::endl;
	list1.swap(list2);
	std::cout << "list1: " << std::endl << list1;
	std::cout << "list2: " << std::endl << list2;
	std::cout << std::endl;


	std::cout << "CLEAR()" << std::endl;
	list1.clear();
	std::cout << list1 << std::endl;


	std::cout << "SPLICE(int idx, LinkedList<T>& other) (Expected: 5, 1, 1, 1, 1, 0)" << std::endl;
	list2.splice(1, list3);
	std::cout << list2 << std::endl;

	std::cout << "list3 (Expected: empty)" << list3 << std::endl;


	for (int i = 9; i > 0; i--)
		list4.push_front(i);
	std::cout << "SPLICE(int idx, LinkedList<T>& other, int other_idx) (Expected: 4, 5, 1, 1, 1, 1, 0)" << std::endl;
	list2.splice(0, list4, 3);
	std::cout << list2 << std::endl;

	std::cout << "list4 (Expected: 1, 2, 3, 5, 6, 7, 8, 9): " << list4 << std::endl;


	std::cout << "SPLICE(int idx, LinkedList<T>& other, int start_idx, int end_idx) (Expected: 4, 5, 1, 1, 1, 2, 3, 5, 6, 7, 1, 1, 0)" << std::endl;
	list2.splice(4, list4, 0, 5);
	std::cout << list2 << std::endl;

	std::cout << "list4 (Expected: 8, 9): " << list4 << std::endl;

	std::cout << "REMOVE() (Expected: 4, 5, 2, 3, 5, 6, 7, 0)" << std::endl;
	list2.remove(1);
	std::cout << list2 << std::endl;

	std::cout << "BUBBLE_SORT() (Expected: 0, 2, 3, 4, 5, 5, 6, 7)" << std::endl;
	bubble_sort(list2);
	std::cout << list2 << std::endl;

	std::cout << "MERGE() (Expected: 0, 2, 3, 4, 5, 5, 6, 7, 8, 9)" << std::endl;
	list2.merge(list4);
	std::cout << list2 << std::endl;

	std::cout << "list4 (Expected: empty): " << list4 << std::endl;

	std::cout << "REVERSE() (Expected: 9, 8, 7, 6, 5, 5, 4, 3, 2, 0)" << std::endl;
	list2.reverse();
	std::cout << list2 << std::endl;
}

void bubble_sort(LinkedList<int>& list)
{
	bool isSorted = false;

	LinkedList<int>::Node* currentNode;
	while (!isSorted)
	{
		isSorted = true;
		currentNode = list.head;

		while (currentNode->next)
		{
			if (currentNode->data > currentNode->next->data)
			{
				LinkedList<int>::Node* nextNode = currentNode->next;
				if (currentNode->previous)
					currentNode->previous->next = nextNode;
				else
					list.head = nextNode;
				if (nextNode->next)
					nextNode->next->previous = currentNode;
				else
					list.tail = currentNode;

				nextNode->previous = currentNode->previous;
				currentNode->next = nextNode->next;
				nextNode->next = currentNode;
				currentNode->previous = nextNode;
				isSorted = false;
			}
			else
				currentNode = currentNode->next;

		}
	}
}

void StackTest()
{
	std::cout << "STACK TESTING BEGIN:" << std::endl;

	Stack<int> stack1;
	std::cout << "stack1 created." << std::endl;
	std::cout << stack1 << std::endl;

	Stack<int> stack2;
	std::cout << "stack2 created." << std::endl;
	std::cout << stack2 << std::endl;

	std::cout << "Pushing 1 onto stack 1." << std::endl;
	stack1.push(1);
	std::cout << stack1 << std::endl;

	std::cout << "empty() on stack1: " << (stack1.empty() ? "true" : "false") << std::endl;
	std::cout << "empty() on stack2: " << (stack2.empty() ? "true" : "false") << std::endl;

	std::cout << "Pushing values onto stack 1. Expected container is \" 9 8 7 6 5 4 3 2 1\"" << std::endl;
	for (int i = 2; i < 10; i++)
		stack1.push(i);
	std::cout << stack1 << std::endl;

	std::cout << "top() of stack 1 should be 9: " << stack1.top() << std::endl;

	std::cout << "Pushing a bunch of 5s to stack 2:" << std::endl;
	for (int i = 0; i < 5; i++)
		stack2.push(5);
	std::cout << stack2 << std::endl;

	std::cout << "Swapping stacks: " << std::endl;
	stack1.swap(stack2);
	std::cout << "stack1: " << std::endl;
	std::cout << stack1 << std::endl;
	std::cout << "stack2: " << std::endl;
	std::cout << stack2 << std::endl;

	std::cout << "popping first two numbers of stack2. Expected container is \" 7 6 5 4 3 2 1\"" << std::endl;
	stack2.pop();
	stack2.pop();
	std::cout << stack2 << std::endl;
}