#
# CISC 2000, Project 5: Timing Has Come Today
# Makefile
#
# Author: A. G. Werschulz <agw AT dsm.fordham.edu>
# Date:   24 November 2013
#
# Usage:
#     make           - Build proj5 executable
#     make proj5     - Build proj5 executable
#     make proj5.o   - Compile proj5.cc
#     make clean     - Clean out the directory
#

# C++11 has an is_sorted() algorithm, which we will use.  So ...
CPP11    = -std=c++11

INCLUDES = -I/usr/local/include/bjarne

# Uncomment this if you want STL-based warnings and templates to be 
# somewhat more readable.
#CXX=gfilt

PICKY    = -Wall -pedantic
CXXFLAGS = $(INCLUDES) $(CPP11) $(PICKY)

TARGET = proj5 
OBJS   = proj5.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm -rf $(TARGETS) *.o  *~ core* \#*\#
