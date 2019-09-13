//Thomas Dolan
//CS54 6pm T
//Brian Goldman
//Lab 07: Functions Intro

//include statements
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

//function declaration
double get_non_negative();
void get_pythagorian_third(double leg1, double leg2);

//main function
int main()
{
  //hello and varaible declaration
  cout<<"Hello user!"<<endl;
  double side1, side2;
  
  //value assignment using function calls
  side1 = get_non_negative();
  side2 = get_non_negative();

  //displaying third side using input values and double the input values
  get_pythagorian_third(side1, side2);
  get_pythagorian_third(2*side1, 2*side2);
 
  //goodybe message and return statemnet
  cout<<"Goodbye user!"<<endl;
  return 0;
}

//first function that gets the user to input a value greater than 0
double get_non_negative()
{
  //variable and input prompt
  double x;
  cout<<"Please enter a non-negative value: ";
  cin>>x;

  //check loop
  while(x<=0)
  {
    cout<<"ERROR! Please try again. Enter a non-negative value: ";
    cin>>x;
  } 

  //returns the value
  return x;
}

//calculates the third side of the triangle
void get_pythagorian_third(double leg1, double leg2)
{
  //varaible declaraiton
  double leg3;
  
  //value calculation
  leg3 = sqrt(leg1*leg1 + leg2*leg2);
  
  //output for user
  cout<<"The third leg is length: "<<leg3<<endl;
  
  //return statement
  return;
}


