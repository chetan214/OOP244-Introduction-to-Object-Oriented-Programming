/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
// Shape.cpp

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace seneca
{
  //  Pure virtual function
  class Shape
  {
  public:
    virtual ~Shape() {}
    virtual void draw(std::ostream &ostr) const  = 0;
    virtual void getSpecs(std::istream &istr) = 0;
  };

  std::ostream &operator<<(std::ostream &ostr, const Shape &src);
  std::istream &operator>>(std::istream &istr, Shape &src);
}

#endif