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
#define _CRT_NO_WARNINGS_
#include "HtmlText.h"
#include <cstring>

namespace seneca {
    // Constructor initializes the HtmlText object with the given filename and title
    HtmlText::HtmlText(const char* filename, const char* title)
        : Text(filename), m_title(nullptr) {
        if (title) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    // Copy constructor
    HtmlText::HtmlText(const HtmlText& other)
        : Text(other), m_title(nullptr) {
        *this = other;
    }

    // Copy assignment operator
    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) {
            Text::operator=(other);

            delete[] m_title;
            if (other.m_title) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            } else {
                m_title = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    // Overrides the write function to convert the text to HTML format
    void HtmlText::write(std::ostream& os) const {
        os << "<html><head><title>";
        if (m_title) {
            os << m_title;
        } else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
        }

        bool MS = false; // To track multiple spaces
        for (int i = 0; (*this)[i] != '\0'; ++i) {
            switch ((*this)[i]) {
                case ' ':
                    if (MS) {
                        os << "&nbsp;";
                    } else {
                        MS = true;
                        os << ' ';
                    }
                    break;
                case '<':
                    os << "&lt;";
                    MS = false;
                    break;
                case '>':
                    os << "&gt;";
                    MS = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    MS = false;
                    break;
                default:
                    MS = false;
                    os << (*this)[i];
                    break;
            }
        }
        os << "</body>\n</html>";
    }
}
