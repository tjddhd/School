/*
 * sumSquares.cpp
 *
 *  Created on: Dec 14, 2011
 *      Author: Thomas Dolan
 */

#include "sumSquares.h"
#include <vector>

int sumSquares(std::vector<int> v, int offset)
{
	if(v.size() == 0)
		return offset;
	int sum = 0;
	if(v.size() > offset)
		sum = (v[offset]*v[offset]) + sumSquares(v, offset+1);
	return sum;
}
