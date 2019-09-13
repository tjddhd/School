# Author: Michael G. Hilgers
# Date: Feb 13 2015

###############################################################
###############################################################
##   ASSIGNMENT THREE - BASIC R SKILS
###############################################################
################################################################

# PROBLEM 1) Comparing Vectors
#
# Script Name: longVec
# Input: Two numeric vectors
# Output: One numeric vector
# Error Checking: None
#
# Description: Given two vectors, the longer will be deteremined and returned. In the
# event of a tie, the vector called x will be returned
#

longVec<-function(x,y)
{
	x_len<-length(x)
	y_len<-length(y)
	

	if(x_len < y_len) a<-y
	else a<-x

	return(a)
}

#=======================================================================
# PROBLEM 2) Intersection Subsets
#
# Script Name: commonEven
# Input: Two numeric vectors
# Output: One numeric vector consisting of only even numbers
# Error Checking: 
#     1) If either input is empty, return NULL
#     2) If either vector is not numeric return NULL
#     3) If the vectors have an empty intersection (length of intersection
#          is 0), return NULL
#     4) If there are no even numbers in the intersection return NULL>
#
# Description: Given two vectors, find their intersection (numbers common to both)
#  and remove all of the odd numbers and return the even numbers
#
# Hints:  
# Run the command: help(intersect)
# For a number x, (x%%2) is zero if x is even and one if x is odd.
# Look into indexing a vector with logical values

commonEven<-function(x,y)
{
	test<-intersect(x,y)
	if(length(test)==0) test = NULL

	test = test[! test%%2]
	
	return(test)
}


#================================================================================
# PROBLEM 3) Longest first difference
#
# Script Name: maxDiff
# Input: x: a numeric vector
#		 seqName: a string containing the name of the vector
#
# Output: A nonzero number equal to the maximum absolute difference
#			of the sequence

# Error Checking: 
#     1) If the input is empty, return NULL
#     2) If the vector is not numeric, return NULL
#
# Messages: Best described by examples. See below:
#
#			"|(a[9]-a[8])| = 7 is the maximum absolute difference"
#        
#           "Input vector must be numeric."
# 
#			"Sequence is empty"
#    
# Hint:  
# Run the command: help(intersect)
# For a number x, (x%%2) is zero if x is even and one if x is odd.
# Look into indexing a vector with logical values	
# Description: Given a sequence, {a[j]}, define the maximum absolute difference as
#         maximum absolute difference of {a} = max |(a[j+1]-a[j])|   j=1,2,3,...,n-1
#----------------------------
# Example:
#	
# Good Case:
#
#  > e<-c(5,7,10,8,4,0,2,-3,-10)
#  > e
#   [1]   5   7  10   8   4   0   2  -3 -10
#  > maxDiff(e,"a")
#   [1] "|(a[9]-a[8])| = 7 is the maximum absolute difference"
#   [1] 7
#  
#
# Error case: Nonnumeric vector
#
#  > maxDiff(c("cat","dog"),"pets")
#   [1] "Input vector must be numeric."
#  NULL
#
# Error case: Empty vector
# > x<-c(2341)
# > x<-x[-1]
# > maxDiff(x,"a")
# [1] "Sequence is empty"
# NULL

# End Example-------------------------------


maxDiff<-function(x,seqName)
{
	ret<-NULL

	if(is.null(x)) print("Sequence is empty")

	else if(!is.numeric(x)) print("Input vector must be numeric")

	else
	{
		max = 0
		index = 0
		for(i in 1:(length(x)-1))
		{
			y = abs(x[i+1]-x[i])
			if(y>max)   
			{
				max = y
				index = i
				ret = i
			}		
		}
	}
	
	if(! is.null(ret) )     cat(paste("|(",seqName),paste("[",ret),paste("]-",seqName),paste("[",ret-1),paste("])| = ",max),paste(" is the maximum absolute difference\n"),file="",sep ="")

}

#============================================================================
# PROBLEM 4) Counting vowels in a list a words
#
# Script Name: vowelMax
# Input: A vector of words (character strings)
# Output: The word with the most vowels
# Error Checking: If the vector of words is empty, a message is written saying 
#  "Vector of words is empty" and returning NULL
#
# Description: Given a vector of word (character strings), this function finds and 
#  returns the word with the most vowels.
#

#
vowelMax<-function(a)
{
	if(is.null(a)) print("Vector of words is empty")

	else{
		max = 0
		letters <- c("a","e","i","o","u")
		ret = 1
		a_hat <- a[a %in% letters]

		for(i in 1:length(a))
		{
			if(length(a[a %in% letters])>max)
			{
				max = length(a[a %in% letters])
				ret = i
			}
		}
	
		print(a %in% letters)

	}
}
