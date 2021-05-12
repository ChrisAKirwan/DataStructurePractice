#include "trees.h"
#include "queue.h"
#include "stack.h"


void TestTrees()
{
	TestBinaryTree();
}


void TestBinaryTree()
{
	std::cout << "Testing Binary Trees:" << std::endl;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	Tree_Binary tree(arr, 15);
	std::cout << " Preorder: ";
	tree.display_preorder();

	std::cout << "  Inorder: ";
	tree.display_inorder();

	std::cout << "Postorder: ";
	tree.display_postorder();

	std::cout << "   Height: " << tree.height() << std::endl;
}

Tree_Binary::Tree_Binary(int* Arr, int arrLen)
{
	Queue<Node*> children;
	root = new Node(Arr[0]);
	Node* p;
	Node* q = root;

	for (int i = 1; i < arrLen; i++)
	{
		if (Arr[i] != -1)
		{
			p = new Node(Arr[i]);
			children.push(p);

			if (i % 2)
				q->lchild = p;
			else
			{
				q->rchild = p;
				q = children.front();
				children.pop();
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				q = children.front();
				children.pop();
			}
		}
	}
}

void Tree_Binary::display_preorder() const
{
	/*
	* No recursion.
	* Recursive solution would be:
	* 
	* void Tree_Binary::display_preorder(Node* p) const
	* {
	*	if(p)
	*	{
	*		std::cout << p->data << " ";
	*		display_preorder(p->lchild);
	*		display_preorder(p->rchild);
	*	}
	* }
	*/

	Stack<Node*> stack1;
	Node* p = root;
	stack1.push(p);

	while (!stack1.empty())
	{
		p = stack1.top();
		stack1.pop();
		std::cout << p->data << " ";

		if(p->rchild)
			stack1.push(p->rchild);
		if(p->lchild)
			stack1.push(p->lchild);
	}

	std::cout << std::endl;
}

void Tree_Binary::display_inorder() const
{
	/*
	* No recursion.
	* Recursive solution would be:
	*
	* void Tree_Binary::display_inorder(Node* p) const
	* {
	*	if(p)
	*	{
	*		display_inorder(p->lchild);
	*		std::cout << p->data << " ";
	*		display_inorder(p->rchild);
	*	}
	* }
	*/

	Stack<Node*> stack1;
	Node* p = root;
	do
	{
		if (!p)
		{
			p = stack1.top();
			stack1.pop();
			std::cout << p->data << " ";
			p = p->rchild;
		}

		while (p)
		{
			stack1.push(p);
			p = p->lchild;
		}

	} while (!stack1.empty());
	

	std::cout << std::endl;
}

void Tree_Binary::display_postorder() const
{
	/*
	* No recursion.
	* Recursive solution would be:
	*
	* void Tree_Binary::display_postorder(Node* p) const
	* {
	*	if(p)
	*	{
	*		display_postorder(p->lchild);
	*		display_postorder(p->rchild);
	*		std::cout << p->data << " ";
	*	}
	* }
	*/
	
	Stack<Node*> stack1;
	Stack<Node*> stack2;
	Node* p = root;
	stack1.push(p);

	while (!stack1.empty())
	{
		p = stack1.top();
		stack1.pop();
		stack2.push(p);

		if (p->lchild)
			stack1.push(p->lchild);
		if (p->rchild)
			stack1.push(p->rchild);
	}

	while (!stack2.empty())
	{
		p = stack2.top();
		stack2.pop();

		std::cout << p->data << " ";
	}
	std::cout << std::endl;
}

void Tree_Binary::display_levelorder() const
{
	Queue<Node*> children;
	children.push(root);
	std::cout << root->data << " ";
	Node* p;

	while (!children.empty())
	{
		p = children.front();
		children.pop();
		
		if (p->lchild)
		{
			std::cout << p->lchild->data << " ";
			children.push(p->lchild);
		}
		if (p->rchild)
		{
			std::cout << p->rchild->data << " ";
			children.push(p->rchild);
		}
	}
}

int Tree_Binary::height() const
{
	Queue<Node*> children;
	children.push(root);
	Node* p;
	int totalHeight = 0;
	int numNodes = 0;

	while (!children.empty())
	{
		if (numNodes == 0)
		{
			numNodes = children.size();

			if (numNodes == 0)
				return totalHeight;
			else
				totalHeight++;
		}


		p = children.front();
		children.pop();
		numNodes--;

		if (p->lchild)
			children.push(p->lchild);
		if (p->rchild)
			children.push(p->rchild);
	}

	return totalHeight;
}

void Tree_Binary::delete_tree(Node* p)
{
	if (p)
	{
		delete_tree(p->lchild);
		delete_tree(p->rchild);
		delete p;
	}
}