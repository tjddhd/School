#include<iostream>
#include "stdlib.h"
#include<fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "DIRECTED_GRAPH.h"
using namespace std;

int main()
{
	float grid[747][747];
	float lat[747];
	float longi[747];
	float disty, distx;
	string temp;
	const int size = 747;
	int visitedFrom[747];
	int distBetween = 0;

	DIRECTED_GRAPH<float, size> map, flow;

	ifstream in;

	in.open("assn4p1_latlong.csv");
	int counter = 0;

	//Reading in values
	while(in.good())
	{
		getline(in, temp, ',');
		getline(in, temp, ',');

		stringstream i1(stringstream::in | stringstream::out);
		i1 << temp;
		i1 >> lat[counter];

		getline(in, temp, ',');

		stringstream i2(stringstream::in | stringstream::out);
		i2 << temp;
		i2 >> longi[counter];

		getline(in, temp, '\n');
		counter++;
	}
	for(int k =0; k<size;k++)
	{
		longi[k]=longi[k]*-1;
		visitedFrom[k] = NOT_YET_VISITED;
	}

	//Setting up our default graph
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(i == j)
			{
				grid[i][j] = 9999;
			}
			else
			{
				distx = abs(69.1*(lat[j]-lat[i]));
				disty = abs(69.1*cos(distx/57.3)*(longi[j]-longi[i]));
				grid[i][j] = sqrt(disty*disty + distx*distx);
			}
			map.addEdge(i, j, grid[i][j]);
			flow.addEdge(i, j, 1);
		}
	}


	//Flow network and path finding
	edmondsKarp(flow);

	cout<<"Flow: ";
	prim(flow, size, visitedFrom);

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(!(flow.isEdge(i,j)))
			{
				//total += map.getEdgeWeight(i,j);
				map.removeEdge(i,j);
				map.removeEdge(j,i);
			}
		}
	}

	cout<<"total: ";
	prim(map, size, visitedFrom);
	cout<<endl;

	//Finds distance between Washington D.C. and Denver with our flow network
	for(int i =100; i<size&&i!=121;)
	{
		distBetween += map.getEdgeWeight(i,visitedFrom[i]);
		i = visitedFrom[i];
	}

	cout<<"Distance between Denver and Washington D.C.: "<<distBetween<<endl;
	distBetween = 0;

	//Finds distance between Washington D.C. and Los Angeles with our flow network
	for(int i =56; i<size&&i!=121;)
	{
		distBetween += map.getEdgeWeight(i,visitedFrom[i]);
		i = visitedFrom[i];
	}

	cout<<"Distance between Los Angeles and Washington D.C.: "<<distBetween<<endl;
	distBetween = 0;

	//Finds distance between Seattle and New York with our flow network
	for(int i =458; i<size&&i!=121;)
	{
		distBetween += map.getEdgeWeight(i,visitedFrom[i]);
		i = visitedFrom[i];
	}

	for(int i =703; i<size&&i!=121;)
	{
		distBetween += map.getEdgeWeight(i,visitedFrom[i]);
		i = visitedFrom[i];
	}

	cout<<"Distance between Seattle and New York: "<<distBetween<<endl;

	in.close();

	return 0;
}
