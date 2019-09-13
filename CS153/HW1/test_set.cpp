/* file test_set.cpp
 * author Nathan Eloe (nwe5g8@mst.edu)
 * brief The unit tests for the Set class
 */
#include "set.h"
#include <gtest/gtest.h>

TEST(SetTest, CorrectDefaultSize)
{
  Set<int> a;
  ASSERT_EQ(0,a.size());
}

TEST(SetTest, CorrectDefaultMaxSize)
{
  Set<int> a;
  ASSERT_EQ(20,a.max_size());
}

TEST(SetTest, InsertSingle)
{
  Set<int> a;
  a.insert(3);
  ASSERT_EQ(3,a[0]);
  ASSERT_EQ(1,a.size());
  ASSERT_EQ(20,a.max_size());
}

TEST(SetTest, InsertMulti)
{
  Set<int> a;
  for (int i=0; i<a.max_size(); i++)
  {
    a.insert(i);
    ASSERT_EQ(i,a[i]);
    ASSERT_EQ(i+1,a.size());
    ASSERT_EQ(20,a.max_size());
  }
}

TEST(SetTest,InsertFull)
{
  Set<int> a;
  for (int i=0; i<a.max_size(); i++)
    a.insert(i);
  ASSERT_THROW(a.insert(42),std::length_error) << "Invalid or no exception";
}

TEST(SetTest, InsertMultipleIdent)
{
  /*This test should check to make sure that the set handles multiple
   * duplicate items being inserted
   */
  Set<int> a;
  a.insert(24);
  a.insert(24); 
  ASSERT_EQ(1, a.size());
  ASSERT_EQ(a[0], 24);
}

TEST(SetTest, BracketReadNegativeIndex)
{
  Set<int> a;
  ASSERT_THROW(int test = a[-1], std::out_of_range);
}

TEST(SetTest, BracketReadIndexLargerThanSize)
{
  Set<int> a;
  ASSERT_THROW(int test = a[3], std::out_of_range);
}

TEST(SetTest, BracketReadIndexIsSize)
{
  Set<int> a;
  ASSERT_THROW(int test = a[0], std::out_of_range);
}

TEST(SetTest, BracketWriteNegativeIndex)
{
  Set<int> a;
  ASSERT_THROW(a[-1]=1, std::out_of_range);
}

TEST(SetTest, BracketWriteIndexLargerThanSize)
{
  Set<int> a;
  ASSERT_THROW(a[3]=1, std::out_of_range);
}

TEST(SetTest, BracketWriteIndexIsSize)
{
  Set<int> a;
  ASSERT_THROW(a[0]=1, std::out_of_range);
}

TEST(SetTest, Clear)
{
  Set<int> a;
  a.insert(1);
  a.clear();
  ASSERT_EQ(0,a.size());
}

TEST(SetTest, ClearMulti)
{
  Set<int> a;
  for (int i=0; i<a.max_size(); i++)
  {
    for (int j=0; j<=i; j++)
      a.insert(j);
    a.clear();
    ASSERT_EQ(0,a.size());
  }
}

TEST(SetTest, ClearEmpty)
{
  Set<int> a;
  a.clear();
  ASSERT_EQ(0,a.size());
}

TEST(SetTest, RemoveFirst)
{
  Set <int> a;
  for (int i=0; i<a.max_size(); i++)
    a.insert(i);
  a.remove(0);
  ASSERT_EQ(a.max_size()-1,a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_EQ(i+1,a[i]);
}

TEST(SetTest, RemoveLast)
{
  Set <int> a;
  for (int i=0; i<a.max_size(); i++)
    a.insert(i);
  a.remove(a[a.size()-1]);
  ASSERT_EQ(a.max_size()-1,a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_EQ(i,a[i]);
}

TEST(SetTest, RemoveMiddle)
{
  Set<int> a;
  for (int i=0; i<a.max_size(); i++)
    a.insert(i);
  a.remove(5);
  ASSERT_EQ(a.max_size()-1,a.size());
  for (int i=0; i<a.size(); i++)
  {
    if (i<5)
      ASSERT_EQ(i,a[i]);
    else
      ASSERT_EQ(i+1,a[i]);
  }
}

TEST(SetTest, FindExist)
{
  /*This test should check to make sure that find returns true
   * when the element is in the set
   */
  Set<int> a;
  for(int i = 0; i < 10; i++)
    a.insert(i*2);
  ASSERT_TRUE(a.find(4));
}

TEST(SetTest, FindDoesNotExist)
{
  /*This test should check to make sure that find returns false
   * when the element is in the set
   */
  Set<int> a;
  for(int i = 0; i < 10; i++)
    a.insert(i*2);
  ASSERT_FALSE(a.find(3));
}

TEST(SetTest, UnionNoDuplicates)
{
  Set <int> a,b;
  for (int i=0; i<a.max_size()/2; i++)
  {
    a.insert(i);
    b.insert(b.max_size()/2+i);
  }
  Set<int>c;
  c = a.set_union(b);
  ASSERT_EQ(c.size(),c.max_size());
  for (int i=0; i<a.max_size(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, UnionWithDuplicates)
{
  /*This test should be similar to UnionWithoutDuplicates
   * It should test to make sure the set_union function works when
   * the two sets being unioned have duplicate item
   */
  Set<int> a,b,c;
  for(int i=0; i<a.max_size(); i++)
  {
    a.insert(i);
    b.insert(i);
  }
  c = a.set_union(b);
  ASSERT_EQ(c.size(),c.max_size());
  for (int i=0; i<a.max_size(); i++)
    ASSERT_TRUE(c.find(i));

}

TEST(SetTest, UnionOverflows)
{
  /*This test should check to make sure the appropriate exception
   * is thrown when the set_union function attempts to make a set that is
   * too large
   */
   Set<int> a,b,c;
  for(int i=0; i<a.max_size(); i++)
  {
    a.insert(i);
    b.insert(i+1);
  }
  ASSERT_THROW(c = a.set_union(b), std::length_error);
}

TEST(SetTest, UnionEmptyNonEmpty)
{
  Set<int> a,b;
  for (int i=0; i<a.max_size(); i++)
    a.insert(i);
  Set <int> c;
  c = a.set_union(b);
  ASSERT_EQ(c.size(),a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(a[i]));
}

TEST(SetTest, UnionNonEmptyEmpty)
{
  /*Similar to UnionEmptyNonEmpty
   * Tests to make sure that a.set_union(b) works when a is empty
   */
  Set<int> a,b;
  for (int i=0; i<b.max_size(); i++)
    b.insert(i);
  Set <int> c;
  c = a.set_union(b);
  ASSERT_EQ(c.size(),a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(a[i]));

}

TEST(SetTest, UnionEmptyEmpty)
{
  /*Test to make sure two empty sets unioned together form an empty set.
   * An empty set has m_size==0
   */
  Set<int> a,b;
  Set <int> c;
  c = a.set_union(b);
  ASSERT_EQ(c.size(),a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(a[i]));

}

TEST(SetTest, DifferenceNoOverlap)
{
  Set<int> a,b;
  for (int i=0; i<a.max_size(); i++)
  {
    a.insert(i);
    b.insert(b.max_size()+i);
  }
  Set <int> c;
  c = a.set_diff(b);
  ASSERT_EQ(a.size(),c.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(a[i]));
}

TEST(SetTest, DifferenceSomeOverlap)
{
  /*Tests to make sure that the set_diff function works
   * when there is some overlap between the sets being diff'd
   */
  Set<int> a,b;
  for (int i=0; i<a.max_size()/2; i++)
  {
    a.insert(i);
    b.insert(i*2);
  }
  Set <int> c;
  c = a.set_diff(b);
  ASSERT_EQ(c.size(), a.max_size()/4);
  for (int i=0; i<c.size(); i++)
    ASSERT_TRUE(c.find(i*2 + 1));
}

TEST(SetTest, DifferenceIdentical)
{
  /*Tests to make sure that taking the difference of two identical
   * sets returns an empty set
   */
   Set<int> a,b;
  for (int i=0; i<a.max_size(); i++)
  {
    a.insert(i);
    b.insert(i);
  }
  Set <int> c;
  c = a.set_diff(b);
  ASSERT_EQ(c.size(), 0);
}

TEST(SetTest, DifferenceEmptyNonEmpty)
{
  Set<int> a,b;
  for (int i=0; i<b.max_size(); i++)
    b.insert(i);
  Set<int> c;
  c = a.set_diff(b);
  ASSERT_EQ(0,c.size());
}

TEST(SetTest, DifferenceNonEmptyEmpty)
{
  /*This test should make sure that the difference of a Nonempty and empty
   * set produces the first set.
   * Will be similar to DifferenceEmptyNonEmpty test
   */
  Set<int> a,b;
  for (int i=0; i<a.max_size(); i++)
    a.insert(i);
  Set<int> c;
  c = a.set_diff(b);
  ASSERT_EQ(a.size(),c.size());
}

TEST(SetTest, DifferenceEmptyEmpty)
{
  /*This test should make sure that the difference of two empty sets
   * is an empty set.
   */
  Set<int> a,b;
  Set<int> c;
  c = a.set_diff(b);
  ASSERT_EQ(0,c.size());
}
