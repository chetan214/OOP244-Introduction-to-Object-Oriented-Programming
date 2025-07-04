/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"

using namespace std;
namespace seneca {


    size_t Utils::getInt(size_t min, size_t max) {
        size_t val{};
        cin >> val;
        while ( cin.fail() || val < min || val >max) {
            cout << "Invalid Selection, try again: ";
            cin.clear( );
            cin.ignore( 12000, '\n' );
            cin >> val;
        }
        cin.ignore( 12000, '\n' );
        return val;
    }

    void Utils::getCstr( char* str, size_t len ) {
        cin.getline( str, len + 1 );
        while ( cin.fail( ) ) {
//            cout << "Maximum " << len << " chars!, retry\n> ";
            cin.clear( );
            cin.ignore( 12000, '\n' );
            cin.getline( str, len + 1 );
        }
    }

}