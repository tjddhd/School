# Author: Michael G. Hilgers
# Date: Feb 11 2015

###############################################################
###############################################################
##   Various Examples of Generating Data 
#      with Different Characteristics
###############################################################
################################################################

# Functions to be used
#  : operator
# seq()
# seq.int()
# args()
# round

################################################################
###################  Deterministic Data Sets ###################
################################################################

#==================== Uniformly distributed Sequences ==============#
# Concept: 
#
#  a(j+1) = a(j) + da
#

## Case:  da = 1
#---> Use the : operator
#     syntax==> from:to

2:10			
-9:-1
(2:20)*3
(5:10) + 2


x<-0
for (j in 5:10) x<-x+j  # Application: Using a sequence to control iteration

length(3:10)  # Number of elements in the sequence

(1:5)			# Certain operations
(11:15)
(1:5)*(11:15)	
(5:10)-(6:11)




## Case: da arbitrary but given

#Performance Note !!!!!!!!!!!!!!!!!!!!!!111
# the "seq" function is what is called "generic" (think "abstract" in OO programming)
#  "seq.int" is an internally implemented primitive function.  It is written in C 
#  and directlyt compiled into the R program.  We'll use it

#  What are the arguments we have available
args(seq.int)

# syntax: seq.int(to) [from=1, by= +1 or -1]
seq.int()     # from = to = 1
seq.int(10)   # Starts at 1 counts to 10 by 1
seq.int(-9)		# Starts at 1 counts to -9 by -1

# syntax: seq.int(from, to,by) 
seq.int(2,10)  # assume from is 2 and to is 10... default by to 1
seq.int(10,2) # assume start=10 set by to -1 to count down

#!!!!!!! Hint: To avoid confusion in more complex sequence construction use keywords
seq.int(from=pi,to=4*pi,by=0.1)
seq.int(to=4*pi,by=0.1)
seq.int(from=pi,by=0.1) ### Error: to defaults to 1 if not specified... ?"seq.int"

# by can be neagive
seq.int(from=5,to=-4,by=-0.2)

# Results can be messy with too many digits.  Use round()
seq.int(from=5,to=-4,by=-pi/13)
round(seq.int(from=5,to=-4,by=-pi/13),2)  # Number of decimal places



# create a uniform sequence in the range of a function
t<-seq.int(from=0,to=12*pi,by=0.1)
m<-min(exp(-t)*sin(10*t))
M<-max(exp(-t)*sin(10*t))
r<-seq(from=m,to=M,by=0.1)
length(r)

#********* Playing with functions ******************
# Function: Reports the details of the max & min
z<-seq(-1.1,5.6,0.2)
maxMinSummary(z)


# Function: Which sequence is longer?
a<-1:15
b<-seq(-1,22.3,by=2)
lengthCompare(a,b)     # Notice the output is weird because of the names

# Function: What is the name of the longest sequence?
seqNames<-c("a","b") # Gave sequences a name
lengthCompareNamed(a,b,seqNames)
seqNames<-c("Colon operator","seq command") # Gave sequences a name
lengthCompareNamed(a,b,seqNames)


#=================== Data with Repeating Patterns ===========#

rep(1:5,2) # basic
rep(1:5) # repeat once
rep(c(3,2,5),3)

arg(rep.int)  # data and times only
rep.int(1:100,3)  # faster than rep

rep(seq(3,9,0.2),times=3)
rep(seq(3,9,0.2),times=3,length.out=20) # gives only 20 of vec created
rep(c(-1,1),length.out=30)

rep(1:5,times=2,each=3)
rep(1:5,each=3)

z<-rep(1:5,times=2,each=3,length.out=40)
maxMinSummary(z)
mmSummary(z)

#######################################################################################
###################  Stochastic Data Sets - Random Number Generation ###################
####################################################################################
#
# There are many extremely important concepts.  These will be discuss in
# a separate document.


#========================== Scrambling sequences via sampling ===============

sample(1:10,5,replace=TRUE)  # with replacement means values may be repeated

sample(1:10,5,replace=FALSE) 

z<-sample(1:1000,100,replace=TRUE)

# Samples are random and change
sample(1:100,10,replace=TRUE)
sample(1:100,10,replace=TRUE)
sample(1:100,10,replace=TRUE)

# Reuse functions
mmSummary(z)


# Function: How many even numbers in the sample?
z<-sample(1:1000,100,replace=TRUE) # new sample
evenCounter(z)
z<-sample(1:1000,100,replace=TRUE) # new sample
evenCounter(z)

#========================== Uniform distribution =======================
#
#  By default, this randomly selects real numbers in (0,1) so that each is equally 
#   likely (that statement will be improved
args(runif)
runif(20)  # create 20 random numbers

xs<-seq(1,by=0.1,length.out=50)
summary(xs)							# summary() mean and quartiles

xse<-xs + runif(50)  # Noisey sequence
summary(xse)

runif(20,min=-1,max=1)
eps<-0.05
xe<-seq(1,by=0.1,length.out=50) + eps*runif(50,min=-1,max=1)

# A peek ahead
# Visualization - Using histograms to visualize probability distributions
dat<-runif(50,min=-1,max=1)
hist(dat)

op <- par(mfrow = c(2, 2))  # This puts the next 4 plots in a 2X2 wineow
dat<-runif(50,min=-1,max=1)
hist(dat,density=TRUE,freq=FALSE,main="Histogram of 50 points")

dat<-runif(500,min=-1,max=1)
hist(dat,density=TRUE,freq=FALSE,main="Histogram of 500 points")

dat<-runif(1500,min=-1,max=1)
hist(dat,density=TRUE,freq=FALSE,main="Histogram of 1500 points")

dat<-runif(5000,min=-1,max=1)
hist(dat,density=TRUE,freq=FALSE,main="Histogram of 5000 points")


#======================= Normal distribution =========================
#
#  By default, this randomly selects any real numbers such that the choice form a normal
#  distribution (that statement will be improved
args(rnorm)

rnorm(50)  # Standard normal:  mean = 0 sd=1
testValues <- rnorm(5000)
testdf = as.data.frame(testValues)
ggplot(data=testdf,aes(x=testValues)) + stat_bin() # simple histogram in {ggplot2}


## Example: White Noise
x<-seq(0,by=0.1,length.out=50)

y<-4.2*x-0.5
summary(y)

e<-rnorm(50)
ye<-4.2*x-0.5 + e
summary(ye)

df<-data.frame(X=x,Y=y,YE=ye)
ggplot(data=df,aes(x=X)) + geom_line(aes(y=Y),colour="red")+geom_line(aes(y=YE),colour="blue")


########## ADVANCED EXAMPLE ##################3
# Comparing Distributions
pts<-c(100,500,5000,10000)
means<-c(0,0,0,0)
sds<-c(1,1,1,1.0)
normalTester(pts,means,sds,3.0,"SampleSize.pdf")



## Example: White Noise
x<-seq(0,by=0.1,length.out=50)
e<-rnorm(50)
y<-4.2*x-0.5
ye<-4.2*x-0.5 + e

df<-data.frame(X=x,Y=y,YE=ye)
ggplot(data=df,aes(x=X)) + geom_line(aes(y=Y),colour="red")+geom_line(aes(y=YE),colour="blue")



#---------------- Transformation of Uniformly distributed Sequences ---- #
# Concept: Let T be a mapping from real numbers to real numbers..  T:R->R
#
#  a(j+1) = a(j) + da
#
#  x(j) = T(a(j))

## CASE:  T() is linear - Denote as L(s)
#	L(x) = mx + b for fixed constants m and b (recall: m is slope , b is y-intercept)

a<-seq(from=0, to = 5, by=0.1)  # Build base uniform sequence
x<- 5*a -1						# Linear Transform with m=5 b=2

# Sometimes you want a real "quick" plot.  This is qplot from the {ggplot2} package. We will
#   it sometimes.  It is almost transparent to use.
require(ggplot2)
qplot(a,x)  # extremely simple for quick peek
qplot(a,x,xlab="Uniform Sequence",ylab="Linear Transform",main="Scatter Plot of Linear Transformation")  # extremely simple for quick peek (Scatterplot)
qplot(a,x,xlab="Uniform Sequence",ylab="Linear Transform",geom="line",main="Line Plot of a Linear Transformation")  # extremely simple for quick peek (Scatterplot)


## Slightly more general transformation
x<-seq(from=0, to = 5, by=0.1)  # Build base uniform sequence

m<--2.3
b<-1.5
y<- m*x + b    # Transformation in slope/intercept form

qplot(x,y,xlab="Uniform Sequence",ylab="Linear Transform",
	geom="line",main="Linear Transformation (y=mx+b")  # extremely simple for quick peek (Scatterplot)
	
## L() is a function defined by me. See MyUtilities.R 
x<-seq(from=0, to = 5, by=0.1)  # Build base uniform sequence
y<-L(x,-2.3,2.2)                # creates line  y = -2.3x+2.2

qplot(x,y,xlab="Uniform Sequence",ylab="Linear Transform",
	geom="line",main="Linear Transformation L(x)")  # extremely simple for quick peek (Scatterplot)


########### A fun (advanced) application
### Gibbs phenomena ########	
x<-seq(from=0, to = 2, by=0.001)  # Build base uniform sequence
y<-T(x,1,50)
GibbsPlot(x,y,1)




