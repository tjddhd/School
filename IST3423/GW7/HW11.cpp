#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{

	double y = 1, x =4;
	
	for(int i = 1; i < 10; i++)
	{
		double j = i;
		while(j > 0)
		{
			y = y*x;
			j--;
		}
		
		cout<< y << endl;
	}
	
	return 0;
}