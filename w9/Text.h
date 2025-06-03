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

#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__

#include <iostream>

namespace seneca {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength() const; // Returns the length of the file

    protected:
        const char& operator[](int index) const; // Index operator for read-only access

    public:
        Text(const char* filename = nullptr); // Constructor
        Text(const Text& other); // Copy constructor
        Text& operator=(const Text& other); // Copy assignment operator
        ~Text(); // Destructor

        void read(); // Reads the file content into memory
        virtual void write(std::ostream& os) const; // Inserts the content into the output stream
    };

    std::ostream& operator<<(std::ostream& os, const Text& text); // Insertion operator overload
}

#endif
