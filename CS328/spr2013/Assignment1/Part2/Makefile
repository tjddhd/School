#######################################
#File name:  makefile2.txt
#Name:       Thomas Dolan
#Class:      CS328
#Professor:  Clayton Price
#Assignment: 1
#Semester:   Spring 2013
#######################################

CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors 

OBJECTS = additives.o\
          beer.o\
		  brewMain.o
		  
.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${CXXFLAGS} $< -o $@
	
default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@
	
clean:
	-@rm core > /dev/null 2>&1
	-@rm driver > /dev/null 2>&1
	-@rm ${OBJECTS} > /dev/null 2>&1
	
additives.o: additives.h additives.cpp
beer.o:      beer.h yeast.h hops.h grains.h beer.cpp
brewMian.o:  wine.h yeast.h additives.h wine.hpp beer.h hops.h grains.h brewMain.cpp