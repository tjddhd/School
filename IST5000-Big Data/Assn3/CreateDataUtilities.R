
################################################################
# Various Functions to utilze in demonstrations of creating data
################################################################

maxMinSummary<-function(x)
{
	s<- paste("The largest value: ",max(x))
	print(s)
	
	si<- paste("The location of the largest value: ", which.max(x))
	print(si)
	
	s<- paste("The smallest value: ",min(x))
	print(s)
	
	si<- paste("The location of the smallest value: ", which.min(x))
	print(si)
		
}

mmSummary<-function(x)
{
	s<- paste("The largest value: ",max(x))
	print(s)
	
	si<- paste("The location of the largest value: ", which.max(x))
	print(si)
	
	s<- paste("The smallest value: ",min(x))
	print(s)
	
	si<- paste("The location of the smallest value: ", which.min(x))
	print(si)
	
	# Find the number of times the max appears in the vector
	N<-length(x)
	counter<-1
	M<-max(x)
	for (j in 1:N) 
	{
		if (x[j]==M) counter<-counter+1
	}
	sc<-paste("The number of times the maximum value is repeated: ",counter)
	print(sc)
		
}

evenCounter<-function(x)
{
	counter<-0
	N<-length(x)
	
	for(j in 1:N)
	{
		#  %% is the modulo operator  if x%%2 is zero, x is even.
		if ((x[j]%%2)==0) counter<-counter+1
	}
	se<-paste("The number of even numbers: ",counter)
	print(se)
}

lengthCompare<-function(x,y)
{
	lx<-length(x)
	ly<-length(y)
	
	if(lx < ly) print("y is the longer sequence")
	else if (lx == ly) print("The sequences are the same length.")
	else print("x is the longer sequence")
}

lengthCompareNamed<-function(x,y,names)
{
	lx<-length(x)
	ly<-length(y)
	
	if(lx < ly) print(paste(names[2]," is the longer sequence"))
	else if (lx == ly) print("The sequences are the same length.")
	else print(paste(names[1]," is the longer sequence"))
}



#  Linear Transformation
L<-function(x,m=1,b=0)  # Default transformation is y=x
{
	return(m*x + b)
}

inv<-function(n)
{
	return(1/n)
}


fourierSum<-function(x,L,terms)
{
	# Think of x as a scalar not a vector
	#terms=3
	#L=1
	#x<-0.5
	odds<-seq(1,by=2,length.out=terms)
	cp<-pi/L
	op<-cp*odds
	y<-x*op
	oddsinv<-inv(odds)
	s<-sin(y)
	ts<-oddsinv*s
	fsum <- (4/pi)*sum(ts)
}

T<-function(x,L,terms)
{
	N<-length(x)
	z<-numeric(N)
	
	for(j in 1:N)
	{
		z[j]<-fourierSum(x[j],L,terms)
	}
			
	return(z)
	
}

squareWave<-function(x,L)
{
	N<-length(x)
	z<-numeric(N)
	
	for (j in 1:N)
	{
		u<-x[j]
		
		if (u<0) z[j]<-0
		else if ((0<=u)&(u< L)) z[j]<- 1
		else if ((L<=u)&(u< 2*L)) z[j]<- -1
		else z[j]<0
		
	}
	return(z)
}

GibbsPlot<-function(x,y,L)
{
	ysq<-squareWave(x,L)
	df<-data.frame(indepVar=x,depFour=y,depSq=ysq)
	p<-ggplot(data=df, aes(x=indepVar)) + xlim(-0.5,2*L+0.5) + ylim(-1.5,1.5)
	p+geom_line(aes(y=depSq)) + geom_line(aes(y=depFour),colour="red")
}

