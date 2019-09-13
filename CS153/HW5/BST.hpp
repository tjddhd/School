/*
 * BST.hpp
 *
 *  Created on: Oct 26, 2011
 *      Author Thomas Dolan
 */

#ifndef BST_HPP_
#define BST_HPP_

#include "BST.h"
#include <string>


template<class T>
bool BST<T>::operator==(const BST<T>& rhs) const
{
	if(m_size != rhs.m_size)
		return false;
	else
	{
		BNODE<T>* temp1 = rootPtr;
		BNODE<T>* temp2 = rhs.rootPtr;
		BNODE<T>* temp3, temp4;
		bool isLeftEqual = false, isRightEqual = false, isThere;

		if(temp1->m_left!=NULL && temp2->m_left!=NULL)
		{
			temp3 = rootPtr->m_left;
			temp4 = rhs.rootPtr->m_left;
			BNODE<T>* temp5 = NULL, temp6 = NULL;
			while(!isLeftEqual)
			{
				if(temp3->m_left != NULL)
				{
					temp5
				}
			}
		}
		else if(temp1->m_left == NULL && temp2->m_left == NULL)
		{
			isLeftEqual = true;
		}
		else
		{
			return false;
		}

		if(temp1->m_right!=NULL && temp2->m_right!=NULL)
		{
			temp3 = rootPtr->m_left;
			temp4 = rhs.rootPtr->m_left;
			while(!isRightEqual)
			{

			}
		}
		else if(temp1->m_right == NULL && temp2->m_right == NULL)
		{
			isRightEqual = true;
		}
		else
		{
			return false;
		}

		return (isLeftEqual && isRightEqual);
	}
}

template<class T>
bool BST<T>::findStartingAtNode(const T& x, BNODE<T>* rootPtr) const
{
	if(rootPtr == NULL)
	  return false;
	if(x == rootPtr->m_data)
	{
		return true;
	}
	else if(x < rootPtr->m_data && rootPtr->m_left != NULL)
	{
		return findStartingAtNode(x, rootPtr->m_left);
	}
	else if(x > rootPtr->m_data && rootPtr->m_right != NULL)
	{
		return findStartingAtNode(x, rootPtr->m_right);
	}
	else
	{
		return false;
	}
}

template<class T>
void BST<T>::clearStartingAtNode(BNODE<T>*& rootPtr)
{
	while(rootPtr != NULL)
	{
		removeMaxNode(rootPtr);
	}
}

template<class T>
void BST<T>::insertStartingAtNode(const T& x, BNODE<T>*& rootPtr)
{
	if(rootPtr==NULL)
	{
		rootPtr = new BNODE<T>(x,NULL,NULL);
		BST<T>::m_size++;
	}
	else
	{
		if(x<rootPtr->m_data)
		{
			return insertStartingAtNode(x,rootPtr->m_left);
			BST<T>::m_size++;
		}
		else if(x>rootPtr->m_data)
		{
			return insertStartingAtNode(x,rootPtr->m_right);
			BST<T>::m_size++;
		}
		else  //x==rootPtr->m_data
		{
			rootPtr->m_count++;
		}
	}
}

template<class T>
bool BST<T>::removeStartingAtNode(const T& x, BNODE<T>*& rootPtr)
{
	if(rootPtr==NULL)
	{
		return false;
	}
	if(rootPtr->m_data > x)
	{
		return BST<T>::removeStartingAtNode(x,rootPtr->m_left);
	}
	else if(rootPtr->m_data < x)
	{
		return BST<T>::removeStartingAtNode(x,rootPtr->m_right);
	}
	else
	{
		if(rootPtr->m_count > 1)
		{
			rootPtr->m_count--;
			return true;
		}
		else
		{
			if(rootPtr->m_left==NULL)
			{
				BNODE<T>* temp = rootPtr;
				rootPtr = rootPtr->m_right;
				BST<T>::m_size--;
				//delete temp;
				return true;
			}
			else
			{
				BNODE<T>* maxValue = rootPtr->m_left;
				while(maxValue->m_right != NULL)
				{
					maxValue = maxValue->m_right;
				}
				rootPtr->m_data = maxValue->m_data;
				rootPtr ->m_count = 1;
				//rootPtr->m_count = maxValue->m_count;
				//delete maxValue;
				//return true;
				removeStartingAtNode(maxValue->m_data, maxValue);
			}
		}
	}
}

template<class T>
T BST<T>::removeMaxNode(BNODE<T>*& rootPtr)
{
	if(rootPtr==NULL)
	{
		//something
	}
	else if(rootPtr->m_right!=NULL)
	{
		return removeMaxNode(rootPtr->m_right);
	}
	else
	{
		return removeStartingAtNode(rootPtr->m_data, rootPtr);
	}

}

template<class T>
void BST<T>::toStringInorderStartingAtNode(std::string& s, BNODE<T>* nodePtr) const
{
	if(nodePtr != NULL)
	{
		BST<T>::toStringInorderStartingAtNode(s, nodePtr->m_left);
		if (s == "")
		  s += (*nodePtr).BNODE<T>::toString();
		else
		  s = s + "," + " " +(*nodePtr).BNODE<T>::toString();
		BST<T>::toStringInorderStartingAtNode(s, nodePtr->m_right);
	}
}

template<class T>
void BST<T>::toStringPreorderStartingAtNode(std::string& s, BNODE<T>* nodePtr) const
{
	if(nodePtr != NULL)
	{
		if (s == "")
		  s += (*nodePtr).BNODE<T>::toString();
		else
		  s = s + "," + " " +(*nodePtr).BNODE<T>::toString();
		toStringPreorderStartingAtNode(s, nodePtr->m_left);
		toStringPreorderStartingAtNode(s, nodePtr->m_right);
	}
}

template<class T>
void BST<T>::toStringPostorderStartingAtNode(std::string& s, BNODE<T>* nodePtr) const
{
	if(nodePtr != NULL)
	{
		toStringPostorderStartingAtNode(s, nodePtr->m_left);
		toStringPostorderStartingAtNode(s, nodePtr->m_right);
		if (s == "")
		  s += (*nodePtr).BNODE<T>::toString();
		else
		  s = s + "," + " " +(*nodePtr).BNODE<T>::toString(); 
	}
}


#endif /* BST_HPP_ */
