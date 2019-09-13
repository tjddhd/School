/*
 * testSort.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: Thomas Dolan
 */
#include "Sorts.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
using namespace std;

TEST(INSERTtest, EmptyArray)
{
  int array[3];
  Sorts mySort;
  ASSERT_TRUE(mySort.getTrue());
}

