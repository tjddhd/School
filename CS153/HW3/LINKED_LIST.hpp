/*
 * LINKED_LIST.hpp
 *
 *  Created on: Sep 25, 2011
 *      Author: Thomas Dolan
 */
#include "NODE.h"
#include "LINKED_LIST.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <class dataType>
LINKED_LIST<dataType>::LINKED_LIST(const LINKED_LIST& otherList)
{
	headPtr = NULL;
	tailPtr = NULL;
	numUsed = 0;
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
	NODE<dataType> *temp = headPtr;
	while(headPtr != NULL)
	{
		if(numUsed == 1)
		{
			delete headPtr;
			headPtr = NULL;
			tailPtr = NULL;
		}
		else
		{
			temp = (headPtr->getNext());
			delete headPtr;
			headPtr = temp;
		}
		numUsed--;
	}
}

template <class dataType>
void LINKED_LIST<dataType>::insertAtHead(const dataType& newData)
{
	if(isEmpty())
	{
		try
		{
			headPtr = new NODE<dataType>;
			headPtr->setData(newData);
			headPtr->setNext(NULL);
			tailPtr = headPtr;
		}
		catch(std::bad_alloc& error)
		{
			throw error;
		}
	}
	else
	{
		try
		{
			NODE<dataType>* temp= headPtr;
			headPtr = new NODE<dataType>;
			headPtr->setData(newData);
			headPtr->setNext(temp);
		}
		catch( std::bad_alloc& error)
		{
			throw error;
		}
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
		catch( std::bad_alloc& error)
		{
			throw error;
		}
		tailPtr->setData(newData);
		tailPtr->setNext(NULL);
		headPtr = tailPtr;
	}
	else
	{
		try
		{
			NODE<dataType>* temp = headPtr;
			while( temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			tailPtr = new NODE<dataType>;
			tailPtr->setNext(NULL);
			tailPtr->setData(newData);
			temp->setNext(tailPtr);
		}
		catch( std::bad_alloc& error)
		{
			throw error;
		}
	}
	numUsed++;
}

template <class dataType>
bool LINKED_LIST<dataType>::removeFirstOccurrence(const dataType& x)
{
	bool found = false;
	if(headPtr != NULL)
	{
		if(headPtr->getData() == x)
		{
			found = true;
			if( tailPtr == headPtr)
			{
				delete headPtr;
				headPtr = NULL;
				tailPtr = NULL;
			}
			else
			{
				NODE<dataType>* temp = headPtr->getNext();
				delete headPtr;
				headPtr = temp;
			}
			numUsed--;
		}
		else
		{
			NODE<dataType>* temp = headPtr;
			while( temp != NULL && !found)
			{
				if( temp->getNext() != NULL)
				{
					if( temp->getNext()->getData() == x )
						found = true;
					else
						temp = temp->getNext();
				}
				else
					temp = temp->getNext();
			}
			if( found)
			{
				if( temp->getNext() == tailPtr)
				{
					delete tailPtr;
					temp->setNext(NULL);
					tailPtr = temp;
				}
				else
				{
					NODE<dataType>* temp2 = temp->getNext()->getNext();
					delete temp->getNext();
					temp->setNext(temp2);
				}
				numUsed--;
			}
		}
	}
	return found;

}

template <class dataType>
int LINKED_LIST<dataType>::removeAllOccurrences(const dataType& x)
{
	int removes = 0;
	while(removeFirstOccurrence(x))
		removes++;
	return removes;
}

template <class dataType>
const LINKED_LIST<dataType>& LINKED_LIST<dataType>::operator = (const LINKED_LIST<dataType> &rhs)
{
	if(headPtr != rhs.getHeadPtr())
	{
		NODE<dataType>* temp = rhs.getHeadPtr();
		clear();
		while(temp != NULL)
		{
			insertAtTail(temp->getData());
			temp = temp->getNext();
		}
	}
	return *this;
}

template <class dataType>
bool LINKED_LIST<dataType>::operator == (const LINKED_LIST &rhs)
{
	if(numUsed != rhs.getNumUsed())
        {
                return false;
        }
        else
	{
		NODE<dataType> *temp1, *temp2;
		temp1 = headPtr;
		temp2 = rhs.getHeadPtr();
		while( temp1 != NULL && temp2 != NULL)
		{
			if( temp1->getData() != temp2->getData())
				return false;
			else
			{
				temp1 = temp1->getNext();
				temp2 = temp2->getNext();
			}
		}
        }
        return true;

}



