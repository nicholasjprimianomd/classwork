/**********************************************************************
 *
 * Project 1: Fast selection
 *
 * Author: Harry Q. Bovik, PhD
 * Date:   3 March 2015
 *
 * Say something here.
 *
 **********************************************************************/

#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * function declarations
 */

template <class T> vector<T> getData(string fileName);
template <class T>
T select(vector<T> data, int k, int& numComparisons);
template <class T>
T select(vector<T> data, int left, int right, int k, int& numComparisons);

int main()
{
   /*
    * get the data
    */
   string dataFileName = "/u/sobolev/agw/class/algorithms/share/proj1/data";
   vector<int> dataVec = getData<int>(dataFileName);

   /*
    * find some statistics about our data
    */
   int numComparisons;                  // how many comparisons were used

   // get min and max
   int size = dataVec.size();        // save some typing
   int smallest = select(dataVec, 1, numComparisons);
   cout << "Smallest = " << smallest
        << ", comparisons = " << numComparisons << endl;
   int largest = select(dataVec, size, numComparisons);
   cout << "Largest = " << largest 
        << ", comparisons = " << numComparisons << endl;

   // get deciles
   for (unsigned int i = 1; i <= 10; i++) {
      int decile = select(dataVec, round((i*size)/10), numComparisons);
      cout << "Decile #" << i << " = " << decile
           << ", comparisons = " << numComparisons << endl;
   }

   return 0;
}

/*
 * function definitions
 */

// read data from a file, store in a vector
template <class T> 
vector<T> getData(string fileName)
{
   ifstream dataStream(fileName.c_str());
   if (!dataStream) {
      cerr << "can't open " << fileName << endl;
      exit(1);
   }

   vector<int> dataVec; 
   int datum;
   while (dataStream >> datum) dataVec.push_back(datum);
   return dataVec;
}

// 
template <class T>
T select(vector<T> data, int k, int& numComparisons)
{
   return select(data, 0, data.size() - 1, k, numComparisons);
}

// here's where you do your real work
// this is a stub version
// your comment?
template <class T>
T select(vector<T> data, int left, int right, int k, int& numComparisons)
{
   // some numbers I threw in just to get this to run
   numComparisons = 123;
   return 42;
}
