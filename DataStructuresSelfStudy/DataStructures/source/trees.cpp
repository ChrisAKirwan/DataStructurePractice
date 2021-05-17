#include "trees.h"
#include "queue.h"
#include "stack.h"


void TestTrees()
{
	TestBinaryTree();
	TestBinarySearchTree();
}


// BINARY TREE
void TestBinaryTree()
{
	std::cout << "====================================================";
	std::cout << std::endl;
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
	std::cout << "Ending Binary Tree Tests." << std::endl;
	std::cout << "====================================================";
	std::cout << std::endl << std::endl;
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


// BINARY SEARCH TREE
void TestBinarySearchTree()
{
	std::cout << "====================================================";
	std::cout << std::endl;
	std::cout << "Testing Binary Search Trees:" << std::endl;

	int arr1[] = { 9, 15, 5, 20, 16, 8, 12, 3, 6 };
	Tree_BinarySearch tree1(arr1, 9);
	std::cout << "New tree created using: {9, 15, 5, 20, 16, 8, 12, 3, 6}" << std::endl;
	std::cout << "Tree's contents: ";
	tree1.display_inorder();
	std::cout << "Height: " << tree1.height() << std::endl << std::endl;
	tree1.print();

	int arr2[] = { 5, 10, 15, 20, 25, 30, 35, 40, 6, 7, 13, 14, 26, 36, 34 };
	Tree_BinarySearch tree2(arr2, 15);
	std::cout << "New tree created using: {5, 10, 15, 20, 25, 30, 35, 40, 6, 7, 13, 14, 26, 36, 34}" << std::endl;
	std::cout << "Tree's contents: ";
	tree2.display_inorder();
	std::cout << "Height: " << tree2.height() << std::endl << std::endl;
	tree2.print();

	std::cout << "Deleting value: 15" << std::endl;
	tree2.remove(15);
	std::cout << "Tree's contents: ";
	tree2.display_inorder();
	std::cout << "Height: " << tree2.height() << std::endl << std::endl;
	tree2.print();

	std::cout << "Deleting value: 34" << std::endl;
	tree2.remove(34);
	std::cout << "Tree's contents: ";
	tree2.display_inorder();
	std::cout << "Height: " << tree2.height() << std::endl << std::endl;
	tree2.print();

	std::cout << "Deleting value: 5" << std::endl;
	tree2.remove(5);
	std::cout << "Tree's contents: ";
	tree2.display_inorder();
	std::cout << "Height: " << tree2.height() << std::endl << std::endl;
	tree2.print();

	int arr3[] = { 5, 10, 15, 20, 25, 30, 35, 40, 6, 7, 13, 14, 26, 36, 34 };
	Tree_BinarySearch tree3(arr3, 15, true);
	std::cout << "New AVL tree created using: {5, 10, 15, 20, 25, 30, 35, 40, 6, 7, 13, 14, 26, 36, 34}" << std::endl;
	std::cout << "Tree's contents: ";
	tree3.display_inorder();
	std::cout << "Height: " << tree3.height() << std::endl;
	tree3.print();

	std::cout << "Deleting value: 15" << std::endl;
	tree3.removeAVL(15);
	std::cout << "Tree's contents: ";
	tree3.display_inorder();
	std::cout << "Height: " << tree3.height() << std::endl << std::endl;
	tree3.print();

	std::cout << "Deleting value: 34" << std::endl;
	tree3.removeAVL(34);
	std::cout << "Tree's contents: ";
	tree3.display_inorder();
	std::cout << "Height: " << tree3.height() << std::endl << std::endl;
	tree3.print();

	std::cout << "Deleting value: 5" << std::endl;
	tree3.removeAVL(5);
	std::cout << "Tree's contents: ";
	tree3.display_inorder();
	std::cout << "Height: " << tree3.height() << std::endl << std::endl;
	tree3.print();

	std::cout << "Ending Binary Search Tree Tests." << std::endl;
	std::cout << "====================================================";
	std::cout << std::endl << std::endl;
}

Tree_BinarySearch::Tree_BinarySearch(int* Arr, int arrLen, bool isAVL)
{
	root = new Node(Arr[0]);
	for (int i = 1; i < arrLen; i++)
	{
		if (isAVL)
			insertAVL(Arr[i]);
		else
			insert(Arr[i]);
	}
}

void Tree_BinarySearch::delete_tree(Node* p)
{
	if (p)
	{
		delete_tree(p->lchild);
		delete_tree(p->rchild);
		delete p;
	}
}

Tree_BinarySearch::Node* Tree_BinarySearch::search(int key) const
{
	Node* p = root;
	while (p)
	{
		if (p->data == key)
			return p;

		if (p->data > key)
			p = p->lchild;
		else
			p = p->rchild;
	}

	return p;
}

void Tree_BinarySearch::insert(int key)
{
	Node* p = root;
	Node* q = nullptr;

	while (p)
	{
		if (p->data == key)
			return;

		q = p;

		if (p->data > key)
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (q)
	{
		p = new Node(key);
		if (q->data > key)
			q->lchild = p;
		else
			q->rchild = p;
	}
}

void Tree_BinarySearch::display_inorder() const
{
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

int Tree_BinarySearch::height() const
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


// AVL TREE
void Tree_BinarySearch::insertAVL(int key)
{
	Stack<Node*> nodePath;
	Node* p = root;
	nodePath.push(p);

	while (p)
	{
		if (p->data == key)
			return;

		if (p->data > key)
			p = p->lchild;
		else
			p = p->rchild;

		if (p)
			nodePath.push(p);
	}

	if (!nodePath.empty())
	{
		Node* q = nodePath.top();

		p = new Node(key);
		if (q->data > key)
			q->lchild = p;
		else
			q->rchild = p;

		while (!nodePath.empty())
		{
			q = nodePath.top();
			nodePath.pop();

			setNodeHeight(q);

			int factor = balanceFactor(q);

			Node* parent = nullptr;
			if (!nodePath.empty())
				parent = nodePath.top();

			if (factor == 2 || factor == -2)
				perform_rotation(q, factor, parent);
		}
	}
}

void Tree_BinarySearch::remove(int key)
{
	Node* parent = nullptr;
	Node* targetNode = root;

	while (targetNode->data != key)
	{
		parent = targetNode;
		if (targetNode->data > key)
			targetNode = targetNode->lchild;
		else
			targetNode = targetNode->rchild;

		if (!targetNode)
			return;
	}

	if (targetNode->lchild || targetNode->rchild)
	{
		Node* swap = targetNode;
		if (swap->lchild)
		{
			// Find inorder predecessor
			Node* swapParent = parent;
			swap = swap->lchild;
			while (swap->rchild)
			{
				swapParent = swap;
				swap = swap->rchild;
			}

			if (swapParent)
				swapParent->rchild = swap->lchild;
		}
		else
		{
			// Find inorder successor
			Node* swapParent = parent;
			swap = swap->rchild;
			while (swap->lchild)
			{
				swapParent = swap;
				swap = swap->lchild;
			}

			if (swapParent)
				swapParent->lchild = swap->rchild;
		}

		if (parent)
		{
			if (parent->data > key)
				parent->lchild = swap;
			else
				parent->rchild = swap;
		}
		else
			root = swap;

		swap->lchild = targetNode->lchild;
		swap->rchild = targetNode->rchild;

		delete targetNode;
	}
	else
	{
		// targetNode has no children. Simply remove the node.
		if (parent)
		{
			if (parent->data > key)
				parent->lchild = nullptr;
			else
				parent->rchild = nullptr;
		}
		else
			root = nullptr;

		delete targetNode;
	}
}

void Tree_BinarySearch::removeAVL(int key)
{
	Stack<Node*> nodePath;
	Node* targetNode = root;

	while (targetNode->data != key)
	{
		nodePath.push(targetNode);
		if (targetNode->data > key)
			targetNode = targetNode->lchild;
		else
			targetNode = targetNode->rchild;

		if (!targetNode)
			return;
	}

	if (targetNode->lchild || targetNode->rchild)
	{
		Node* swap = targetNode;
		if (swap->lchild)
		{
			// Find inorder predecessor
			Node* swapParent = nodePath.top();
			swap = swap->lchild;
			while (swap->rchild)
			{
				swapParent = swap;
				swap = swap->rchild;
			}

			if (swapParent)
				swapParent->rchild = swap->lchild;
		}
		else
		{
			// Find inorder successor
			Node* swapParent = nodePath.top();
			swap = swap->rchild;
			while (swap->lchild)
			{
				swapParent = swap;
				swap = swap->lchild;
			}

			if (swapParent)
				swapParent->lchild = swap->rchild;
		}

		if (!nodePath.empty())
		{
			if (nodePath.top()->data > key)
				nodePath.top()->lchild = swap;
			else
				nodePath.top()->rchild = swap;
		}
		else
			root = swap;

		swap->lchild = targetNode->lchild;
		swap->rchild = targetNode->rchild;

		delete targetNode;
		nodePath.push(swap);
	}
	else
	{
		// targetNode has no children. Simply remove the node.
		if (!nodePath.empty())
		{
			if (nodePath.top()->data > key)
				nodePath.top()->lchild = nullptr;
			else
				nodePath.top()->rchild = nullptr;
		}
		else
			root = nullptr;

		delete targetNode;
	}

	while (!nodePath.empty())
	{
		Node* q = nodePath.top();
		nodePath.pop();

		setNodeHeight(q);

		int factor = balanceFactor(q);

		Node* parent = nullptr;
		if (!nodePath.empty())
			parent = nodePath.top();

		if (factor == 2 || factor == -2)
			perform_rotation(q, factor, parent);
	}
}

Tree_BinarySearch::Node* Tree_BinarySearch::rotation_LL(Node* p)
{
	// perform the rotation, return the leading node. Let the operation that called the function connect the head node to the parent.
	Node* q = p->lchild;
	p->lchild = q->rchild;
	q->rchild = p;

	setNodeHeight(p);
	setNodeHeight(q);

	return q;
}

Tree_BinarySearch::Node* Tree_BinarySearch::rotation_LR(Node* p)
{
	Node* q = p->lchild;
	Node* r = q->rchild;

	q->rchild = r->lchild;
	p->lchild = r->rchild;
	r->lchild = q;
	r->rchild = p;

	setNodeHeight(p);
	setNodeHeight(q);
	setNodeHeight(r);

	return r;
}

Tree_BinarySearch::Node* Tree_BinarySearch::rotation_RR(Node* p)
{
	Node* q = p->rchild;
	p->rchild = q->lchild;
	q->lchild = p;

	setNodeHeight(p);
	setNodeHeight(q);

	return q;
}

Tree_BinarySearch::Node* Tree_BinarySearch::rotation_RL(Node* p)
{
	Node* q = p->rchild;
	Node* r = q->lchild;

	q->lchild = r->rchild;
	p->rchild = r->lchild;
	r->lchild = p;
	r->rchild = q;

	setNodeHeight(p);
	setNodeHeight(q);
	setNodeHeight(r);

	return r;
}

int Tree_BinarySearch::balanceFactor(Node* p) const
{
	int factor;

	if (p->lchild && p->rchild)
		factor = p->lchild->height - p->rchild->height;
	else if (p->lchild)
		factor = p->lchild->height;
	else if (p->rchild)
		factor = 0 - p->rchild->height;
	else
		factor = 0;

	return factor;
}

void Tree_BinarySearch::setNodeHeight(Node* p)
{
	if (p->lchild && p->rchild)
	{
		if (p->lchild->height >= p->rchild->height)
			p->height = p->lchild->height + 1;
		else
			p->height = p->rchild->height + 1;
	}
	else if (p->lchild)
		p->height = p->lchild->height + 1;
	else if (p->rchild)
		p->height = p->rchild->height + 1;
	else
		p->height = 1;
}

void Tree_BinarySearch::perform_rotation(Node* p, int factor, Node* parent)
{
	if (factor == 2)
	{
		// Left-side imbalance
		Node* r = nullptr;

		if (balanceFactor(p->lchild) == 1)
		{
			// Left-Left imbalance -- LL Rotation
			r = rotation_LL(p);
		}
		else
		{
			// Left-Right imbalance -- LR Rotation
			r = rotation_LR(p);
		}

		if (parent)
		{
			if (parent->data > p->data)
				parent->lchild = r;
			else
				parent->rchild = r;
		}
		else
			root = r;
	}

	if (factor == -2)
	{
		// Right-side imbalance
		Node* r = nullptr;

		if (balanceFactor(p->rchild) == -1)
		{
			// Right-Right imbalance -- RR Rotation
			r = rotation_RR(p);
		}
		else
		{
			// Right-Left imbalance -- RL Rotation
			r = rotation_RL(p);
		}

		if (parent)
		{
			if (parent->data > p->data)
				parent->lchild = r;
			else
				parent->rchild = r;
		}
		else
			root = r;
	}
}

void Tree_BinarySearch::displayNodes() const
{
	Stack<Node*> stack1;
	Node* p = root;
	do
	{
		if (!p)
		{
			p = stack1.top();
			stack1.pop();
			std::cout << "[";
			if(p->lchild)
				std::cout << p->lchild->data << " | " << p->data << " | ";
			else
				std::cout << "- | " << p->data << " | ";

			if (p->rchild)
				std::cout << p->rchild->data << "]" << std::endl;
			else
				std::cout << "-]" << std::endl;

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