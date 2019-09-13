/* file main.cpp
 * author Lisa Tatro
 * brief The generic gtest runner
  *Date: 9/2/2011
 *Class: CS153  1A
 */
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
  /* Herein lies the beauty of gtest.  The runner is 2 lines
   * and will run any tests in any .cpp files in the same directory
   * or any directory you are telling it to compile.
   * This runner will work for virtually everything you do this semester
   *
   * All this line does is initialize googletest with the arguments you
   * passed in.
   */
  ::testing::InitGoogleTest(&argc, argv);
  /* This line runs all your tests and returns the result */
  return RUN_ALL_TESTS();
}
