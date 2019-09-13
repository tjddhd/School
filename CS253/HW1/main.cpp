//Thomas Dolan
//CS253, Section B
//Gerry Howser
//Project 1: Insertion Sort runtime
//main.cpp

#include "sort.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	srandom(time(NULL));
	time_t rawtime;
	const int SIZE = 400000;
	
	if(SIZE == 0)
		return 0;
	else
	{
		int a[SIZE], b[SIZE], c[SIZE];
	
		int i =0;
		while(i<SIZE)
		{
			a[i] = random()%1000;
			b[i] = i;
			c[i] = SIZE - i;
			i++;
		}
		clock_t t1=clock(),t2;
		cout<<"AVERAGE CASE:\n"<<endl;	
		insertSort(a, SIZE);
		t2=clock();
		cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;
		
		
		t1=clock();
		cout<<"BEST CASE:\n"<<endl;
		insertSort(b, SIZE);
		t2=clock();
		cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;
		
		t1=clock();
		cout<<"WORST CASE:\n"<<endl;
		insertSort(c, SIZE);
		t2=clock();
		cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;
		
		//Display loop that was commented when number being 
		//sorted was very large
		//
		//i =0;
		//while(i <100)
		{
			//cout << a[i] <<endl;
			//cout << b[i] <<endl;
			//cout << c[i] <<endl;
			//i++;
		}
		return 0;
	}
}
