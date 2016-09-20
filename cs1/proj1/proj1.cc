/**********************************************************************
*
* Project 1:Counting Coins
*
* Author: Nicholas J. Primiano <nprimiano@fordham.edu>
* Date: 24 January 2013 
*
* This program calculates a total number of dollars by adding
* desired amounts of various denominations of coins.
* It prints this value in cents and dollars.
*
**********************************************************************/

#include <bjarne/std_lib_facilities.h>

//The usual main() function
int main()
{

    //Determine the number of each denomination
    cout << "Enter the number of coins you have for each denomination.\n";
    cout << "  Pennies? ";					
    int pennies;
    cin >> pennies;
    cout << "  Nickels? ";
    int nickels; 
    cin >> nickels;
    cout << "  Dimes? ";
    int dimes;
    cin >> dimes;
    cout << "  Quarters? ";
    int quarters;
    cin >> quarters;
    cout << "  Half dollars? ";
    int half_dollars;
    cin >> half_dollars;

    //Check if any denomination should be singular
    if (pennies == 1)
        cout << "You have 1 penny.\n";
    else 
        cout << "You have " << pennies << " pennies.\n";

    if (nickels == 1)
	cout << "You have 1 nickel.\n";
    else
         cout << "You have " << nickels << " nickels.\n";

    if (dimes == 1)
         cout << "You have 1 dime.\n";
    else
         cout << "You have " << dimes << " dimes.\n";

    if (quarters == 1)
         cout << "You have 1 quarter.\n";
    else 
         cout << "You have " << quarters << " quarters.\n";

    if (half_dollars == 1)
	 cout << "You have 1 half dollar.\n";
    else 
	 cout << "You have " << half_dollars << " half dollars.\n";

    /*Calculate number of cents using the number of 
    provided for each denomination*/    
    pennies = pennies * 1;
    nickels = nickels * 5;
    dimes = dimes * 10;
    quarters = quarters * 25;
    half_dollars = half_dollars * 50;
    
    int total;		//Total value in cents
    total = pennies + dimes + nickels + quarters + half_dollars;

    //Calculate remaining cents for $0.00 format
    int cents ;	       //Total value of cents (without dollars)
    cents = total % 100;
	
    //Calculate total dollars for $0.00 format
    int dollars;       // Total value of dollars (without cents)
    dollars = total / 100; 

    //Check to determine if the total value is $0.01 and print that value
    if (total == 1){
	 cout << "The value of all your coins is 1 cent, which is $0.01.\n";
    }
    else {
    /*Check to determine if the value of the remaining cents is less than 10 
    in order to add a "0" before the number and print the value*/
	 if (cents < 10)
	      cout << "The value of all your coins is " << total 
	           << " cents,  which is $" << dollars << ".0" 
	           << cents << ".\n"; 
	 /*If the total value is greater than 10 cents  print 
	 the total value*/
	 else 
	      cout << "The value of all your coins is " 
                   << total << " cents, which is $" 
	           << dollars << "." << cents << ".\n";
    }	
    /*The main functions returns 0, indicating successful 
    completion of the program*/
    return 0; 
}
