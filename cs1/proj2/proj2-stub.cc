/**********************************************************************
 *
 * Project 2: Quadratic Equation Solver
 *
 * Say something here.
 *
 * Author: Joe Btfsplk
 * Date:   2 February 2012
 *
 **********************************************************************/

#include <bjarne/std_lib_facilities.h>

// function declarations
void solve_linear(double b, double c);
void solve_quadratic(double a, double b, double c);

int main()
{
   // input the coefficients of the polynomial
   double a, b, c;                      // coefficients of the polynomial
   // figure out the rest yourself!!

   // handle degenerate case (linear equation) and quit
   if (a == 0)  // linear equation, not quadratic
      solve_linear(b, c);
   else  // genuine quadratic equation ... forge ahead
      solve_quadratic(a, b, c);
}

// solve the linear equation b*x + c == 0
void solve_linear(double b, double c)
{
   cout << "Trying to solve linear equation "
        << b << "*x + " << c << " == 0\n";
   // figure out the rest yourself!
}

// use classical quadratic formula to solve a genuine quadratic equation
// a*x^2 + b*x + c ==0, with a != 0
void solve_quadratic(double a, double b, double c)
{
   cout << "Trying to solve the quadratic equation "
        << a << "*x*x + " << b << "*x + " << c << " == 0\n";
   // figure out the rest yourself!
}
