/* File: test_container.cpp
 * Author: Thomas Dolan
 * Description: The unit tests for the dynamic Container class
 */
#include "container.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

TEST(ContainerTest, DefaultSize)
{
  Container<int> a;
  ASSERT_EQ(0,a.size());
}

TEST(ContainerTest, DefaultMaxSize)
{
  Container<int> a;
  ASSERT_EQ(20,a.max_size());
}

TEST(ContainerTest, Destructor)
{
// *** YOU NEED TO WRITE THIS! 
/*
Make a container, then destruct it. Check that resulting size
is 0.
*/
	Container<int> a;
	a.~Container();

	ASSERT_EQ(0,a.size());
}

TEST(ContainerTest, FindInEmpty)
{
  Container<int> a;
  ASSERT_FALSE(a.find(42));
}

TEST(ContainerTest, SingleInsertAndFind)
{
  Container<int> a;
  a.insert(3);
  ASSERT_EQ(3,a[0]);
  ASSERT_EQ(1,a.size());
  ASSERT_EQ(20,a.max_size());
  ASSERT_FALSE(a.find(42));
  ASSERT_TRUE(a.find(3));
}

TEST(ContainerTest, MultipleInsertAndFindWithDupsNoResize)
{
  Container<int> a;
  a.insert(42); a.insert(34); a.insert(56); a.insert(42);
  ASSERT_EQ(4, a.size());
  ASSERT_EQ(20,a.max_size());
  ASSERT_TRUE(a.find(42));
  ASSERT_TRUE(a.find(34));
  ASSERT_TRUE(a.find(56));
}

TEST(ContainerTest, MultipleInsertAndFindWithNoDupsNoResize)
{
  Container<int> a;
  a.insert(42); a.insert(34); a.insert(56); a.insert(17);
  ASSERT_EQ(4, a.size());
  ASSERT_EQ(20,a.max_size());
  ASSERT_TRUE(a.find(34));
  ASSERT_TRUE(a.find(42));
  ASSERT_TRUE(a.find(17));
  ASSERT_TRUE(a.find(56));
}

TEST(ContainerTest, MultipleInsertAndFindWithNoDupsResize)
{
// *** YOU NEED TO WRITE THIS! 
/*
Make a container, insert several values (no duplicates),
and check that you can find each of those values.
Insert enough values that m_data will have to repeatedly 
resize, and check that the new size is always what we would
expect.
*/

  Container<int> a;
  int temp;

  for (int i =0; i < a.max_size() * .5; i++)
  {
    temp = a.max_size();
    a.insert(i);
    ASSERT_EQ(a[i], i);
    if(a.size() == (temp * .5) +1)
    {
      ASSERT_EQ(a.max_size(), int(temp * 1.2));
    }
  }
}

TEST(ContainerTest, MultipleInsertAndFindWithDupsResize)
{
// *** YOU NEED TO WRITE THIS! 
/*
Similar to MultipleInsertAndFindWithNoDupsResize, but
insert some duplicate values.
*/
  Container<int> a;
  int temp;
 
  for (int i =0; i < a.max_size() * .5; i++)
  {
    a.insert(2);
    ASSERT_EQ(a[i], 2);
  }
  for(int i = a.max_size() * .5; i < 50; i++)
  {
    temp = a.max_size();
    a.insert(i);
    if(a.size() == (temp * .5) +1)
      ASSERT_EQ(a.max_size(), int(temp * 1.2));
  }


}

TEST(ContainerTest, BracketReadNegativeIndex)
{
  Container<int> a;
  ASSERT_THROW(int test = a[-1], std::out_of_range);
}

TEST(ContainerTest, BracketReadIndexLargerThanSize)
{
  Container<int> a;
  ASSERT_THROW(int test = a[3], std::out_of_range);
}

TEST(ContainerTest, BracketReadIndexIsSize)
{
  Container<int> a;
  ASSERT_THROW(int test = a[0], std::out_of_range);
}

TEST(ContainerTest, BracketWriteNegativeIndex)
{
  Container<int> a;
  ASSERT_THROW(a[-1]=1, std::out_of_range);
}

TEST(ContainerTest, BracketWriteIndexLargerThanSize)
{
  Container<int> a;
  ASSERT_THROW(a[3]=1, std::out_of_range);
}

TEST(ContainerTest, BracketWriteIndexIsSize)
{
  Container<int> a;
  ASSERT_THROW(a[0]=1, std::out_of_range);
}

TEST(ContainerTest, ClearWhenEmpty)
{
  Container<int> a;
  a.clear();
  ASSERT_EQ(0,a.size());
}

TEST(ContainerTest, ClearWhenOneResize)
{
  Container<int> a;
  a.insert(1);
  a.clear();
  ASSERT_EQ(0,a.size());
  ASSERT_EQ(16,a.max_size());
}

TEST(ContainerTest, ClearWhenMultipleResize)
{
  Container<int> a;
  for (int i = 0; i < 10; i++)
    a.insert(i);
  a.clear();
  ASSERT_EQ(0,a.size());
  ASSERT_EQ(2,a.max_size());
}

TEST(ContainerTest, RemoveWhenEmpty)
{
  Container<int> a;
  a.remove(3);
  ASSERT_EQ(0,a.size());
  ASSERT_EQ(20,a.max_size());
  ASSERT_FALSE(a.find(3));
}

TEST(ContainerTest, RemoveWhenNoDupsResize)
{
// *** YOU NEED TO WRITE THIS! 
/*
Make a container, insert several values (no duplicates),
and then remove them (checking that you can no longer find each of those values).
Remove enough values that m_data will have to repeatedly resize,
and check that the new size is always what we would expect.
*/
	Container<int> a;
	int temp_max;
	for (int i =0; i < a.max_size() * .5; i++)
	{
	  a.insert(i);
	  ASSERT_EQ(a[i], i);
	}
	for (int i = int(a.max_size() * .5) -1; i >= 0; i--)
	{
		temp_max = a.max_size();
		a.remove(i);
		ASSERT_FALSE(a.find(i));
		if(a.size() == (temp_max *.8) -1)
         	    ASSERT_EQ(a.max_size(), int(temp_max * .8));
	}

}

TEST(ContainerTest, RemoveWhenDupsResize)
{
// *** YOU NEED TO WRITE THIS! 
/*
Similar to RemoveWhenNoDupsResize, but
insert some duplicate values.
*/
        int test = 20;
        Container<int> a;
        int temp;
        for (int i =0; i < a.max_size() * .5; i++)
        {
          a.insert(0);
          ASSERT_EQ(a[i], 0);
        }
        for (int i=0; i< a.max_size() * .5; i++)
        {
          a.remove(0);
          if(i == a.max_size() *.5 -1)
            ASSERT_FALSE(a.find(0));
          else
        ASSERT_TRUE(a.find(0));
        }
        for(int i = 0; i < test; i++)
          a.insert(i);
        for(int i = test; i >=0; i--)
        {
          temp = a.max_size();
          a.remove(i -1);
          if(a.size() == (temp *.8) -1)
          ASSERT_EQ(a.max_size(), int(temp * .8));
        }


}

TEST(ContainerTest, InsertNotEnoughMemory)
{ 
  Container<int> a;
  int mem_limit = 0;
  while (true)
  {
	  try
      {
          a.insert(mem_limit);
          mem_limit++;
      }
      catch(std::bad_alloc& b)
      {
          break;
      }
  }
  a.~Container();
  
  Container<int> b;
  for (int i = 0; i < mem_limit-1; i++)
  {
	  try
      {
          b.insert(i);
      }
      catch(std::bad_alloc& b)
      {
          break;
      }
  }

  ASSERT_THROW(b.insert(7654), std::bad_alloc);
}

TEST(ContainerTest, CopyConstructor)
{
// *** YOU NEED TO WRITE THIS!  
/*
Make a container, insert several values, and then use the copy
constructor to make a copy of it. Check that the copy is exactly 
the same as the original (i.e., can find the same values, has the same size and max_size, etc.).
*/
	int test_num = 20;
	Container<int> a;

	for( int i = 0; i < test_num; i++)
	  a.insert(i);

	Container<int>b(a);
	for( int i =0; i < test_num; i++)
	  ASSERT_EQ(b[i], a[i]);
	ASSERT_EQ(b.size(), a.size());
	ASSERT_EQ(b.max_size(), a.max_size());
	
}

TEST(ContainerTest, CopyConstructorNotEnoughMemory)
{
// *** YOU NEED TO WRITE THIS! 
/*
Make a container and insert several values (enough to take up
almost all available memory). Then try to make a copy of it, 
which should throw a bad_alloc exception.
*/
	Container<int> a;
	  int mem_limit = 0;
	  while (true)
	  {
		  try
		  {
	          a.insert(mem_limit);
	          mem_limit++;
	      }
	      catch(std::bad_alloc& b)
		  {
	          break;
	      }
	  }

	  a.~Container();

	  Container<int> b;
	  for (int i = 0; i < mem_limit-1; i++)
	  {
	      try
	      {
	          b.insert(i);
	      }
	      catch(...)
	      {
	          break;
	      }
	  }

	  ASSERT_THROW(Container<int> c(b), std::bad_alloc);
}





