/*//////////////////////////////////////////////////////////////////////////
                        Workshop - #9
Name: Chetan Arora
Email: carora18@myseneca.ca
Student ID: 100976240
Section: ZFF
Date:  July 31 2024
/////////////////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied
the code that my professor provided to complete my workshops and assignments.
////////////////////////////////////////////////////////////////////////////*/
#define _CTR_NO_WARNINGS_
#include "Text.h"
#include <fstream>
#include <cstring>

namespace seneca {
    // Returns the length of the file in bytes
    int Text::getFileLength() const {
        int len = 0;
        std::ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    // Provides read-only access to the content of the text
    const char& Text::operator[](int index) const {
        return m_content[index];
    }

    // Constructor initializes the Text object with the given filename
    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }

    // Copy constructor
    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        *this = other;
    }

    // Copy assignment operator
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            delete[] m_filename;
            delete[] m_content;

            if (other.m_filename) {
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
            } else {
                m_filename = nullptr;
            }

            if (other.m_content) {
                m_content = new char[strlen(other.m_content) + 1];
                strcpy(m_content, other.m_content);
            } else {
                m_content = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    // Reads the file content into memory
    void Text::read() {
        delete[] m_content;
        m_content = nullptr;

        if (m_filename) {
            std::ifstream file(m_filename);
            if (file.is_open()) {
                int length = getFileLength();
                if (length > 0) {
                    m_content = new char[length + 1];
                    file.clear();
                    file.seekg(0, std::ios::beg);
                    file.read(m_content, length);
                    m_content[length] = '\0';
                }
            }
        }
    }

    // Inserts the content of the Text object into the output stream
    void Text::write(std::ostream& os) const {
        if (m_content) {
            os << m_content;
        }
    }

    // Overloads the insertion operator for Text objects
    std::ostream& operator<<(std::ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}


