#ifndef BST_H
#define BST_H

//*****************************************************************************************************

#include "Node.h"
#include "Student.h"
#include <new>
#include <iostream>
using namespace std;

//*****************************************************************************************************

template <typename T>
class BST
{
private:
	Node<T> * root;

	int _getCount(Node<T> * pRoot) const;
	Node<T> * _retrieve(Node<T> * pRoot, const T & dataOut) const;
	Node<T> * _insert(Node<T> * pRoot, const T & dataIn) const;
	Node<T> * _remove(Node<T> * pRoot, const T & dataOut) const;
	void _destruct(Node<T> * pRoot) const;
	int _getHt(Node<T> * pRoot) const;
	bool _isComplete(Node<T> * pRoot) const;
	bool _isBalanced(Node<T> * pRoot) const;
	void _inOrderTraverse(Node<T> * pRoot, void(*display)(T & data)) const;
public:
	BST();
	~BST();
    bool insert(const T & dataIn);
	bool retrieve(T & dataOut) const;
	bool update(const T & dataIn);
	bool remove(T & dataOut);
	int getCount() const;
	int getHt() const;
	bool isEmpty() const;
	bool isFull() const;
	bool isComplete() const;
	bool isBalanced() const;
	void inOrderTraverse(void(*display)(T & data)) const;
};

//*****************************************************************************************************

template <typename T>
BST<T>::BST()
{
	root = nullptr;
}

//*****************************************************************************************************

template <typename T>
BST<T>::~BST()
{
	_destruct(root);
}

//*****************************************************************************************************

template <typename T>
int BST<T>::_getHt(Node<T> * pRoot) const
{
	int height = 0,
		leftHeight = 0,
		rightHeight = 0;

	if (pRoot)
	{
		leftHeight = _getHt(pRoot->left);
		rightHeight = _getHt(pRoot->right);
	}

	if (leftHeight > rightHeight)
		height = 1 + leftHeight;
	else
		height = 1 + rightHeight;

	return height;
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_destruct(Node<T> * pRoot) const
{
	if (pRoot)
	{
		_destruct(pRoot->left);
		_destruct(pRoot->right);
		delete pRoot;
	}
}

//*****************************************************************************************************

template <typename T>
Node<T> * BST<T>::_retrieve(Node<T> * pRoot, const T & dataOut) const
{
	if (pRoot)
	{
		if (pRoot->data > dataOut)
		{
			pRoot = _retrieve(pRoot->left, dataOut);
		}
		else if (pRoot->data < dataOut)
		{
			pRoot = _retrieve(pRoot->right, dataOut);
		}
	}

	return pRoot;
}

//*****************************************************************************************************

template <typename T>
Node<T> * BST<T>::_insert(Node<T> * pRoot, const T & dataIn) const
{
	if (pRoot != nullptr)
	{
		if (pRoot->data > dataIn)
		{
			pRoot->left = _insert(pRoot->left, dataIn);
		}
		else if (pRoot->data < dataIn)
		{
			pRoot->right = _insert(pRoot->right, dataIn);
		}
	}
	else
		pRoot = new Node<T>(dataIn);

	return pRoot;
}

//*****************************************************************************************************

template <typename T>
Node<T> * BST<T>::_remove(Node<T> * pRoot, const T & dataOut) const
{
	Node<T> * pMax;
	Node<T> * pDel;

	if (pRoot)
	{
		if (pRoot->data > dataOut)
		{
			pRoot->left = _remove(pRoot->left, dataOut);
		}
		else if (pRoot->data < dataOut)
		{
			pRoot->right = _remove(pRoot->right, dataOut);

		}
		else
		{
			if ((pRoot->left) && (pRoot->right))
			{
				pMax = pRoot->left;

				while ((pMax) && (pMax->right))
				{
					pMax = pMax->right;
				}

				pRoot->data = pMax->data;

				pRoot->left = _remove(pRoot->left, pMax->data);
			}
			else
			{
				pDel = pRoot;

				if (pRoot->left)
				{
					pRoot = pRoot->left;
				}
				else
					pRoot = pRoot->right;

				delete pDel;

			}
		}
	}
	return pRoot;
}

//*****************************************************************************************************

template <typename T>
int BST<T>::_getCount(Node<T> * pRoot) const
{
	int result = 0;

	if (pRoot)
	{
		result = 1 + _getCount(pRoot->left) + _getCount(pRoot->right);
	}

	return result;
}

//*****************************************************************************************************

template <typename T>
int BST<T>::getCount() const
{
	return (_getCount(root));
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::retrieve(T & dataOut) const
{
	bool success = false;
	Node<T> * pFound;

	pFound = _retrieve(root, dataOut);

	if (pFound)
	{
		dataOut = pFound->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::insert(const T & dataIn)
{
	bool success = false;
	Node<T> * pFound;
	 
	pFound = _retrieve(root, dataIn);

	if (!pFound)
	{
		root = _insert(root, dataIn);
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::update(const T & dataIn)
{
	bool success = false;
	Node<T> * pFound;

	pFound = _retrieve(root, dataIn);

	if (pFound)
	{
		pFound->data = dataIn;
		success = true;
	}


	return success;
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::remove(T & dataOut)
{
	bool success = false;
	Node <T> * pFound;

	pFound = _retrieve(root, dataOut);

	if (pFound)
	{
		dataOut = pFound->data;
		root = _remove(root, dataOut);
		success = true;
	}

	return success;

}

//*****************************************************************************************************

template <typename T>
int BST<T>::getHt() const
{
	return((_getHt(root)) - 1);
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::isEmpty() const
{
	bool empty = false;

	if (root == nullptr)
	{
		empty = true;
	}

	return empty;
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::isFull() const
{
	bool isFull = false;
	T data;
	Node<T> * pFull = new (nothrow) Node<T>(data);

	if (!pFull)
	{
		isFull = true;
	}
	else
		delete pFull;

	return isFull;
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::isBalanced() const
{
	return (_isBalanced(root));
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::_isBalanced(Node<T> * pRoot) const
{
	bool result = true;

	if (pRoot)
	{
		if (abs((_getHt(pRoot->left) - _getHt(pRoot->right))) <= 1)
		{
			result = _isBalanced(pRoot->left) && _isBalanced(pRoot->right);
		}
		else
			result = false;
	}

	return result;
}

//*****************************************************************************************************


template<typename T>
void BST<T>::inOrderTraverse(void(*display)(T & data)) const
{
	_inOrderTraverse(root, display);
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_inOrderTraverse(Node<T> * pRoot, void(*display)(T & data)) const
{
	if (pRoot)
	{
		_inOrderTraverse(pRoot->left, display);
		display(pRoot->data);
		_inOrderTraverse(pRoot->right, display);
	}
}


//*****************************************************************************************************

template <typename T>
bool BST<T>::isComplete() const
{
	return (_isComplete(root));
}

//*****************************************************************************************************

template <typename T>
bool BST<T>::_isComplete(Node<T> * pRoot) const
{
	bool result = true;

	if (pRoot)
	{
		if ((_getHt(pRoot->left) - _getHt(pRoot->right)) == 0 )
		{
			result = _isComplete(pRoot->left) && _isComplete(pRoot->right);
		}
		else
			result = false;
	}

	return result;
}

//*****************************************************************************************************

#endif
