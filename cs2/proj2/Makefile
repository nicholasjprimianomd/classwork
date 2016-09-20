#
# CISC 2000, Project 2: Extending the GUI
# Makefile
#
# Author: A. G. Werschulz <agw AT dsm.fordham.edu>
# Date:   13 Aug 2013
#
# Usage:
#     make           - Build proj2 executable
#     make proj2.o   - Compile proj2.o (you probably won't need to do this)
#     make Square.o  - Compile square.o (you probably won't need to do this)
#     make clean     - Clean out the directory
#

TARGET = proj2
OBJS   = proj2.o Square.o

GUI_INCLUDES   = /usr/local/include/bjarne/GUI

INCLUDES = -I$(GUI_INCLUDES) -I$(FLTK_INC)
LIBS     = -lX11 -ljpeg -lstdc++ -lbookgui -lfltk -lfltk_images
CXXFLAGS = $(INCLUDES) -Wall 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBFLAGS) $(LIBS)

Square.o: Square.cc Square.h

# A rule to clean up the directory
clean:
	rm -rf $(TARGETS) *.o  *~ core* \#*\#
