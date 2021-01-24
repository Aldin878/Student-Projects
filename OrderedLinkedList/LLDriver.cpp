#include "LinkedList.h"
template <typename T>
void display(LinkedList<T> &);

//*******************************************************************************************************

int main()
{
	LinkedList<int> ll;

	display<int>(ll);

	return 0;

}

template <typename T>
void display(LinkedList<T> &ll)
{
	int intRetrieve = 0;
	bool boolRetrieve = 0;

	ll.insert(5);

	ll.insert(4);
	
	ll.insert(0);
	
	ll.insert(1);
	
	ll.insert(2);
	
	ll.insert(3);
	
	ll.display();
	
	ll.insert(8);
	
	cout << "After inserting 8: " << endl;
	ll.display();
	
	ll.remove(3);

	cout << "After removing 3: " << endl;
	ll.display();
	
	ll.viewFront(intRetrieve);
	
	cout << "The front value is: " << intRetrieve << endl;
	ll.viewBack(intRetrieve);
	
	cout << "The back value is: " << intRetrieve << endl;
	boolRetrieve = ll.isEmpty();

	cout << "Is the list empty? " << boolRetrieve << endl;
	boolRetrieve = ll.isFull();

	cout << "Is the list full? " << boolRetrieve << endl;
	ll.getSize(intRetrieve);

	cout << "The number of nodes are: " << intRetrieve << endl;
	cout << "Attempting to retrieve 10..." << endl;

	boolRetrieve = ll.retrieve(10);

	cout << "10 found? " << boolRetrieve << endl;
	cout << "Attempting to retrieve 0..." << endl;
	boolRetrieve = ll.retrieve(0);
	
	cout << "0 found? " << boolRetrieve << endl;
	cout << "Clearing list..." << endl;
	ll.clearList();
	
	boolRetrieve = ll.isEmpty();
	cout << "Is the list empty? " << boolRetrieve << endl;
}

//*******************************************************************************************************

/*
0 1 2 3 4 5
After inserting 8:
0 1 2 3 4 5 8
After removing 3:
0 1 2 4 5 8
The front value is: 0
The back value is: 8
Is the list empty? 0
Is the list full? 0
The number of nodes are: 6
Attempting to retrieve 10...
10 found? 0
Attempting to retrieve 0...
0 found? 1
Clearing list...
Is the list empty? 1
Press any key to continue . . .


*/
