

#include <bjarne/std_lib_facilities.h>


int main()
{

  double a;
  double b;
  double c;
  double x;
  double root_1;
  double root_2;
  double discriminant;

  cout << "Enter the coefficients of a quadratic equation a*x**2 + b*x + c:" << endl;
  cout << "  a?: ";
  cin >> a;

  cout << " b?";
  cin >> b;

  cout << " c?";
  cin >> c;

  cout << "Trying to solve quadratic equation " << a << "*x*x +" 
  << b << "+" << c << endl; 
  
 if ((a == 0) && (b != 0)){
    x = ((a - c)/b);
    cout << "Linear function." << endl;
    cout << "Root 1: " << x << endl;
    return 0;
  }

  if (((b)*(b)-(4*a*c)) < 0) {
    cout << "No real roots." << endl;
    return 0;
  }
  else {
    discriminant = sqrt(((b)*(b))-(4*(a)*(c)));
  }

  if (((b*b) == (b*b)-((4*(a)*(c))))){
      root_1 = (((-b))+discriminant)/(2*(a)));
      root_2 = (((-b))-discriminant)/(2*(a)));
      cout << "Using the " 
      if (root_1 == 0){
        root_1=c/(a*root_2);
        cout << "Using the stable formula: Two roots, x = " << root_1 
        << "and x = " << root_2 << endl;
        return 0;
      }
      else {
        root_2=c/(a*root_1);
        cout << "Using the stable formula: Two roots, x = " << root_1 
        << "and x = " << root_2 << endl;
        return 0;
      }
    }

   if (discriminant == 0) { 
      if(a == 0 && c == 0){
        cout << "An Identity." << endl;
        return 0;
    }
      else if(a == 0 && c != 0){
        cout << "A Contradiction." << endl;
        return 0;
      }
      root_1 = (-b)/(2*a);
      cout << "One real root" <<  endl;
      cout << "Root 1: " << root_1 << endl;
      return 0;
    }

    root_1 = ((((-1)*(b))+discriminant)/(2*(a)));
    cout << "This is a quadratic function" << endl;
    cout << "Root 1: " << root_1 << endl;

    root_2 = ((((-1)*(b))-discriminant)/(2*(a)));
    cout << "This is a quadratic function" << endl;
    cout << "Root 2: " << root_2 << endl;
    return 0;
}
