// DSA_Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include "BST.h"
#include <vector>

#include <ctime>
#include "Queue.h"
#include <exception> //(catches exceptions)
#include <stdexcept>
using namespace std;
void displayMenu();
class myexception : public exception
{
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
} myex;

int main()
{
	// instantiate local variables
	BST bst;
	string S;
	int i = 1;
	ItemType item;
	Queue queue;
	int option = 1;
	int trycatch = 1;
	BST* mytree = new BST();

	// ask for user input

	while (trycatch != 0)
	{
		try {
			cout << "Insert a number: ";
			cin >> S;
			int s = stoi(S);
			if (s > 0)
			{

				//vector
				std::srand(unsigned(std::time(0)));
				std::vector<int> queuevector;

				// set some values:
				for (i = 1; i < s; ++i) {
					s = s - i;
					queuevector.push_back(i);
				}
				queuevector.push_back(i);

				// using built-in random generator:
				std::random_shuffle(queuevector.begin(), queuevector.end());
				for (int i = 0; i < queuevector.size(); i++) {
					bst.insert(queuevector[i]); //INSERT RANDOMISED
					queue.enqueue(item = queuevector[i]);
					mytree->insert(queuevector[i]);
				}

				//testing purposes
				// print out content:
				std::cout << "queuevector contains:";
				for (std::vector<int>::iterator it = queuevector.begin(); it != queuevector.end(); ++it)
					std::cout << ' ' << *it;

				std::cout << '\n';

				//testing purposes
				//queue.displayItems(); // the numbers of the tree nodes
				bst.inorder();
				while (true)
				{
					try
					{
						displayMenu();
						cin >> option;
					}
					catch (std::exception& e)
					{
						std::cerr << "exception caught: " << e.what() << '/n' << endl;
					}
					catch (const char * str)
					{
						std::cout << "Exception: " << str << std::endl;
					}
					if (option == 1)
					{
						cout << "Enter a number to search : ";
						cin >> item;
						BinaryNode* p = bst.search1(item);
						if (p != NULL)
							cout << "Found" << endl;
						else
							cout << "Not found" << endl;
					}
					else if (option == 2)
					{
						int n;
						cout << "Enter a number to add : ";
						cin >> n;
						BinaryNode* p = bst.search2(n);
						if (p != NULL)
						{
							cout << "This number is already in the tree.";
						}
						else
						{
							bst.insert(n);
							cout << "The number has been inserted" << endl;
						}
					}
					else if (option == 3)
					{
						int k;
						cout << "Enter a number to delete : ";
						cin >> k;
						BinaryNode* p = bst.search2(k);
						if (p != NULL)
						{
							bst.remove(k);
							cout << "The number is deleted" << endl;
							bst.inorder();
						}
						else
							cout << "This number is not in the tree.";
					}
					else if (option == 4)
					{
						bst.inorder();
					}
					else if (option == 5)
					{
						int nodeNumber;
						Queue nodeQueue;
						cout << "Please enter the Kth node of the tree: ";
						cin >> nodeNumber;
						if (nodeNumber <= queue.size() && nodeNumber > 0)
						{
							bst.printLevel(nodeQueue);
							cout << "The value of the " << nodeNumber << "th node is = " << nodeQueue.getK(nodeNumber) << endl;
						}
						else
							cout << "Please enter a number from 1 to " << queue.size() << endl;

					}
					else if (option == 6)
					{
						int number;
						cout << "Enter the depth of the tree you want to print (1-6): ";
						cin >> number;
						if (number <= 6 && number >= 1)
							bst.printLevelOrder(number);
					}
					else if (option == 0) {
						cout << "Thanks for using our program!" << endl;
						break;
					}
					else
						cout << "Invalid option." << endl;
				}
			}
			else
			{
				cout << "Don't enter a negative number!" << endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << '/n' << endl;
		}
		catch (const char * str)
		{
			std::cout << "Exception: " << str << std::endl;
		}
		continue;
	}
	return 0;
}

void displayMenu()
{
	cout << endl;
	cout << "Binary Search Tree \n";
	cout << "--------------------------------\n";;
	cout << "1 Search for a node \n";
	cout << "2 Add a new item \n";
	cout << "3 Delete an item \n";
	cout << "4 Display values in ascending order \n";
	cout << "5 Display value of the nodes in level-by-level traversal \n";
	cout << "6 Display the Binary Search Tree \n";
	cout << "0 Exit \n";
	cout << "--------------------------------\n";
	cout << "Enter option : ";
}


