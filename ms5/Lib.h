// Final Project Milestone 5
// Lib Module
// File	Lib.h
// Version 1.0
// Author	
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////

#ifndef SENECA_LIB_H__
#define SENECA_LIB_H__

namespace sdds {

	// maximum number of day a publication can be borrowed with no penalty
	const int SENECA_MAX_LOAN_DAYS = 15;

	// The width in which the title of a publication should be printed on the
	// console
	const int SENECA_TITLE_WIDTH = 30;

	// The width in which the author name of a book should be printed on the console
	const int SENECA_AUTHOR_WIDTH = 15;

	// The width in which the shelf id of a publication should be printed on the
	// console
	const int SENECA_SHELF_ID_LEN = 4;

	// The length of membership number of members of the library
	const int SENECA_MEMBERSHIP_LEN = 5;

	// Maximum number of publications the library can hold.
	const int SENECA_LIBRARY_CAPACITY = 333;

	const int SEARCH_ON_LOAN = 1;

	const int SEARCH_AVAILABLE = 2;

	const int SEARCH_ALL = 3;

} // namespace seneca

#endif