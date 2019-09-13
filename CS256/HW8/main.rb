

x =100
y =100
total =0
temp = 0

while x <1000
{	while y <1000
	{	temp = x*y
		if "#{temp}" == "#{temp}".reverse
			total = temp
		
		y=y+1
	
	}
	x=x+1
	
}
