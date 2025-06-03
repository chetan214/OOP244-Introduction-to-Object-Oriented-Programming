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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include <cstring>

using namespace std;

namespace seneca {

    MenuItem::MenuItem(const char* c) : content(nullptr) {
        if (c && c[0] != '\0') {
            content = new char[strlen(c) + 1];
            strcpy(content, c);
        }
    }

    MenuItem::~MenuItem() {
        delete[] content;
    }

    MenuItem::operator bool() const {
        return content != nullptr && content[0] != '\0';
    }

    MenuItem::operator const char*() const {
        return content;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (*this) {
            os << content;
        }
        return os;
    }

    Menu::Menu(const char* t) : title(nullptr), numItems(0) {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            items[i] = nullptr;
        }
        if (t && t[0] != '\0') {
            title = new MenuItem(t);
        }
    }

    Menu::~Menu() {
        delete title;
        for (unsigned int i = 0; i < numItems; ++i) {
            delete items[i];
        }
    }

    std::ostream& Menu::displayTitle(std::ostream& os) const {
        if (title) {
            title->display(os);
        }
        return os;
    }

    std::ostream& Menu::displayMenu(std::ostream& os) const {
        if (title) {
            displayTitle(os) << ":\n";
        }
        for (unsigned int i = 0; i < numItems; ++i) {
            os.width(2);
            os << i + 1 << "- ";
            items[i]->display(os) << "\n";
        }
        os << " 0- Exit\n> ";
        return os;
    }

    unsigned int Menu::run() const {
        unsigned int selection;
        bool valid = false;
        displayMenu(cout);
        do {
            cin >> selection;
            if (cin.fail() || selection > numItems) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Selection, try again: ";
            } else {
                valid = true;
            }
        } while (!valid);
        return selection;
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (numItems < MAX_MENU_ITEMS) {
            items[numItems++] = new MenuItem(menuItemContent);
        }
        return *this;
    }

    Menu::operator unsigned int() const {
        return numItems;
    }

    Menu::operator bool() const {
        return numItems > 0;
    }

    const char* Menu::operator[](unsigned int index) const {
        return *items[index % numItems];
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        return menu.displayTitle(os);
    }
}
