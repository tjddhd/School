//TJ Dolan
//CS53, MWF Section Noisy Girl
//sllokcuN wehttaM
//Project 5

//include statements
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

//function prototypes
void greetings();
double get_anger_level();
double get_arm_diameter();
int burninations(double anger, double arm);
int death_count(double burninations);
double revenue_loss(int death);
void output_stats(double arm, double anger, int burn, int death, double revenue);
void signoff();

//main function
int main()
{
  //random seed
  srandom(time(NULL));
  
  //function calls
  greetings();

  double angry = get_anger_level();
 
  double beefcake = get_arm_diameter();

  int crispyPeasants = burninations(angry, beefcake);

  int deaths = death_count(crispyPeasants);

  double loss = revenue_loss(deaths);

  output_stats(angry, beefcake, crispyPeasants, deaths, loss);
  
  signoff();
}

//greeting message because I have to be semi-nice to the user
void greetings()
{
  cout<<"Hello User! Welcome to Trogdor's Super-Fun-Happy-Go-Lucky Mayhem Calculator!"<<endl;
  return;
}

//ANGRY TROGDOR IS ANGRY
double get_anger_level()
{
  double anger;
  cout<<"Please input Trogdor's anger level: ";
  cin>>anger;
 
  while(anger <= 0)
  {
    cout<<"ERROR! Please enter a positive number, nimwit: ";
    cin>>anger;
  }
  
  return anger;
}

//BEEFY TROGDOR IS BEEFY
double get_arm_diameter()
{
  double armDiam;
  cout<<"Please input Trogdor's arm diameter: ";
  cin>>armDiam;
  
  while(armDiam <= 0)
  {
    cout<<"ERROR! Please enter a positive number nimwit: ";
    cin>>armDiam;
  }
 
  return armDiam;
}

//I prefer my peasants slow cooked rather than instant charbroil
int burninations(double angerLev, double armDiam)
{
  int burns;
  const int vCons = 17;
  const int burnPeasantsBurn = 40;
  
  burns = static_cast<int>(angerLev * (1 + 1.0/vCons) + static_cast<float>(burnPeasantsBurn)/vCons + armDiam);
   
  cout<<burns<<endl;
  return burns;
}

//Trogdor wins at murder, arson, weddings and irony
int death_count(double burns)
{
  int kills, killChance = 200;
  bool isKilled = false;  

  //These statements have been commented out to save space but can be uncommented if you wish to see full output
  //cout<<"20% chance of death"
  //    <<"\nBurnination         death"<<endl;
  for(int i = 0; i < burns; i++)
  {
    isKilled = (random()%1000) <= killChance;
    
    if(isKilled)
    {
      kills++;
      killChance++;
      //cout<<i<<"        yes"<<endl;
      //cout<<(killChance/10.0)<<" chance now"<<endl;
    }
    else
    {
      //cout<<i<<"        no"<<endl;
    }

  }
  return kills;
}

//Funeral costs could have been covered if they had had an affordable life insurance plan from the Colonial Penn Program
double revenue_loss(int deaths)
{
  const double tax = 0.15;
  const int salary = 455;
 
  double loss = deaths*tax*salary;
  return loss;
}

//It's like baseball stats... except more dragon-y
void output_stats(double armDiam, double angerLev, int burns, int deaths,
                  double revenue)
{
  cout<<"Trogdor is burninating!\n"
      <<"He currently has a beefy arm diameter of "<< armDiam
      <<"in. and an anger level of "<<angerLev<<endl;
  cout<<"Burninaitons generated: "<<burns<<endl;
  cout<<"Predicted number of deaths: "<<deaths<<endl;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2); 

  cout<<"Lost revenue: $"<<revenue<<endl;
  return;
}

//Thank god, they're leaving me alone now
void signoff()
{
  cout<<"Goodbye user!"<<endl;
}

