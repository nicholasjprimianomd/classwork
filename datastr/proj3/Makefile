# CISC 2200: Data Structures
# Makefile for Project 3
#
# Author: Arthur G. Werschulz
# Date:   3 March 2014

CXXFLAGS=-Wall
# change this to
# CXX=gfilt
# if you want STL error msgs filtered
CXX=g++

######################################################################
# 
# The next section of this Makefile contains two stanzas.  Depending
# on which stack implementation you use, you'll need to make sure that
# the other one is commented out.
#
# As provided, the STL stack version is uncommented, and the author's
# implementation is commented out.
#
######################################################################

# This stanza assumes that you're using the STL stack, rather than one
# of the author's stack implementation.
proj3: proj3.o 
	$(CXX) $(CXXFLAGS) -o proj3 proj3.o

# This stanza assumes that you're using the author's array-based
# stack implementation.  Make the obvious change if you're using
# another implementation.
#
# BTW, I haven't tested this, but I'm pretty sure it's correct.  If
# any of you decide to use one of the author's implementations, let me
# know if there are problems
# 
# proj3: proj3.o ArrayStack.o
# 	$(CXX) $(CXXFLAGS) -o proj3 proj3.o ArrayStack.o
# ArrayStack.o: ArrayStack.cpp ArrayStack.h StackInterface.h
# 	$(CXX) $(CXXFLAGS) -c ArrayStack.h

######################################################################
#
# There is no need for you to touch anything beyond this point.
#
######################################################################

clean:
	rm -f *.o proj3

veryclean:
	rm -f *.o proj3 \#* *~ core*
