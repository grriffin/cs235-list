#ifndef wholeNumber_h
#define wholeNumber_h

#include <ostream>
#include "list.h"
#include <iostream>
#include <iomanip>

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
friend std::ostream & operator << (std::ostream & out, WholeNumber & rhs) {
    int num = 0; // count for the comma
    // traverse through the nodes
    for (custom::list<int>::reverse_iterator it = rhs.data.rbegin(); it != rhs.data.rend(); ++it) {
        if (!(num%3)) { // comma if there is another set of 3
            std::cout << std::setfill('0') << std::setw(3) << *it;
            std::cout << ","; 
            num++;
        } else { // no comma if there isn't another set of 3
            std::cout << *it;
            num++;
        }

    }
    // output the numbers in each node
}

// fetch a given number
friend std::istream & operator >> (std::istream & in, WholeNumber & rhs) {
    int num;
    in >> num;
    WholeNumber n2(num);
    rhs = n2;
    return in;
}

// add onto a given whole number
WholeNumber & operator += (WholeNumber & rhs) {
    const int MAX = 1000;
    int carryOver = 0;

    custom::list<int>::iterator lhsIt = this->data.begin();
    custom::list<int>::iterator rhsIt = rhs.data.begin();

    custom::list<int> newList = custom::list<int>();

    while (lhsIt != this->data.end() || rhsIt != rhs.data.end()) {
        int total = *lhsIt + *rhsIt + carryOver;
        int totalAfter = total % MAX;
        newList.push_front(totalAfter);
        lhsIt++;
        rhsIt++;
    }
    if (carryOver) {
        newList.push_front(carryOver);
    }
    return *this;
}

// assignment operator for numbers
WholeNumber & operator = (unsigned int value) {
    
}

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