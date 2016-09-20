/** @mainpage
 *
 * CISC 2200: Data Structures<br/>
 * Recursive Fibonacci demo<br/>
 *
 * <p>Counts the number of additions needed by a naive recursive
 * Fibonacci algorithm.</p>
 *
 * @author Art Werschulz
 * @date 24 Jan 2015
 * @file fib-count.cc
 *
 **********************************************************************/

#include <iostream>
using namespace std;

// function prototype
unsigned int fib_count(unsigned int n, unsigned int &numAdds);

/**
 * The usual main function
 *
 * Asks the user for a non-negative integer <em>n</em>, and then computes the
 * first <em>n</em> Fibonacci numbers, as well as the number of additions
 * needed to compute same.
 */
int main()
{
   /// order of highest Fibonacci number
   unsigned int n;

   cout << "Order of highest Fibnoacci number? ";
   cin >> n;

   for (unsigned int i = 0; i <= n; i++) {
      /// number of additions needed for each Fibonacci number
      unsigned int numAdds;
      unsigned int fib = fib_count(i, numAdds);
      cout << "Fib[" << i << "] = " << fib << ", additions = " 
           << numAdds << endl;
   }

   return 0;
}

/**
 * Naive implementation of recursive Fibonacci algorithm.
 *
 * @param n index of Fibonacci number
 * @param numAdds total number of additions used, which is assumed to
 * have been correctly set by any previous recursive call
 * @return Fibonacci number F<sub><em>n</em></sub>
 * @pre n >= 0
 * @post numAdds the new number of additions used
 */

unsigned int fib_count(unsigned int n, unsigned int &numAdds)
{
   numAdds = 0;
   if (n == 0 || n == 1) return 1;
   // n >= 2  here
   // numbers of additions for the two recursive calls
   unsigned int numAddsPrev, numAddsPrevPrev;
   unsigned fib = fib_count(n-1, numAddsPrev) + 
      fib_count(n-2, numAddsPrevPrev);
   numAdds = numAddsPrev + numAddsPrevPrev + 1;
   return fib;
}
