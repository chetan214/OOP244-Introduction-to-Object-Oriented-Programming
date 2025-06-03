/*/////////////////////////////////////////////////////////////////////////
                          Milestone 1
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>

namespace seneca {

    const unsigned int MAX_MENU_ITEMS = 20;

    class Menu; // Forward declaration

    class MenuItem {
        char* content;
        MenuItem(const char* c = nullptr);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        operator bool() const;
        operator const char*() const;
        std::ostream& display(std::ostream& os) const;
        friend class Menu;
    };

    class Menu {
        MenuItem* title;
        MenuItem* items[MAX_MENU_ITEMS];
        unsigned int numItems;
    public:
        Menu(const char* title = nullptr);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        std::ostream& displayTitle(std::ostream& os) const;
        std::ostream& displayMenu(std::ostream& os) const;
        unsigned int run() const;
        Menu& operator<<(const char* menuItemContent);
        operator unsigned int() const;
        operator bool() const;
        operator const char*() const;
        const char* operator[](unsigned int index) const;
        unsigned int operator~() const;

        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
    };
}

#endif
