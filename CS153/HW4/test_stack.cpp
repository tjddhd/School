/*
 * test_stack.cpp
 *
 *  Created on: Oct 14, 2011
 *      Author: THOMAS DOLAN
 */

#include <gtest/gtest.h>
#include "STACK.h"
#include "NODE.h"
#define ASSERT_NULL ASSERT_FALSE
#define ASSERT_NOT_NULL ASSERT_TRUE

TEST(Stack, TopWhenEmpty)
{
  STACK <int> a;
  ASSERT_THROW(a.top(),std::length_error);
}

TEST(Stack, TopWhenOneValue)
{
  STACK <int> a;
  a.push(9);
  ASSERT_EQ( (a.top()) , 9);  
}

TEST(Stack, TopWhenMultipleValues)
{
  STACK <int> a;
  for (int i = 0; i < 10; i++)
    a.push(i);
  ASSERT_EQ( (a.top()), 9);
}

TEST(Stack, PushWhenEmpty)
{
  STACK <int> a;
  a.push(9);
  ASSERT_EQ(1,a.size());
  ASSERT_NOT_NULL(a.getHeadPtr());
  ASSERT_EQ(9,a.getHeadPtr()->m_data);

}

TEST(Stack, PushWhenOneValue)
{
  STACK <int> a;
  a.push(9);
  ASSERT_EQ(1,a.size());
  ASSERT_NOT_NULL(a.getHeadPtr());
  ASSERT_EQ(9,a.getHeadPtr()->m_data);
  
  a.push(10);
  ASSERT_EQ(2,a.size());
  ASSERT_NOT_NULL(a.getHeadPtr());
  ASSERT_EQ(10,a.getHeadPtr()->m_data);
}

TEST(Stack, PushWhenMultipleValues)
{
  STACK <int> a;
  a.push(1);
  for (int i=2; i<10; i++)
  {
    a.push(i);
    ASSERT_EQ(i,a.size());
    ASSERT_NOT_NULL(a.getHeadPtr());
    ASSERT_EQ(i,a.getHeadPtr()->m_data);
  }
}

TEST(Stack, PopWhenEmpty)
{
  STACK <int> a;
  ASSERT_THROW(a.pop(),std::length_error);
}

TEST(Stack, PopWhenOneValue)
{
  STACK <int> a;
  a.push(9);
  a.pop();
  ASSERT_EQ(a.size(), 0);
  ASSERT_NULL(a.getHeadPtr());
}

TEST(Stack, PopWhenMultipleValues)
{
  STACK <int> a;
  for (int i=0; i<100; i++)
    a.push(i);
  for (int i=99; i>-1; i--)
  {
    a.pop();
    ASSERT_FALSE(a.STACK<int>::find(i));
    ASSERT_EQ(i,a.size());
    for (int j=i-1; j>-1; j--)
      ASSERT_TRUE(a.STACK<int>::find(j));
  }
} 