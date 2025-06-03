/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1 (P1)
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date	   : 15 May 2024
 
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "ShoppingRec.h"
#include "Utils.h"
using namespace std;

namespace seneca {

ShoppingRec getShoppingRec() {
    ShoppingRec R = {};
    cout << "Item name: ";
    readCstr(R.m_title, MAX_TITLE_LENGTH);
    cout << "Quantity: ";
    R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
    return R;
}
void displayShoppingRec(const ShoppingRec* shp) {
    cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
        " qty:(" << shp->m_quantity << ")" << endl;
}
void toggleBoughtFlag(ShoppingRec* rec) {
    rec->m_bought = !rec->m_bought;

}
bool isShoppingRecEmpty(const ShoppingRec* shp) {
    return shp->m_title[0] == 0;
}
}