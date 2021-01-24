#include "AStack.h"
#include <iostream>

//*******************************************************************************************************

template <typename T>
void display(ArrayStack<T> &);

//*******************************************************************************************************

int main()
{
	ArrayStack<int> obj;

	display<int>(obj);

	return 0;
}

//*******************************************************************************************************

template <typename T>
void display(ArrayStack<T> &obj)
{
	int data = 0;
	ArrayStack<int> temp;

	cout << "Is the stack currently empty?" << " " << obj.isEmpty() << endl;
	cout << "Pushing 1, 2, 3, 4, and 5..." << endl;

	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);

	cout << "The size of the stack currently is: " << obj.getSize() << endl;
	cout << "Displaying values in stack: ";

	while (obj.pop(data) == true)
	{
		cout << data << " ";
		temp.push(data);
	}
	
	while (temp.pop(data) == true)
	{
		obj.push(data);
	}

	cout << endl;
	cout << "Display values in stack again: ";

	while (obj.pop(data) == true)
	{
		cout << data << " ";
		temp.push(data);
	}

	while (temp.pop(data) == true)
	{
		obj.push(data);
	}

	cout << endl;
	cout << "Is the stack full? " << obj.isFull() << endl;

	cout << "Popping the first 3 values out..." << endl;
	obj.pop(data);
	
	cout << "The first value popped is: " << data << endl;
	obj.pop(data); 

	cout << "The second value popped is: " << data << endl;
	obj.pop(data);

	cout << "The third value popped is: " << data << endl;

	cout << "The array now is: ";
	
	while (obj.pop(data) == true)
	{
		cout << data << " ";
		temp.push(data);
	}

	while (temp.pop(data) == true)
	{
		obj.push(data);
	}
	
	cout << endl;
	cout << "Is the array empty? " << obj.isEmpty() << endl;
}

//*******************************************************************************************************

/*
Is the stack currently empty? 1
Pushing 1, 2, 3, 4, and 5...
The size of the stack currently is: 5
Displaying values in stack: 5 4 3 2 1
Display values in stack again: 5 4 3 2 1
Is the stack full? 1
Popping the first 3 values out...
The first value popped is: 5
The second value popped is: 4
The third value popped is: 3
The array now is: 2 1
Is the array empty? 0
Press any key to continue . . .
*/
