//Teej Dolan 
//CS53, Section Trogdor-is-worshipped-in-this-class
//Sonic, Tails, and Matt Nuckolls
//Project 8: Do you even need to guess the topic anymore?
//laTarea8.cpp

//include statements
#include<iostream>
#include<fstream>
#include<string>
#include"functions.h"

//main funciton
int main()
{
  //variable and ifstream/ofstream opened
  char stockChoice;
  const int size = 6;
  ifstream jedi;
  ofstream sith;

  //Array declared and counter initialized
  Stock portfolio[size];
  int counter = 0;
 
  //files opened and values read in
  sith.open("portfolio.dat");
  jedi.open("burninations.dat");
  jedi >> portfolio[counter];
  while(jedi.good())
  { 
    counter++;
    jedi >> portfolio[counter];
  }

  //sort funciton call
  sorter(portfolio, counter);

  //Loop for user input
  do
  {
    cout<<"Do you wish to enter a new stock?(Y/y/N/n): ";
    cin>>stockChoice;

    while(stockChoice != 'Y' && stockChoice != 'y' &&
          stockChoice != 'N' && stockChoice != 'n')
    {
      cout<<"Please enter value option: ";
      cin >> stockChoice;
    }
    
    if(stockChoice == 'Y' || stockChoice == 'y')
    {
      cout<<"Please enter the stock info and then press enter. "
          <<"(name/enter/price/enter/peRatio/enter): ";
      cin>>portfolio[counter];
      counter++;
    }

    sorter(portfolio, counter);

  }while(stockChoice != 'N' && stockChoice != 'n' && counter < size);

  if(counter == size)
  {
    cout<<"Lol sorry no more room!"<<endl;
  }
 
  //writes the array to the output file
  for(int i =0; i<size; i++)
  {
    sith<< portfolio[i]<<endl;
  }  

  //file close
  jedi.close();
  sith.close();

  return 0;
}


