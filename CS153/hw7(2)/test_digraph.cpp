/*!\file test_digraph.cpp
 * \author Jennifer Leopold
 * \brief Test cases for the DIRECTED_GRAPH class
 */

#include "DIRECTED_GRAPH.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
using namespace std;

// NOTE: Each may test multiple (different) functions

TEST(DIGRAPHTest, DefaultConstructor)
{
  DIRECTED_GRAPH<int, 0> g;
  ASSERT_EQ(0, g.size());
  ASSERT_TRUE(g.isEmpty());
  ASSERT_FALSE(g.find(42));
}

TEST(DIGRAPHTest, ClearWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  g.clear();
  ASSERT_EQ(0, g.size());
}

TEST(DIGRAPHTest, TwoVerticesNoEdges)
{
  DIRECTED_GRAPH<int, 2> g;
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

TEST(DIGRAPHTest, TwoVerticesOneUnweightedEdge)
{
  DIRECTED_GRAPH<int, 2> g;
  ASSERT_EQ(2, g.size());
  g.addEdge(0, 1);
  ASSERT_TRUE(g.isEdge(0,1));
  ASSERT_FALSE(g.isEdge(1,0));
  ASSERT_EQ(1, g.getEdgeWeight(0,1));
}

TEST(DIGRAPHTest, TwoVerticesOneWeightedEdge)
{
  DIRECTED_GRAPH<int, 2> g;
  ASSERT_EQ(2, g.size());
  g.addEdge(0, 1, 5);
  ASSERT_TRUE(g.isEdge(0,1));
  ASSERT_FALSE(g.isEdge(1,0));
  ASSERT_EQ(5, g.getEdgeWeight(0,1));
}

TEST(DIGRAPHTest, ManyVerticesWeightedEdges)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++) {
    g.addEdge(i, n - i - 1, i * 2 + 1);
    ASSERT_TRUE(g.isEdge(i, n - i - 1));
    ASSERT_EQ(i * 2 + 1, g.getEdgeWeight(i, n - i - 1));
  }
}

TEST(DIGRAPHTest, RemoveEdgesWhenManyVerticesWeightedEdges)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++)
    g.addEdge(i, n - i - 1, i * 2 + 1);
  for (int i = 0; i < n; i++) {
    g.removeEdge(i, n - i - 1);
    ASSERT_FALSE(g.isEdge(i, n - i - 1));
  }
}

TEST(DIGRAPHTest, ClearWhenManyVertices)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++)
    g.addEdge(i, n - i - 1, i * 2 + 1);
  g.clear();
  ASSERT_EQ(0, g.size());
}


TEST(DIGRAPHTest, ReferenceEdgeOutOfRange)
{
  DIRECTED_GRAPH<int, 10> g;
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
  ASSERT_THROW(g.vertexInDegree(500), std::out_of_range);
  ASSERT_THROW(g.vertexOutDegree(500), std::out_of_range);
}

TEST(DIGRAPHTest, EqualityBothEmpty)
{
  DIRECTED_GRAPH<int, 0> g1, g2;
  ASSERT_TRUE(g1 == g2);
  ASSERT_TRUE(g2 == g1);
}

TEST(DIGRAPHTest, EqualitySameSizeDifferentEdges)
{
  DIRECTED_GRAPH<int, 3> g1;
  DIRECTED_GRAPH<int, 3> g2;
  g1.addEdge(0,1); g2.addEdge(0,1); g2.addEdge(1,0);
  ASSERT_FALSE(g1 == g2);
  ASSERT_FALSE(g2 == g1);
}

TEST(DIGRAPHTest, EqualitySameSizeSameEdgesDifferentWeights)
{
  DIRECTED_GRAPH<int, 3> g1;
  DIRECTED_GRAPH<int, 3> g2;
  g1.addEdge(0,1,5); g2.addEdge(0,1,7);
  ASSERT_FALSE(g1 == g2);
  ASSERT_FALSE(g2 == g1);
}

TEST(DIGRAPHTest, EqualitySameSizeSameEdgesDifferentData)
{
  DIRECTED_GRAPH<string, 3> g1;
  DIRECTED_GRAPH<string, 3> g2;
  g1.addEdge(0,1); g2.addEdge(0,1);
  g1.setVertexData(0, "cat"); g1.setVertexData(1, "dog");
  g1.setVertexData(0, "cat"); g1.setVertexData(1, "goat");
  ASSERT_FALSE(g1 == g2);
  ASSERT_FALSE(g2 == g1);
}

TEST(DIGRAPHTest, EqualityEverythingIsSame)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g1, g2;
  for (int i = 0; i < n; i++) {
    g1.addEdge(i, n - i - 1, i * 2 + 1);
    g2.addEdge(i, n - i - 1, i * 2 + 1);
    g1.setVertexData(i, i + 100);
    g2.setVertexData(i, i + 100);
  }
  ASSERT_TRUE(g1 == g2);
  ASSERT_TRUE(g2 == g1);
}

TEST(DIGRAPHTest, IsSimpleWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  ASSERT_TRUE(g.isSimple());
}

TEST(DIGRAPHTest, IsSimpleWhenNonEmpty)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3);
  ASSERT_TRUE(g.isSimple());
}

TEST(DIGRAPHTest, IsSimpleWhenLoop)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,1); g.addEdge(2,3);
  ASSERT_FALSE(g.isSimple());
}

TEST(DIGRAPHTest, IsSimpleWhenParallelEdges)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,0); g.addEdge(2,3);
  ASSERT_FALSE(g.isSimple());
}

TEST(DIGRAPHTest, IsCompleteWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  ASSERT_TRUE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenNonEmptyMissingEdges)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(3,2);
  ASSERT_FALSE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenNonEmptyNoMissingEdges)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(0,2); g.addEdge(0,3);
  g.addEdge(2,1); g.addEdge(3,2); g.addEdge(1,3);
  ASSERT_TRUE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenLoop)
{
  DIRECTED_GRAPH<int, 3> g;
  g.addEdge(0,1); g.addEdge(1,1); g.addEdge(2,1);
  ASSERT_FALSE(g.isComplete());
}

TEST(DIGRAPHTest, IsCompleteWhenParallelEdges)
{
  DIRECTED_GRAPH<int, 3> g;
  g.addEdge(0,1); g.addEdge(1,0); g.addEdge(2,1);
  ASSERT_FALSE(g.isComplete());
}

TEST(DIGRAPHTest, IsAcyclicWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  ASSERT_TRUE(g.isAcyclic());
}

TEST(DIGRAPHTest, IsAcyclicWhenOneVertexNoEdges)
{
  DIRECTED_GRAPH<int, 1> g;
  ASSERT_TRUE(g.isAcyclic());
}

TEST(DIGRAPHTest, IsAcyclicWhenLoop)
{
  DIRECTED_GRAPH<int, 2> g;
  g.addEdge(0,0); g.addEdge(0,1);
  ASSERT_FALSE(g.isAcyclic());
}

TEST(DIGRAPHTest, IsAcyclicWhenConnectedButNoCycle)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(3,2);
  ASSERT_TRUE(g.isAcyclic());
}

TEST(DIGRAPHTest, IsAcyclicWhenConnectedWithCycle)
{
  DIRECTED_GRAPH<int, 4> g;
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3); g.addEdge(3,1);
  ASSERT_FALSE(g.isAcyclic());
}

TEST(DIGRAPHTest, IsBipartiteEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  int vertexGrouping[1];
  ASSERT_TRUE(g.isBipartite(vertexGrouping));
}/*

TEST(DIGRAPHTest, IsBipartiteNotEmpty)
{
  DIRECTED_GRAPH<int, 5> g;
  g.addEdge(0,1); g.addEdge(0,3); 
  g.addEdge(1,2); g.addEdge(1,4);
  g.addEdge(2,3); g.addEdge(4,3);
  int vertexGrouping[5];
  ASSERT_TRUE(g.isBipartite(vertexGrouping));
  ASSERT_EQ(vertexGrouping[0], vertexGrouping[2]);
  ASSERT_EQ(vertexGrouping[0], vertexGrouping[4]);
  ASSERT_EQ(vertexGrouping[1], vertexGrouping[3]);
  ASSERT_FALSE(vertexGrouping[0] == vertexGrouping[1]);
}

TEST(DIGRAPHTest, IsNotBipartiteExtraEdge)
{
  DIRECTED_GRAPH<int, 5> g;
  g.addEdge(0,1); g.addEdge(0,3); 
  g.addEdge(1,2); g.addEdge(1,4);
  g.addEdge(2,3); g.addEdge(4,3);
  g.addEdge(3,1);  // this edge makes it not bipartite
  int vertexGrouping[5];
  ASSERT_FALSE(g.isBipartite(vertexGrouping));
}

TEST(DIGRAPHTest, IsNotBipartiteMissingEdge)
{
  DIRECTED_GRAPH<int, 5> g;
  g.addEdge(0,1); g.addEdge(0,3); 
  g.addEdge(1,2); g.addEdge(1,4);
  g.addEdge(2,3); // g.addEdge(4,3);  // needs this edge to be bipartite
  int vertexGrouping[5];
  ASSERT_FALSE(g.isBipartite(vertexGrouping));
}*/


TEST(DIGRAPHTest, VertexDegreeWhenNoEdges)
{
  DIRECTED_GRAPH<int, 2> g;
  ASSERT_EQ(0, g.vertexInDegree(0)); ASSERT_EQ(0, g.vertexOutDegree(0));
  ASSERT_EQ(0, g.vertexInDegree(1)); ASSERT_EQ(0, g.vertexOutDegree(1));
  ASSERT_EQ(0, g.graphDegree());
}

TEST(DIGRAPHTest, VertexDegreeWhenEdges)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n-2; i++) {
    g.addEdge(i, n - i - 1);
    if (i < 50)
      g.addEdge(i, 99);
    else if (i > 50) g.addEdge(i, 98);
  }
  ASSERT_EQ(0, g.vertexInDegree(0)); ASSERT_EQ(1, g.vertexOutDegree(0));
  ASSERT_EQ(0, g.vertexInDegree(1)); ASSERT_EQ(2, g.vertexOutDegree(1));
  for (int i = 2; i < n-2; i++) {
    ASSERT_EQ(1, g.vertexInDegree(i));
    if (i != 50)
      ASSERT_EQ(2, g.vertexOutDegree(i));
    else ASSERT_EQ(1, g.vertexOutDegree(i));
    //cout << "i = " << i << " in = " << g.vertexInDegree(i)
    //     << " out = " << g.vertexOutDegree(i) << endl;
  }
  ASSERT_EQ(48, g.vertexInDegree(98)); ASSERT_EQ(0, g.vertexOutDegree(98));
  ASSERT_EQ(50, g.vertexInDegree(99)); ASSERT_EQ(0, g.vertexOutDegree(99));
  //cout << g.graphDegree() << endl; 
  ASSERT_EQ(388, g.graphDegree());
}

TEST(DIGRAPHTest, SelfAssignmentWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  g = g;
  ASSERT_TRUE(g.isEmpty());
}

TEST(DIGRAPHTest, SelfAssignmentWhenNotEmpty)
{

  const int n = 100;
  DIRECTED_GRAPH<int, n> g;
  for (int i = 0; i < n; i++) {
    g.addEdge(i, n - i - 1, i * 2 + 1);
    g.setVertexData(i, i % 10);
  }
  g = g;
  ASSERT_EQ(n, g.size());
  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(g.isEdge(i, n - i - 1));
    ASSERT_EQ(i * 2 + 1, g.getEdgeWeight(i, n - i - 1));
    ASSERT_EQ(i % 10, g.getVertexData(i));
  }
}

TEST(DIGRAPHTest, AssignmentWhenNotEmpty)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g;
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
}

TEST(DIGRAPHTest, ComplementWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g1, g2;
  g1.complement(g2);
  ASSERT_TRUE(g1.isEmpty());
}

TEST(DIGRAPHTest, ComplementWhenTwoVerticesTwoEdges)
{
  DIRECTED_GRAPH<int, 2> g1, g2;
  g1.addEdge(0,1); g1.addEdge(1,0);
  g2.complement(g1);
  ASSERT_FALSE(g2.isEdge(0,1));
  ASSERT_FALSE(g2.isEdge(1,0));
  ASSERT_TRUE(g2.isEdge(0,0));
  ASSERT_TRUE(g2.isEdge(1,1));
}

TEST(DIGRAPHTest, ComplementWhenNotEmptyNoEdges)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g1, g2;
  g1.complement(g2);  // make g1 the complement of g2
  for (int i = 0; i < n; i++) {
    ASSERT_EQ(g1.getVertexData(i), g2.getVertexData(i));
    for (int j = 0; j < n; j++)
      ASSERT_TRUE(g1.isEdge(i,j));
  }
}

TEST(DIGRAPHTest, ComplementWhenNotEmptySomeEdges)
{
  const int n = 100;
  DIRECTED_GRAPH<int, n> g1, g2;
  for (int i = 0; i < n; i++) {
    g2.setVertexData(i, i - 10);
    if ((i % 2) == 0)  
      g2.addEdge(i, i % 2, 100+ i);
  }
  g1.complement(g2);  // make g1 the complement of g2
  for (int i = 0; i < n; i++) {
    ASSERT_EQ(g1.getVertexData(i), g2.getVertexData(i));
    if ((i % 2) == 0)
      ASSERT_FALSE(g1.isEdge(i, i % 2));
    else ASSERT_TRUE(g1.isEdge(i, i % 2));
  }
}

TEST(DIGRAPHTest, BFSWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  int visited[1];
  ASSERT_THROW(g.bfs(0, visited), std::out_of_range);
}

TEST(DIGRAPHTest, BFSWhenSingleVertexNoEdges)
{
  DIRECTED_GRAPH<int, 1> g;
  int visited[1];
  g.bfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, BFSWhenSingleVertexOneEdge)
{
  DIRECTED_GRAPH<int, 1> g;
  int visited[1];
  g.addEdge(0,0);
  g.bfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, BFSWhenNotEmptySomeEdgesStartingFrom0)
{
  DIRECTED_GRAPH<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(0,3); 
  g.addEdge(2,1); // note: makes a cycle from vertex 0 to vertex 2!
  g.addEdge(4,3); // note: no way to get to vertex 4!
  g.bfs(0, visited);
  ASSERT_EQ(0, visited[0]);
  ASSERT_EQ(1, visited[1]); ASSERT_EQ(1, visited[3]);
  ASSERT_EQ(2, visited[2]);
  ASSERT_EQ(NOT_YET_VISITED, visited[4]);
}

TEST(DIGRAPHTest, BFSWhenNotEmptySomeEdgesNotStartingFrom0)
{
  DIRECTED_GRAPH<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(1,3); 
  g.addEdge(2,4); g.addEdge(3,4);
  g.bfs(1, visited);
  ASSERT_EQ(NOT_YET_VISITED, visited[0]);
  ASSERT_EQ(0, visited[1]);
  ASSERT_EQ(1, visited[2]); ASSERT_EQ(1, visited[3]);
  ASSERT_EQ(2, visited[4]);
}

TEST(DIGRAPHTest, DFSWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  int visited[1];
  ASSERT_THROW(g.dfs(0, visited), std::out_of_range);
}

TEST(DIGRAPHTest, DFSWhenSingleVertexNoEdges)
{
  DIRECTED_GRAPH<int, 1> g;
  int visited[1];
  g.dfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, DFSWhenSingleVertexOneEdge)
{
  DIRECTED_GRAPH<int, 1> g;
  int visited[1];
  g.addEdge(0,0);
  g.dfs(0, visited);
  ASSERT_EQ(0, visited[0]);
}

TEST(DIGRAPHTest, DFSWhenNotEmptySomeEdgesStartingFrom0)
{
  DIRECTED_GRAPH<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3); 
  g.addEdge(2,0); // note: makes a cycle from vertex 0 to vertex 2!
  g.addEdge(4,3); // note: no way to get to vertex 4!
  g.dfs(0, visited);
  for (int i = 0; i < 4; i++)
    ASSERT_EQ(i, visited[i]);
  ASSERT_EQ(NOT_YET_VISITED, visited[4]);
}

TEST(DIGRAPHTest, DFSWhenNotEmptySomeEdgesNotStartingFrom0)
{
  DIRECTED_GRAPH<int, 5> g;
  int visited[5];
  g.addEdge(0,1); g.addEdge(1,2); g.addEdge(2,3); 
  g.addEdge(2,0); // note: makes a cycle from vertex 0 to vertex 2!
  g.addEdge(4,3); // note: no way to get to vertex 4!
  g.dfs(1, visited);
  ASSERT_EQ(0, visited[1]);
  ASSERT_EQ(1, visited[2]);
  ASSERT_EQ(2, visited[3]);
  ASSERT_EQ(2, visited[0]);
  ASSERT_EQ(NOT_YET_VISITED, visited[4]);
}

TEST(DIGRAPHTest, IsConnectedWhenEmpty)
{
  DIRECTED_GRAPH<int, 0> g;
  ASSERT_TRUE(g.isStronglyConnected());  // weird case 
}

TEST(DIGRAPHTest, IsStronglyConnectedWhenSingleVertex)
{
  DIRECTED_GRAPH<int, 1> g;
  ASSERT_TRUE(g.isStronglyConnected());  // another weird case 
  g.addEdge(0,0);
  ASSERT_TRUE(g.isStronglyConnected());  // another weird case
}

TEST(DIGRAPHTest, IsStronglyConnectedWhenCanReachAllVertices)
{
  DIRECTED_GRAPH<int, 5> g;
  g.addEdge(0,1);
  g.addEdge(1,2); 
  g.addEdge(2,3); 
  g.addEdge(2,0); // note: makes a cycle from vertex 0 to vertex 2!
  g.addEdge(3,4); 
  g.addEdge(4,0);
  ASSERT_TRUE(g.isStronglyConnected());
}

TEST(DIGRAPHTest, IsStronglyConnectedWhenCannotReachAllVertices)
{
  DIRECTED_GRAPH<int, 5> g;
  g.addEdge(0,1);
  g.addEdge(1,2); 
  g.addEdge(2,3); 
  g.addEdge(2,0); // note: makes a cycle from vertex 0 to vertex 2!
  g.addEdge(4,3); // note: no vertex can reach vertex 4 
  g.addEdge(4,0);
  ASSERT_FALSE(g.isStronglyConnected());
}

TEST(DIGRAPHTest, IsStronglyConnectedWhenSinglePath)
{
  DIRECTED_GRAPH<int, 5> g;
  g.addEdge(0,1);
  g.addEdge(1,2); 
  g.addEdge(2,3); 
  g.addEdge(3,4);
  ASSERT_FALSE(g.isStronglyConnected());
}

