#include "wholeNumber.h"
#include "list.h"
#include <iostream>
#include <iomanip>

std::ostream &operator<<(std::ostream &out, const WholeNumber &rhs)
{
    int num = 0; // count for the comma
    // traverse through the nodes
    for (custom::list<int>::const_reverse_iterator it = rhs.data.crbegin(); it != rhs.data.crend(); ++it)
    {
        if (!(num % 3))
        { // comma if there is another set of 3
            std::cout << std::setfill('0') << std::setw(3) << *it;
            std::cout << ", ";
            num++;
        }
        else
        { // no comma if there isn't another set of 3
            std::cout << *it;
            num++;
        }
    }
    // output the numbers in each node
    return out;
}

// fetch a given number
std::istream &operator>>(std::istream &in, WholeNumber &rhs)
{
    int value;
    std::cin >> value;
    if (std::cin)
    {
        rhs.data.push_back(value);
        char separator;
        while (std::cin >> separator >> value && separator == ',')
        {
            rhs.data.push_back(value);
        }
    }
    if (!std::cin.eof())
    {
        std::cerr << "format error in input" << std::endl;
    }
    return in;
    std::ostream &operator<<(std::ostream &out,
                             const WholeNumber &rhs);

    // fetch a given number
    std::istream &operator>>(std::istream &in, WholeNumber &rhs);
    return in;
}

// add onto a given whole number
WholeNumber &WholeNumber::operator+=(const WholeNumber &rhs)
{
    if (rhs.data.empty())
        return *this;

    if (this->data.empty())
    {
        data = rhs.data;
        return *this;
    }

    WholeNumber newNumber;

    list_type::reverse_iterator it1 = data.rbegin();
    list_type::const_reverse_iterator it2 = rhs.data.crbegin();
    int carryOver = 0;

    while (it1 != data.rend() || it2 != rhs.data.crbegin())
    {
        int v1 = it1 == data.rend() ? 0 : *(it1++);
        int v2 = it2 == data.crend() ? 0 : *(it2++);

        int total = v1 + v2 + carryOver;
        int newValue = total % 1000;
        carryOver = total >= 1000 ? 1 : 0;

        newNumber.data.push_back(newValue);
    }

    this->data = newNumber.data;
    return *this;
}

// assignment operator for numbers
WholeNumber &WholeNumber::operator=(unsigned int value)
{
    //bad implementation here, assumes that it's less than 3 digits or the rest won't work.
    data.clear();
    data.push_back(value);
    return *this;
}