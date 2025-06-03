/*------------------------------------------------------------------
 Final Project Milestone 4
 Book Module
 File	Book.h
 Version 1.0

 Revision History
 -----------------------------------------------------------
 Name            Date           Reason

------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#ifndef SENECA_BOOK_H__
#define SENECA_BOOK_H__
#include "Publication.h"
namespace seneca {

	class Book : public Publication {

		char* m_authorName{ nullptr };

	public:
		void setEmpty();
		void setName(const char* name);

		Book();
		Book(const char* name);

		~Book();
		Book(const Book&);
		Book& operator=(const Book&);


		char type() const;


		std::ostream& write(std::ostream& os) const;

		std::istream& read(std::istream& is);

		void set(int member_id);

		operator bool();

	};
}
#endif // !SENECA_BOOK_H__