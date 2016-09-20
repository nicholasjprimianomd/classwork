/**********************************************************************
 *
 * Project 2: Fast Polynomial Multiplication
 *
 * Author: Harry Q. Bovik, PhD
 * Date:   3 March 2015
 *
 * Say something here.
 *
 **********************************************************************/

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// function declarations

typedef int CoeffType;

template <class T> vector<T> getData(string fileName);
vector<CoeffType> classical(vector<CoeffType> a, vector<CoeffType> b,
                            int& numOperations);
vector<CoeffType> fast(vector<CoeffType> a, vector<CoeffType> b, 
                       int& numOperations);

int main(int argc, char** argv)
{
   /*
    * get the data
    */
   if (argc != 3) {
      cerr << "Usage: " << argv[0] << " aCoeffFile bCoeffFile\n";
      return 1;
   }
   vector<CoeffType> aCoeffs = getData<CoeffType>(argv[1]);
   vector<CoeffType> bCoeffs = getData<CoeffType>(argv[2]);

   /*
    * compute the product, via classical and fast techniques
    */
   int classicalOps, fastOps;
   vector<CoeffType> classicalProduct = classical(aCoeffs, bCoeffs,
                                                  classicalOps);
   vector<CoeffType> fastProduct = fast(aCoeffs, bCoeffs, fastOps);

   /*
    * report results
    */
   if (classicalProduct != fastProduct) {  // oops
      cout << "Error: fast and classical algorithms don't produce "
           << "same results\n";
      return(2);
   }

   cout << "Both algorithms agree.  Compare operation counts:\n"
        << "  Classical algorithm: " << classicalOps << endl
        << "  Fast algorithm: " << fastOps << endl;

   return 0;
}
 

/*
 * function definitions
 */

// read data from a file, store in a vector
template <class T> vector<T> getData(string fileName)
{
   ifstream dataStream(fileName.c_str());
   if (!dataStream) {
      cerr << "can't open " << fileName << endl;
      exit(1);
   }

   vector<T> dataVec; 
   T datum;
   while (dataStream >> datum) dataVec.push_back(datum);
   return dataVec;
}

// comment
vector<CoeffType> classical(vector<CoeffType> a, vector<CoeffType> b,
                            int& numOperations)
{
   int aSize = a.size();
   int bSize = b.size();
   numOperations = 0;
   vector<CoeffType> v(aSize + bSize - 1);

   return v;
}

// comment
vector<CoeffType> fast(vector<CoeffType> a, vector<CoeffType> b, 
                       int& numOperations)
{
   int aSize = a.size();
   int bSize = b.size();
   numOperations = 0;
   vector<CoeffType> v(aSize + bSize - 1);

   return v;
}



