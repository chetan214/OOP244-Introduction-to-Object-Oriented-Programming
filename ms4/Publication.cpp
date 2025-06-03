/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Publication.cpp
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <iomanip>
#include <cstring>

#include "Publication.h"

using namespace std;

namespace seneca {

    void Publication::setDefault() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    Publication::Publication() {
        setDefault();
    }

    Publication::~Publication() {
        delete[] m_title;
        setDefault();
    }

    void Publication::set(int member_id) {
        if (member_id >= 10000 && member_id <= 99999) {
            m_membership = member_id;
        }
        else if (member_id == 0) {
            m_membership = member_id;
        }
    }

    void Publication::setRef(int value) {
        if (value > 0 && m_libRef != value) {
            m_libRef = value;
        }
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }
    bool Publication::conIO(ios& io) const {
        return (&io == &cin || &io == &cout);
    }

    ostream& Publication::write(ostream& os) const {
        char tempTitle[SENECA_TITLE_WIDTH + 1] = { 0 };
        strncpy(tempTitle, m_title, SENECA_TITLE_WIDTH);

        if (conIO(os)) {
            os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << tempTitle << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t";
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << tempTitle << "\t";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << "\t" << m_date;
        }
        return os;
    }


    std::istream& Publication::read(std::istream& is) {
        char tempTitle[255]{};
        char tempShelfId[SENECA_SHELF_ID_LEN + 1]{};
        int tempLibRef = -1;
        int Tempmembership = 0;
        Date tempDate;

        if (m_title) {
            setDefault();
        }

        if (conIO(is)) {

            cout << "Shelf No: ";
            is.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1);

            if (strlen(tempShelfId) != SENECA_SHELF_ID_LEN) {
                is.setstate(ios::failbit);
            }

            cout << "Title: ";
            is.getline(tempTitle, 255);

            cout << "Date: ";
            is >> tempDate;
        }

        else {

            is >> tempLibRef;

            is.ignore();

            is.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1, '\t');

            is.getline(tempTitle, 255, '\t');

            is >> Tempmembership;

            is.ignore();

            is >> tempDate;

        }

        if (!tempDate) {
            is.setstate(ios::failbit);
        }

        if (is) {
            m_title = new char[strlen(tempTitle) + 1];

            strcpy(m_title, tempTitle);
            strcpy(m_shelfId, tempShelfId);

            m_membership = Tempmembership;

            m_date = tempDate;

            m_libRef = tempLibRef;
        }
        return is;
    }

    Publication::operator bool() const {
        return (m_title != nullptr && m_title[0] != '\0');
    }

    Publication::Publication(const Publication& Pub) {

        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }

        m_title = new char[strlen(Pub.m_title) + 1];
        strcpy(m_title, Pub.m_title);

        strcpy(m_shelfId, Pub.m_shelfId);

        m_membership = Pub.m_membership;
        m_date = Pub.m_date;
        m_libRef = Pub.m_libRef;
    }


    Publication& Publication::operator=(const Publication& Pub) {
        if (this != &Pub) {

            if (m_title) {
                delete[] m_title;
                m_title = nullptr;
            }

            set(Pub.m_membership);
            setRef(Pub.m_libRef);
            strcpy(m_shelfId, Pub.m_shelfId);
            m_date = Pub.m_date;

            if (Pub.m_title != nullptr && Pub.m_title[0] != '\0') {
                m_title = new char[strlen(Pub.m_title) + 1];
                strcpy(m_title, Pub.m_title);
            }
            else {
                m_title = nullptr;
            }
        }
        return *this;
    }



}