
//TJ (Teej) Dolan
//Matt Nuckolls
//CS53 MWF, Section (E/m)^(1/2) = C aka Section Noisy Girl
//Project 3

//User input YAY
#include<iostream>

//Thingy
using namespace std;

//Main method
int main()
{
  //Varible declaration
  int numberSN;
  int ones, tens, hundreds, thousands, tenThousands;
  bool even;

  //Greeting message and prompt for input from a drunk.... Yeah I'm not the smartest program out there
  cout<<"Hello there, Jerry Garcia! Getting over your hangover? Well allow me to help you out!"
      <<"\nWhat is the number stamped onto your hairbrush?: ";
  cin>> numberSN;

  //Check on input
  while(numberSN < 10000 && numberSN > 99999)
  {
    cout<<"ERROR JERRY GARCIA, ERROR JERRY GARCIA!!! Please enter a valid SN numneber: ";
    cin>> numberSN;
  }

  //Check on evenness or oddness  
  if(numberSN % 2 == 0)
  { 
    even = true;
  }
  else
  {
    even = false;
  }

  //Getting each digit from the input
  ones = numberSN % 10;
  tens = (numberSN/10) % 10;
  hundreds = (numberSN/100) % 10;
  thousands = (numberSN/1000) % 10;
  tenThousands = (numberSN/10000) % 10;

  //Jerry Garcia's stupidly complicated system for hair styling
  if(even == true && hundreds == 3)
  { 
    cout<<"Brush your hair into a scary style and then shave, Jerry Garcia"<<endl;
  }
  else if(even == true)
  {
    cout<<"Brush your hair into a scary style, Jerry Garcia"<<endl;
  }

  if(even == false && thousands == 4)
  {
    cout<<"Put your hair into a ponytail, Jerry Garcia"<<endl;
  }

  if(even == false && thousands + hundreds == 4)
  {
    cout<<"Color your hair grey, Jerry Garcia"<<endl;
  }

  if(even == false && ((tenThousands + hundreds + ones - (thousands + tens)) == 11 || (tenThousands+ hundreds+ ones - (thousands + tens) == 22)))
  {
    cout<<"Be content and play your banjo, Jerry Garcia"<<endl;
  }
  else
  {
    cout<<"Just play your guitar and smile, Jerry Garcia"<<endl;
  }

  //Goodbye message.... $20 says he forgets what he supposed to do and has to run me again :P
  cout<<"Thank you Jerry Garcia! Please have a pleasant day rocking out."<<endl;

  return 0;

}

