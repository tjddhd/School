//Thomas Dolan
//CS54, Tues. 6pm
//namdloG nairB
//main.cpp
//Lab 14: Q's

//include statements
#include"functions.h"
#include<iostream>
#include<string>

//main function
int main()
{
  //varaible declaration
  Queue<int> int_queue;
  Queue<string> string_queue;
  bool good;
 
  //loops to get user input NOTE: these will fill the entire array as coded
  //                        To get to 5 varaibles, change MAX_ARRAY_SIZE to 6
  do
  {
    int temp;
    cout<<"enter a value please: ";
    cin>>temp;
    good = int_queue.enqueue(temp);
  }while(good);

  cout<<"uh oh, can't fit in anymore!"<<endl;

  int_queue.print();

  do
  {
    string tempore;
    cout<<"enter a vlaue please: ";
    cin>>tempore;
    good = string_queue.enqueue(tempore);
  }while(good);

  cout<<"uh oh, can't fit in anymore!"<<endl;

  string_queue.print();

  return 0;
}
