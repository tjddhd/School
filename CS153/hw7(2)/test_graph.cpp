/*!\file test_graph.cpp
 * \author Lisa Tatro && Thomas Dolan
 * \tests UNDIRECTED_GRAPH class
 */
 
#include "UNDIRECTED_GRAPH.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
using namespace std;

TEST(UndirectedGRAPHTest, DefaultConstructor)
{
  UNDIRECTED_GRAPH<int, 0> g;
  ASSERT_EQ(0, g.size());
  ASSERT_TRUE(g.isEmpty());
  ASSERT_FALSE(g.find(42));
}

TEST(UndirectedGRAPHTest, ClearWhenEmpty)
{
  UNDIRECTED_GRAPH<int, 0> g;
  g.clear();
  ASSERT_EQ(0, g.size());
}

TEST(UndirectedGRAPHTest, TwoVerticesNoEdges)
{
  UNDIRECTED_GRAPH<int, 2> g;
  g.setVertexData(0, 42);
  g.setVertexData(1, 34);
  ASSERT_EQ(2, g.size());
  ASSERT_FALSE(g.isEdge(0,0));
  ASSERT_FALSE(g.isEdge(1,1));
  ASSERT_EQ(42, g.getVertexData(0));
  ASSERT_EQ(34, g.getVertexData(1));
  ASSERT_TRUE(g.find(42));
  ASSERT_TRUE(g.find(34));
  ASSERT_FALSE(g.find(666));
  ASSERT_THROW(g.getVertexData(500), std::out_of_range);
  ASSERT_THROW(g.isEdge(500,1), std::out_of_range);
  ASSERT_THROW(g.isEdge(1,500), std::out_of_range);
  ASSERT_THROW(g.isEdge(500,500), std::out_of_range);
}
 
TEST(UndirectedGRAPHTest, TwoVerticesOneUnweightedEdge)
{
  UNDIRECTED_GRAPH<int, 2> g;
  ASSERT_EQ(2, g.size());
  g.addEdge(0, 1);
  ASSERT_TRUE(g.isEdge(0,1));
  ASSERT_TRUE(g.isEdge(1,0));
  ASSERT_EQ(1, g.getEdgeWeight(0,1));
  ASSERT_EQ(1, g.getEdgeWeight(1,0));
}

TEST(UndirectedGRAPHTest, TwoVerticesOneWeightedEdge)
{
  UNDIRECTED_GRAPH<int, 2> g;
  ASSERT_EQ(2, g.size());
  g.addEdge(0, 1, 5);
  ASSERT_TRUE(g.isEdge(0,1));
  ASSERT_TRUE(g.isEdge(1,0));
  ASSERT_EQ(5, g.getEdgeWeight(0,1));
  ASSERT_EQ(5, g.getEdgeWeight(1,0));
}

TEST(UndirectedGRAPHTest, ManyVerticesWeightedEdges)
{
  const int n = 100;
  UNDIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++) {
    g.addEdge(i, n - i - 1, i * 2 + 1);
    ASSERT_TRUE(g.isEdge(i, n - i - 1));
	ASSERT_TRUE(g.isEdge(n - i - 1, i));
    ASSERT_EQ(i * 2 + 1, g.getEdgeWeight(i, n - i - 1));
	ASSERT_EQ(i * 2 + 1, g.getEdgeWeight(n - i - 1, i));
  }
}

TEST(UndirectedGRAPHTest, RemoveEdgesWhenManyVerticesWeightedEdges)
{
  const int n = 100;
  UNDIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++)
    g.addEdge(i, n - i - 1, i * 2 + 1);
  for (int i = 0; i < n; i++) {
    g.removeEdge(i, n - i - 1);
    ASSERT_FALSE(g.isEdge(i, n - i - 1));
	ASSERT_FALSE(g.isEdge(n - i - 1, i));
  }
}

TEST(UndirectedDIGRAPHTest, ClearWhenManyVertices)
{
  const int n = 100;
  UNDIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++)
    g.addEdge(i, n - i - 1, i * 2 + 1);
  g.clear();
  ASSERT_EQ(0, g.size());
}

TEST(UndirectedDIGRAPHTest, ReferenceEdgeOutOfRange)
{
  UNDIRECTED_GRAPH<int, 10> g;
  ASSERT_THROW(g.isEdge(50,50), std::out_of_range);
  ASSERT_THROW(g.isEdge(0,50), std::out_of_range);
  ASSERT_THROW(g.isEdge(50,0), std::out_of_range);
  ASSERT_THROW(g.addEdge(50,50), std::out_of_range);
  ASSERT_THROW(g.addEdge(0,50), std::out_of_range);
  ASSERT_THROW(g.addEdge(50,0), std::out_of_range);
  ASSERT_THROW(g.removeEdge(50,50), std::out_of_range);
  ASSERT_THROW(g.removeEdge(0,50), std::out_of_range);
  ASSERT_THROW(g.removeEdge(50,0), std::out_of_range);
  ASSERT_THROW(g.getEdgeWeight(50,50), std::out_of_range);
  ASSERT_THROW(g.getEdgeWeight(0,50), std::out_of_range);
  ASSERT_THROW(g.getEdgeWeight(50,0), std::out_of_range);
  ASSERT_THROW(g.setEdgeWeight(50,50, 2), std::out_of_range);
  ASSERT_THROW(g.setEdgeWeight(0,50, 2), std::out_of_range);
  ASSERT_THROW(g.setEdgeWeight(50,0, 2), std::out_of_range);
  ASSERT_THROW(g.getVertexData(50), std::out_of_range);
  ASSERT_THROW(g.setVertexData(50, 42), std::out_of_range);
  ASSERT_THROW(g.vertexDegree(500), std::out_of_range);
}

TEST(UndirectDIGRAPHTest, EqualityBothEmpty)
{
  UNDIRECTED_GRAPH<int, 0> g1, g2;
  ASSERT_TRUE(g1 == g2);
  ASSERT_TRUE(g2 == g1);
}

TEST(UndirectedDIGRAPHTest, EqualitySameSizeDifferentEdges)
{
  UNDIRECTED_GRAPH<int, 3> g1;
  UNDIRECTED_GRAPH<int, 3> g2;
  g1.addEdge(0,1); g2.addEdge(0,1); g2.addEdge(1,0);
  ASSERT_FALSE(g1 == g2);
  ASSERT_FALSE(g2 == g1);
}

TEST(UndirectedDIGRAPHTest, EqualitySameSizeSameEdgesDifferentWeights)
{
  UNDIRECTED_GRAPH<int, 3> g1;
  UNDIRECTED_GRAPH<int, 3> g2;
  g1.addEdge(0,1,5); g2.addEdge(0,1,7);
  ASSERT_FALSE(g1 == g2);
  ASSERT_FALSE(g2 == g1);
}

TEST(UndirectedDIGRAPHTest, EqualitySameSizeSameEdgesDifferentData)
{
  UNDIRECTED_GRAPH<string, 3> g1;
  UNDIRECTED_GRAPH<string, 3> g2;
  g1.addEdge(0,1); g2.addEdge(0,1);
  g1.setVertexData(0, "cat"); g1.setVertexData(1, "dog");
  g1.setVertexData(0, "cat"); g1.setVertexData(1, "goat");
  ASSERT_FALSE(g1 == g2);
  ASSERT_FALSE(g2 == g1);
}

TEST(UndirectedDIGRAPHTest, EqualityEverythingIsSame)
{
  const int n = 100;
  UNDIRECTED_GRAPH<int, n> g1, g2;
  for (int i = 0; i < n; i++) {
    g1.addEdge(i, n - i - 1, i * 2 + 1);
    g2.addEdge(i, n - i - 1, i * 2 + 1);
    g1.setVertexData(i, i + 100);
    g2.setVertexData(i, i + 100);
  }
  ASSERT_TRUE(g1 == g2);
  ASSERT_TRUE(g2 == g1);
}

TEST(UndirectedDIGRAPHTest, IsSimpleWhenLoop)
{
  UNDIRECTED_GRAPH<int, 4> g;
  g.addEdge(1,1); 
  ASSERT_FALSE(g.isSimple());
}

TEST(UndirectedDIGRAPHTest, IsCompleteWhenEmpty)
{
  UNDIRECTED_GRAPH<int, 0> g;
  ASSERT_TRUE(g.isComplete());
}

TEST(UndirectedDIGRAPHTest, IsCompleteWhenNonEmptyMissingEdges)
{
  UNDIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(3,2);
  ASSERT_FALSE(g.isComplete());
}

TEST(UndirectedDIGRAPHTest, IsCompleteWhenNonEmptyNoMissingEdges)
{
  UNDIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(0,2); g.addEdge(0,3);
  g.addEdge(2,1); g.addEdge(3,2); g.addEdge(1,3);
  ASSERT_TRUE(g.isComplete());
}

TEST(UndirectedDIGRAPHTest, IsCompleteWhenLoop)
{
  UNDIRECTED_GRAPH<int, 3> g;
  g.addEdge(0,1); g.addEdge(1,1); g.addEdge(2,1);
  ASSERT_FALSE(g.isComplete());
}

TEST(UndirectedDIGRAPHTest, IsAcyclicWhenEmpty)
{
  UNDIRECTED_GRAPH<int, 0> g;
  ASSERT_TRUE(g.isAcyclic());
}

TEST(UndirectedDIGRAPHTest, IsAcyclicWhenOneVertexNoEdges)
{
  UNDIRECTED_GRAPH<int, 1> g;
  ASSERT_TRUE(g.isAcyclic());
}

TEST(UndirectedDIGRAPHTest, IsAcyclicWhenLoop)
{
  UNDIRECTED_GRAPH<int, 1> g;
  g.addEdge(0,0);
  ASSERT_FALSE(g.isAcyclic());
}

TEST(UndirectedDIGRAPHTest, VertexDegreeWhenNoEdges)
{
  UNDIRECTED_GRAPH<int, 2> g;
  ASSERT_EQ(0, g.graphDegree());
}

TEST(undirectedDIGRAPHTest, VertexDegreeWhenLoopEdges)
{
  UNDIRECTED_GRAPH<int,2> g;
  g.addEdge(0,0);
  g.addEdge(1,1);
  ASSERT_EQ(4, g.graphDegree());
}

TEST(UndirectedDIGRAPHTest, VertexDegreeWhenAllEdges)
{
  const int n = 100;
  int degree = 0;
  UNDIRECTED_GRAPH<int, n> g;
  for(int i = 0; i < g.size(); i++)
  {
    for(int j = i; j < g.size(); j++)
	{
	  if( i != j)
	  {
	    degree++;
		g.addEdge(i,j);
		ASSERT_EQ(degree, g.graphDegree());
	  }
	  else
	  {
	    degree = degree + 2;
		g.addEdge(i,j);
		ASSERT_EQ(degree, g.graphDegree());
	  }
	}
  } 
}

/*TEST(UndirectedDIGraphTEST, VertexDegreeWhenNoLoops)
{
  const int n = 100;
  int degree = 0;
  UNDIRECTED_GRAPH<int, n> g;
  for(int i = 0; i < g.size(); i++)
  {
    for( int j = i + 1; j < g.size(); i++)
	{
	  
	}
}*/

TEST(UndirectedDIGRAPHTest, SelfAssignmentWhenEmpty)
{
  UNDIRECTED_GRAPH<int, 0> g;
  g = g;
  ASSERT_TRUE(g.isEmpty());
}

TEST(UndirectedDIGRAPHTest, SelfAssignmentWhenNotEmpty)
{
	//FIXME
	//Somewhere in here is memory leak, search and destroy
  const int n = 100;
  UNDIRECTED_GRAPH<int, n> g;
  for (int i = 0; i < n; i++) {
    g.addEdge(i, n - i - 1, i * 2 + 1);
    g.setVertexData(i, i % 10);
	g.setVertexData(i%10, i);
  }
  g = g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(g.isEdge(i, n - i - 1));
	ASSERT_TRUE(g.isEdge(n - i - 1, i));
    ASSERT_EQ(i * 2 + 1, g.getEdgeWeight(i, n - i - 1));
	ASSERT_EQ(i * 2 + 1, g.getEdgeWeight( n - i - 1, i));
    ASSERT_EQ(i % 10, g.getVertexData(i));
  }
}

/*TEST(undirectedDIGRAPHTest, AssignmentWhenNotEmpty)
{
  const int n = 100;
  UNDIRECTED_GRAPH<int, n> g;
  for (int i = 0; i < n; i++) {
    g.addEdge(i, n - i - 1, i * 2 + 1);
    g.setVertexData(i, i % 10);
  }
  DIRECTED_GRAPH<int, n> g2;
  g2 = g;
  ASSERT_EQ(n, g2.size());
  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(g2.isEdge(i, n - i - 1));
    ASSERT_EQ(i * 2 + 1, g2.getEdgeWeight(i, n - i - 1));
    ASSERT_EQ(i % 10, g2.getVertexData(i));
  }
}*/

TEST(UndirectedDIGRAPHTest, ComplementWhenEmpty)
{
  UNDIRECTED_GRAPH<int, 0> g1, g2;
  g1.complement(g2);
  ASSERT_TRUE(g1.isEmpty());
}

