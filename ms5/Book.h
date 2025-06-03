// Final Project Milestone 5
// Book Module
// File	Book.h
// Author	
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SENECA_BOOK_H__
#define SENECA_BOOK_H__

#include "Publication.h"
#include <iostream>

namespace sdds {
	class Book : public Publication {
	private:
		char* m_authorName;

		void setAuthorName(const char* authorName);

	public:
		Book();

		Book(const Book&);

		Book& operator=(const Book&);

		~Book();

		char type() const override;

		std::ostream& write(std::ostream& os = std::cout) const override;

		std::istream& read(std::istream& is = std::cin) override;

		void set(int member_id) override;

		operator bool() const override;
	};
}; // namespace seneca

#endif