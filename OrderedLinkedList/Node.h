#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

//*******************************************************************************************************

template <typename t>
struct node
{
	t data;
	node<t> * next;
	node();
	node(t, node<t> * n = nullptr);
};

//*******************************************************************************************************

template <typename t>
node<t>::node()
{
	data = 0;
	next = nullptr;
}

//*******************************************************************************************************

template <typename t>
node<t>::node(t dataIn, node<t> * n)
{
	data = dataIn;
	next = n;
}

//*******************************************************************************************************

#endif
