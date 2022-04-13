/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 4 - Syntax Checker: File 3 of 5
*@version 1.0
*Generic Stack Template Class
*/

#if !defined(GENSTACK_H)
#define GENSTACK_H
#include <iostream>
#include "DoublyLinkedList.h"
#include <exception>

using namespace std;
/*

*/
template <class T>
class GenStack
{
    public:
        GenStack();
        ~GenStack();
        void push(T data);
        T pop();
        T peek();
        bool isEmpty();
        int getSize();

    private:
        DoublyLinkedList<T> *myList;

};

template <class T>
GenStack<T>::GenStack()
{
    myList = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack()
{
    delete myList;
}

template <class T>
void GenStack<T>::push(T data)
{
    myList->insertFront(data);
}

template <class T>
T GenStack<T>::pop()
{
    // check is stack is empty
    if(isEmpty())
    {
        throw runtime_error("Stack is empty, nothing to pop");
    }
    return myList->removeFront();
}

template <class T>
T GenStack<T>::peek()
{
    if(isEmpty())
    {
        throw runtime_error("Stack is empty, nothing to peek");
    }
    return myList->getAtPos(0);
}

template <class T>
bool GenStack<T>::isEmpty()
{
    return myList->isEmpty();
}

template <class T>
int GenStack<T>::getSize()
{
    return myList->getSize();
}

#endif
