/**********************************************************************
 *
 * CISC 3595, Fall 2013
 * Project 1: A Simple Version of "cp"
 *
 * Author: A. G. Werschulz
 * Date:   24 Sept 2013
 *
 * This is a C++ implementation, to be used as a guide for the C
 * implementation. 
 *
 **********************************************************************/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   // Sanity checking
   if (argc != 3) {
      cerr << "Usage: cp file1 file2\n";
      return 1;
   }

   ifstream ifs(argv[1]);
   if (!ifs) {
      cerr << "Cannot open " << argv[1] << " for reading\n";
      return 2;
   }

   ofstream ofs(argv[2]);
   if (!ofs) {
      cerr << "Cannot open " << argv[2] << " for writing\n";
      return 3;
   }

   // main I/O loop
   char ch;
   while (ifs >> ch)
      ofs << ch;

   // clean up
   ifs.close();
   ofs.close();
}
