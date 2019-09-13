/*!\file DIRECTED_GRAPH.h
 * \author Jennifer Leopold
 * \brief class definition for a directed graph
 */
#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include "COLLECTION.h"
#include <stdexcept>
#include <iostream>
using namespace std;

#define NOT_YET_VISITED -1   // used for BFS and DFS

template <class T, unsigned int N>
class DIRECTED_GRAPH : public COLLECTION<T> {
    
// Note: COLLECTION<T>::m_size = # vertices = N   
public:
//weights can only be ints
  typedef int** int_Dbl_Array_Ptr;
  typedef T* T_array_Ptr;
  
protected:
  int_Dbl_Array_Ptr m_Edges_Array;
  T_array_Ptr vertices_data_array;
public:
  // Purpose: default constructor
  // Postconditions: initializes the data structure to be have N vertices,
  // no edges, and a data value for each vertex (initialized to the default
  // value for type T)
  DIRECTED_GRAPH();
  
  // Purpose: destructor
  // Postconditions: removes all edges and deallocates all dynamically 
  // allocated memory associated with the data structure (via clear)
  ~DIRECTED_GRAPH() { clear(); }
  
  // Purpose: clear this graph
  // Postconditions: removes all edges and deallocates all dynamically 
  // allocated memory associated with the data structure 
  void clear(); 
  
  // Purpose: determine whether there is a vertex with a specified data value
  // Parameters: x is the data value to be found
  // Returns: true if there is a vertex with data value x; otherwise, false
  bool find(const T& x) const;
  
  // Purpose: add edge(i,j) with weight w
  // Parameters: i is source vertex, j is destination vertex, w is weight
  // (note: default value for weight is 1)
  // Postconditions: edge (i, j) is added to the graph with weight w
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  void addEdge(const unsigned int i, 
               const unsigned int j, const int w = 1);
  
  // Purpose: remove edge(i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Postconditions: edge (i, j) is removed from the graph 
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  void removeEdge(const unsigned int i, const unsigned int j);
  
  // Purpose: determine whether there is an edge (i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Returns: true if there is an edge (i,j); otherwise, false 
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  bool isEdge(const unsigned int i, const unsigned int j) const;
  
  // Purpose: get the weight associated with edge (i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Returns: the weight associated with edge (i,j); if no such edge exists,
  // return 0
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  int getEdgeWeight(const unsigned int i, const unsigned int j) const;
  
  // Purpose: set the weight associated with edge (i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Postconditions: the weight associated with edge (i,j) has been set to w
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  void setEdgeWeight(const unsigned int i, 
                     const unsigned int j, const int w);
  
  // Purpose: get the data associated with vertex i 
  // Parameters: i is the specified vertex
  // Returns: the data associated with vertex i
  // Exceptions: if i >= # vertices in this graph then throw
  // an out_of_range error
  T getVertexData(const unsigned int i) const;
  
  // Purpose: set the data associated with vertex i 
  // Parameters: i is the specified vertex, data is the specified data value
  // Postconditions: the data value associated with vertex i has been 
  // set to data
  // Exceptions: if i >= # vertices in this graph then throw
  // an out_of_range error
  void setVertexData(const unsigned int i, const T& data);
  
  // Purpose: get the # edges coming in to vertex i 
  // Parameters: i is the specified vertex
  // Returns: the # edges coming in to vertex i
  // Exceptions: if i >= # vertices in this graph then throw
  // an out_of_range error
  int vertexInDegree(const unsigned int i) const;
  
  // Purpose: get the # edges coming out of vertex i 
  // Parameters: i is the specified vertex
  // Returns: the # edges coming out of vertex i
  // Exceptions: if i >= # vertices in this graph then throw
  // an out_of_range error
  int vertexOutDegree(const unsigned int i) const;
  
  // Purpose: determine the degree of this graph 
  // Returns: the sum of the inDegree and outDegree of every vertex 
  // in this graph
  int graphDegree() const;
  
  // Purpose: determine whether this graph is simple (i.e., contains no
  // parallel edges (e.g., (u, v) and (v, u)), and no loops (e.g., (u, u))) 
  // Returns: true if this graph is simple; otherwise, false 
  bool isSimple() const; 
  
  // Purpose: determine whether this graph is complete (i.e., is simple and
  // there is an edge (u, v) or (v, u) for every pair of vertices u and v)
  // Returns: true if this graph is complete; otherwise, false 
  bool isComplete() const;
  
  // Purpose: determine whether this graph is acyclic (i.e., does not 
  // contain a cycle)
  // Returns: true if this graph is acyclic; otherwise, false
  bool isAcyclic() const; 
  
  // Purpose: determine whether this graph is bipartite (i.e., whether the
  // vertices can be partitioned into 2 groups such that there is an edge
  // between every vertex in one group and every vertex in the other group,
  // and, if 2 vertices are in the same group, there is not an edge between 
  // them)
  // Parameters: vertexGrouping is a 1D array of size N (essentially passed 
  // by reference since it is an array); upon termination of this function,
  // vertexGrouping[i] should be 1 or 2 representing whether vertex i is in 
  // group 1 or 2 (if the graph is in fact bipartite)
  // Returns: true if this graph is bipartite; otherwise, false
  bool isBipartite(int vertexGrouping[]) const; 
  
  // Purpose: determine whether this graph is strongly connected (i.e., 
  // there is a directed path from u to v and a directed path from v to u 
  // for every pair of vertices u and v where u != v)
  // Returns: true if this graph is complete; otherwise, false
  bool isStronglyConnected() const; 
 
  // Purpose: construct this graph to be the complement of the 
  // specified graph (i.e., if there is an edge (i,j) in compMe, then
  // there should not be an edge (i,j) in this graph; if there is not an edge
  // (i,j) in compMe, then there should be an edge (i,j) with weight 1 in
  // this graph)
  // Parameters: compMe is the graph that this graph should become 
  // the complement of 
  // Postconditions: this graph is the complement of graph compMe
  void complement(const DIRECTED_GRAPH<T, N>& compMe);

  // Purpose: perform a breadth-first search (BFS) on this graph starting at 
  // specified vertex
  // Parameters: start is the vertex from which the breadth-first search should
  // begin; visited is a 1D array of size N (essentially passed by reference
  // since it is an array); upon termination of this function, visited[i]
  // should be an integer indicating when vertex i was visited (e.g., 
  // visited[start] = 0, if there is an edge (start, u) then visited[u] = 1, 
  // etc.); if a vertex v is never visited in a bfs beginning at start, then
  // visited[v] should be set to NOT_YET_VISITED (which is #define'd in 
  // DIRECTED_GRAPH.h)
  // Exceptions: if start >= # vertices in this graph then throw
  // an out_of_range error
  void bfs(const unsigned int start, int visited[]) const; 
  
  // Purpose: perform a depth-first search (DSF) on this graph starting at 
  // specified vertex
  // Parameters: start is the vertex from which the depth-first search should
  // begin; visited is a 1D array of size N (essentially passed by reference
  // since it is an array); upon termination of this function, visited[i]
  // should an integer indicating when vertex i was visited (e.g., 
  // visited[start] = 0, if there is an edge (start, u) then visited[u] = 1,
  // and if there is an edge (u, v) then visited[v] = 2, etc.); if a vertex
  // v is never visited in a dfs beginning at start, then
  // visited[v] should be set to NOT_YET_VISITED (which is #define'd in 
  // DIRECTED_GRAPH.h)
  // Exceptions: if start >= # vertices in this graph then throw
  // an out_of_range error
  void dfs(const unsigned int start, int visited[], int count) const; 

  // Purpose: determine whether or not this graph is equivalent to
  // a specified graph 
  // Parameters: rhs is the graph to be compared to this graph
  // Returns: if the graphs are exactly the same in terms of 
  // structure and content, return true; otherwise, return false
  bool operator==(const DIRECTED_GRAPH<T, N>& rhs) const;
  
  // Purpose: construct this graph to be equivalent to the 
  // specified graph
  // Parameters: rhs is graph to copy 
  // Returns: the graph constructed
  // Postconditions: this graph is equivalent in content and 
  // structure to the specified graph
  DIRECTED_GRAPH<T, N>& operator=(DIRECTED_GRAPH<T, N>& rhs); 
  
  //Purpose: construct a minimal spanning tree
  //Parameters: graph and its size
  //Post: A minimal spanning tree
  //Will also display the combined edge weight of the MST
  void prim(DIRECTED_GRAPH<T, N> & G, int size);

};


#include "DIRECTED_GRAPH.hpp"

#endif // DIRECTED_GRAPH.h

