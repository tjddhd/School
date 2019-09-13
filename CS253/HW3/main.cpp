//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//main.cpp

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include "knapRecur.h"
#include "knapGreed.h"
#include "knapDynam.h"
using namespace std;

int main() {
	srandom(time(NULL));
	
	int price[500000];
	for(int i = 0; i < 500000; i++)
		price[i] = rand()%50;

	int weight[500000];
	for(int i = 0; i < 500000; i++)
			weight[i] = rand()%50;
	
	int capacity = 500;
	int size =500000/*, min=0*/;
	

	cout<<"Knapsack Dynamic: ";
	clock_t t1=clock(),t2;
	int total = knapDynamic(price, weight, capacity, size);
	t2=clock();
	cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;

	cout<<total<<endl;

	cout<<"Knapsack Greedy: ";
	clock_t t1=clock(), t2;
	int total = knapGreedy(price, weight, capacity, size);
	t2=clock();
	cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;

	cout<<total<<endl;

	cout<<"Knapsack Recursion: ";
	t1=clock();
	total = knapRecursion(price, weight, capacity, min);
	t2=clock();
	cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;
	
	cout<<total<<endl;

	return 0;
	
}
