/* File: main.cpp
 * Author: Nathan Eloe (nwe5g8@mst.edu)
 * Description: The generic gtest runner
 */
#include <gtest/gtest.h>
#include "container.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  /* 
   Herein lies the beauty of gtest.  The runner is 2 lines
   and will run any tests in any .cpp files in the same directory
   or any directory you are telling it to compile.
   This runner will work for virtually everything you do 
   this semester
   
   All this first line does is initialize googletest with 
   the arguments you passed in.
  */
  ::testing::InitGoogleTest(&argc, argv);
  /* This line runs all your tests and returns the result */
  return RUN_ALL_TESTS();
}
