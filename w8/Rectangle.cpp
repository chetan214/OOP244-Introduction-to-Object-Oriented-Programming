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
// Rectangle.cpp

#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace seneca
{
  Rectangle::Rectangle(const char *_label, int _width, int _height) : LblShape(_label)
  {
    int _compareWidth = strlen(LblShape::label()) + 2;

    // if not meet the condition, rectangle will be set to empty
    if (_width > _compareWidth && _height > 3) {
      m_width = _width;
      m_height = _height;
    }
  }

  void Rectangle::getSpecs(std::istream &istr)
  {
    int _width;
    int _height;
    char _comma;
    bool _escape = false;

    do {
      // read the label by using base class's getSpecs
      LblShape::getSpecs(istr);

      // read the value of the m_width and the comma and the value of the m_height
      istr >> _width >> _comma >> _height;

      if (!istr) {
        istr.clear();
        istr.ignore(32767, '\n');
      }
      else {
        // it will ignore The rest of the characters up to and including '\n'
        istr.ignore();
        m_width = _width;
        m_height = _height;
        _escape = true;
      }
    } while (!_escape);
  }

  void Rectangle::draw(std::ostream &ostr) const
  {
    if (m_width > 0 && m_height >> 0) {
      // draw the label and symbol following the provided format
      // Draw first line
      ostr << '+';
      ostr.width(m_width - 2);
      ostr.fill('-');
      ostr << '-' << '+' << endl;

      // Draw second line
      ostr << '|';
      ostr.width(m_width - 2);
      ostr.fill(' ');
      ostr << left << LblShape::label() << '|' << endl;

      // Draw middle lines
      for (unsigned int i = 0; i < (m_height - 3); i++) {
        ostr << '|';
        ostr.width(m_width - 2);
        ostr.fill(' ');
        ostr << ' ' << '|' << endl;
      }

      // Draw last line
      ostr << '+';
      ostr.width(m_width - 2);
      ostr.fill('-');
      ostr << '-' << '+';
    }
  }
}