/*•	You will implement and test an ORDERED linked list class that uses nodes to store items. 

•	Add a second header file to the project named LinkedList.h. 
Place the standard #ifndef statement (and the associated #define and #endif) in the file.   
Add the required standard department/course heading at the top of the file.   

•	This file will contain the definition of the templated class “LinkedList”.   

•	This LinkedList class will have just one private data member that is a pointer to the first node in the list. 
You may not add any other member variables

•	The Node class should have two member variables ( a data and a pointer  as discussed in class). 
You may not add any other member variables
*/

//*******************************************************************************************************
//
//      File:               LinkedList.h
//
//      Student:            Aldin Topalbegovic
//
//      Assignment:         Program  3
//
//      Course Name:        Data Structures I 
//
//      Course Number:      COSC 3050 - 02
//
//      Due:                Sept 19, 2018
//
//
//      This is a linked list header file. It uses node.h to create and link nodes.
//
//      Other files included: Node.h, LLDriver.cpp
//                            	
//
//*******************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <new>

//*******************************************************************************************************

template <typename t> 
class LinkedList
{
private:
	node<t> * front;
public:
	LinkedList();
	~LinkedList();
	bool insert(const t &);
	void display() const;
	bool remove(const t &);
	bool retrieve(const t &) const;
	bool viewFront(t &) const;
	bool isEmpty() const;
	bool isFull() const;
	bool clearList();
	bool viewBack(t &) const;
	bool getSize(t &) const;
};

//*******************************************************************************************************

template <typename t> 
LinkedList<t>::LinkedList()
{
	front = nullptr;
}

//*******************************************************************************************************

template <typename t>
LinkedList<t>::~LinkedList()
{
	node <t> * pTemp = front;

	while (pTemp != nullptr)
	{
		front = front->next;
		delete pTemp;
		pTemp = front;
	}
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::insert(const t &dataIn)
{
	bool success = false;

	node<t> * pPrev = nullptr;
	node<t> * pAfter = front;

	while (pAfter != nullptr && pAfter->data < dataIn)
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	node<t> *pnewNode = new (nothrow) node<t>(dataIn);
	pnewNode->next = pAfter;
	
	if (pnewNode != nullptr)
	{
		if (pPrev != nullptr)
		{
			pPrev->next = pnewNode;
		}
		else
			front = pnewNode;
		
		success = true;
	}

	return success; 
}

//*******************************************************************************************************

template <typename t>
void LinkedList<t>::display() const
{
	node<t> * pTemp = front;

	while (pTemp != nullptr)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->next;
	}

	cout << endl;
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::remove(const t &dataIn)
{
	bool success = false;

	node<t> * pTemp = front;
	node<t> * pPrev = nullptr;

	while (pTemp != nullptr && pTemp->data < dataIn)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataIn)
	{
		if (pPrev != nullptr)
		{
			pPrev->next = pTemp->next;
		}
		else
			front = pTemp->next;
		
		delete pTemp;
		success = true;
	}

	return success;
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::retrieve(const t &dataIn) const
{
	bool success = false;

	node<t> * pTemp = front;

	while (pTemp != nullptr && pTemp->data != dataIn)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataIn)
	{
		success = true;
	}


	return success;
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::viewFront(t &dataOut) const
{
	bool success = false;

	if (front != nullptr)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::isEmpty() const
{
	bool success = false;

	if (front == nullptr)
	{
		success = true;
	}

	return success;
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::isFull() const
{
	bool success = false;

	node<t> *pFull = new (nothrow) node<t>(0);

	if (pFull == nullptr)
	{
		success = true;
	}

	delete[] pFull;

	return success;
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::clearList()
{
	bool success = false;

	node<t> * pEmpty = front;

	if (front != nullptr)
	{
		success = true;

		while (pEmpty != nullptr)
		{
			front = front->next;
			delete pEmpty;
			pEmpty = front;
		}
	}

	return success; 
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::viewBack(t &dataOut) const
{
	bool success = false;

	node <t> * pBack = front;
	
	if (pBack != nullptr)
	{
		success = true;

		while (pBack->next != nullptr)
		{
			pBack = pBack->next;
		}
		
		dataOut = pBack->data;
	}


	return success; 
}

//*******************************************************************************************************

template <typename t>
bool LinkedList<t>::getSize(t &dataOut) const
{
	bool success = false;
	int counter = 0;

	node <t> * pCount = front;

	if (pCount != nullptr)
	{
		success = true;

		while (pCount != nullptr)
		{
			pCount = pCount->next;
			counter++;
		}
	}

	dataOut = counter;
	
	return success; 
}

//*******************************************************************************************************

#endif
