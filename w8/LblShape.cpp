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
// LblShape.cpp

#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace seneca
{
  const char *LblShape::label() const
  {
    return m_label;
  }

  LblShape::LblShape(const char *_label)
  {
    if (_label && _label[0] != '\0') {
      m_label = new char[strlen(_label) + 1];
      strcpy(m_label, _label);
    }
  }

  LblShape::~LblShape()
  {
    if (m_label) {
      delete[] m_label;
      m_label = nullptr;
    }
  }

  void LblShape::getSpecs(std::istream &istr)
  {
    string _label;

    // Reads a comma-delimited Cstring form istream
    getline (istr, _label, ',');

    // copy the Cstring into the newly allocated memory
    delete[] m_label;
    m_label = new char[strlen(_label.c_str()) + 1];
    strcpy(m_label, _label.c_str());
  }
}