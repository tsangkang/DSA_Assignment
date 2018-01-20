// BST.h
#pragma once
#include "BinaryNode.h"
#include "Queue.h"
#include <string>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

class BST
{
private:

	BinaryNode* root;		// root of the BST

public:

	// constructor
	BST();

	// search an item in the binary search tree
	BinaryNode* search1(ItemType1 target);
	BinaryNode* search1(BinaryNode* root, ItemType1 target);

	BinaryNode* search2(ItemType1 target);
	BinaryNode* search2(BinaryNode* root, ItemType1 target);

	// insert an item to the binary search tree
	void insert(ItemType1 item);
	void insert(BinaryNode* &root, ItemType1 item);

	// delete an item from the binary search tree
	void remove(ItemType1 target);
	void remove(BinaryNode* &root, ItemType1 target);

	// traverse the binary search tree in inorder
	void inorder();
	void inorder(BinaryNode* t);

	// traverse the binary search tree in preorder
	void preorder();
	void preorder(BinaryNode* t);

	// traverse the binary search tree in postorder
	void postorder();
	void postorder(BinaryNode* t);

	// compute the height of the binary search tree
	int getHeight();
	int getHeight(BinaryNode* t);

	// count the number of nodes in the binary search tree
	int countNodes();
	int countNodes(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty();

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode* t);

	void printLevel(Queue &q);
	void printLevel(BinaryNode* t, Queue &q);
	void BST::printGivenLevel(BinaryNode* t, int level, Queue &q);
	void BST::printLevelOrder(int depth);
	void BST::printLevelOrder(BinaryNode* t, int depth);
};
