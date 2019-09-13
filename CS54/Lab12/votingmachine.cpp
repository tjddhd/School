//Thomas Dolan
//CS54, tues. 6pm
//Brian Goldman
//votingmachine.cpp


//include statements
#include"votingmachine.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

//default constructor
VotingMachine::VotingMachine()
{
  m_yesCount = 0;
  m_noCount = 0;
}

//copy constructor.... just because
VotingMachine::VotingMachine(const VotingMachine& source)
{
  *this = source;
}

//= operator overload
VotingMachine& VotingMachine::operator=(const VotingMachine& rhs)
{
  m_yesCount = rhs.getYesCount();
  m_noCount = rhs.getNoCount();

  return *this;
}

//insertBallot function to read in votes from user
void VotingMachine::insertBallot(const char vote)
{
  if(vote != 'y' && vote != 'n')
  {
    cout<<"Please enter an actual vote"<<endl;
    return;
  }
  
  if( vote == 'y')
  {
    m_yesCount++;
  }
  else
  {
    m_noCount++;
  }
  return;
}

//returns number of yes votes
int VotingMachine::getYesCount() const
{
  return m_yesCount;
}

//returns number of no votes
int VotingMachine::getNoCount() const
{
  return m_noCount;
}

