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
// LblShape.h

#ifndef SENECA_Lblshape_H_
#define SENECA_Lblshape_H_

#include "Shape.h"

namespace seneca
{
  class LblShape : public Shape
  {
    char *m_label {nullptr};

  protected:
    const char *label() const;

  public:
    LblShape() {}
    LblShape(const char *_label);
    virtual ~LblShape();

    // prevent copying
    LblShape(const LblShape &src) = delete;
    LblShape &operator=(const LblShape &src) = delete;

    // Override the base class's getSpecs pure virtual function
    void getSpecs(std::istream &istr);
  };
}
#endif