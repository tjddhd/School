//Thomas Dolan
//CS54, tues. 6pm
//Brian Goldman
//Lab12: Voting Machine thingy
//main.cpp

//include statements
#include"votingmachine.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

//main function
int main()
{
  //class instance and char variable
  VotingMachine ballotBox;
  char vote;

  //greeting
  cout<<"Welcome to the elections user!"<<endl;

  //loop for election
  for(int i = 0; i < 9; i++)
  {
    cout<<"Please enter your vote(y/n): ";
    cin>>vote;
    ballotBox.insertBallot(vote);
  }
  
  //result output 
  cout<<"Number of 'Yes' votes: "<<ballotBox.getYesCount()
      <<"\nNumber of 'No' votes: "<<ballotBox.getNoCount()<<endl;

  //signoff
  cout<<"Bye-bye user!"<<endl;

  return 0;
}

