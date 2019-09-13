/*
 * test_hashtable.cpp
 *
 *  Created on: Dec 6, 2011
 *      Author: Owner
 */
/*
#include "HASHTABLE.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
using namespace std;

TEST(HASHTest, DefaultConstructorWithSameTypes)
{
  HASHTABLE <int, int> h;
  ASSERT_EQ(0, h.size());
  ASSERT_TRUE(h.isEmpty());
  ASSERT_FALSE(h.find(42));
}

TEST(HASHTest, DefaultConstructorBadAlloc)
{
	ASSERT_THROW(HASHTABLE<int, int> h(0));
}

TEST(HASHTest, DefaultConstructorWithDifferentTypes)
{
  HASHTABLE <int, char> h;
  ASSERT_EQ(0, h.size());
  ASSERT_TRUE(h.isEmpty());
  ASSERT_FALSE(h.find(42));
}

TEST(HASHTest, ClearWhenEmpty)
{
	HASHTABLE<int, int> h;
	h.clear();
	ASSERT_EQ(0, h.size());
}

TEST(HASHTest, InsertOneNoLinearProbing)
{
	HASHTABLE<int, int> h;
	h.insert(2,42);
	ASSERT_TRUE(h.find(42));
}

TEST(HASHTest, InsertSameKeyOverride)
{
	HASHTABLE<int,int> h;
	h.insert(2,24); h.insert(2,42);
	ASSERT_TRUE(h.find(42));
	ASSERT_FALSE(h.find(24));
}

TEST(HASHTest, InsertManyNoLinearProbingNoMod)
{
	HASHTABLE<int, int> h;
	h.insert(2,42);
	ASSERT_TRUE(h.find(42));
	ASSERT_TRUE(h.find(2, 2));
}

TEST(HASHTest, InsertManyNoLinearProbingWithMod)
{
	HASHTABLE<int, int> h;
	h.insert(102,42);
	ASSERT_TRUE(h.find(42));
	ASSERT_TRUE(h.find(102, 2));
}

TEST(HASHTest, InsertTwoWithLinearProbing)
{
	HASHTABLE<int, int> h1, h2;
	h1.insert(2,42); h2.insert(102,24)
	ASSERT_TRUE(h1.find(42));
	ASSERT_TRUE(h1.find(2, 2));
	ASSERT_TRUE(h2.find(24));
	ASSERT_TRUE(h2.find(102,3));
}

TEST(HASHTest, InsertManyWithLinearProbing)
{
	HASHTABLE<int, int> h1;
	int sum = 0;
	for(int i =0; i < h1.DEFAULT_CAPACITY; i++)
	{
		h1.insert(sum,i);
		ASSERT_TRUE(h1.find(i));
		ASSERT_TRUE(h1.find(sum, i));
		sum += DEFAULT_CAPACITY;
	}
}

TEST(HASHTest, RemoveWhileEmpty)
{
	HASHTABLE<int, int> h;
	h.remove(42);
	ASSERT_EQ(0, h.size());
}

TEST(HASHTest, RemoveNotEmptySameKey)
{
	HASHTABLE<int, int> h;
	h.insert(2,2);
	h.remove(2);
	ASSERT_EQ(0, h.size());
}

TEST(HASHTest, RemoveNotEmptyDifferentKey)
{
	HASHTABLE<int,int> h;
	h.insert(2,2);
	h.remove(3);
	ASSERT_EQ(1,h.size());
}

TEST(HASHTest, RemoveNotEmptyMod)
{
	HASHTABLE<int,int>h;
	h.insert(102,2);
	ASSERT_TRUE(h.find(102));
	h.remove(2);
	ASSERT_EQ(0,h.size());
}

TEST(HASHTest, RemoveNotEmptyMultipleRemoves)
{
	HASHTABLE<int, int> h;
	h.insert(2,3);
	h.insert(3,4);
	h.insert(4,5);
	h.remove(2,3);
	ASSERT_EQ(2,h.size());
	ASSERT_FALSE(h.find(3));
	ASSERT_FALSE(h.find(2,2));
	h.remove(3,4);
	ASSERT_EQ(1,h.size());
	ASSERT_FALSE(h.find(4));
	ASSERT_FALSE(h.find(3,3));
	h.remove(4,5);
	ASSERT_EQ(0,h.size());
	ASSERT_FALSE(h.find(5));
	ASSERT_FALSE(h.find(4,4));
}

TEST(HASHTest, RemoveNotEmptyMultipleRemovesNoLinearProbing)
{
	HASHTABLE<int,int> h;
	
	for(int i =0; i < h.DEFAULT_CAPACITY; i++)
	{
		h.insert(i,i);
		ASSERT_TRUE(h.find(i));
		ASSERT_TRUE(h.find(i, i));
		h.remove(i);
		ASSERT_FALSE(h.find(i));
		ASSERT_FALSE(h.find(i, i));
	}
}

TEST(HASHTest, RemoveNotEmptyMultipleRemovesLinearProbing)
{
	HASHTABLE<int, int> h;
	int sum = 0;

	for(int i =0; i < h.DEFAULT_CAPACITY; i++)
	{
		h.insert(sum,i);
		ASSERT_TRUE(h.find(i));
		ASSERT_TRUE(h.find(sum, i));
	}
	
	
	for(int j =0; j < h.DEFAULT_CAPACITY; j++)
	{
		h.remove(sum);
		ASSERT_FALSE(h.find(j));
		ASSERT_FALSE(h.find(sum,j));
	}
}

TEST(HASHTest, BracketFind)
{
	HASHTABLE<int, int> h;
	h.insert(2,3);
	h.insert(3,4);
	h.insert(4,5);
	
	ASSERT_EQ(3, h[2]);
	ASSERT_EQ(4, h[3]);
	ASSERT_EQ(5, h[4]);
}

TEST(HASHTest, BracketCannotFind)
{
	HASHTABLE<int, int> h;
	h.insert(2,3);
	
	ASSERT_EQ(0, h[1]);
	ASSERT_EQ(0, h[3]);
}

TEST(HASHTest, IteratorCanFind)
{
	HASHTABLE<int, int> h;
	h.insert(0,1);
	h.insert(1,2);
	h.insert(2,3);
	
	h.iteratorReset();
	
	ASSERT_EQ(1, h.iteratorGetNext());
	ASSERT_EQ(2, h.iteratorGetNext());
	ASSERT_EQ(3, h.iteratorGetNext());
}

TEST(HASHTest, IteratorWrapAround)
{
	HASHTABLE<int, int> h(3);
	h.insert(0,1);
	h.insert(1,2);
	h.insert(2,3);
	
	h.iteratorReset();
	
	ASSERT_EQ(1, h.iteratorGetNext());
	ASSERT_EQ(2, h.iteratorGetNext());
	ASSERT_EQ(3, h.iteratorGetNext());
	ASSERT_EQ(1, h.iteratorGetNext());
}*/
