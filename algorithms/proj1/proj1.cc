/**********************************************************************
 *
 * Project 1: Fast selection
 *
 * Author: Nicholas Primiano
 * Date:   23 March 2015
 *
 * This is a randomized divide and conquer algorithm for selection.
 * The algorithm finds the kth smallest (or largest) value in an 
 * array and counts the number of comparisons it took to find the
 * element.
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
T select(vector<T> data, int left, int right, unsigned int k, int& numComparisons);

int main()
{
    /*
     * get the data
     */
    string dataFileName =
	"/u/sobolev/agw/class/algorithms/share/proj1/data";
    vector<int> dataVec = getData<int>(dataFileName);

    /*
     * find some statistics about our data
     */
    int numComparisons;                  // how many comparisons were
					 // used

    // get min and max
    int size = dataVec.size();        // save some typing
    int smallest = select(dataVec, 1, numComparisons);
    cout << "Smallest = " << smallest
	 << ", comparisons = " << numComparisons << endl;
    numComparisons = 0;
    int largest = select(dataVec, size, numComparisons);
    cout << "Largest = " << largest
	 << ", comparisons = " << numComparisons << endl;
    //get deciles
    for (unsigned int i = 1; i <= 10; i++) {
	numComparisons = 0;
	int decile = select(dataVec, round((i*size)/10),
			    numComparisons);
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

/*
 *Container function for recursive calls
 */

template <class T>
T select(vector<T> data, int k, int& numComparisons)
{
    return select(data, 0, data.size() - 1, k, numComparisons);
}

/*
 * This function sorts a data vector into three separate vectors
 * around a random pivot point. The new vectors are made up of 
 * values of the origional data set that are, less than, greater than, 
 * or equal to the pivot.
 *
 * If k is less than the number of elements in the left vector, the
 * function is called on the less than data set.  If k is greater than 
 * the number of elements in the left vector and less than or equal to
 * the number of elements in left vector plus the number of elements
 * in the pivot vector, the function returns the 0th element in the
 * pivot vector. If k is greater than the size of the left vector plus 
 * the size of the pivot vector, the function is called on greater than 
 * vector.
 *
 */

template <class T>
T select(vector<T> data, int left, int right, unsigned int k, int& numComparisons)
{
    //declare sorting vectors
    vector<T> Sl;
    vector<T> Sr;
    vector<T> v;

    if(data.size()==1) {
	return data[0]; //only one element left, return this element
    }

    srand(time(NULL));
    int pIndex = rand() % (data.size()-1);
    int value = data[pIndex];

    //place elements in correct vectors
    for(unsigned int i = 0; i < data.size(); i++) {
	if(data[i] < value){
	    Sl.push_back(data[i]);
	    numComparisons = numComparisons + 1;
	}
	else if(data[i] == value) {
	    numComparisons = numComparisons + 2;
	    v.push_back(data[i]);
	}
	else {
	    numComparisons = numComparisons + 3;
	    Sr.push_back(data[i]);
	}
    }

    //recrusive call on vectors determined by the value of k
    if(k <= Sl.size()) {
	return select(Sl, 0, Sl.size()-1,k, numComparisons);
    }
    if(k > Sl.size() && k <= (Sl.size() + v.size())) {
	return v[0]; //all elements of v are the same return v[0]
    }
    if(k > (Sl.size() + v.size())) {
	return select(Sr, 0, Sr.size()-1,k-Sl.size()-v.size(),
		      numComparisons);
    }
    return 0;
}
