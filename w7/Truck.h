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
// Truck.h

#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace seneca
{
  class Truck : public MotorVehicle
  {
    double m_MaxCapacity{0.00};
    double m_CurrCapacity{0.00};

  public:
    Truck(){}
    Truck(const char *_license, int _year, double _capacity,
          const char *_address = nullptr);
    ~Truck(){}

    bool addCargo(const double cargo);
    bool unloadCargo();

    // Display the information of MotorVehicle
    std::ostream &write(std::ostream &os) const;

    // Receive new information from the user
    std::istream &read(std::istream &in);
  };
  std::ostream &operator<<(std::ostream &ostr, const Truck &src);
  std::istream &operator>>(std::istream &istr, Truck &src);
}

#endif