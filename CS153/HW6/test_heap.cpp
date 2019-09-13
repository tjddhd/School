/*!\file test_heap.cpp
 * \author Nathan Eloe
 * \brief Test cases for the BST class
 */

#include "HEAP.h"
#include "BNODE.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isSorted(vector<int> v)
{
  for (int i=0; i<v.size()-1; i++)
    if (v[i]>v[i+1])
      return false;
  return true;
}

bool maxHeapnessHolds(BNODE<int>* n)
{
  if (n==NULL) //odd case, whatevs
    return true;
  if (n->m_left == NULL && n->m_right == NULL)
    return true;
  if (n->m_left == NULL)
    return n->m_data>=n->m_right->m_data && maxHeapnessHolds(n->m_right);
  if (n->m_right == NULL)
    return n->m_data>=n->m_left->m_data && maxHeapnessHolds(n->m_left);
  return n->m_data >= n->m_left->m_data && maxHeapnessHolds(n->m_left) &&
    n->m_data >= n->m_right->m_data && maxHeapnessHolds(n->m_right);
}

bool minHeapnessHolds(BNODE<int>* n)
{
  if (n==NULL) //odd case, whatevs
    return true;
  if (n->m_left == NULL && n->m_right == NULL)
    return true;
  if (n->m_left == NULL)
    return n->m_data<=n->m_right->m_data && minHeapnessHolds(n->m_right);
  if (n->m_right == NULL)
    return n->m_data<=n->m_left->m_data && minHeapnessHolds(n->m_left);
  return n->m_data <= n->m_left->m_data && minHeapnessHolds(n->m_left) &&
    n->m_data <= n->m_right->m_data && minHeapnessHolds(n->m_right);
}


// Note: Need to test for both a MIN heap and a MAX heap!!!

TEST (MaxHeapTest, DefaultConstructor)
{
  HEAP<int> heap;
  ASSERT_EQ(0, heap.size());
  ASSERT_EQ(0, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
}

TEST (MaxHeapTest, SingleInsert)
{
  HEAP<int> heap;
  heap.insert(42);
  ASSERT_EQ(1, heap.size());
  ASSERT_EQ(1, heap.height(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_TRUE(heap.isFull(heap.getRoot()));
}

TEST (MaxHeapTest, Insert2NoSwap)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  ASSERT_EQ(2, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
}

TEST (MaxHeapTest, Insert2Swap)
{
  HEAP<int> heap;
  heap.insert(21);
  heap.insert(42);
  ASSERT_EQ(2, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("21 (1), 42 (2)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, Insert3NoSwap)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  ASSERT_EQ(3, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_TRUE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("21 (1), 42 (3), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, Insert3Swap)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(66);
  ASSERT_EQ(3, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_TRUE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("21 (1), 66 (3), 42 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, Insert4NoSwap)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(17);
  ASSERT_EQ(4, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("17 (1), 21 (2), 42 (4), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, Insert4Swap)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(66);
  ASSERT_EQ(4, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("21 (1), 42 (2), 66 (4), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, InsertMultiNoSwap)
{
  HEAP<int> heap;
  int n = 16;
  for (int i = n; i >= 1; i--)
    heap.insert(i);
  ASSERT_EQ(n, heap.size());
  ASSERT_EQ(5, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("1 (1), 9 (2), 13 (4), 8 (1), 15 (8), 7 (1), 12 (3), 6 (1), 16 (16), 5 (1), 11 (3), 4 (1), 14 (7), 3 (1), 10 (3), 2 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, InsertMultiSwap)
{
  HEAP<int> heap;
  int n = 8;
  for (int i = 1; i <= n; i++)
    heap.insert(i);
  ASSERT_EQ(n, heap.size());
  ASSERT_EQ(4, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("1 (1), 4 (2), 7 (4), 3 (1), 8 (8), 2 (1), 6 (3), 5 (1)",heap.toStringInorder().c_str());
}

TEST(MaxHeapTest, InsertManySomeSwapSomeNot)
{
  srand(time(NULL));
  HEAP<int> heap;
  for (int i=0; i<10000; i++)
  {
    heap.insert(random());
    ASSERT_TRUE(maxHeapnessHolds(heap.getRoot()));
  }
}

TEST (MaxHeapTest, RemoveEmpty)
{
  HEAP<int> heap;
  ASSERT_FALSE(heap.removeRoot());
}

TEST (MaxHeapTest, RemoveWhen1)
{
  HEAP<int> heap;
  heap.insert(42);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(0, heap.size());
  ASSERT_EQ(0, heap.height(heap.getRoot()));
}

TEST (MaxHeapTest, RemoveWhen2)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(1, heap.size());
  ASSERT_EQ(1, heap.height(heap.getRoot()));
  ASSERT_STREQ("21 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, RemoveWhen3)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(2, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_STREQ("21 (1), 24 (2)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, RemoveWhen4)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(10);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(3, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_STREQ("21 (1), 24 (3), 10 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, RemoveWhen5)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(10);
  heap.insert(12);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(4, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_STREQ("10 (1), 21 (2), 24 (4), 12 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, RemoveWhen6)
{
  HEAP<int> heap;
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(10);
  heap.insert(12);
  heap.insert(20);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(5, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_STREQ("10 (1), 21 (3), 12 (1), 24 (5), 20 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, RemoveWhenMany)
{
  HEAP<int> heap;
  int n = 8;
  for (int i = n; i > 0; i--)
    heap.insert(i);
  ASSERT_TRUE(heap.removeRoot()); 
  ASSERT_EQ(n-1, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_STREQ("1 (1), 5 (3), 4 (1), 7 (7), 3 (1), 6 (3), 2 (1)",heap.toStringInorder().c_str());
}

TEST (MaxHeapTest, RemovePreservesHeapness)
{
  srand(time(NULL));
  HEAP<int> heap;
  vector<int> v;
  for (int i=0; i<1000; i++)
    heap.insert(random());
  //we're dealing with a max heap, so the values should
  //come off in descending order (reverse sorted)
  v.push_back(heap.getRoot()->m_data);
  while (heap.size()>0)
  {
    v.insert(v.begin(),heap.getRoot()->m_data);
    heap.removeRoot();
  }
  ASSERT_TRUE(isSorted(v));

}

// Note: Need to test for both a MIN heap and a MAX heap!!!

TEST (MinHeapTest, DefaultConstructor)
{
  HEAP<int> heap(false);
  ASSERT_EQ(0, heap.size());
  ASSERT_EQ(0, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
}

TEST (MinHeapTest, SingleInsert)
{
  HEAP<int> heap(false);
  heap.insert(42);
  ASSERT_EQ(1, heap.size());
  ASSERT_EQ(1, heap.height(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_TRUE(heap.isFull(heap.getRoot()));
}

TEST (MinHeapTest, Insert2Swap)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  ASSERT_EQ(2, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
}

TEST (MinHeapTest, Insert2NoSwap)
{
  HEAP<int> heap(false);
  heap.insert(21);
  heap.insert(42);
  ASSERT_EQ(2, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (2)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, Insert3Swap)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  ASSERT_EQ(3, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_TRUE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (3), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, Insert3NoSwap)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(66);
  ASSERT_EQ(3, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_TRUE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (3), 66 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, Insert4Swap)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(17);
  ASSERT_EQ(4, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (2), 17 (4), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, Insert4NoSwap)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(66);
  ASSERT_EQ(4, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("66 (1), 42 (2), 21 (4), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, InsertMultiSwap)
{
  HEAP<int> heap(false);
  int n = 16;
  for (int i = n; i >= 1; i--)
    heap.insert(i);
  ASSERT_EQ(n, heap.size());
  ASSERT_EQ(5, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("16 (1), 10 (2), 7 (4), 13 (1), 2 (8), 14 (1), 8 (3), 9 (1), 1 (16), 15 (1), 6 (3), 11 (1), 3 (7), 12 (1), 4 (3), 5 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, InsertMultiNoSwap)
{
  HEAP<int> heap(false);
  int n = 8;
  for (int i = 1; i <= n; i++)
    heap.insert(i);
  ASSERT_EQ(n, heap.size());
  ASSERT_EQ(4, heap.height(heap.getRoot()));
  ASSERT_FALSE(heap.isFull(heap.getRoot()));
  ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  ASSERT_STREQ("8 (1), 4 (2), 2 (4), 5 (1), 1 (8), 6 (1), 3 (3), 7 (1)",heap.toStringInorder().c_str());
}

TEST(MinHeapTest, InsertManySomeSwapSomeNot)
{
  srand(time(NULL));
  HEAP<int> heap(false);
  for (int i=0; i<10000; i++)
  {
    heap.insert(random());
    ASSERT_TRUE(minHeapnessHolds(heap.getRoot()));
  }
}

TEST (MinHeapTest, RemoveEmpty)
{
  HEAP<int> heap(false);
  ASSERT_FALSE(heap.removeRoot());
}

TEST (MinHeapTest, RemoveWhen1)
{
  HEAP<int> heap(false);
  heap.insert(42);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(0, heap.size());
  ASSERT_EQ(0, heap.height(heap.getRoot()));
}

TEST (MinHeapTest, RemoveWhen2)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(1, heap.size());
  ASSERT_EQ(1, heap.height(heap.getRoot()));
  ASSERT_STREQ("42 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, RemoveWhen3)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(2, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_STREQ("42 (1), 24 (2)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, RemoveWhen4)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(10);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(3, heap.size());
  ASSERT_EQ(2, heap.height(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (3), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, RemoveWhen5)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(10);
  heap.insert(12);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(4, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (2), 12 (4), 24 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, RemoveWhen6)
{
  HEAP<int> heap(false);
  heap.insert(42);
  heap.insert(21);
  heap.insert(24);
  heap.insert(10);
  heap.insert(12);
  heap.insert(20);
  ASSERT_TRUE(heap.removeRoot());
  ASSERT_EQ(5, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_STREQ("42 (1), 21 (3), 24 (1), 12 (5), 20 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, RemoveWhenMany)
{
  HEAP<int> heap(false);
  int n = 8;
  for (int i = n; i > 0; i--)
    heap.insert(i);
  ASSERT_TRUE(heap.removeRoot()); 
  ASSERT_EQ(n-1, heap.size());
  ASSERT_EQ(3, heap.height(heap.getRoot()));
  ASSERT_STREQ("8 (1), 5 (3), 6 (1), 2 (7), 7 (1), 3 (3), 4 (1)",heap.toStringInorder().c_str());
}

TEST (MinHeapTest, RemovePreservesHeapness)
{
  srand(time(NULL));
  HEAP<int> heap(false);
  vector<int> v;
  for (int i=0; i<1000; i++)
    heap.insert(random());
  //we're dealing with a max heap, so the values should
  //come off in descending order (reverse sorted)
  v.push_back(heap.getRoot()->m_data);
  while (heap.size()>0)
  {
    v.push_back(heap.getRoot()->m_data);
    heap.removeRoot();
  }
  ASSERT_TRUE(isSorted(v));

}

//Assignment and comparison are generic, so we'll test them once

TEST(HeapTest, testCompareTrue)
{
  HEAP<int> h1, h2;
  for (int i=0; i<50; i++)
  {
    h1.insert(i);
    h2.insert(i);
  }
  ASSERT_TRUE(h1==h2);
}

TEST(HeapTest, testCompareFalse)
{
  //make one a min heap, so the trees will inherently be different
  HEAP<int> h1, h2(false);
  for (int i=0; i<50; i++)
  {
    h1.insert(i);
    h2.insert(i);
  }
  ASSERT_FALSE(h1==h2);
}
TEST(HeapTest, testAssignment)
{
  HEAP<int> h1, h2;
  for (int i=0; i<100; i++)
    h1.insert(i);
  h2=h1;
  ASSERT_TRUE(h1==h2);
}

TEST(HeapTest, testAssignmentSelf)
{
  HEAP<int> h1;
  for (int i=0; i<100; i++)
    h1.insert(i);
  h1=h1;
  //Make sure we didn't free ourselves :/
  ASSERT_EQ(100,h1.size());
}

TEST(HeapTest, testAssignmentEmpty)
{
  HEAP<int> h1,h2;
  for (int i=0; i<100; i++)
    h1.insert(i);
  h1=h2;
  ASSERT_TRUE(h1==h2);
}

