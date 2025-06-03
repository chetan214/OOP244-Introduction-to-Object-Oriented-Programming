/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date       : 31 May 2024

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include "Bill.h"
using namespace seneca;

int main() {
   Bill B;
    B.init("Quick Shopping", 5);
    B.add("Milk 2%", 4.99, false);
    B.display();
    B.add(nullptr, 15.50, true);
    B.add("Frying Pan", 24.99, true);
    B.add("Eggs", -2.99, false);
    B.display();
    B.deallocate();
    B.init("Quick Shopping", 5);
    B.add("Milk 2%", 4.99, false);
    B.add("Spatula", 15.50, true);
    B.add("Frying Pan", 24.99, true);
    B.add("Eggs", 5.99, false);
    B.add("Bug Spray", 9.99, true);
    B.display();
    B.deallocate();
    return 0;
}

