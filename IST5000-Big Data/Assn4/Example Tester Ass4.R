# AUTHOR: Michael G. Hilgers
# Date: Feb 18 2015

###############################################################
###############################################################
##
##   ASSIGNMENT FOUR - EXAMPLE TESTER
##
###############################################################
################################################################
##
##  INSTRUCTIONS: Once you have written the R functions
##
##    adjMatrix()
##    noFriends()
##    addPerson()
##    growNetwork()
##
##  in the framework file, run them.  Then use this script to 
##  see if they appear to be working.
##
###############################################################
################################################################

A<-adjMatrix(10,0.4,TRUE)

adjMatrix(10,0.8,TRUE)
adjMatrix(10,0.2,FALSE)
adjMatrix(10,0.8,FALSE)


A<-adjMatrix(10,0.2,FALSE)
x<-mostFriends(A,TRUE)


A<-adjMatrix(20,0.1,FALSE)
x<-noFriends(A,TRUE)

A<-adjMatrix(10,0.1,FALSE)
x<-addPerson(A,0.8,TRUE)


A<-adjMatrix(10,0.4,TRUE)
x<-growNetwork(A,3,0.8,TRUE)


