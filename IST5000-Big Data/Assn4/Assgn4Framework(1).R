# AUTHOR: Michael G. Hilgers
# Date: Feb 18 2015

###############################################################
###############################################################
##   ASSIGNMENT FOUR - RANDOM GRAPHS
##
##   DUE DATE: Wednesday, March 11, 2015, 11:59 PM
##
##   Value: 100 points
##
###############################################################
################################################################
##
##  NAME:
##
##  INSTRUCTIONS:
##    1)  Please enter your name as above.
##    2)  Save this file with your name as part of the filename.
##    3)  Following the specifications given below, supply the R
##         commands required to make the function behave as 
##         required.
#################################################################


#===============================================================================
# PROBLEM 1) Creating Random Adjacency Matrices
#
# Script Name: adjMatrix
# Input: 
#		n... The number of vertices in the graph
#		p... Probablity two vertices are connected
#		plot... whether or not the matrix should be plotted as a graph
# Output: The nxn matrix of zero and ones
# Error Checking: The dimension is postive (else return NULL)
#
# Description: The matrix is related to a simple, undirected graph of n vertices.
#  In the graph is Vertex i and Vectex j are joined by an edge, then in the matrix
#   A[i,j] = 1, if no edge exists then A[i,j]=0.  There are differenct ways of handling 
#   the diagonal.  We will require the diagonal elements to be NA.
#
#   The matrix must be symmetric.  That is A[i,j]=A[j,1]
#
#   Whether or not an entry in the matrix is 0 or 1, is determined by drawing numbers
#   from the binomial distribution.  This distribution will yield a 1 with probability p and a 
#   o with probability (1-p).  In R it will work like this, in the ith column (vertex i)
#   , we require A[i,i] to be NA.  This leaves n-1 entries to be determined. We
#   use the command rbinom(n-1,1,p) to general these entries all at once, or
#   rbinom(1,1,p) to generate them one at a time.
#
# Plot: Using igraph create a simple plot. Use a color easy on the eyes such
#   as something found in the Brewer color palette (discussed in class)
#

requires(igraph)

adjMatrix<-function(n,p,plot=FALSE)
{
	
}

#============================================================================
# PROBLEM 2) Person with the most friends in the network

# Script Name: vowelMax
# Input: 
#        A... An adjacency matrix
#        plot... Plot the graph with the "friends" network highlighted
# Output: The number of the vertex with the most edge connections
# Error Checking: None
#
# Description: The number of "friends" a person has in a network is the 
#   number of edges connected to that vertex.  The ith person
#   in the network, will be connected to the jth person if A[i,j]=1.  So the 
#   number of 1's in the ith column reports how many edges connect person i to others
#   In mathematical terms, this is called the "degree" of vertex i. 
#
#   So you must determine the number of ones in each column and then find
#   which column has the most ones.
#
# Hint:  There is a quick trick to use here.  Since a column has only
#  0 or 1 in it, the sum of all of the numbers in the column is the same
#  as the number of 1's in the column.  Prove that to yourself. 
#
# Plot: Use igraph to plot the graph. Use three colors for the vertices: one
# for the most friendly person, another for his/her immediate friends, and another
#  for the remaining vertices. Color red the edges from the most friendly person to
#  his/her friends.  All remaining edges are black.
#

mostFriends<-function(A,plot=FALSE)
{
	
	
}


#============================================================================
# PROBLEM 3) Find a lonely person

# Script Name: noFriends
# Input: 
#        A... An adjacency matrix
# Output: The number of the vertex with the no edge connections
# Error Checking: None
#
# Description: The number of "friends" a person has in a network is the 
#   number of edges connected to that vertex.  The ith person
#   in the network, will be connected to the jth person if A[i,j]=1.  So the 
#   number of 1's in the ith column reports how many edges connect person i to others
#   In mathematical terms, this is called the "degree" of vertex i. 
#
#   So you must determine the number of ones in each column and then find
#   which column has the most ones.
#
# Hint:  There is a quick trick to use here.  Since a column has only
#  0 or 1 in it, the sum of all of the numbers in the column is the same
#  as the number of 1's in the column.  Prove that to yourself. 
#
# Plot: Create a plot of the graph using igraph.  Make the "lonely" person/people a
# different color
#

noFriends<-function(A,plot=FALSE)
{
	
}
#============================================================================
# PROBLEM 4) Number of friendship relationships in the network

# Script Name: numFriendships
# Input: 
#        A... An adjacency matrix
# Output: The number of uniqe edges in the graph 
#
# Description:  The number of friendships in the network is the number of edges
#    in the graph.  Basically, count the ones in the adjacency matrix, but be
#    careful.  (Remember, an edge from i to j is the same as an edge from j to 1)
#
#  
#

numFriendships<-function(A)
{
	
}

#============================================================================
# PROBLEM 5) Add a person to the friendship network

# Script Name: addPerson
# Input: 
#        A... An adjacency matrix
#		 p... Probability a relationship forms
#		 plot... Show the new person and relationships
# Output: New adjacency matrix
#
# Description:  As in creating an adjacency matrix, a new column is added
#  and the binomail distribution is used to determine the 1 entries.
#
# Plot: Plot the graph using igraph. Use three colors for the vertices: one
# for the newly added person, another for his/her immediate friends, and another
#  for the remaining vertices. Color red the edges from the new person to
#  his/her friends.  All remaining edges are black.
#
#  
#

addPerson<-function(A,p,plot)
{
	
}
#============================================================================
# PROBLEM 6) Add several people to the friendship network

# Script Name: growNetwork
# Input: 
#        A... An adjacency matrix
#		 p... Probability a relationship forms
#		 n... the number of people to add
#		 plot... Show the new person and relationships
# Output: New adjacency matrix
#
# Plot: Plot the graph using igraph. Use three colors for the vertices: one
# for the newly added person, another for his/her immediate friends, and another
#  for the remaining vertices. Color red the edges from the new person to
#  his/her friends.  All remaining edges are black.
#  
#
growNetwork<-function(A,n,p,plot=FALSE)
{
	
}



