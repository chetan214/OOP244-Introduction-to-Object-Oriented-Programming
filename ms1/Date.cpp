// Final Project Milestone 1 
// Date Module
// File	Date.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <limits>
using namespace std;
#include "Date.h"
namespace seneca {

   // Validates the date setting the error code and then returns true, if valid, and false if invalid.
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }

   // returns the number of days in the current month (the month stored in m_mon attribute)
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   // returns the current system year (2024 for this semester)
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }

   // sets the date to the current date (system date)
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }

   // returns the number of days passed since the date 0001/1/1
   int Date::daysSince0001_1_1()const {  
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }

   // creates a date with the current date
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }

   // creates a date with assigned values then validates the date and sets the error code accordingly
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }

   // returns a string stating the current status of the date
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }

   // returns the m_CUR_YEAR attribute value
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }

   // returns the error code or zero if the date is valid
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }

   // sets the error code value
   int Date::errCode()const {
      return m_ErrorCode;
   }

   //returns true if the Date is in an erroneous state.
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }
   
   ////////////--------/////////////
   std::istream& Date::read(std::istream& is) {
      errCode(NO_ERROR);
      char separator; // Variable to hold the separator character

      // Read the year, the month and the day member variables using istream
      is >> m_year >> separator >> m_mon >> separator >> m_day;

      if (is.fail()) {
         errCode(CIN_FAILED); 
         is.clear(); 
      } else {
         validate(); 
      }
      is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      return is; // Return the istream object
   }

   std::ostream& Date::write(std::ostream& os = std::cout)const{
      if (bad()) { // If the Date object is in a "bad" state
         os << dateStatus(); // Print the dateStatus()
      } else {
         os << m_year << '/';
         os << std::setw(2) << std::setfill('0') << m_mon << '/';
         os << std::setw(2) << std::setfill('0') << m_day;

         os << std::setfill(' ');
      }
      return os; 
   }
   
   bool Date::operator==(const Date& d)const{
       return this->daysSince0001_1_1() == d.daysSince0001_1_1(); 
   }

   bool Date::operator!=(const Date& d)const{
      return this->daysSince0001_1_1() != d.daysSince0001_1_1();
   }
   
   bool Date::operator>=(const Date& d)const{
      return this->daysSince0001_1_1() >= d.daysSince0001_1_1();
   }
   
   bool Date::operator<=(const Date& d)const{
      return this->daysSince0001_1_1() <= d.daysSince0001_1_1();
   }

   bool Date::operator>(const Date& d)const{
      return this->daysSince0001_1_1() > d.daysSince0001_1_1();
   }

   bool Date::operator<(const Date& d) const{
      return this->daysSince0001_1_1() < d.daysSince0001_1_1();
   }
   
   long int Date::operator-(Date i) const {
      return this->daysSince0001_1_1() - i.daysSince0001_1_1();
   }

   Date::operator bool() const {
      return m_ErrorCode == NO_ERROR;
   }



   //Overloads of insertion and extraction operators to call write and read methods of Date
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }


}
