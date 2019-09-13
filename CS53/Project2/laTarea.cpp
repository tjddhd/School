//Thomas (TJ) Dolan
//Matthew Nuckolls
//CS53 Section Si, 1pm MWF

//Allows User input to be used cuz I, as a program, am too stupid to come up with my own
#include<iostream>

//Thingy we are told to put in
using namespace std;

//Main method
int main()
{
  //Variable declaration
  int burninations;
  const int vCons = 17;
  const int burnPeasantsBurn = 40;
  float angerLevel, armDiam;
  
  //Greeting and first input
  cout<<"Welcome to this extremely important program! \nThis calculation on Trogdor's burniantions could be vital to your survival!"<<endl;
  cout<<"\nQuickly! Before Trogdor gets here, what is his anger level: "; 
  cin>>angerLevel;
  
  //Second input
  cout<<"\nI think I can hear him... No I can see that fiery dragon-man of doom!! \nHurry up and tell me the diameter of the mighty Trogdor's biceps: ";
  cin>>armDiam;

  //Calculations and output because I am a slave to the user
  burninations = static_cast<int>(angerLevel * (1 + 1/static_cast<float>(vCons)) + static_cast<float>(burnPeasantsBurn)/vCons + armDiam);
  cout<<"Ok, based on my calculations from the info you gave me, I have come to these numbers:"<<endl;
  cout<<"\nTrogdor's Anger Level:\t"<<angerLevel<<endl;
  cout<<"Bicep Diameter:\t\t"<<armDiam<<endl;
  cout<<"\nBurninations:\t\t"<<burninations<<endl;

  //Goodbye message...
  cout<<"\nThank god... Trogdor's out of burninaitons for the time being. Let's take this time to run away like the scared little girls we are"<<endl;

  return 0;
}

