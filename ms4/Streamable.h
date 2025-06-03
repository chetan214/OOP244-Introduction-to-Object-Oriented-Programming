/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Streamable.h
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name          Date            Reason

------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/


#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H

#include <iostream>


namespace seneca {

    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;

        virtual std::istream& read(std::istream& is) = 0;

        virtual bool conIO(std::ios& io) const = 0;

        virtual operator bool() const = 0;

        virtual ~Streamable() = default;
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& s);
    std::istream& operator>>(std::istream& is, Streamable& s);
}

#endif //!SENECA_STREAMABLE_H