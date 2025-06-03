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

#ifndef SENECA_SHOPPINGLIST_H // replace with relevant names
#define SENECA_SHOPPINGLIST_H

// Your header file content goes here
#include "ShoppingRec.h"
namespace seneca {
bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();
}
#endif
