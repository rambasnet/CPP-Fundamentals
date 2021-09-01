
/*
	Code implements a linked list whereby strings are the data stored in
	each node.
*/

#ifndef LIST
#define LIST

#include <string>
using namespace std;

int listdatacmp(const string&, const string&);			// user defined compare function

class linkedlist
{
	public:						// public methods
		linkedlist();
		~linkedlist();
		void addtotail(const string&);		
		bool isempty();
		string removefromhead();
		void insert(const string&);
	private:					// node data and declaration - hidden in class
		struct node;
		typedef node* nodeptr;

		struct node
		{
			string data;
			nodeptr next;
		};
		nodeptr head;
};	
	
#endif
