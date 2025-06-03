/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #10
Name: Chetan Arora
Email: carora18@myseneca.ca
Student ID: 100976240
Section: ZFF
Date:  Aug 7 2024
/////////////////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied
the code that my professor provided to complete my workshops and assignments.
////////////////////////////////////////////////////////////////////////////*/

/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace seneca{
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}