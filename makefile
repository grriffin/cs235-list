###############################################################
# Program:
#     Assignment 07, LIST
#     Brother JonesL, CS235
# Author:
#     Nathan Rigg, Dallen Cluff, Dan Worwood, Griffin Pope
# Summary:
#     Implementation of list class using linked lists. Took probably 15 hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h assignment07.o fibonacci.o wholeNumber.o
	g++ -o a.out assignment07.o fibonacci.o wholeNumber.o -g  -std=c++11
	tar -cf assignment07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment07.o : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
assignment07.o: list.h assignment07.cpp
	g++ -c assignment07.cpp -g  -std=c++11

fibonacci.o: fibonacci.h fibonacci.cpp list.h
	g++ -c fibonacci.cpp -g  -std=c++11

wholeNumber.o: wholeNumber.h wholeNumber.cpp list.h
	g++ -c wholeNumber.cpp -g  -std=c++11

