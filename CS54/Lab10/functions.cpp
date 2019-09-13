//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman

//include statements
#include<iostream>
#include<string>

using namespace std;

//swap funciton that was given
void swap(int& num1, int& num2)
{
  int temp = num2;
  num2 = num1;
  num1 = temp;
}

//shuffle function to randomly swap array numbers
void shuffle(int my_array[], const int array_size)
{
  for(int i = 0; i < array_size; i++)
  {
    int rand = random() %10;
    while(rand <i || rand ==10)
    {
      rand = random()%10;
    }
    int temp1 = my_array[i];
    int temp2 = my_array[rand];

    swap(temp1, temp2);
   
    my_array[i] = temp1;
    my_array[rand] = temp2;
  }
}

//greeting function
void greeting()
{
  cout<<"Hey there user!"<<endl;
}

//signoff function
void signoff()
{
   cout<<"Bye bye user!"<<endl;
}

