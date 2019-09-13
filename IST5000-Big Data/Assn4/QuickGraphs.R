# Author: Michael G. Hilgers
# Date: Feb 18 2015

###############################################################
###############################################################
##   Assignment 4 - Quick Sheet for Drawing Graphs
###############################################################
################################################################

# We build graphs from adjacency matrices (discussed in detail elsewhere).
# You will create random matrices.  I will "hard code" an example for these
# notes

require(igraph)
require(RColorBrewer)

A<-rbind(c( NA ,   1,   1,   0,   1,  1,  0,    0,    1,     0),
c( 1,   NA,    0,    1,    1,    0,    0,    1,    0,     0),
c( 1,    0,   NA,    0,    0,    0,    0,    1,    0,     1),
c( 0,    1,    0,   NA,    0,    0,    0,    0,    0,     0),
c( 1,    1,    0,    0,   NA,    1,    0,    0,    0,     0),
c( 1,    0,    0,    0,    1,   NA,    1,    0,    1,     1),
c( 0,    0,    0,    0,    0,    1,   NA,    0,    1,     0),
c( 0,    1,    1,    0,    0,    0,    0,   NA ,   0,     0),
c(  1,    0,    0,    0,    0,    1,    1,    0,   NA,     0),
c(  0,    0,    1,    0,    0,    1,    0,    0,    0,    NA))


######### Basic plot ##########

gA <- graph.adjacency( A, mode="undirected",diag=FALSE )# Create graph from Adj matrix
plot(gA, layout=layout.auto,main="Random Graph")


######## Graph plot with specified color #######
colpal<-brewer.pal(8,"Dark2")  # Good color palette for catagorical variables
		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-colpal[1]	# You choose 1 to 8... try some others
plot(gA, layout=layout.auto,main="Random Graph using Brewer Color Palette")

# If you want to explore more about color pallettes:
help(package=RColorBrewer)
display.brewer.all() # see your options
brewer.pal.info  # details

######## Graph plot with different colors for different vertices #######

# One vertex
pastel<-brewer.pal(8,"Pastel2")  # Try a different palette		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-pastel[1]	# Base color for all nodes
V(gA)[5]$color<-pastel[4]  # changes the 5 vertex to the 4th color of the palette
plot(gA, layout=layout.auto,main="Random Graph A Vertix Colored")

# Range of vertices
anotherPal<-brewer.pal(9,"Set1")  # Try a different palette for no good reason		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-anotherPal[1]	# Base color for all nodes
V(gA)[4:6]$color<-anotherPal[4]  # changes the 5 vertex to the 4th color of the palette
plot(gA, layout=layout.auto,main="Random Graph With A Range of Vertices Colored")

# Subset of vertices
diffPal<-brewer.pal(8,"Accent")  # Try a different palette for no good reason
v<-c(2,5,8,10)		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-diffPal[1]	# Base color for all nodes
V(gA)[v]$color<-diffPal[4]  # changes the 5 vertex to the 4th color of the palette
plot(gA, layout=layout.auto,main="Random Graph With A Range of Vertices Colored")

######## Graph plot with different colors for different edges #######

# One edge
pastel<-brewer.pal(8,"Pastel2")  # Try a different palette		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-pastel[1]	# Base color for all nodes

E(gA)$color<-"black"	# Base colors for edges
E(gA)[1%--%3]$color<-"red"  #  colors the edge from vertex 1 to vertex 3
plot(gA, layout=layout.auto,main="Random Graph An Edge Colored")

# color all edges from a particular node
pastel<-brewer.pal(8,"Pastel2")  # Try a different palette		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-pastel[1]	# Base color for all nodes

E(gA)$color<-"black"	# Base colors for edges
E(gA)[3%--%1:10]$color<-"red"  #  Any edge from 3 to the other vertices
plot(gA, layout=layout.auto,main="Random Graph A Set of Edges Colored")
	
	
######## Combining ideas #######

# color all edges from a particular node
cp<-brewer.pal(12,"Paired")  # Try a different palette		
gA <- graph.adjacency(A, mode="undirected",diag=FALSE )
V(gA)$color<-cp[1]	# Base color for all nodes
V(gA)[5]$color<-cp[6] # Give vertex 5 a different color

# Find neighbors of 5
n<-which(A[,5]==1) # Hint..
V(gA)[n]$color<-cp[5] # Give vertices neighboring 5 a different color

E(gA)$color<-"black"	# Base colors for edges
E(gA)[5%--%n]$color<-"red"  #  Any edge from 5 to its neighbors
plot(gA, layout=layout.auto,main="Random Graph Featuring Vertex 5")


