/**********************************************************************
 *
 * Project 2: Threaded Fibonacci
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date: 28 October 2013
 *
 * Compute Fibonacci numbers using threads. 
 * 
 **********************************************************************/
//includes
#include <pthread.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Function that computes sequence
void* compute(void* fib_number);
//Global vector to hold sequence 
vector<int> fib;

int main(int argc, char ** argv){
    //New thread variables
    pthread_t child;  
    int fib_number;

    //Input error handling
    if(argc != 2){
	cerr << "Usage: proj2 fib_number" << endl;
	return 1;
    }
    
    //Change input from type string to type int 
    fib_number = atoi(argv[1]);
    //fibs[ 47] is the largest fib number that will fit in an int
    if(fib_number < 0 ||fib_number > 47){
	cerr << "argument was " << argv[1] 
	     <<", must be between 0 and 47 inclusive" << endl;
	return 2;
    }

    //Create new thread and run compute()
    pthread_create(&child, NULL, compute, &fib_number);
    
    //Join threads wait for both to finish executing 
    pthread_join(child, NULL);

    //Print styled Fibonacci sequence
    for (int i = 0; i < fib_number; i++){
	printf("fibs[%3d] = %d \n", i, fib[i]);
    }
    return 0;
}

//Comput Fibonacci sequence
void* compute(void *fib_number){
    //Cast n to int
    int n = *(static_cast<int *>(fib_number));
    
    //Fibs[  0]
    fib.push_back(0);
    //Fibs[  1]
    fib.push_back(1);
    //Generate Fibs[  2...n-1]
    for(int i = 2; i < n; i++){
	fib.push_back(fib[i-1] + fib[i-2]);
    }
    return 0;
}
