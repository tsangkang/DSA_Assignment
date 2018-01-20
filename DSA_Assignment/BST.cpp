
#include "BST.h"
#include <cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;
#include <sstream>
#include <cstddef>  // for NULL
#include <new>      // for bad_alloc
#define Count 10

// constructor
BST::BST()
{
	root = NULL;
}

// search an item in the binary search tree
BinaryNode* BST::search1(ItemType1 target)
{
	return search1(root, target);
}

BinaryNode* BST::search1(BinaryNode* t, ItemType1 target)
{
	if (t == NULL)	// item not found
		return NULL;
	else
	{
		if (t->item == target)	// item found
		{
			if (target == root->item) 
			{
				cout << "Root" << endl;
				return t;
			}
		}
		else
			if (target < t->item)	// search in left subtree
			{
				cout << "L" << endl;
				return search1(t->left, target);
			}
			else // search in right subtree
			{
				cout << "R" << endl;
				return search1(t->right, target);
			}
	}
}

BinaryNode* BST::search2(ItemType1 target)
{
	return search2(root, target);
}

BinaryNode* BST::search2(BinaryNode* t, ItemType1 target)
{
	if (t == NULL)	// item not found
		return NULL;
	else
	{
		if (t->item == target)	// item found
		{
			return t;
		}
		else
			if (target < t->item)	// search in left subtree
			{
				return search2(t->left, target);
			}
			else // search in right subtree
			{
				return search2(t->right, target);
			}
	}
}

// insert an item to the binary search tree
void BST::insert(ItemType1 item)
{
	insert(root, item);
}

void BST::insert(BinaryNode* &t, ItemType1 item)
{
	if (t == NULL)
	{
		BinaryNode *newNode = new BinaryNode;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}
	else
		if (item < t->item)
			insert(t->left, item);  // insert in left subtree
		else
			insert(t->right, item); // insert in right subtree
}

// delete an item from the binary search tree
void BST::remove(ItemType1 target)
{
	remove(root, target);
}

void BST::remove(BinaryNode* &t, ItemType1 target)
{
	// search for the node to be deleted

	BinaryNode* current = t;
	BinaryNode* parent = NULL;
	bool isLeftChild = false;
	bool found = false;
	while ((!found) && (current != NULL))
	{
		if (target == current->item)
		{
			found = true;
		}
		else
		{
			parent = current;
			if (target < current->item)
			{
				current = current->left;	// go to left subtree
				isLeftChild = true;
			}
			else
			{
				current = current->right;	// go to right subtree
				isLeftChild = false;
			}
		}
	}

	if (found)
	{
		// -----------------------  case 1 : node is a leaf ------------------------
		if (current->left == NULL && current->right == NULL)
		{
			if (current == t)	// node to be deleted is a root
				t = NULL;
			else
				if (isLeftChild)
					parent->left = NULL;
				else
					parent->right = NULL;
		}
		else
			// -----------------------  case 2 : node has only 1 child  ----------------
			if (current->left == NULL)
			{
				if (current == t)
					t = current->right;
				else
				if (isLeftChild)
					parent->left = current->right;
				else
					parent->right = current->right;;
			}
			else
				if (current->right == NULL)
				{
					if (current == t)
						t = current->left;
					else
					if (isLeftChild)
						parent->left = current->left;
					else
						parent->right = current->left;;
				}
				else
					// -----------------------  case 3 : node has 2 children  ------------------
				{
					// find the successor ( rightmost child in the node’s left subtree)
					BinaryNode* successor = current->left;
					while (successor->right != NULL)
						successor = successor->right;
					// replace the node’s item with that of the successor
					int n = successor->item;
					// delete the successor (either case 1 or case 2)
					remove(t, n);
					// replace the node’s item with that of the successor
					current->item = n;
				}
	}
}

// traverse the binary search tree in inorder
void BST::inorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		inorder(root);
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->item << endl;
		inorder(t->right);
	}
}
// traverse the binary search tree in preorder
void BST::preorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		preorder(root);
}

void BST::preorder(BinaryNode* t)
{
	if (t != NULL)
	{
		cout << t->item << endl;
		preorder(t->left);
		preorder(t->right);
	}
}

// traverse the binary search tree in postorder
void BST::postorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		postorder(root);
}

void BST::postorder(BinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->item << endl;
	}
}

// compute the height of the binary search tree
int BST::getHeight()
{
	return getHeight(root);
}

int BST::getHeight(BinaryNode* t)
{
	if (t == NULL)
		return 0;
	else {
		int leftHt = getHeight(t->left);
		int rightHt = getHeight(t->right);
		if (leftHt > rightHt)
			return leftHt + 1;
		else
			return rightHt + 1;
	}
	//return 1 + max(getHeight(t->left), getHeight(t->right));
}

// count the number of nodes in the binary search tree
int BST::countNodes()
{
	return countNodes(root);
}

int BST::countNodes(BinaryNode* t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + countNodes(t->left) + countNodes(t->right);
}

// check if the binary search tree is balanced
bool BST::isBalanced()
{
	return isBalanced(root);
}

bool BST::isBalanced(BinaryNode *t)
{
	if (t != NULL)
	{
		if (getHeight(t) < 4)
		{
			int leftHeight = getHeight(t->left);
			int rightHeight = getHeight(t->right);

			if (abs(leftHeight - rightHeight) <= 1)
				return true;
			else
				return false;
		}
		else
			return (isBalanced(t->left) && isBalanced(t->right));
	}
	else
		return true;
}

// check if the binary search tree is empty
bool BST::isEmpty()
{
	return (root == NULL);
}


void BST::printLevel(Queue &q) 
{
	return printLevel(root, q);
}

void BST::printLevel(BinaryNode *t, Queue &q) {
	int h = getHeight(t);
	for (int i = 1; i <= h; i++)
		printGivenLevel(t, i, q);
}

string printTree(BinaryNode *root, int level, string gap) {
	if (level == 1) {
		if (root == 0) {
			return gap + "-" + gap;
		}
		stringstream out;
		out << root->item;
		return gap + out.str() + gap;
	}
	else if (level>1) {
		string leftStr = printTree(root ? root->left : 0 , level - 1, gap);
		string rightStr = printTree(root ? root->right : 0 , level - 1, gap);

		return leftStr + " " + rightStr;
	}
	else return "";
}

void BST::printGivenLevel(BinaryNode* t, int level, Queue &q)
{
	if (t == NULL)
		return;
	if (level == 1)
	{
		q.enqueue(t->item);
	}
	else if (level > 1)
	{
		printGivenLevel(t->left, level - 1, q);
		printGivenLevel(t->right, level - 1, q);
	}
}
void BST::printLevelOrder(int depth) {
	printLevelOrder(root, depth);
}

void BST::printLevelOrder(BinaryNode* root, int depth) {
	for (int i = 1; i <= depth; i++) {
		string gap = "";
		for (int j = 0; j<pow(2, depth - i) - 1; j++) {
			gap += " ";
		}
		string levelNodes = printTree(root, i, gap);
		cout << levelNodes << endl;
	}
}
