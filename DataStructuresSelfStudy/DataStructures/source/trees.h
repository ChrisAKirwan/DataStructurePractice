#pragma once
#include <iostream>

void TestTrees();
void TestBinaryTree();
void TestBinarySearchTree();

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


class Tree_BinarySearch
{
public:
	struct Node
	{
		Node() : lchild(nullptr), data(0), height(1), rchild(nullptr) {}
		Node(int val) : lchild(nullptr), data(val), height(1), rchild(nullptr) {}

		Node* lchild;
		int data;
		int height;
		Node* rchild;
	};

	Tree_BinarySearch() : root(new Node(0)) {}
	Tree_BinarySearch(int* Arr, int numNodes, bool isAVL = false);
	~Tree_BinarySearch() { delete_tree(root); }

	// Properties
	Node* root;

	// Methods
	Node* search(int key) const;
	void insert(int key);
	void insertAVL(int key);
	void display_inorder() const;
	int height() const;
	void remove(int key);
	void removeAVL(int key);
	void displayNodes() const;

	// The two below print() functions are borrowed from stackoverflow user Adrian Schneider
	// https://stackoverflow.com/a/51730733
	// I am simply using them to aid in debugging code using a visual tree representation.
	void print(const std::string& prefix, const Node* node, bool isLeft)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "|--" : "L--");

			// print the value of the node
			std::cout << node->data << std::endl;

			// enter the next tree level - left and right branch
			print(prefix + (isLeft ? "|   " : "    "), node->lchild, true);
			print(prefix + (isLeft ? "|   " : "    "), node->rchild, false);
		}
	}

	void print()
	{
		print("", root, false);
	}

private:
	void delete_tree(Node* p);
	void perform_rotation(Node* p, int factor, Node* parent = nullptr);
	Node* rotation_LL(Node* p);
	Node* rotation_LR(Node* p);
	Node* rotation_RR(Node* p);
	Node* rotation_RL(Node* p);
	int balanceFactor(Node* p) const;
	void setNodeHeight(Node* p);
};