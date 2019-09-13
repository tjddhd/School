//Thomas Dolan
//CS54, Tues. 6pm
//Brian Goldman
//functions.h

//Guard statements
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>

using namespace std;

//global constants
const int MAX_ARRAY_SIZE = 21;

//templated class
template<class K>
class Queue
{
  public:
    //Desc: Default constructor
    //Pre:  none
    //Post: Queue variable declared
    Queue();

    //Desc: Adds value onto end of queue
    //Pre:  Queue not full, otherwise program closes
    //Post: Queue has been added to
    bool enqueue(const K& enq);

    //Desc: Removes value at end of queue
    //Pre:  There are vlaues in queue, otherwise program closes
    //Post: Queue has been decremented
    bool dequeue();

    //Desc: Gets the value of the front of queue
    //Pre:  none
    //Post: Front of queue value returned
    const K& front() const;
   
    //Desc: Gets the current size of the queue
    //Pre:  none
    //Post: queue size returned
    const int size() const;

    //Desc: Prints a Queue variable
    //Pre:  none
    //Post: Queue has been outputted
    void print();

  private:
    //member variables
    K m_arr[MAX_ARRAY_SIZE];
    int m_currentSize;
};

#include"functions.hpp"

#endif


