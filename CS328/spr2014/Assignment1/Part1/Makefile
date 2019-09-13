#######################################
# Name:       Thomas Dolan
# Class:      CS328
# Professor:  Clayton Price
# Assignment: 1
# File name:  makefile1.txt
# Semester:   Spring 2014
#######################################

default: all

all: driver

driver: brewMain.o\
        additives.o\
        beer.o
	g++ brewMain.o additives.o beer.o -o driver
	
brewMain.o: brewMain.cpp\
            wine.h\
            wine.hpp\
            yeast.h\
            additives.h\
            beer.h\
            hops.h\
            grains.h
	g++ -c brewMain.cpp -o brewMain.o

additives.o: additives.cpp\
             additives.h
	g++ -c additives.cpp -o additives.o

beer.o: beer.cpp\
        beer.h\
        yeast.h\
        hops.h\
        grains.h
	g++ -c beer.cpp -o beer.o
	
clean:
	-@rm core > /dev/null 2>&1
	-@rm driver > /dev/null 2>&1
	-@rm brewMain.o > /dev/null 2>&1
	-@rm additives.o > /dev/null 2>&1
	-@rm beer.o > /dev/null 2>&1
