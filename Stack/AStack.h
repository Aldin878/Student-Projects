#ifndef ASTACK_H
#define ASTACK_H
#include <new>
using namespace std;

//*******************************************************************************************************

template <typename T> class ArrayStack
{
private:
	T * stack;
	int top;
	int capacity;
public:
	ArrayStack(int c = 5);
	~ArrayStack();
	bool push(const T &);
	bool pop(T &);
	bool peek(T &) const;
	int getSize() const;
	bool isFull() const;
	bool isEmpty() const;
};

//*******************************************************************************************************

template <typename T>
ArrayStack<T>::ArrayStack(int c)
{
	capacity = c;
	top = -1;
	stack = new (nothrow) T[capacity];
}

//*******************************************************************************************************

template <typename T>
ArrayStack<T>::~ArrayStack()
{
	capacity = 0;
	top = -1;
	delete[] stack;
}

//*******************************************************************************************************

template <typename T>
bool ArrayStack<T>::push(const T &dataIn)
{
	bool success = false;

	if (stack != nullptr && top + 1 < capacity)
	{
		top++;
		stack[top] = dataIn;
		success = true;
	}

	return success;
}

//*******************************************************************************************************

template <typename T>
bool ArrayStack<T>::pop(T &dataOut)
{
	bool success = false;

	if (stack != nullptr && top > -1)
	{
		dataOut = stack[top];
		top--;
		success = true;
	}

	return success;
}

//*******************************************************************************************************

template <typename T>
bool ArrayStack<T>::peek(T &dataOut) const
{
	bool success = false;

	if (stack != nullptr && top > -1)
	{
		dataOut = stack[top];
		success = true;
	}

	return success;
}

//*******************************************************************************************************

template <typename T>
int ArrayStack<T>::getSize() const
{
	return top + 1;
}

//*******************************************************************************************************

template <typename T>
bool ArrayStack<T>::isFull() const
{
	bool success = false;

	if (stack == nullptr || top + 1 == capacity)
	{
		success = true;
	}

	return success; 
}

//*******************************************************************************************************

template <typename T>
bool ArrayStack<T>::isEmpty() const
{
	bool success = false;

	if (top == -1)
	{
		success = true;
	}

	return success;
}

//*******************************************************************************************************

#endif
