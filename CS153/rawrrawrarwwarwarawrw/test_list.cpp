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
  ASSERT_EQ(0,a.size()) << "\n** Bad DefaultConstructor: -2\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad DefaultConstructor: -2\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad DefaultConstructor: -2\n";
}

TEST(LinkedList, CopyConstructor)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LINKED_LIST<int> b(a);
  ASSERT_EQ(a.size(), b.size()) << "\n** Bad CopyConstructor: -2\n";
  //Make sure the head and tail match
  NODE<int>* currA = a.getHeadPtr();
  NODE<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data)<< "\n** Bad CopyConstructor: -2\n";
    currA=currA->m_next;
    currB=currB->m_next;
  }
}

TEST(LinkedList, CopyConstructorEmpty)
{
  LINKED_LIST <int> a;
  LINKED_LIST <int> b(a);
  ASSERT_NULL(b.getHeadPtr())<< "\n** Bad CopyConstructorEmpty: -2\n";
  ASSERT_NULL(b.getTailPtr())<< "\n** Bad CopyConstructorEmpty: -2\n";
  ASSERT_EQ(0,b.size())<< "\n** Bad CopyConstructorEmpty: -2\n";
}

TEST(LinkedList, ClearWhenEmpty)
{
  LINKED_LIST<int> a;
  a.clear();
  ASSERT_EQ(0,a.size())<< "\n** Bad ClearWhenEmpty: -2\n";
  ASSERT_NULL(a.getHeadPtr())<< "\n** Bad ClearWhenEmpty: -2\n";
  ASSERT_NULL(a.getTailPtr())<< "\n** Bad ClearWhenEmpty: -2\n";
}

TEST(LinkedList, ClearWhenNotEmpty)
{
  LINKED_LIST<int> a;
  for (int i=0; i<100; i++)
    a.insertAtHead(i);
  a.clear();
  ASSERT_EQ(0,a.size()) << "\n** Bad ClearWhenNotEmpty: -2\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad ClearWhenNotEmpty: -2\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad ClearWhenNotEmpty: -2\n";
}

TEST(LinkedList, InsertOneAtHead)
{
  LINKED_LIST <int> a;
  a.insertAtHead(1);
  ASSERT_EQ(1,a.size()) << "\n** Bad InsertOneAtHead: -2\n";
  ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertOneAtHead: -2\n";
  ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertOneAtHead: -2\n";
  ASSERT_EQ(1,a.getHeadPtr()->m_data) << "\n** Bad InsertOneAtHead: -2\n";
  ASSERT_EQ(1,a.getTailPtr()->m_data) << "\n** Bad InsertOneAtHead: -2\n";
}

TEST(LinkedList, InsertManyAtHead)
{
  LINKED_LIST <int> a;
  a.insertAtHead(1);
  for (int i=2; i<100; i++)
  {
    a.insertAtHead(i);
    ASSERT_EQ(i,a.size()) << "\n** Bad InsertManyAtHead: -2\n";
    ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertManyAtHead: -2\n";
    ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertManyAtHead: -2\n";
    ASSERT_EQ(i,a.getHeadPtr()->m_data) << "\n** Bad InsertManyAtHead: -2\n";
    ASSERT_EQ(1,a.getTailPtr()->m_data) << "\n** Bad InsertManyAtHead: -2\n";
  }
}

TEST(LinkedList, InsertOneAtTail)
{
  LINKED_LIST <int> a;
  a.insertAtTail(1);
  ASSERT_EQ(1,a.size()) << "\n** Bad InsertOneAtTail: -2\n";
  ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertOneAtTail: -2\n";
  ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertOneAtTail: -2\n";
  ASSERT_EQ(1,a.getHeadPtr()->m_data) << "\n** Bad InsertOneAtTail: -2\n";
  ASSERT_EQ(1,a.getTailPtr()->m_data) << "\n** Bad InsertOneAtTail: -2\n";
}

TEST(LinkedList, InsertManyAtTail)
{
  LINKED_LIST <int> a;
  a.insertAtTail(1);
  for (int i=2; i<100; i++)
  {
    a.insertAtTail(i);
    ASSERT_EQ(i,a.size()) << "\n** Bad InsertManyAtTail: -2\n";
    ASSERT_NOT_NULL(a.getHeadPtr()) << "\n** Bad InsertManyAtTail: -2\n";
    ASSERT_NOT_NULL(a.getTailPtr()) << "\n** Bad InsertManyAtTail: -2\n";
    ASSERT_EQ(i,a.getTailPtr()->m_data) << "\n** Bad InsertManyAtTail: -2\n";
    ASSERT_EQ(1,a.getHeadPtr()->m_data) << "\n** Bad InsertManyAtTail: -2\n";
  }
}

TEST(LinkedList, RemoveFirstOnly)
{
  LINKED_LIST <int> a;
  a.insertAtHead(1);
  ASSERT_TRUE(a.removeFirstOccurrence(1)) << "\n** Bad RemoveFirstOnly: -2\n";
  ASSERT_EQ(0,a.size()) << "\n** Bad RemoveFirstOnly: -2\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveFirstOnly: -2\n";
  ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveFirstOnly: -2\n";
}

TEST(LinkedList, RemoveFirstNotInList)
{
  LINKED_LIST<int> a;
  ASSERT_FALSE(a.removeFirstOccurrence(1)) << "\n** Bad RemoveFirstNotInList: -2\n";
}

TEST(LinkedList, RemoveFirstHead)
{
  LINKED_LIST <int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  for (int i=9; i>=0; i--)
  {
    ASSERT_TRUE(a.removeFirstOccurrence(i)) << "\n** Bad RemoveFirstHead: -2\n";
    ASSERT_EQ(i, a.size()) << "\n** Bad RemoveFirstHead: -2\n";
    if (i>0)
      ASSERT_EQ(i-1, a.getHeadPtr()->m_data) << "\n** Bad RemoveFirstHead: -2\n";
    else if (i==0)
    {
      ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveFirstHead: -2\n";
      ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveFirstHead: -2\n";
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
    ASSERT_TRUE(a.removeFirstOccurrence(i)) << "\n** Bad RemoveFirstTail: -2\n";
    ASSERT_EQ(9-i, a.size()) << "\n** Bad RemoveFirstTail: -2\n";
    if (i<9)
      ASSERT_EQ(i+1, a.getTailPtr()->m_data);
    else if (i==0)
    {
      ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveFirstTail: -2\n";
      ASSERT_NULL(a.getTailPtr()) << "\n** Bad RemoveFirstTail: -2\n";
    }
  }
}

TEST(LinkedList, RemoveFirstMiddle)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtTail(i);
  ASSERT_TRUE(a.removeFirstOccurrence(5)) << "\n** Bad RemoveFirstMiddle: -2\n";
  ASSERT_EQ(9,a.size()) << "\n** Bad RemoveFirstMiddle: -2\n";
  int i=0;
  NODE<int>* currA = a.getHeadPtr();
  while (currA)
  {
    ASSERT_EQ(i,currA->m_data) << "\n** Bad RemoveFirstMiddle: -2\n";
    currA=currA->m_next;
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
  ASSERT_EQ(0,a.removeAllOccurrences(11)) << "\n** Bad RemoveAllNotInList: -2\n";
  ASSERT_EQ(10,a.size()) << "\n** Bad RemoveAllNotInList: -2\n";
}

TEST(LinkedList, RemoveAllAllInList)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(1);
  ASSERT_EQ(10,a.removeAllOccurrences(1)) << "\n** Bad RemoveAllAllInList: -2\n";
  ASSERT_EQ(0,a.size()) << "\n** Bad RemoveAllAllInList: -2\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveAllAllInList: -2\n";
  ASSERT_NULL(a.getHeadPtr()) << "\n** Bad RemoveAllAllInList: -2\n";
}

TEST(LinkedList, RemoveAllSomeInList)
{
  LINKED_LIST <int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i%2);
  ASSERT_EQ(5,a.removeAllOccurrences(1)) << "\n** Bad RemoveAllSomeInList: -2\n";
  ASSERT_EQ(5,a.size()) << "\n** Bad RemoveAllSomeInList: -2\n";
  ASSERT_EQ(0,a.getHeadPtr()->m_data) << "\n** Bad RemoveAllSomeInList: -2\n";
  ASSERT_EQ(0,a.getTailPtr()->m_data) << "\n** Bad RemoveAllSomeInList: -2\n";
}

TEST(LinkedList, IsEmptyWhenEmpty)
{
  LINKED_LIST<int>a;
  ASSERT_TRUE(a.isEmpty()) << "\n** Bad IsEmptyWhenEmpty: -2\n";
}

TEST(LinkedList, IsEmptyWhenNotEmpty)
{
  LINKED_LIST<int>a;
  a.insertAtHead(1);
  ASSERT_FALSE(a.isEmpty()) << "\n** Bad IsEmptyWhenNotEmpty: -2\n";
}

TEST(LinkedList, AssignmentOperator)
{
  LINKED_LIST<int> a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LINKED_LIST<int> b;
  b=a;
  ASSERT_EQ(a.size(), b.size()) << "\n** Bad AssignmentOperator: -2\n";
  //Make sure the head and tail match
  ASSERT_EQ(a.getHeadPtr()->m_data, b.getHeadPtr()->m_data) << "\n** Bad AssignmentOperator: -2\n";
  ASSERT_EQ(a.getTailPtr()->m_data, b.getTailPtr()->m_data) << "\n** Bad AssignmentOperator: -2\n";
  NODE<int>* currA = a.getHeadPtr();
  NODE<int>* currB = b.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data) << "\n** Bad AssignmentOperator: -2\n";
    currA=currA->m_next;
    currB=currB->m_next;
  }
}

TEST(LinkedList, AssignmentOperatorSelfAssignment)
{
  LINKED_LIST<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  a=a;
  //Make sure we didn't delete ourselves :/
  ASSERT_EQ(9,a.getHeadPtr()->m_data) << "\n** Bad AssignmentOperatorSelfAssignment: -2\n";
  ASSERT_EQ(0,a.getTailPtr()->m_data) << "\n** Bad AssignmentOperatorSelfAssignment: -2\n";
  NODE<int>* currA = a.getHeadPtr();
  NODE<int>* currB = a.getHeadPtr();
  while (currA && currB)
  {
    ASSERT_EQ(currA->m_data,currB->m_data) << "\n** Bad AssignmentOperatorSelfAssignment: -2\n";
    currA=currA->m_next;
    currB=currB->m_next;
  }
}

TEST(LinkedList, EqualityAreEqual)
{
  LINKED_LIST<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  LINKED_LIST<int>b(a);
  ASSERT_TRUE(b==a) << "\n** Bad EqualityAreEqual: -2\n";
}

TEST(LinkedList, EqualityAreSame)
{
  LINKED_LIST<int>a;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_TRUE(a==a) << "\n** Bad EqualityAreSame: -2\n";
}

TEST(LinkedList, EqualityAreNotTheSame)
{
  LINKED_LIST<int>a,b;
  for (int i=0; i<10; i++)
  {
    a.insertAtHead(i);
    b.insertAtHead(i+1);
  }
  ASSERT_FALSE(a==b) << "\n** Bad EqualityAreNotTheSame: -2\n";
}

TEST(LinkedList, EqualityEmptyNonEmpty)
{
  LINKED_LIST<int>a,b;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_FALSE(b==a) << "\n** Bad EqualityEmptyNonEmpty: -2\n";
}

TEST(LinkedList, EqualityNonEmptyEmpty)
{
  LINKED_LIST<int>a,b;
  for (int i=0; i<10; i++)
    a.insertAtHead(i);
  ASSERT_FALSE(a==b) << "\n** Bad EqualityNonEmptyEmpty: -2\n";
}

TEST(LinkedList, RemoveAtHeadThrowsException)
{
  LINKED_LIST<int> a;
  ASSERT_THROW(a.removeAtHead(),std::length_error);
}

TEST(LinkedList, RemoveAtHeadRemoveOne)
{
  LINKED_LIST<int> a;
  a.insertAtHead(0);
  a.removeAtHead();
  ASSERT_EQ(0,a.size());
}

TEST(LinkedList, RemoveAtHeadRemoveMany)
{
  LINKED_LIST<int> a;
  for (int i=0; i<100; i++)
    a.insertAtTail(i);
  for (int i=0; i<100; i++)
  {
    a.removeAtHead();
    ASSERT_FALSE(a.find(i));
    ASSERT_EQ(100-i-1,a.size());
    for (int j=i+1; j<100; j++)
      ASSERT_TRUE(a.find(j));
  }
}

TEST(LinkedList, RemoveAtTailThrowsException)
{
  LINKED_LIST<int> a;
  ASSERT_THROW(a.removeAtTail(),std::length_error);
}

TEST(LinkedList, RemoveAtTailRemoveOne)
{
  LINKED_LIST<int> a;
  a.insertAtHead(0);
  a.removeAtTail();
  ASSERT_EQ(0,a.size());
}

TEST(LinkedList, RemoveAtTailRemoveMany)
{
  LINKED_LIST<int> a;
  for (int i=0; i<100; i++)
    a.insertAtHead(i);
  for (int i=0; i<100; i++)
  {
    a.removeAtTail();
    ASSERT_FALSE(a.find(i));
    ASSERT_EQ(100-i-1,a.size());
    for (int j=i+1; j<100; j++)
      ASSERT_TRUE(a.find(j));
  }
} 
