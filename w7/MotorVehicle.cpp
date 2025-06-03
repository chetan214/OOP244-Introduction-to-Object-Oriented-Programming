/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
// MotorVehicle.cpp

#include "MotorVehicle.h"

using namespace std;

namespace seneca
{
  int strLen(const char *s)
  {
    // Declare Variable to store the length
    int length = 0;

    // Set the "while" loop to repeat until the corresponding index has a value
    while (s[length])
      length++;

    return length;
  }

  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src)
  {
    int i = 0;

    // Set the "while" loop to repeat until 'src' has a value the corresponding index
    while (src[i]) {
      // Copy the String from 'src' to 'des'
      des[i] = src[i];
      i++;
    }

    // Set the last index to be NULL value
    des[i] = '\0';
  }

  // strCmp: Compares two C-strings
  int strCmp(const char *s1, const char *s2)
  {
    int i = 0, result = 0;
    bool flag = false;

    // Set the "while" loop to repeat until the comparison between "s1" and "s2" is complete
    while (!flag) {
      if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
        result = s1[i] - s2[i];
        flag = true;
      }

      i++;
    }

    return result;
  }
  
  MotorVehicle::MotorVehicle(const char *_license, int _year, const char *_location)
  {
    if (_license) strCpy(m_license, _license);
    m_year = _year;
    strCpy(m_address, _location);
  }

  void MotorVehicle::moveTo(const char* _address)
  {
    if (strCmp(m_address, _address) != 0) {
      cout << "|";
      cout.width(8);
      cout << m_license << "| |";

      cout.width(20);
      cout << m_address << " ---> ";

      cout.width(20);
      cout << left << _address << "|" << right << endl;

      strCpy(m_address, _address);
    }
  }

  std::ostream &MotorVehicle::write(std::ostream &os) const
  {
    os << "|";
    os.width(5);
    os << m_year << " | " << m_license << " | " << m_address;

    return os;
  }

  std::istream &MotorVehicle::read(std::istream &in)
  {
    cout << "Built year: ";
    in >> m_year;
    while (!in) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild year, Retry to enter: ";
      cin >> m_year;
    }

    cout << "License plate: ";
    in >> m_license;

    cout << "Current location: ";
    in >> m_address;
    while (m_address[0] < 65 || m_address[0] > 122) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild location, Retry to enter: ";
      cin >> m_address;
    }

    return in;
  }

  std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &src)
  {
    return src.write(ostr);
  }

  std::istream &operator>>(std::istream &istr, MotorVehicle &src)
  {
    return src.read(istr);
  }

}