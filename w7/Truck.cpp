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
// Truck.cpp

#include <iostream>
#include "Truck.h"

using namespace std;

namespace seneca
{
  Truck::Truck(const char *_license, int _year, double _capacity,
               const char *_address) : MotorVehicle(_license, _year)
  {
    if (_capacity > 0) m_MaxCapacity = _capacity;
    if (_address) this->moveTo(_address);
  }

  bool Truck::addCargo(const double cargo)
  {
    bool result = false;

    // If the maximum capacity is exceeded, it is no longer loaded
    if (cargo > 0 && (m_CurrCapacity != m_MaxCapacity)) {
      m_CurrCapacity += cargo;
      result = true;
      if (m_CurrCapacity > m_MaxCapacity) m_CurrCapacity = m_MaxCapacity;
    }

    return result;
  }

  bool Truck::unloadCargo()
  {
    bool result = false;

    // If the current capacity is empty, will not be unloaded.
    if (m_CurrCapacity > 0) {
      m_CurrCapacity = 0.00;
      result = true;
    }

    return result;
  }

  std::ostream& Truck::write(std::ostream &os) const
  {
    MotorVehicle::write(os);
    os << " | " << m_CurrCapacity << "/" << m_MaxCapacity;

    return os;
  }

  std::istream &Truck::read(std::istream &in)
  {
    MotorVehicle::read(in);

    cout << "Capacity: ";
    in >> m_MaxCapacity;
    while (!in) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild Max Capacity, Retry to enter: ";
      cin >> m_MaxCapacity;
    }

    cout << "Cargo: ";
    in >> m_CurrCapacity;
    while (!in) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild cargo amount, Retry to enter: ";
      cin >> m_CurrCapacity;
    }

    return in;
  }

  std::ostream &operator<<(std::ostream &ostr, const Truck &src)
  {
    return src.write(ostr);
  }

  std::istream &operator>>(std::istream &istr, Truck &src)
  {
    return src.read(istr);
  }
}