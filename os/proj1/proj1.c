/**********************************************************************
 *
 * CISC 3595, Fall 2013
 * Project 1: A Simple Version of "cp"
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date:   30 Sep1t 2013
 *
 * This is a C++ implementation, to be used as a guide for the C
 * implementation. 
 *
 **********************************************************************/

/*
  includes
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

/*
  global define
 */

#define BUFFER_SIZE 65536     //size of file buffer

/*
  funtion declarations
 */

void input_usage();
int copyfile(const char* scr, const char* dest);

int main(int argc, char** argv)
{
	//proper input check
	if (argc != 3) {
		input_usage();
		return 1;
	}
	
	//copy file argv[1] to file argv[2]
	return copyfile(argv[1], argv[2]);
		
	return 0;
}

//checks for proper input
void input_usage()
{
	printf("usage: proj1 SOURCE DEST\n");
}

/*     copies scr file to destfile takes a char pointer to the source
       file and a charpointer to the destination
*/
int copyfile(const char* src, const char* dest)
{
	char buffer[BUFFER_SIZE];
	
	//open file for reading
	int filedsrc = open(src, O_RDONLY);
	if(filedsrc  == -1){
		fprintf(stderr,"Could not open  %s for copying\n", src);
		return 2;
	}
	
	//open file for writing
	int fddest = open(dest,O_WRONLY|O_CREAT,S_IRWXU);
	if(fddest == -1){
		fprintf(stderr,"Could not copy to %s.\n", dest);
		return 3;
	}
	
	//read src file into buffer
	size_t actual_size = read(open(src, O_RDONLY),buffer,sizeof(buffer));
	if (actual_size < 0){
		fprintf(stderr, "Could not read %s", src);
		return 4;
	}
	
	//loop to write src file to dest file
	bool loop = true;
	while(loop) {		
	 	int result = write(fddest, buffer, actual_size);
		if (result < 0){
			fprintf(stderr, "Could not write to %s.\n", dest);
			return 5;
		}
		if (result < sizeof(buffer)){ 
			return 0;
		}
	}
	close(filedsrc);
	close(fddest);
	return 0;
}
