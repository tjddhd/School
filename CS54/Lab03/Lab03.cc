//Thomas (TJ) Dolan
//CS54 6pm
//Goldman
//Program to calculate velocity and distance

//Allows user input
#include <iostream>

using namespace std;

//Main method
int main()
{
	//Variable declaration
	const int acceleration = 9;
	float distance, time, velocity;

	//Greeting and user input
	cout<<"Hello there, bloodthristy pirates. \nI am a program that can help you efficiently calculate the death rate of your victims."<<endl;
	cout<<"Please enter the relative time expected for your screaming vicitms to fall: ";
	cin>>time;

	//Calculations
	velocity = acceleration * time;
	distance = static_cast<float>(acceleration)/2*time*time;

	//Output of results and goodbye message
	cout<<"Thank you, scallywag pirates. Your victims should fall a distance of "<<distance<<" at a velocity of "<< velocity<<" for a time of "<<time<<" seconds."<<endl;
	cout<<"Please use think to use this program in the future when plotting horrible deaths for your prisoners. \nGoodbye user."<<endl;

	return 0;
}
