/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Streamable.cpp
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace seneca {

    ostream& operator<<(ostream& os, const Streamable& rhs) {
        if (rhs) {
            rhs.write(os);
        }
        return os;
    }

    istream& operator>>(istream& is, Streamable& rhs) {
        return (rhs.read(is));
    }
}