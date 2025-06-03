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
#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__

#include "Text.h"

namespace seneca {
    class HtmlText : public Text {
        char* m_title; // Holds the title of the HTML conversion

    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr); // Constructor
        HtmlText(const HtmlText& other);           // Copy constructor
        HtmlText& operator=(const HtmlText& other); // Copy assignment operator
        ~HtmlText();                               // Destructor

        void write(std::ostream& os) const override; // Overrides the write function to convert text to HTML format
    };
}

#endif
