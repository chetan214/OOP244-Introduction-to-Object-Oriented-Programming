/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date       : 10 Jun 2024

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
  class Account {
    int m_number;
    double m_balance;

    void setEmpty();

  public:
    Account();
    Account(const int number, const double balance);
    ~Account() {};

    std::ostream &display() const;

    operator bool() const;

    operator int() const;


    operator double() const;

  
    bool operator~() const;

   
    Account &operator+=(const double _into);

    Account &operator-=(const double _draw);

   
    Account &operator>>(Account &_move);

   
    Account &operator<<(Account &_move);

   
    Account &operator=(const int _acc);

   
    Account &operator=(Account &_move);

    friend double operator+(const Account &_left, const Account &_right);

 
    friend double operator+=(double &_value, const Account &_add);
  };
} // namespace sdds
#endif // SENECA_ACCOUNT_H_