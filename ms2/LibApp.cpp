/*/////////////////////////////////////////////////////////////////////////
                          Milestone 2
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF
/////////////////////////////////////////////////////////////////////////*/

#include "LibApp.h"

#include <iostream>


namespace seneca
{
	bool LibApp::confirm(const char* message)
	{
		Menu confirmationMenu(message);

		confirmationMenu << "Yes";
		const unsigned choice = confirmationMenu.run();
		return choice == 1;
	}

	void LibApp::load()
	{
		std::cout << "Loading Data\n";
	}

	void LibApp::save()
	{
		std::cout << "Saving Data\n";
	}

	void LibApp::search()
	{
		std::cout << "Searching for publication\n";
	}

	void LibApp::returnPub()
	{
		search();
		std::cout << "Returning publication\n";
		std::cout << "Publication returned\n\n";

		m_changed = true;
	}

	void LibApp::newPublication()
	{
		std::cout << "Adding new publication to library\n";

		bool confirmed = confirm("Add this publication to library?");
		if (confirmed)
		{
			m_changed = true;
			std::cout << "Publication added\n";
		}
		std::cout << '\n';
	}

	void LibApp::removePublication()
	{
		std::cout << "Removing publication from library\n";
		search();
		bool confirmed = confirm("Remove this publication from the library?");
		if (confirmed)
		{
			m_changed = true;
			std::cout << "Publication removed\n";
		}
		std::cout << '\n';
	}

	void LibApp::checkOutPub()
	{
		search();
		bool confirmed = confirm("Check out publication?");
		if (confirmed)
		{
			m_changed = true;
			std::cout << "Publication checked out\n";
		}
		std::cout << '\n';
	}

	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		m_mainMenu << "Add New Publication" << "Remove Publication" <<
			"Checkout publication from library" <<
			"Return publication to library";
		m_exitMenu << "Save changes and exit" <<
			"Cancel and go back to the main menu";

		load();
	}

	void LibApp::run()
	{
		while (true)
		{
			unsigned choiceMain = m_mainMenu.run();
			if (choiceMain == 1)
				newPublication();
			else if (choiceMain == 2)
				removePublication();
			else if (choiceMain == 3)
				checkOutPub();
			else if (choiceMain == 4)
			{
				returnPub();
			}
			else
			{
				if (m_changed)
				{
					unsigned choiceExit = m_exitMenu.run();
					if (choiceExit == 1)
					{
						save();
						m_changed = false;
						break;
					}
					if (choiceExit == 0)
					{
						bool confirmed = confirm("This will discard all the changes are you sure?");
						if (confirmed)
						{
							m_changed = false;
							break;
						}
					}
					if (choiceExit == 2)
						std::cout << '\n';
				}
				else
				{
					m_changed = false;
					break;
				}
			}
		}
		std::cout << "\n-------------------------------------------\n";
		std::cout << "Thanks for using Seneca Library Application" << std::endl;
	}

}