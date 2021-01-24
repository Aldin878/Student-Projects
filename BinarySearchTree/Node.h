#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
	T data;

	union {
		Node<T> * next;
		Node<T> * left;
	};

	union {
		Node<T> * prev;
		Node<T> * right;
	};

	Node();
	Node(T, Node<T>* n = nullptr, Node<T> * p = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(T dataIn, Node<T> * n, Node<T> * p)
{
	data = dataIn;
	left = n;
	right = p;
}

//*****************************************************************************************************

#endif
