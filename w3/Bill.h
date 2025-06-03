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
#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"
namespace seneca {
    class Bill {
        char m_title[37];
        Item* m_items;
        int m_noOfItems;
        int m_itemsAdded;
        double totalTax()const;
        double totalPrice()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(const char* title, int noOfItems);
        bool add(const char* item_name, double price, bool taxed);
        void display()const;
        void deallocate();
    };
}
#endif 