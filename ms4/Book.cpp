/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Book.cpp
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name          Date            Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Book.h"

using namespace std;

namespace seneca {

	void Book::setEmpty()
	{
		if (m_authorName) {
			delete[] m_authorName;
		}
		m_authorName = nullptr;
	}


	void Book::setName(const char* name)
	{
		m_authorName = new char[strlen(name) + 1];
		strcpy(m_authorName, name);

	}

	Book::Book() {
		setEmpty();
	}
	Book::Book(const char* name)
	{
		if (m_authorName) {
			delete[] m_authorName;
		}
		setName(name);
	}

	Book::~Book() {
		setEmpty();
	}

	Book::Book(const Book& b) {
		if (this != &b) {
			if (m_authorName) {
				delete[] m_authorName;
			}
			if (b.m_authorName && b.m_authorName[0] != '\0') {
				setName(b.m_authorName);
			}
			else {
				m_authorName = nullptr;
			}
		}
	}

	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			Publication::operator=(b);
			if (m_authorName) {
				delete[] m_authorName;
			}
			if (b.m_authorName && b.m_authorName[0] != '\0') {
				setName(b.m_authorName);
			}
			else {
				m_authorName = nullptr;
			}
		}
		return *this;
	}


	char Book::type() const
	{
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
		Publication::write(os);

		if (conIO(os)) {
			os << " ";
			char tempName[SENECA_AUTHOR_WIDTH + 1] = { '\0' };
			strncpy(tempName, m_authorName, SENECA_AUTHOR_WIDTH);
			os << setw(SENECA_AUTHOR_WIDTH) << left << setfill(' ') << tempName << " |";
		}
		else {
			os << "\t" << m_authorName;
		}
		return os;
	}

	std::istream& Book::read(std::istream& is) {
		Publication::read(is);
		char tempName[256] = { 0 };
		if (m_authorName) {
			setEmpty();
		}

		if (conIO(is)) {
			is.ignore();

			cout << "Author: ";
		}
		else {
			is.ignore();
		}

		is.get(tempName, 256);

		if (is) {
			if (m_authorName) {
				delete[] m_authorName;
			}
			setName(tempName);
		}

		return is;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);

		Publication::resetDate();
	}
	Book::operator bool() {
		return (m_authorName && m_authorName[0] != '\0' && Publication::operator bool());
	}

}