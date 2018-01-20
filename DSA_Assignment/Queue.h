/** @file Queue.h */
#pragma once
#include <iostream>
#include <string>

typedef int ItemType;

/** ADT queue - Pointer-based implementation. */
class Queue
{
private:
	/** A node on the queue. */
	struct Node
	{
		/** A data item on the queue. */
		ItemType item;
		/** Pointer to next node.     */
		Node    *next;
	}; // end Node

	   /** Pointer to front node in the queue. */
	Node *frontNode;
	/** Pointer to back node in the queue. */
	Node *backNode;

public:

	/** Default constructor. */
	Queue();

	/** Destructor. */
	~Queue();

	// Queue operations:
	bool isEmpty();
	bool enqueue(ItemType& item);
	bool dequeue();
	bool dequeue(ItemType& item);
	void getFront(ItemType& item);
	void displayItems();
	int size();
	bool dequeueItem(ItemType& item, ItemType position);
	int getK(int n);

}; // end Queue
   // End of header file.