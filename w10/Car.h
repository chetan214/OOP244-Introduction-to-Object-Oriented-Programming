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
#ifndef SENECA_CAR_H_
#define SENECA_CAR_H_
#include "ReadWrite.h"
namespace seneca {
   class Car : public ReadWrite {
      char m_plate[9];
      char m_makeModel[41];
   public:
      Car(const char* plate = "", const char* makeModel = "");
      void set(const char* plate, const char* makeModel);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* mmSubstr)const;
   };


}
#endif
