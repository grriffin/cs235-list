/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>
#include "fibonacci.h" // for fibonacci() prototype
#include "wholeNumber.h"
#include "list.h" // for LIST
using namespace std;

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin >> number;

   //Will need to be of type Fib, but this works for now
   WholeNumber first = 0;
   WholeNumber second = 1;
   cout << "\t" << 1 << endl;
   // your code to display the first <number> Fibonacci numbers
   for (int i = 1; i < number; i++)
   {
      WholeNumber newNumber = first;
      newNumber += second;
      first = second;
      second = newNumber;
      cout << "\t" << second << endl;
   }

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin >> number;

   //Will need to be of type Fib, but this works for now
   first = 0;
   second = 1;
   // your code to display the first <number> Fibonacci numbers
   for (int i = 1; i < number; i++)
   {
      WholeNumber newNumber = first;
      newNumber += second;
      first = second;
      second = newNumber;
   }
   cout << "\t" << second << endl;
}
