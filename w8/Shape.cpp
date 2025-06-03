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
// Shape.h

#include <iostream>
#include "Shape.h"

namespace seneca
{
  std::ostream &operator<<(std::ostream &ostr, const Shape &src)
  {
    src.draw(ostr);
    return ostr;
  }
  std::istream &operator>>(std::istream &istr, Shape &src)
  {
    src.getSpecs(istr);
    return istr;
  }
}