/* file test_set.cpp
 * author Nathan Eloe (nwe5g8@mst.edu)
 * brief The unit tests for the Set class
 */
#include "SET.h"
#include <gtest/gtest.h>

TEST(SetTest, CorrectDefaultSize)
{
  SET<int> a;
  ASSERT_EQ(0,a.size());
}

TEST(SetTest, CorrectDefaultMaxSize)
{
  SET<int> a;
  ASSERT_EQ(20,a.maxSize());
}

TEST(SetTest, InsertSingle)
{
  SET<int> a;
  a.insert(3);
  ASSERT_EQ(1,a.size());
  ASSERT_EQ(20,a.maxSize());
}

TEST(SetTest, InsertMulti)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
  {
    a.insert(i);
    ASSERT_EQ(i+1,a.size());
    ASSERT_EQ(20,a.maxSize());
  }
}

TEST(SetTest,InsertFull)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  ASSERT_THROW(a.insert(42),std::length_error) << "Invalid or no exception";
}

TEST(SetTest, InsertMultipleIdent)
{
  SET<int>a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  a.insert(0);
  ASSERT_EQ(a.maxSize(),a.size());
}

TEST(SetTest, BracketReadNegativeIndex)
{
  SET<int> a;
  ASSERT_THROW(int test = a[-1], std::out_of_range);
}

TEST(SetTest, BracketReadIndexLargerThanSize)
{
  SET<int> a;
  ASSERT_THROW(int test = a[3], std::out_of_range);
}

TEST(SetTest, BracketReadIndexIsSize)
{
  SET<int> a;
  ASSERT_THROW(int test = a[0], std::out_of_range);
}

TEST(SetTest, BracketWriteNegativeIndex)
{
  SET<int> a;
  ASSERT_THROW(a[-1]=1, std::out_of_range);
}

TEST(SetTest, BracketWriteIndexLargerThanSize)
{
  SET<int> a;
  ASSERT_THROW(a[3]=1, std::out_of_range);
}

TEST(SetTest, BracketWriteIndexIsSize)
{
  SET<int> a;
  ASSERT_THROW(a[0]=1, std::out_of_range);
}

TEST(SetTest, Clear)
{
  SET<int> a;
  a.insert(1);
  a.clear();
  ASSERT_EQ(0,a.size());
}

TEST(SetTest, ClearMulti)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
  {
    for (int j=0; j<=i; j++)
      a.insert(j);
    a.clear();
    ASSERT_EQ(0,a.size());
  }
}

TEST(SetTest, ClearEmpty)
{
  SET<int> a;
  a.clear();
  ASSERT_EQ(0,a.size());
}

TEST(SetTest, RemoveFirst)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  a.remove(0);
  ASSERT_EQ(a.maxSize()-1,a.size());
  ASSERT_FALSE(a.find(0));
}

TEST(SetTest, RemoveLast)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  a.remove(a[a.size()-1]);
  ASSERT_EQ(a.maxSize()-1,a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(a.find(i));
}

TEST(SetTest, RemoveMiddle)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  a.remove(5);
  ASSERT_EQ(a.maxSize()-1,a.size());
  for (int i=0; i<a.size(); i++)
  {
    if (i<5)
      ASSERT_EQ(i,a[i]);
    else
      ASSERT_EQ(i+1,a[i]);
  }
}

TEST(SetTest, RemoveOnly)
{
  SET<int> a;
  a.insert(0);
  a.remove(0);
  ASSERT_EQ(0,a.size());
  ASSERT_FALSE(a.find(0));
}

TEST(SetTest, RemoveSome)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  for (int i=0; i<a.maxSize(); i++)
  {
    if (i%2 == 0)
      a.remove(i);
  }
  for (int i=0; i<a.maxSize(); i++)
  {
    if (i%2 == 0)
      ASSERT_FALSE(a.find(i));
    else
      ASSERT_TRUE(a.find(i));
  }
}

TEST(SetTest, FindExist)
{
  SET <int> a;
  a.insert(1);
  ASSERT_TRUE(a.find(1));
}

TEST(SetTest, FindDoesNotExist)
{
  SET<int> a;
  a.insert(1);
  ASSERT_FALSE(a.find(2));
}

TEST(SetTest, UnionNoDuplicates)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize()/2; i++)
  {
    a.insert(i);
    b.insert(b.maxSize()/2+i);
  }
  SET<int>c;
  c = a.setUnion(b);
  ASSERT_EQ(c.size(),c.maxSize());
  for (int i=0; i<a.maxSize(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, UnionWithDuplicates)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize()/2; i++)
  {
    a.insert(i);
    b.insert(b.maxSize()/2+i-1);
  }
  b.insert(b.maxSize()-1);
  SET<int>c;
  c = a.setUnion(b);
  ASSERT_EQ(c.size(),c.maxSize());
  for (int i=0; i<a.maxSize(); i++)
    ASSERT_TRUE(c.find(i));

}

TEST(SetTest, UnionOverflows)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize(); i++)
  {
    a.insert(i);
    b.insert(b.maxSize()+i);
  }
  SET<int>c;
  ASSERT_THROW(c = a.setUnion(b),std::length_error);
}

TEST(SetTest, UnionEmptyNonEmpty)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  SET<int> c;
  c = a.setUnion(b);
  ASSERT_EQ(c.size(),a.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, UnionNonEmptyEmpty)
{
  SET<int> a,b;
  for (int i=0; i<b.maxSize(); i++)
    b.insert(i);
  SET<int> c;
  c = a.setUnion(b);
  ASSERT_EQ(c.size(),b.size());
  for (int i=0; i<b.size(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, UnionEmptyEmpty)
{
  SET<int> a,b,c;
  c = a.setUnion(b);
  ASSERT_EQ(0,c.size());
}

TEST(SetTest, DifferenceNoOverlap)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize(); i++)
  {
    a.insert(i);
    b.insert(b.maxSize()+i);
  }
  SET<int> c;
  c = a.setDiff(b);
  ASSERT_EQ(a.size(),c.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, DifferenceSomeOverlap)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  b.insert(0);
  SET<int> c;
  c = a.setDiff(b);
  ASSERT_EQ(a.maxSize()-1,c.size());
  for (int i=1; i<a.size(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, DifferenceIdentical)
{
  SET<int> a;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  SET<int> c;
  c = a.setDiff(a);
  ASSERT_EQ(0,c.size());
}

TEST(SetTest, DifferenceEmptyNonEmpty)
{
  SET<int> a,b;
  for (int i=0; i<b.maxSize(); i++)
    b.insert(i);
  SET<int> c;
  c = a.setDiff(b);
  ASSERT_EQ(0,c.size());
}

TEST(SetTest, DifferenceNonEmptyEmpty)
{
  SET<int> a,b;
  for (int i=0; i<a.maxSize(); i++)
    a.insert(i);
  SET<int> c;
  c = a.setDiff(b);
  ASSERT_EQ(a.size(),c.size());
  for (int i=0; i<a.size(); i++)
    ASSERT_TRUE(c.find(i));
}

TEST(SetTest, DifferenceEmptyEmpty)
{
  SET<int> a,b,c;
  c = a.setDiff(b);
  ASSERT_EQ(0,c.size());
}

TEST (SetTest, ComparisonNotEqualValues)
{
  SET<int> a,b;
  a.insert(1);
  b.insert(0);
  ASSERT_FALSE(a==b);
}

TEST (SetTest, ComparisonDifferentSizes)
{
  SET<int> a,b;
  a.insert(0);
  b.insert(0);
  b.insert(1);
  ASSERT_FALSE(a==b);
}

TEST(SetTest, ComparisonDifferentOrders)
{
  SET<int> a,b;
  a.insert(0);
  a.insert(1);
  b.insert(1);
  b.insert(0);
  ASSERT_TRUE(a==b);
}

TEST(SetTest, ComparisonEmptyNonEmpty)
{
  SET<int>a,b;
  b.insert(0);
  ASSERT_FALSE(a==b);
}

TEST(SetTest, ComparisonNonEmptyEmpty)
{
  SET<int>a,b;
  a.insert(0);
  ASSERT_FALSE(a==b);
}

TEST(SetTest, ComparisonSameOrder)
{
  SET<int>a,b;
  for (int i=0; i<10; i++)
  {
    a.insert(i);
    b.insert(i);
  }
  ASSERT_TRUE(a==b);
}

TEST(SetTest, Assignment)
{
  SET<int> a,b;
  for (int i=0; i<10; i++)
    b.insert(i);
  a=b;
  ASSERT_TRUE(a==b);
}
