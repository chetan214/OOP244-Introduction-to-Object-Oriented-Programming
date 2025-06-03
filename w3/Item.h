/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date       : 31 May 2024

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_
namespace seneca {
    class Item {
        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display()const;
        bool isValid()const;
        double price()const;
        double tax()const;
    };
}

#endif 
