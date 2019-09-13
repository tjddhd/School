/*
 * main.cpp
 *
 *  Created on: Feb 6, 2012
 *      Author: Thomas Dolan
 */

#include "Sorts.h"
#include <iostream>
using namespace std;

int main()
{
  int array[10];
  Sorts mySort;
  mySort.insertionSort(array, 0);
  if(mySort.getTrue())
    cout<<"we did it"<<endl;
  else
    cout<<"more work to do..."<<endl;

  mySort.mergeSort(array, 0, 0);
  if(mySort.getTrue())
    cout<<"we did it"<<endl;
  else
    cout<<"more work needed"<<endl;
  
  array[0] = 3;
  array[1] = 54;
  array[2] = 1;
  array[3] = 78;
  array[4] = 45;
  array[5] = 102;
  array[6] = 17;
  array[7] = 65;
  array[8] = 73;
  array[9] = 56;

  mySort.mergeSort(array,0,10);
  if(mySort.getTrue())
    cout<<"we did it"<<endl;
  else
    cout<<"more work to do..."<<endl;
  cout<<array[0]<<" "<<array[1]<< " " <<array[2]<<" "<<array[3]<<" "<<array[4]<< " " <<array[5]<<" "<<array[6]<<" "<<array[7]<< " " <<array[8]<<" "<<array[9]<<endl;


  return 0;
}

