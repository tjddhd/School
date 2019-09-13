//Thomas Dolan
//CS54, Tues. 6pm
//Brian Goldman
//functions.cpp

//include statements
#include"functions.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

//Default constructor
template<class K>
Queue<K>::Queue()
{
  m_currentSize = 1;
}

//Adds to the Queue
template<class K>
bool Queue<K>::enqueue(const K& enq)
{
  bool good;
  if(m_currentSize < MAX_ARRAY_SIZE)
  {
    m_arr[m_currentSize-1] = enq;
    m_currentSize++;
    good = true;
  }
  else
  {
    good = false;
  }
  return good;
}

//Queue removal function
template<class K>
bool Queue<K>::dequeue()
{
  bool good;
  if(m_currentSize > 0)
  {
    for(int i = 0; i > m_currentSize; i++)
    {
      m_arr[i] = m_arr[i+1];
    }
    m_currentSize--;
    good = true;
  }
  else
  {
    good = false;
  }
  return good;
}

//front of queue function
template<class K>
const K& Queue<K>::front() const
{
  if(m_currentSize == 0)
  {
    exit(1);
  }
  else
  {
    return m_arr[0];
  }
}

//size function
template<class K>
const int Queue<K>::size() const
{
  return m_currentSize;
}

//Output function cause i was too lazy to overload the << operator
template<class K>
void Queue<K>::print()
{
  for(int i = 0; i < m_currentSize-1; i++)
  {
    cout<<m_arr[i]<<endl;
  }
}




