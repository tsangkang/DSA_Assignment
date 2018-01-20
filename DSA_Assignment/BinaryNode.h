#pragma once

#include <iostream>
// BinaryNode.h

typedef int ItemType1;

struct BinaryNode
{
	ItemType1   item;	// data item
	BinaryNode *left;	// pointer pointing to left subtree
	BinaryNode *right;	// pointer pointing to right subtree
};

