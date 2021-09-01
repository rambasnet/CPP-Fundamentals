
/*
	Code implements a linked list whereby strings are the data stored in
	each node.
*/

/*
	Source file for implementation of the linkedlist. Refer to header definition for prototypes
*/

#include "linkedlist.h"
#include <string>
#include <iostream>
using namespace std;

linkedlist::linkedlist()								// default constructor
{
	head = NULL;
}
    
linkedlist::~linkedlist()								// destructor for linked list
{
	nodeptr current;
	current = head;
	while (head != NULL)
	{
		head = current->next;
		delete current;
		current = head;
	}
	head = NULL;
}

void linkedlist::addtotail(const string& newdata)		// add to end of the list
{
	nodeptr tmp, curr;

	tmp = new node;
	tmp->data = newdata;
	tmp->next = NULL;

	if (head != NULL)
	{
		curr = head;
		while (curr->next)
			curr = curr->next;
		curr->next = tmp;
	}
	else
		head = tmp;
}

bool linkedlist::isempty()								// is the list empty
{
	if (head == NULL)
		return true;
	else
		return false;
}

string linkedlist::removefromhead()						// remove node from head of list
{
	// YOU ARE TO IMPLEMENT THIS
}

void linkedlist::insert(const string& newdata)			// insertion method
{
	nodeptr tmp;
	tmp = new node;
	tmp->data = newdata;
	tmp->next = NULL;

	nodeptr curr;
	nodeptr prev;
	curr = head;
	prev = NULL;

	while (curr && listdatacmp(newdata, curr->data) >= 0)	// while not the place to insert
	{
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL)										// perform insertion
		head = tmp;
	else
		prev->next = tmp;
	tmp->next = curr;


}

int listdatacmp(const string& data1, const string& data2)		// list data compare function - provide by user
{
	// SUITABLE ADDITION HERE

	return 1;
}	
	
	
