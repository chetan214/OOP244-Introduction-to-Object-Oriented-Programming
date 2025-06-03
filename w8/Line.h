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
// Line.h

#ifndef SENECA_LINE_H_
#define SENECA_LINE_H_

#include "LblShape.h"

namespace seneca
{
  class Line : public LblShape
  {
    unsigned int m_length {0};

  public:
    Line() {}
    Line(const char *_label, int _length);
    virtual ~Line() {}

    // Override the base class's getSpecs virtual function
    void getSpecs(std::istream &istr);
    // Override the base class's draw virtual function
    void draw(std::ostream &ostr) const;
  };
}
#endif