/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "list.h"

// the interactive fibonacci program
void fibonacci();

class Fib
{
private: 
  List<int> numbers;
public:
  Fib(){}
  Fib(const int &t);
  Fib(const Fib &rhs);
  //Now sure how to add << operator
  Fib &operator+=(const Fib &rhs);
  Fib &operator=(const Fib &rhs);
};

#endif // FIBONACCI_H

