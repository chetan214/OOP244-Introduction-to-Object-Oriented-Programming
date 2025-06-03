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
// MotorVehicle.h

#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H

#include <iostream>

namespace seneca
{
  int strLen(const char *s);
  void strCpy(char *des, const char *src);
  int strCmp(const char *s1, const char *s2);
  
  class MotorVehicle
  {
    char m_license[9]{'\0'};
    char m_address[64]{'\0'};
    unsigned int m_year{0};

  public:
    MotorVehicle(){}
    MotorVehicle(const char *_license, int _year, const char *_location = "Factory");
    ~MotorVehicle(){}

    // moves the vehicle to the new address
    void moveTo(const char* _address);

    // Display the information of MotorVehicle
    std::ostream &write(std::ostream &os) const;

    // Receive new information from the user
    std::istream &read(std::istream &in);
  };

  std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &src);
  std::istream &operator>>(std::istream &istr, MotorVehicle &src);
}
#endif