/* File: LINKED_LIST.hpp
 * Author: Lisa Tatro
 *Class: CS153 1A
 * Description: Definition of a templated single linked list
 *              that uses dynamic memory allocation
 */
#include "NODE.h"
#include "LINKED_LIST.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <class dataType> 
LINKED_LIST<dataType>::LINKED_LIST(const LINKED_LIST<dataType>& otherList)
{
	*this = otherList;
}

template <class dataType>
LINKED_LIST<dataType>::~LINKED_LIST()
{
	clear();
}

template <class dataType>
void LINKED_LIST<dataType>::clear()
{
	if( !isEmpty())
	{
		if( numUsed == 1)
		{
			delete headPtr;
			headPtr = NULL;
			tailPtr = NULL;
			numUsed--;
		}
		else
		{
			NODE<dataType>* temp = headPtr -> getNext();
			delete headPtr;
			headPtr = temp;
			temp = NULL;
			numUsed--;
		}
	}
}

template <class dataType>
void LINKED_LIST<dataType>::insertAtHead(const dataType& newData)
{
	if( isEmpty())
	{
		try
		{
			headPtr = new NODE<dataType>;
		} 
		catch( std::bad_alloc &e)
		{
			throw e;
		}
		headPtr-> setData(newData);
		headPtr-> setNext(NULL);
		tailPtr = headPtr;
	}
	else
	{
		try
		{
			NODE<dataType>* temp= new NODE<dataType>;
			// FIND ME
			temp-> setData(newData);
			temp-> setNext(headPtr);
			headPtr = temp;
			temp = NULL;
		} 
		catch( std::bad_alloc &e)
		{
			throw e;
		}
		// I GO HERE
		
	}
	numUsed++;
}

template <class dataType>
void LINKED_LIST<dataType>::insertAtTail(const dataType& newData)
{
	if( isEmpty())
	{
		try
		{
			tailPtr = new NODE<dataType>;
		} 
		catch( std::bad_alloc &e)
		{
			throw e;
		}
		tailPtr -> setData(newData);
		tailPtr -> setNext(NULL);
		headPtr = tailPtr;
	}
	else
	{
		try
		{
			NODE<dataType>* temp = new NODE<dataType>;
			// FIND ME
			while( temp -> getNext() != NULL)
			temp = temp -> getNext();
		try
		{
			tailPtr = new NODE<dataType>;
		} 
		catch( std::bad_alloc &e)
		{
			throw e;
		}
		tailPtr -> setNext(NULL);
		// MAYBE ISSUE
		tailPtr -> setData(newData);
		temp -> setNext(tailPtr);
		temp = NULL;
		} 
		catch( std::bad_alloc &e)
		{
			throw e;
		}
		// I GO HERE
	}
	numUsed++;
}

template <class dataType>
bool LINKED_LIST<dataType>::removeFirstOccurrence(const dataType& x)
{
	bool found = false;
	// Using only one pointer gives me a special case for if the first NODE is x
	if( headPtr != NULL || headPtr -> getData() == x)
	{
		found = true;
		//special case of a 1 item list
		if( tailPtr == headPtr)
		{
			delete headPtr;
			headPtr = NULL;
			tailPtr = NULL;
		}
		else
		{
			NODE<dataType>* temp = headPtr -> getNext();
			delete headPtr;
			headPtr = temp;
			temp = NULL;
		}
		numUsed--;
	}
	else
	{
		// Finding x in my list
		NODE<dataType>* temp = headPtr;
		while( temp != NULL && !found)
		{	
			if( temp -> getNext() != NULL)
			{
				if( temp -> getNext() -> getData() == x )
					found = true;
				else
					temp = temp -> getNext();
			}
			else
				temp = temp -> getNext();
		}
		// x has been found, there will be two cases x is in the middle or at the end of the list
		if( found)
		{
			// x is at the end
			if( temp -> getNext() == tailPtr)
			{
				delete tailPtr;
				temp -> setNext(NULL);
				tailPtr = temp;
				temp = NULL;
			}
			else
			{
				NODE<dataType>* temp2 = temp -> getNext() -> getNext();
				delete temp -> getNext();
				temp -> setNext(temp2);
				temp = NULL;
			}
			numUsed--;
		}
	}	
	return found;
}

template <class dataType>
int LINKED_LIST<dataType>::removeAllOccurrences(const dataType& x)
{
	int numRemoves = 0;
	while(removeFirstOccurrence(x))
		numRemoves++;
	return numRemoves;
}

template <class dataType>
const LINKED_LIST<dataType>& LINKED_LIST<dataType>::operator = (const LINKED_LIST<dataType> &rhs)
{
	if( rhs.getHeadPtr() == this -> headPtr)
		return *this;
	else
	{
		clear();
		
		NODE<dataType>* temp = rhs.getHeadPtr();
		while( temp != NULL)
		{
			insertAtTail(temp -> getNext() -> getData());
			temp = temp -> getNext();
		}
		temp = NULL;
		return *this;
	}
}

template <class dataType>
bool LINKED_LIST<dataType>::operator == (const LINKED_LIST<dataType> &rhs)
{	
	if ( numUsed != rhs.getNumUsed())
		return false;
	else
	{
		NODE<dataType> *temp1, *temp2;
		temp1 = headPtr;
		temp2 = rhs.getHeadPtr();
		while( temp1 != NULL && temp2 != NULL)
		{
			if( temp1 -> getData() != temp2 -> getData())
				return false;
			else
			{
				temp1 = temp1 -> getNext();
				temp2 = temp2 -> getNext();
			}
		}
		temp1 = NULL;
		temp2 = NULL;
		return true;
	}
}