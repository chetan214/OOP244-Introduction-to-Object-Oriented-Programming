/*/////////////////////////////////////////////////////////////////////////
                          Milestone 2
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF
/////////////////////////////////////////////////////////////////////////*/


#include "Menu.h"

namespace seneca
{
	class LibApp
	{
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		bool confirm(const char* message);
		void load();
		void save();
		void search();

		void returnPub();

	public:
		void newPublication();
		void removePublication();
		void checkOutPub();

		LibApp();
		void run();
	};
}