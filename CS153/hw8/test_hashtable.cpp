/*
 * test_hashtable.cpp
 *
 *  Created on: Dec 6, 2011
 *      Author: Owner
 */

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

/*TEST(HASHTest, DefaultConstructorBadAlloc)
{
	ASSERT_THROW(HASHTABLE<int, int> h(0), std::bad_alloc);
}
*/
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
	int key = 2;
	h.insert(key,42);
	ASSERT_TRUE(h.find(42));
	ASSERT_TRUE(h.find(key, key));
}

TEST(HASHTest, InsertManyNoLinearProbingWithMod)
{
	HASHTABLE<int, int> h;
	int key = 102;
	int position = 2;
	h.insert(key,42);
	ASSERT_TRUE(h.find(42));
	ASSERT_TRUE(h.find(key, position));
}

TEST(HASHTest, InsertTwoWithLinearProbing)
{
	HASHTABLE<int, int> h1, h2;
	int key1 = 2;
	int key2 = 102;
	int position1 = 2;
	int position2 = 3;
	h1.insert(key1,42); h2.insert(key2,24);
	ASSERT_TRUE(h1.find(42));
	ASSERT_TRUE(h1.find(key1, position1));
	ASSERT_TRUE(h2.find(24));
	ASSERT_TRUE(h2.find(key2,position2));
}

TEST(HASHTest, InsertManyWithLinearProbing)
{
	HASHTABLE<int, int> h1;
	int sum = 0;
	for(int i =0; i < DEFAULT_CAPACITY; i++)
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
	int key1 =2, key2 = 3, key3 = 4;
	int pos1 =2, pos2 = 3, pos3 = 4;
	HASHTABLE<int, int> h;
	h.insert(key1,3);
	h.insert(key2,4);
	h.insert(key3,5);
	h.remove(2);
	ASSERT_EQ(2,h.size());
	ASSERT_FALSE(h.find(3));
	ASSERT_FALSE(h.find(key1,pos1));
	h.remove(3);
	ASSERT_EQ(1,h.size());
	ASSERT_FALSE(h.find(4));
	ASSERT_FALSE(h.find(key2,pos2));
	h.remove(4);
	ASSERT_EQ(0,h.size());
	ASSERT_FALSE(h.find(5));
	ASSERT_FALSE(h.find(key3,pos3));
}

TEST(HASHTest, RemoveNotEmptyMultipleRemovesNoLinearProbing)
{
	HASHTABLE<int,int> h;
	
	for(int i =0; i < DEFAULT_CAPACITY; i++)
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

	for(int i =0; i < DEFAULT_CAPACITY; i++)
	{
		h.insert(sum,i);
		ASSERT_TRUE(h.find(i));
		ASSERT_TRUE(h.find(sum, i));
	}
	
	
	for(int j =0; j < DEFAULT_CAPACITY; j++)
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
}












