/*/////////////////////////////////////////////////////////////////////////
                          Milestone 2
Full Name  :Chetan Arora
Student ID#:100976240
Email      :carora18@myseneca.ca
Section    :ZFF
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>

namespace seneca
{
	const int MAX_MENU_ITEMS = 20;

	class Menu;

	class MenuItem
	{
		friend class Menu;

		char* m_menu_content;

		MenuItem();
		MenuItem(const char* menu_content);

		MenuItem(const MenuItem& menu_item) = delete;
		MenuItem& operator=(const MenuItem& menu_item) = delete;

		~MenuItem();

		operator bool() const;
		operator const char* () const;

		friend void display(std::ostream& out, const MenuItem& menuItem);
	};

	class Menu
	{
		MenuItem m_title;
		MenuItem* m_menu_items[MAX_MENU_ITEMS];
		int m_size;

	public:
		Menu();
		Menu(const char* title);

		~Menu();

		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;

		friend void displayTitle(std::ostream& out, const Menu& menu);
		void displayMenu() const;

		unsigned int run() const;

		unsigned int operator~() const;
		Menu& operator<<(const char* menuItemContent);

		operator int() const;
		operator unsigned int() const;
		operator bool() const;

		friend std::ostream& operator<<(std::ostream& out, const Menu& menu);
		const char* operator[](const unsigned int i) const;
	};
}