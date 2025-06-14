// Final Project Milestone 5
// Date Module
// File	Date.h
// Version 1.0
// Author	
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#ifndef SENECA_DATE_H__
#define SENECA_DATE_H__
#include <iostream>
namespace sdds {

    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;

    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = { "No Error", "cin Failed", "Bad Year Value",
                                    "Bad Month Value", "Bad Day Value" };
    const int MIN_YEAR = 1500;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1()
            const; // returns number of days passed since the date 0001/1/1
        bool
            validate();             /* validates the date setting the error code and then
                                     returning the result   true, if valid, and false if invalid.*/
        void errCode(int);      // sets the error code
        int systemYear() const; // returns the current system year
        bool bad() const;       // return true if
        int mdays() const;      // returns the number of days in current month
        void setToToday();      // sets the date to the current date (system date)
    public:
        Date();                           // creates a date with current date
        Date(int year, int mon, int day); /* create a date with assigned values
                                           then validates the date and sets the
                                           error code accordingly */
        int errCode() const; // returns the error code or zero if date is valid
        const char* dateStatus()
            const; // returns a string corresponding the current status of the date
        int currentYear() const; // returns the m_CUR_YEAR value;

        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;

        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator>=(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;

        int operator-(const Date& other) const;
        operator bool();
    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);
} // namespace seneca
#endif