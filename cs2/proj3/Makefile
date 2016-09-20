# Project 3: Makefile
#
# Author: A. G. Werschulz <agw AT dsm.fordham.edu>
# Date:   15 Feb 2010
#
# Usage:
#     make         - Build proj3 executable
#     make all     - Build proj3 executable#    
#     make proj3   - Build proj3 executable
#     make proj3.o - Compile proj3a.cc
#     make clean   - Clean out the directory

GUI_INCLUDES   = /usr/local/include/bjarne/GUI

# Needed for g++ 4.4.2 under Fedora 12 Linux.
IGNORE_DEPRECATIONS=-Wno-deprecated

INCLUDES = -I$(GUI_INCLUDES) -I$(FLTK_INC)

LIBS     = -ljpeg -lstdc++ -lbookgui -lfltk -lfltk_images -lX11 -ljpeg -Wall
CXXFLAGS = $(INCLUDES) -DNDEBUG $(IGNORE_DEPRECATIONS) 

TARGETS = proj3

all: $(TARGETS)

# A rule to build executable file out of a .o file
$(TARGETS): %: %.o
	$(CXX) -o $@ $(LIBFLAGS) $< $(LIBS)

# A rule to build .o file out of a .cc file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# A rule to clean up the directory
clean:
	rm -rf $(TARGETS) *.o  *~ core* \#*\#

