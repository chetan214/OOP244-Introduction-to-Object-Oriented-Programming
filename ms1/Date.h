// Final Project Milestone 1 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
/*/////////////////////////////////////////////////////////////////////////
                          Milestone 1
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_DATE_H__
#define SENECA_DATE_H__
#include <iostream>
namespace seneca {
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };

   /* When I create a Date object, it stores the year, month, and day in the membber variables
      It checks if these values are valid:
      1) Year Validation: Ensures the year is between 1500 and the current year.
      2) Month Validation: Ensures the month is between 1 and 12.
      3) Day Validation: Ensures the day is between 1 and the maximum number of days in that month (takes leap years into account).

      If any of these validations fail, the Error Code is set to a non-zero value indicating what went wrong.

   */
   const int  MIN_YEAR = 1500;
   class Date {
   private:
      int m_year; // an integer between the year 1500 till today
      int m_mon; // an integer between 1 and 12
      int m_day; // an integer between 1 and the number of days in the month
      int m_ErrorCode; /* An integer that indicates if there was an error.
                          Value is ZERO if there are no errors, meaning the date is valid.
                          Different non-zero values represent specific types of errors (e.g., invalid month, day, etc.) */
      int m_CUR_YEAR;
      int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
      bool validate();             /* validates the date setting the error code and then returning the result 
                                    true, if valid, and false if invalid.*/
      void errCode(int);           // sets the error code
      int systemYear()const;       // returns the current system year
      bool bad()const;             // return true if
      int mdays()const;            // returns the number of days in current month
      void setToToday();           // sets the date to the current date (system date)
   public:
      Date();                      // creates a date with current date
      Date(int year, int mon, int day); /* create a date with assigned values
                                         then validates the date and sets the 
                                         error code accordingly */
      int errCode()const;         // returns the error code or zero if date is valid
      const char* dateStatus()const;  // returns a string corresponding the current status of the date
      int currentYear()const;         // returns the m_CUR_YEAR value;
      std::istream& read(std::istream& is);
      std::ostream& write(std::ostream& os)const;
      bool operator==(const Date& d)const;
      bool operator!=(const Date& d)const;
      bool operator>=(const Date& d)const;
      bool operator<=(const Date& d)const;
      bool operator>(const Date& d)const;
      bool operator<(const Date& d) const;
      long int operator-(Date i)const;
      operator bool()const;   
   };

   std::ostream& operator<<(std::ostream& os, const Date& RO);
   std::istream& operator>>(std::istream& is, Date& RO);
}
#endif