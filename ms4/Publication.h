/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Publication.h
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name            Date           Reason

------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

//Publication class module
//The publication class is a general encapsulation of any periodic publication.
//Later by adding an author to the descendant of the Publication class we will encapsulate a Book for the system.


#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include "Lib.h"
#include "Streamable.h"
#include "Date.h"

namespace seneca {

	class Publication : public Streamable {

		char* m_title;

		char m_shelfId[SENECA_SHELF_ID_LEN + 1];

		int m_membership;

		int m_libRef;

		Date m_date;

	public:

		Publication();

		void setDefault();

		virtual void set(int member_id);

		void setRef(int value);

		void resetDate();

		virtual char type()const;

		bool onLoan()const;

		Date checkoutDate()const;

		bool operator==(const char* title)const;

		operator const char* ()const;

		int getRef()const;

		bool conIO(std::ios& io)const;

		std::ostream& write(std::ostream& os) const;

		std::istream& read(std::istream& is);
		operator bool()const;

		~Publication();
		Publication(const Publication& Pub);
		Publication& operator=(const Publication& Pub);
	};
}

#endif // !SENECA_PUBLICATION_H