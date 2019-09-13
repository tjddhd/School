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
	float grid[757][757];
	float lat[757];
	float longi[757];
	float disty, distx;
	string temp;
	int size = 757;

	DIRECTED_GRAPH<float, 757> map;

	ifstream in;

	in.open("assn4p1_latlong.csv");
	int counter = 0;

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

	for(int i = 0; i < 757; i++)
	{
		for(int j = 0; j < 757; j++)
		{
			if(i == j)
			{
				grid[i][j] = 99999;
			}
			else
			{
				disty = 68.98*(lat[i]-lat[j]);
				distx = 69.27*cos(lat[j])*(longi[i]-longi[j]);
				grid[i][j] = sqrt(disty*disty + distx*distx);
				map.addEdge(i, j, grid[i][j]);
			}
		}
	}

	prim(map, size);

	in.close();

	return 0;
}
