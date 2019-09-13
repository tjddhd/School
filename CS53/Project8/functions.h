//Teej Dolan
//CS53, Section C
//Matthew Nuckolls
//functions.h

//Guard statements
//I found that a program doesn't work very well without these
//Or at all
//It took 3 days of banging my head against the wall to figure that out
//-_-
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//include statements
#include<string>

using namespace std;

//Stock struct to hold info from file and user
struct Stock
{
  string m_name;
  float m_price;
  float m_peRatio;
};

//Desc: Greets the user
//Pre:  None
//Post: User has been greeted
void greeting();

//Desc: Goodbyes the user
//Pre:  None
//Post: User has been goodbyed
void signoff();

//Desc: Overloads the extraction operator to read in Stock
//Pre:  none
//Post: Stock has been read in
istream& operator>>(istream& ins, Stock& stock);

//Desc: Overloads the insertion operator to display Stock
//Pre:  none
//Post: Stock has been displayed
ostream& operator<<(ostream& outs, Stock& stock);

//Desc: Overloads the < operator
//Pre:  None
//Post: returns a true or false value
bool operator<(Stock& stock1, Stock& stock2);

//Desc: Templated sort funciton
//Pre:  arr has values that can use the < operator
//Post: arr ahs been sorted
template<class T>
void sorter(T arr[], const int a);

//include the hpp file
#include"functions.hpp"

#endif



