#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>
#include "dnode.h"

using namespace std;

int main() {
	dnode * doublyLink = NULL, * doublyLink2 = new dnode(8), * previous = NULL;

	// Test to see if Empty List Displays
	cout << "Test of Empty List" << endl;
	traverse(doublyLink);

	// Test traverse on an intialized new dnode, and display: 8
	cout << "Test of traverse on an intialized new dnode, and display: 8" << endl;
	traverse(doublyLink2);

	// Test head_insert to create a new list and display: 60, 20, 10
	cout << "Test of head_insert to create a new list and display: 60, 20, 10" << endl;
	list_head_insert(doublyLink, 10);
	list_head_insert(doublyLink, 20);
	list_head_insert(doublyLink, 60);
	traverse(doublyLink); 

	const dnode * doublyLink3 = doublyLink;

	// Test list_length on doublyLink (should be 3)
	cout << "list_length on doublyLink (should be 3)" << endl;
	cout << "The length of doublyLink = " << list_length(doublyLink) << endl << endl;

	// Test list_locate function in doublyLink, to find 3rd position in list
	cout << "Test list_locate function in doublyLink, to find 3rd position in list" << endl;
	previous = list_locate(doublyLink, 3);
	// Test insert function on doublyLink to display: 60, 20, 30, 10
	cout << "Test insert function on doublyLink to display: 60, 20, 30, 10" << endl;
	previous = previous->back();
	list_insert(previous,30);
	traverse(doublyLink);

	//Test insert on last node of doublyLink to display: 60, 20, 30, 10, 75 
	cout << "Test insert on last node of doublyLink to display: 60, 20, 30, 10, 75 " << endl;
	previous = list_locate(doublyLink, 4);
	previous = previous;
	list_insert(previous, 75);
	traverse(doublyLink);

	// Test list_locate function in doublyLink3, to find 3rd position in list (30)
	cout << "Test list_locate function in doublyLink3, to find 3rd position in list (30)" << endl;
	const dnode * conLoc;
	conLoc = list_locate(doublyLink3, 3);
	cout << "The third position in the constant list is = " << conLoc->data() << endl << endl;

	// Test list_search function in doublyLink, to find the position of the 30 node in the list
	cout << "Test list_search function in doublyLink, to find the position of the 30 node in the list" << endl;
	previous = list_search(doublyLink, 30);
	// insert function on doublyLink to display: 60, 20, 100, 30, 10, 75
	previous = previous->back();
	list_insert(previous, 100);
	traverse(doublyLink);

	// Test list_search function in doublyLink3, to find the 10 node 
	cout << "Test list_search function in doublyLink3, to find the 10 node" << endl;
	conLoc = list_search(doublyLink3, 10);
	cout << "The 10 node in the constant list is = " << conLoc->data() << endl << endl;

	// Test list_head_remove to display: 20, 100, 30, 10, 75
	cout << "Test list_head_remove to display: 20, 100, 30, 10, 75" << endl;
	list_head_remove(doublyLink);
	traverse(doublyLink);

	// Test list_remove on node 100 
	cout << "Test list_remove on node 100 " << endl;
	previous = doublyLink->fore();
	list_remove(previous);
	traverse(doublyLink);

	// Test list_remove on last node 75
	cout << "Test list_remove on last node 75" << endl;
	previous = list_search(doublyLink, 75);
	list_remove(previous);
	traverse(doublyLink);

	// Test list_copy...When completed cout head_ptr = 20, and tail_ptr = 10
	cout << "Test list_copy...When completed cout head_ptr = 20, and tail_ptr = 10" << endl;
	dnode* head_ptr, *tail_ptr;
	list_copy(doublyLink, head_ptr, tail_ptr);
	cout << "The data in the copied head_ptr = " << head_ptr->data() << endl
		<< "The data in the copied tail_ptr = " << tail_ptr->data() << endl << endl;

	// Test list_clear
	cout << "Test list_clear" << endl;
	list_clear(doublyLink);
	traverse(doublyLink);

	system("pause");
	return 0;
}