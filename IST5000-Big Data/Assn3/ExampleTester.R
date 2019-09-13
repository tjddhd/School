# Author: Michael G. Hilgers
# Date: Feb 13 2015

###############################################################
###############################################################
##   ASSIGNMENT THREE - Example Tester Script
###############################################################
################################################################

# Students supply the definitions for the scripts: longVec(), commonEven(), maxDiff(),
#   and vowelMax().  I will compile those then run a script I suppy to test them.  This
#  is just an example.

# Examples of testing longVec() (Mix up whether max is on left or right, data types, equality, etc

x<-1:10
y<-1:15
longVec(x,y)

y<-1:4
longVec(x,y)

x<-1:5
y<-1:5
longVec(x,y)

x<-seq(3.2,by=-2.4,length.out=20)
y<-seq(pi,by=192.4,length.out=20)
longVec(x,y)

# Examples of testing commonEven() (Mix up errors with normal. Have some by insepction

x<-3:10
y<-3:10
commonEven(x,y)

x<-11:15
y<-3:10
commonEven(x,y)

x<-seq(1,11,by=2)
y<-seq(2,12,by=2)
commonEven(x,y)


x<-c("cat","dog","bird")
y<-1:12
commonEven(x,y)

# Examples of testing maxDiff()

x<-c(1,3,8,-2,-2)
maxDiff(x,"b")

x<-NULL
maxDiff(x,"b")

x<-NA
maxDiff(x,"b")


# Examples of testing vowelMax()

x<-c("a","aa","aae","eaeo","aeiou","aaaaeeee")
vowelMax(x)

x<-c("abc","defea","aeioggggg","ddddd")
vowelMax(x)







