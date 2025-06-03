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
// Line.cpp

#include <iostream>
#include "Line.h"

using namespace std;

namespace seneca
{
  Line::Line(const char *_label, int _length) : LblShape(_label)
  {
    if (_length > 0)
      m_length = _length;
  }

  void Line::getSpecs(std::istream &istr)
  {
    int _length;
    bool _escape = false;

    do {
      // read the label by using base class's getSpecs
      LblShape::getSpecs(istr);

      // read the value of the m_length
      istr >> _length;

      if (!istr) {
        istr.clear();
        istr.ignore(32767, '\n');
      }
      else {
        // it will ignore The rest of the characters up to and including '\n'
        istr.ignore();
        m_length = _length;
        _escape = true;
      }
    } while (!_escape);
  }

  void Line::draw(std::ostream &ostr) const
  {
    if (m_length > 0 && LblShape::label()) {
      // draw the label and symbol following the provided format
      ostr << LblShape::label() << endl;
      ostr.width(m_length);
      ostr.fill('=');
      ostr << '=';
    }
  }
}
