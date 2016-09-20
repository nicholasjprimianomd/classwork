#
# CISC 2000, Project 1: Some Computer Graphics Examples
# Makefile
#
# Author: Arthur G. Werschulz
# Date:   9 September 2013
#
# This Makefile builds an executable out of any source file in the
# current directory whose name ends in ".cc".
#
# Sample usages:
#   make          - Build all the executables
#   make proj1a   - Build the proj0 executable
#   make proj1a.o - Compile the proj0.o object file 
#                  (you probably won't need this very often)
#   make clean   - Clean out the directory

GUI_INCLUDES   = /usr/local/include/bjarne/GUI

INCLUDES = -I$(GUI_INCLUDES) -I$(FLTK_INC)
LIBS     = -lstdc++ -lbookgui -lfltk -lfltk_images -lX11 -ljpeg
CXXFLAGS = $(INCLUDES) -Wall

.SUFFIXES: .cc .o

# Create a list of source files.
SOURCES  = $(shell ls *.cc)
# Create a list of object files from the source file lists.
OBJECTS = ${SOURCES:.cc=.o}     
# Create a list of targets.
TARGETS = ${SOURCES:.cc=}     

# Build all targets by default
all: 	$(TARGETS)

# A rule to build executable file out of an .o file
$(TARGETS): %: %.o $(GUI_LIB)
	$(CXX) -o $@ $(LIBFLAGS) $< $(LIBS)

# A rule to build .o file out of a $(SOURCE_EXT) file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# A rule to clean all the intermediates, targets, emacs backup files,
# core files, etc.
clean:	
	rm -rf $(TARGETS) $(OBJECTS) *.out *.stackdump *~ core* \#*\#
