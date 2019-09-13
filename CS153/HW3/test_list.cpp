/*!\file test_LINKED_LIST.cpp
 * \author Nathan Eloe
 * \brief Tests for the linked LINKED_LIST class
 */

#include <gtest/gtest.h>
#include "LINKED_LIST.h"
#include "NODE.h"
//For readability, we're going to define an ASSERT_NULL macro
#define ASSERT_NULL ASSERT_FALSE
#define ASSERT_NOT_NULL ASSERT_TRUE

TEST(LinkedList, DefaultConstructor)
{
  LINKED_LIST <int> a;
  ASSERT_EQ(0,a.getNumUsed());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedList, CopyConstructor)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LINKED_LIST<int> b(a);
  ASSERT_EQ(a.getNumUsed(), b.getNumUsed());
  //Make sure the head and tail match
  NODE<int>* currA = a.getHeadPtr();
  NODE<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->getData(),currB->getData());
    currA=currA->getNext();
    currB=currB->getNext();
  }
}

TEST(LinkedList, CopyConstructorEmpty)
{
  LINKED_LIST <int> a;
  LINKED_LIST <int> b(a);
  ASSERT_NULL(b.getHeadPtr());
  ASSERT_NULL(b.getTailPtr());
  ASSERT_EQ(0,b.getNumUsed());
}

TEST(LinkedList, ClearWhenEmpty)
{
  LINKED_LIST<int> a;
  a.clear();
  ASSERT_EQ(0,a.getNumUsed());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedList, ClearWhenNotEmpty)
{
  LINKED_LIST<int> a;
  for (int i=0; i<100; i++)
    a.insertAtHead(i);
  a.clear();
  ASSERT_EQ(0,a.getNumUsed());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedList, InsertOneAtHead)
{
  LINKED_LIST <int> a;
  a.insertAtHead(1);
  ASSERT_EQ(1,a.getNumUsed());
  ASSERT_NOT_NULL(a.getHeadPtr());
  ASSERT_NOT_NULL(a.getTailPtr());
  ASSERT_EQ(1,a.getHeadPtr()->getData());
  ASSERT_EQ(1,a.getTailPtr()->getData());
}

TEST(LinkedList, InsertManyAtHead)
{
  LINKED_LIST <int> a;
  a.insertAtHead(1);
  for (int i=2; i<100; i++)
  {
    a.insertAtHead(i);
    ASSERT_EQ(i,a.getNumUsed());
    ASSERT_NOT_NULL(a.getHeadPtr());
    ASSERT_NOT_NULL(a.getTailPtr());
    ASSERT_EQ(i,a.getHeadPtr()->getData());
    ASSERT_EQ(1,a.getTailPtr()->getData());
  }
}

TEST(LinkedList, InsertOneAtTail)
{
  LINKED_LIST <int> a;
  a.insertAtTail(1);
  ASSERT_EQ(1,a.getNumUsed());
  ASSERT_NOT_NULL(a.getHeadPtr());
  ASSERT_NOT_NULL(a.getTailPtr());
  ASSERT_EQ(1,a.getHeadPtr()->getData());
  ASSERT_EQ(1,a.getTailPtr()->getData());
}

TEST(LinkedList, InsertManyAtTail)
{
  LINKED_LIST <int> a;
  a.insertAtTail(1);
  for (int i=2; i<100; i++)
  {
    a.insertAtTail(i);
    ASSERT_EQ(i,a.getNumUsed());
    ASSERT_NOT_NULL(a.getHeadPtr());
    ASSERT_NOT_NULL(a.getTailPtr());
    ASSERT_EQ(i,a.getTailPtr()->getData());
    ASSERT_EQ(1,a.getHeadPtr()->getData());
  }
}

TEST(LinkedList, RemoveFirstOnly)
{
  LINKED_LIST <int> a;
  a.insertAtHead(1);
  ASSERT_TRUE(a.removeFirstOccurrence(1));
  ASSERT_EQ(0,a.getNumUsed());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getTailPtr());
}

TEST(LinkedList, RemoveFirstNotInList)
{
  LINKED_LIST<int> a;
  ASSERT_FALSE(a.removeFirstOccurrence(1));
}

TEST(LinkedList, RemoveFirstHead)
{
  LINKED_LIST <int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  for (int i=9; i>=0; i--)
  {
    ASSERT_TRUE(a.removeFirstOccurrence(i));
    ASSERT_EQ(i, a.getNumUsed());
    if (i>0)
      ASSERT_EQ(i-1, a.getHeadPtr()->getData());
    else if (i==0)
    {
      ASSERT_NULL(a.getHeadPtr());
      ASSERT_NULL(a.getTailPtr());
    }
  }
}

TEST(LinkedList, RemoveFirstTail)
{
  LINKED_LIST <int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  for (int i=0; i<10; i++)
  {
    ASSERT_TRUE(a.removeFirstOccurrence(i));
    ASSERT_EQ(9-i, a.getNumUsed());
    if (i<9)
      ASSERT_EQ(i+1, a.getTailPtr()->getData());
    else if (i==0)
    {
      ASSERT_NULL(a.getHeadPtr());
      ASSERT_NULL(a.getTailPtr());
    }
  }
}

TEST(LinkedList, RemoveFirstMiddle)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtTail(i);
  ASSERT_TRUE(a.removeFirstOccurrence(5));
  ASSERT_EQ(9,a.getNumUsed());
  int i=0;
  NODE<int>* currA = a.getHeadPtr();
  while (currA)
  {
    ASSERT_EQ(i,currA->getData());
    currA=currA->getNext();
    i++;
    if (i==5)
      i++;
  }
}

TEST(LinkedList, RemoveAllNotInList)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_EQ(0,a.removeAllOccurrences(11));
  ASSERT_EQ(10,a.getNumUsed());
}

TEST(LinkedList, RemoveAllAllInList)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(1);
  ASSERT_EQ(10,a.removeAllOccurrences(1));
  ASSERT_EQ(0,a.getNumUsed());
  ASSERT_NULL(a.getHeadPtr());
  ASSERT_NULL(a.getHeadPtr());
}

TEST(LinkedList, RemoveAllSomeInList)
{
  LINKED_LIST <int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i%2);
  ASSERT_EQ(5,a.removeAllOccurrences(1));
  ASSERT_EQ(5,a.getNumUsed());
  ASSERT_EQ(0,a.getHeadPtr()->getData());
  ASSERT_EQ(0,a.getTailPtr()->getData());
}

TEST(LinkedList, IsEmptyWhenEmpty)
{
  LINKED_LIST<int>a;
  ASSERT_TRUE(a.isEmpty());
}

TEST(LinkedList, IsEmptyWhenNotEmpty)
{
  LINKED_LIST<int>a;
  a.insertAtHead(1);
  ASSERT_FALSE(a.isEmpty());
}

TEST(LinkedList, AssignmentOperator)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LINKED_LIST<int> b;
  b=a;
  ASSERT_EQ(a.getNumUsed(), b.getNumUsed());
  //Make sure the head and tail match
  ASSERT_EQ(a.getHeadPtr()->getData(), b.getHeadPtr()->getData());
  ASSERT_EQ(a.getTailPtr()->getData(), b.getTailPtr()->getData());
  NODE<int>* currA = a.getHeadPtr();
  NODE<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->getData(),currB->getData());
    currA=currA->getNext();
    currB=currB->getNext();
  }
}

TEST(LinkedList, AssignmentOperatorSelfAssignment)
{
  LINKED_LIST<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  a=a;
  //Make sure we didn't delete ourselves :/
  ASSERT_EQ(9,a.getHeadPtr()->getData());
  ASSERT_EQ(0,a.getTailPtr()->getData());
  NODE<int>* currA = a.getHeadPtr();
  NODE<int>* currB = a.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->getData(),currB->getData());
    currA=currA->getNext();
    currB=currB->getNext();
  }
}

TEST(LinkedList, EqualityAreEqual)
{
  LINKED_LIST<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LINKED_LIST<int>b(a);
  ASSERT_TRUE(b==a);
}

TEST(LinkedList, EqualityAreSame)
{
  LINKED_LIST<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_TRUE(a==a);
}

TEST(LinkedList, EqualityAreNotTheSame)
{
  LINKED_LIST<int>a,b;
  for (int i=0; i<10; i++)
  {
    a.insertAtHead(i);
    b.insertAtHead(i+1);
  }
  ASSERT_FALSE(a==b);
}

TEST(LinkedList, EqualityEmptyNonEmpty)
{
  LINKED_LIST<int>a,b;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_FALSE(b==a);
}

TEST(LinkedList, EqualityNonEmptyEmpty)
{
  LINKED_LIST<int>a,b;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_FALSE(a==b);
}
