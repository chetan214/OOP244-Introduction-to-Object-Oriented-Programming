/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Date.cpp
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name           Date            Reason

------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

// Final Project Milestone 4
// Date Module
// File	Date.cpp
// Version 2.0
// Author	Fardad Soleimanloo
// Revision History
// ------------------------------------------------------------
// Name                               Date                 Reason
/////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;
namespace seneca {
    bool seneca_test = false;
    int seneca_year = 2024;
    int seneca_mon = 12;
    int seneca_day = 25;


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
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    int Date::systemYear()const {
        int theYear = seneca_year;
        if (!seneca_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }
    void Date::setToToday() {
        if (seneca_test) {
            m_day = seneca_day;
            m_mon = seneca_mon;
            m_year = seneca_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }


    int Date::daysSince0001_1_1()const {
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }
    Date::Date() :m_CUR_YEAR(systemYear()) {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }
    int Date::errCode()const {
        return m_ErrorCode;
    }
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }

    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }
    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }


    istream& Date::read(istream& is) {
        errCode(NO_ERROR);
        int year, month, day;
        char character;
        is >> year >> character >> month >> character >> day;
        m_year = year;
        m_mon = month;
        m_day = day;
        if (!is)
        {
            errCode(CIN_FAILED);

        }
        else {
            validate();
        }

        return is;
    }

    Date::operator bool() const {
        return (!bad());
    }

    int Date::fetchDay()const {
        return daysSince0001_1_1();
    }

    bool operator==(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() == rhs.fetchDay());
    }

    bool operator!=(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() != rhs.fetchDay());
    }

    bool operator>=(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() >= rhs.fetchDay());
    }
    bool operator<= (const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() <= rhs.fetchDay());
    }

    bool operator>(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() > rhs.fetchDay());
    }
    bool operator<(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() < rhs.fetchDay());
    }

    int operator-(const Date& lhs, const Date& rhs) {
        return (lhs.fetchDay() - rhs.fetchDay());
    }



    ostream& Date::write(ostream& os) const {
        if (bad()) {
            os << dateStatus();
        }
        else {
            os << m_year << "/" << setfill('0') << setw(2) << m_mon << "/" << setfill('0') << setw(2) << m_day;
        }
        return os;
    }




}