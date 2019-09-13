//TJ Dolan
//Project 6, Section C.5
//functions.cpp

//include statements
#include"functions.h"
#include<iostream>

using namespace std;

//Greeting function cuz i'm polite and shit
void greeting()
{
  cout<<"Howdy there Jerry Garcia! Haven't we met before?" <<endl;
  cout<<"Anyways, I'm the financial aid calculometer thing"<<endl;
}

//Menu function and shit
int menu()
{
  int menuChoice;
  cout<<"Jerry Garcia's financial..... thingy\n"
      <<"\n1. Enter student number\n"
      <<"2. Validate this number\n"
      <<"3. Assets\n"
      <<"4. Calculate financial aid package\n"
      <<"5. Quit"<<endl;
  cout<<"Please enter a number 1-5: ";
  cin>>menuChoice;
  
  while(menuChoice<1 || menuChoice>5)
  {
    cout<<"ERROR JERRY GARCIA, ERROR JERRY GARCIA!! Please enter 1-5: ";
    cin>>menuChoice;
  }

  return menuChoice;
}

//evaluator method and shit (switch case is the devil)
void evaluator(int choice, bool& firstSelected, bool& secondSelected, int& studentID, int& assets, int& aid)
{
  //trolololol switch case
  switch(choice)
  {
    //roflcopter 1st case
    case(1):
    {
      firstSelected = true;
      
      cout<<"Please enter the student's ID number: ";
      cin>>studentID;
      
      while(!(studentID > 1500000 && studentID < 3599999))
      {
        cout<<"OH EM GEE, you are so stupid! Gimme a good velue, RIGHT NOW!: ";
        cin>>studentID;
      }
    }
    break;

    //lololol 2nd case
    case(2):
    {
      if(firstSelected)
      {
        secondSelected = true;
        if(studentID >= 1500000 && studentID <= 1599999)
        {
          cout<<"This is a freshman"<<endl;
        }    
        else if(studentID >= 2000000 && studentID <= 2099999)
        {
          cout<<"This is a sophomore"<<endl;
        }
        else if(studentID >= 2500000 && studentID <= 2599999)
        {
          cout<<"This is a junior"<<endl;
        }
        else if(studentID >= 3000000 && studentID <= 3099999)
        {
          cout<<"This is a senior"<<endl;
        }
        else if(studentID >= 3500000 && studentID <= 3599999)
        {
          cout<<"This a grad student"<<endl;
        }
        else
        {
          cout<<"ERROR. Does not match any grade level. "
              <<"Please re-enter studentID number"<<endl;
          break;
        }
      }
      else
      {
        cout<<"Please select 1st option first"<<endl;
      }
    }
    break;
 
    //Eeeekkk 3rd case
    case(3):
    {
      if(firstSelected && studentID != 0)
      {
        if(secondSelected)
        {
          cout<<"Please enter assets of student: ";
          cin>>assets;
         
          while(assets < 0)
          {
            cout<<"ERROR! Please enter a positive value: ";
            cin>>assets;
          }
        }
        else
        {
          cout<<"Please select 2nd option first"<<endl;
        }
      }
      else
      {
        cout<<"Please select 1st option first"<<endl;
      }
    }
    break;

    //Eeewww 4th case
    case(4):
    {
      if(firstSelected && studentID != 0)
      {
        if(secondSelected)
        {
          int ones = studentID%10;
          int tens = (studentID/10)%10;
          int hundreds = (studentID/100)%10;
          int thousands = (studentID/1000)%10;
          int tenThousands = (studentID/10000)%10;
          //Just because
          //int hundredThousands = (studentID/100000)%10;
          //int millions = (studentID/1000000)%10;
         
          if(assets != 0)
          {
            aid = 1;
            for(int i= 0; i<thousands; i++)
            {
              aid = aid*tenThousands;
            }
            aid = aid * max(hundreds, tens, ones);
            aid = aid + assets;
 
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2); 
            cout<<"This student has qualified for $"<<aid<<" in aid"<<endl;
          }
          else
          {
            aid = 1;
            for(int i = 0; i<thousands; i++)
            {
              aid = aid*tenThousands;
            }
            aid = aid *max(hundreds, tens, ones);
            
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);
            cout<<"This student has qualified for $"<<aid<<" in aid"<<endl;
          }
        }
        else
        {
          cout<<"Please select 2nd option first"<<endl;
        }
      }
      else
      {
        cout<<"Please select 1st option first"<<endl;
      }
    }
    break;
 
    //everything went better than expected with the default case :)
    default:
    {
      break;
    }
  }
}

//max function and not shit
int max(int a, int b, int c)
{
  if(a > c)
  {
    if(a>b)
    {
      return a;
    }
    else
    {
      return b;
    }
  }
  else if(b > c)
  {
    if(b>a)
    {
      return b;
    }
    else
    {
      return a;
    }
  }
  else
  {
    return c;
  }
}

//signoff function and shit
void signoff()
{
  cout<<"See ya later, Jerry Garcia!"<<endl;
}
