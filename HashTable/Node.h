#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node();
	Node(T, Node<T>* n = nullptr, Node<T>* p = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(T dataIn, Node<T>* n, Node<T>* p)
{
	data = dataIn;
	next = n;
	prev = p;
}

//*****************************************************************************************************

#endif
