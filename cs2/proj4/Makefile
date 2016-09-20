#
# CISC 2000, Project 4: Strings, the Hard Way
# Makefile
#
# Author: A. G. Werschulz <agw AT dsm.fordham.edu>
# Date:   1 November 2014
#
# Usage:
#     make           - Build proj4 executable
#     make proj4     - Build proj4 executable
#     make proj4.o   - Compile proj4.cc
#     make clean     - Clean out the directory
#

TARGET = proj4
OBJS   = proj4.o 

# delete the "#" in the next line if you need to use a debugger
CXXFLAGS = -Wall #-g

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm -rf $(TARGET) *.o  *~ core* \#*\#
