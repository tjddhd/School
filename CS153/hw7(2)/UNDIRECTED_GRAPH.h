/*!\file UNDIRECTED_GRAPH.h
 * \author Lisa Tatro && Thomas Dolan
 * \brief class definition for a undirected graph
 */
 
 #ifndef UNDIRECTED_GRAPH_H
 #define UNDIRECTED_GRAPH_H
 
 #include "DIRECTED_GRAPH.h"
 #include <stdexcept>
 #include <iostream>
 using namespace std;
 
 template <class T, unsigned int N>
 class UNDIRECTED_GRAPH: protected DIRECTED_GRAPH<T,N> {

public:

  // Purpose: default constructor
  // Postconditions: initializes the data structure to be have N vertices,
  // no edges, and a data value for each vertex (initialized to the default
  // value for type T)
  UNDIRECTED_GRAPH() {}
  
  // Purpose: destructor
  // Postconditions: removes all edges and deallocates all dynamically 
  // allocated memory associated with the data structure (via clear)
  ~UNDIRECTED_GRAPH() { clear(); }
  
  // Purpose: clear this graph
  // Postconditions: removes all edges and deallocates all dynamically 
  // allocated memory associated with the data structure
  void clear() { DIRECTED_GRAPH<T,N>:: clear(); }
  
  // Purpose: determine whether there is a vertex with a specified data value
  // Parameters: x is the data value to be found
  // Returns: true if there is a vertex with data value x; otherwise, false
  bool find(const T& x) const {DIRECTED_GRAPH<T,N>:: find(x); }
  
  // Purpose: add edge(i,j) with weight w
  // Parameters: i is source vertex, j is destination vertex, w is weight
  // (note: default value for weight is 1)
  // Postconditions: edge (i, j) is added to the graph with weight w
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  void addEdge(const unsigned int i, const unsigned int j, const int w=1);
  
  // Purpose: remove edge(i,j) 
  // Parameters: i is source vertex, j is destination vertex
  // Postconditions: edge (i, j) is removed from the graph 
  // Exceptions: if i or j >= # vertices in this graph then throw
  // an out_of_range error
  void removeEdge(const unsigned int i, const unsigned int j);
  
  // Purpose: get the # edges to vertex i 
  // Parameters: i is the specified vertex
  // Returns: the # edges coming  to vertex i
  // Exceptions: if i >= # vertices in this graph then throw
  // an out_of_range error
  int vertexDegree(const unsigned int i) const;
  
  // Purpose: determine the degree of this graph 
  // Returns: the sum of the inDegree and outDegree of every vertex 
  // in this graph
  int graphDegree() const;
  
  // Purpose: determine whether this graph is simple (i.e., contains no
  // loops (e.g., (u, u))) 
  // Returns: true if this graph is simple; otherwise, false
  bool isSimple() const;
  
  // Purpose: determine whether this graph is complete (i.e., is simple and
  // there is an edge (u, v) or (v, u) for every pair of vertices u and v)
  // Returns: true if this graph is complete; otherwise, false
  bool isComplete() const;
  
   // Purpose: construct this graph to be the complement of the 
  // specified graph (i.e., if there is an edge (i,j) in compMe, then
  // there should not be an edge (i,j) in this graph; if there is not an edge
  // (i,j) in compMe, then there should be an edge (i,j) with weight 1 in
  // this graph)
  // Parameters: compMe is the graph that this graph should become 
  // the complement of 
  // Postconditions: this graph is the complement of graph compMe
  void complement(const UNDIRECTED_GRAPH<T,N>& compMe) {DIRECTED_GRAPH<T,N>::complement(compMe);};
  
  // Purpose: determine whether or not this graph is equivalent to
  // a specified graph 
  // Parameters: rhs is the graph to be compared to this graph
  // Returns: if the graphs are exactly the same in terms of 
  // structure and content, return true; otherwise, return false
  bool operator==(const UNDIRECTED_GRAPH<T,N>& rhs) const;
  
  // Purpose: construct this graph to be equivalent to the 
  // specified graph
  // Parameters: rhs is graph to copy 
  // Returns: the graph constructed
  // Postconditions: this graph is equivalent in content and 
  // structure to the specified graph
  UNDIRECTED_GRAPH<T,N>& operator=(DIRECTED_GRAPH<T,N>& rhs);
  
  const unsigned int size() const { return COLLECTION<T>::size(); }
  bool isEmpty() const { return COLLECTION<T>::isEmpty(); }
  void setVertexData(const unsigned int i, const T& data) {DIRECTED_GRAPH<T, N>::setVertexData(i, data);}
  bool isEdge(const unsigned int i, const unsigned int j) const {return (DIRECTED_GRAPH<T,N>::isEdge(i, j));} 
  T getVertexData(const unsigned int i) const {return DIRECTED_GRAPH<T, N>::getVertexData(i);}
  int getEdgeWeight(const unsigned int i, const unsigned int j) const {return DIRECTED_GRAPH<T, N>::getEdgeWeight(i, j);}
  void setEdgeWeight(const unsigned int i,const unsigned int j, const int w) {DIRECTED_GRAPH<T, N>::setEdgeWeight(i, j, w);}
  bool isAcyclic() const { return DIRECTED_GRAPH<T,N>::isAcyclic(); }
 
 };
 
 #include "UNDIRECTED_GRAPH.hpp"
 
 #endif
