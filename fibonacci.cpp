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
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
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
   cin  >> number;

   long int first = 0;
   long int second = 1;
   long int temp;
   cout << 1 << endl;
   // your code to display the first <number> Fibonacci numbers
   for (int i = 1; i < number; i++)
   {
      temp = second;           
      second += first;          
      first = temp;            

      cout << second << ",";
   }
   
   cout << endl;
   
    // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;
   
   first = 0;
   second = 1;
   //does not handle very large numbers such as fib #100.
   for (int i = 1; i < number; i++)
   {
      temp = second;             
      second += first;          
      first = temp;             
      
      if (i == number - 1)
      cout << second << endl;
   }
}


