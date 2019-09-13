default:	all

all:	run

run:	main	\
		sumSquares
	g++ main.o sumSquares.o -o driver
	
libsumSquares.so:	sumSquares.o
	
sumSquares:	sumSquares.h	\
			sumSquares.cpp
		g++ -c sumSquares.cpp

main:	sumSquares.h	\
		libsumSquares.so	\
		main.o	\
		main.cpp
	g++ -c main.cpp 
	
clean:	
	rm main.o libsumSquares.so a.out driver sumSquares.o -rf
	
tar: 
	tar -cvzf tjddhd.tgz main.cpp sumSquares.h sumSquares.cpp Makefile