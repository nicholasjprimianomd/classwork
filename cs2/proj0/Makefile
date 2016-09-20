#
# CISC 2000, Project 0: Getting Started (the GUI Version)
# Makefile
#
# Author: Arthur G. Werschulz
# Date:   15 August 2013
#
# Usage:
#   make         - Build all the executables
#   make proj0   - Build the proj0 executable
#   make proj0.o - Compile the proj0.o object file 
#                  (you probably won't need this very often)
#   make clean   - Clean out the directory

TARGET = proj0
OBJS   = proj0.o

GUI_INCLUDES   = /usr/local/include/bjarne/GUI

INCLUDES = -I$(GUI_INCLUDES) -I$(FLTK_INC)
LIBS     = -lX11 -ljpeg -lstdc++ -lbookgui -lfltk -lfltk_images
CXXFLAGS = $(INCLUDES) -Wall 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBFLAGS) $(LIBS)

# A rule to clean up the directory
clean:
	rm -rf $(TARGETS) *.o  *~ core* \#*\#
