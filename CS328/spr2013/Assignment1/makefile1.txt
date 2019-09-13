#######################################
#File name:  makefile1.txt
#Name:       Thomas Dolan
#Class:      CS328
#Professor:  Clayton Price
#Assignment: 1
#Semester:   Spring 2013
#######################################

default: all

all: driver

driver: driver.o\
		parser.o\
		scanner.o\
		signal.o\
		token.o\
		tokenlist.o
	g++ driver.o parser.o scanner.o signal.o token.o tokenlist.o -o driver

driver.o: enChar.h\
          signal.h\
		  parser.h\
		  tokenlist.h\
		  token.h\
		  enTokens.h\
		  Amatrix.h\
		  Avector.h\
		  scanner.h\
		  driver.cpp
	g++ -c driver.cpp
	
parser.o: parser.h\
          tokenlist.h\
		  token.h\
		  enTokens.h\
		  Amatrix.h\
		  Avector.h\
		  signal.h\
		  parser.cpp
	g++ -c parser.cpp

scanner.o: scanner.h\
           enChar.h\
		   tokenlist.h\
		   token.h\
		   enTokens.h\
		   signal.h\
		   scanner.cpp
	g++ -c scanner.cpp

signal.o: signal.h\
          signal.cpp
	g++ -c signal.cpp

token.o: token.h\
         enTokens.h\
		 token.cpp
	g++ -c token.cpp

tokenlist.o: tokenlist.h\
             token.h\
			 enTokens.h\
			 signal.h\
			 tokenlist.cpp
	g++ -c tokenlist.cpp
	
clean:
	-@rm core > /dev/null 2>&1
	-@rm driver > /dev/null 2>&1
	-@rm driver.o > /dev/null 2>&1
	-@rm parser.o > /dev/null 2>&1
	-@rm scanner.o > /dev/null 2>&1
	-@rm signal.o > /dev/null 2>&1
	-@rm token.o > /dev/null 2>&1
	-@rm tokenlist.o > /dev/null 2>&1