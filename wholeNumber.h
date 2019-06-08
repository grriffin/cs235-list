#ifndef wholeNumber_h
#define wholeNumber_h

#include <ostream>
#include "list.h"

/************************************************
* WHOLE NUMBER
* A class to represent an arbitrary large whole
* number. Currently supports:
* INSERTION : for displaying the number w/o thousands separator
* += : add one WholeNumber onto this
* = (int) : assign an integer to the current value
* = : assign one WholeNumber onto this
***********************************************/
class WholeNumber
{
public:
// constructors. We will use the default destructor
WholeNumber() { data.push_back(0); }
WholeNumber(unsigned int value) { *this = value; }
WholeNumber(const WholeNumber & rhs) { *this = rhs; }

// display the number
friend std::ostream & operator << (std::ostream & out,
const WholeNumber & rhs);

// fetch a given number
friend std::istream & operator >> (std::istream & in, WholeNumber & rhs);

// add onto a given whole number
WholeNumber & operator += (const WholeNumber & rhs);

// assignment operator for numbers
WholeNumber & operator = (unsigned int value);

// assignment operator for values
WholeNumber & operator = (const WholeNumber & rhs)
{
data = rhs.data;
return *this;
}
private:
custom::list <int> data;
};

#endif // WHOLE_NUMBER_H
