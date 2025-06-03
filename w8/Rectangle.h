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
// Rectangle.h

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace seneca
{
  class Rectangle : public LblShape
  {
    unsigned int m_width  {0};
    unsigned int m_height {0};

  public:
    Rectangle() {}
    Rectangle(const char *_label, int _width, int _height);
    virtual ~Rectangle() {}

    void getSpecs(std::istream &istr);
    void draw(std::ostream &ostr) const;
  };
}
#endif