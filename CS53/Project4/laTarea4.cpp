//TJ Dolan
//Matt Nuckolls
//CS53, Section C-C-C-C-COMBO BREAKER
//Project 4 aka do Jerry Garcia's job

#include<iostream>
#include<string>

using namespace std;

int main()
{
  cout<<"Hello Jerry Garcia!"<<endl;
  cout<<"I'm your financial aid do-hickey program"<<endl;

  int menuChoice, studentID, check = 0;
  float assets, aid;
  bool maxChances = true, firstSelected = false, secondSelected = false, hasAssets;
  
  do
  {
    if(maxChances)
    {
      cout<<"Jerry Garcia's financial....... thingy"<<endl;
      cout<<"\n1. Enter student number"<<endl;
      cout<<"2. Validate this number"<<endl;
      cout<<"3. Assets"<<endl;
      cout<<"4. Calculate financial aid package"<<endl;
      cout<<"5. Quit"<<endl;
      cout<<"6. Peace out"<<endl;
      cout<<"Please enter a number 1-6: ";
      cin>>menuChoice;
    
      while(menuChoice < 1 || menuChoice > 6)   
      {
        cout<<"ERROR JERRY GARCIA, ERROR JARRY GARCIA!! Please enter 1-6: ";
        cin>>menuChoice;
      }
      
   
      switch(menuChoice)
      {
        case(1):
        { 
          cout<< "Plese a student ID number: ";
          cin>> studentID;
          firstSelected = true;
          
          while(!(studentID >= 1500000 && studentID <= 3599999))
          {
            if(check < 5)
            {
              check++;
              cout<<"OH EM GEE, You are so stupid! Gimme a good value, RIGHT NOW!: ";
              cin>> studentID;
            }
            else
            {
              maxChances = false;
              break;
            }
          }
        }
        break;

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
              cout<<"this is a grad student"<<endl;
            }
            else
            {
              cout<<"ERROR. Does not match any grade level. "
                  <<"Please re-enter student ID number"<< endl;
              break;
            }
          }
          else
          {
            cout<<"ERROR. Please select option 1 first"<<endl;
            break;
          }
        }
        break;

        case(3):
        {
          if(firstSelected)
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
             
              hasAssets = true;
            }
            else
            {
              cout<<"ERROR. Please select option 2 first"<<endl;
            }
          }
          else
          {
            cout<<"ERROR. Please select option 1 first"<<endl;
            break;
          }
        }
        break;

        case(4):
        {
          if(firstSelected)
          {
            if(secondSelected)
            {
              int ones = studentID % 10;
              int tens = (studentID/10) % 10;
              int hundreds = (studentID/100) % 10;
              int thousands = (studentID/1000) % 10;
              int tenThousands = (studentID/10000) % 10;
              int millions = (studentID/1000000) % 10;

              if(hasAssets)
              {
                aid = assets + (millions + thousands + hundreds + tens + ones) * 4.3;
                cout.setf(ios::fixed);
                cout.setf(ios::showpoint);
                cout.precision(2);
                cout<<"This student has qualified for $"<< aid <<" in financial aid"<<endl;
              }
              else
              {
                aid = ((tenThousands*1.0)*(thousands*1.0)*(hundreds*1.0)*(tens*1.0)*(ones*1.0));
                cout.setf(ios::fixed);
                cout.setf(ios::showpoint);
                cout.precision(2);
                cout<<"This student has qualified for $"<< aid <<" in financial aid"<<endl;
              }
            }
            else
            {
              cout<<"ERROR. Please select option 2 first"<<endl;
              break;
            }
          }
          else
          {
            cout<<"ERROR. Please select option 1 first"<<endl;
            break;
          }
        }
        break;

        case(5):
        {
          cout<<"You picked number five"<<endl;
        }
        break;

        case(6):
        {
          cout<<"Peace man"<<endl;
        }
        break;
      } 
    }
    else
    {
      cout<<"You are fired! Dummy!"<<endl;
      break;
    } 

  }while(menuChoice != 5);
  

  cout<<"Goodbye Jerry Garcia!"<<endl;

  return 0;
}

