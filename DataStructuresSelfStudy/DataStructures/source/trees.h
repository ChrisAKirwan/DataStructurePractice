#pragma once
#include <iostream>

void TestTrees();
void TestBinaryTree();

class Tree_Binary
{
public:
	struct Node
	{
		Node() : lchild(nullptr), data(0), rchild(nullptr) {}
		Node(int val) : lchild(nullptr), data(val), rchild(nullptr) {}

		Node* lchild;
		int data;
		Node* rchild;
	};

	Tree_Binary() : root(new Node(0)) {}
	Tree_Binary(int* Arr, int numNodes);
	~Tree_Binary() { delete_tree(root); }

	// Properties
	Node* root;

	// Methods
	void display_preorder() const;
	void display_inorder() const;
	void display_postorder() const;
	void display_levelorder() const;
	int height() const;

private:
	void delete_tree(Node* p);
};