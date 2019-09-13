// Thomas Dolan
//CS54, tues 6pm
//Brian Goldman
//votingmachine.h

//guard statements
#ifndef VOTINGMACHINE_H
#define VOTINGMACHINE_H

//VotingMachine class definition
class VotingMachine
{
  public:
    
    //Desc: Default construtor
    //Pre:  none
    //Post: Creates a VotingMachine variable
    VotingMachine();

    //Desc: Copy constructor
    //Pre:  none
    //Post: Copy of VotingMachine variable has been created
    VotingMachine( const VotingMachine& source);

    //Desc: = operator overload
    //Pre:  none
    //Post: = operator has been overloaded to allow VotingMachine variables 
    //      to be equated
    VotingMachine& operator=( const VotingMachine& rhs);

    //Desc: checks the user's vote
    //Pre:  user enters a char
    //Post: vote has been either cast or thrown out
    void insertBallot(const char vote);

    //Desc: gets the 'yes' vote count
    //Pre:  none
    //Post: returns 'yes' count
    int getYesCount() const;
 
    //Desc: gets the 'no' vote count
    //Pre:  none
    //Post: returns 'no' count
    int getNoCount() const;

  private:
    //yes and no count variables
    int m_yesCount, m_noCount;
};

#endif

