/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date       : 31 May 2024

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <cstring>
#include "Bill.h"

using namespace std;
namespace seneca {

    //Adds all the taxes of the items using a loop and returns the sum.
    double Bill::totalTax()const{
        double ret = 0.0;
        int i;
        for ( i = 0; i < m_noOfItems; ++i) {
            ret += m_items[i].tax();
        }
        return ret;
    }

    //Adds all the prices of the items using a loop and returns the sum;
    double Bill::totalPrice()const{
        double ret = 0.0;
        int i;
        for ( i = 0; i < m_noOfItems; ++i) {
            ret += m_items[i].price();
        }
        return ret;
    }

    //print title
    void Bill::Title()const{
        cout << "+--------------------------------------+\n";

        if(isValid()){
            cout << "| ";
            cout.setf( ios::left );
            cout.width(36);
            cout  << m_title;
            cout.unsetf( ios::left );
            cout << " |" << endl;
        }else{
            cout << "| Invalid Bill                         |" <<endl;
        }

        cout << "+----------------------+---------+-----+\n";
        cout << "| Item Name            | Price   + Tax |\n";
        cout << "+----------------------+---------+-----+" << endl;
    }


    void Bill::footer()const{

        cout << "+----------------------+---------+-----+" << endl;
        if(isValid()){
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf( ios::fixed );
            cout.precision(2);
            cout << totalTax()  << " |" << endl;
            cout.unsetf(ios::right);
            cout.unsetf( ios::fixed );


            cout << "|              Total Price: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf( ios::fixed );
            cout.precision(2);
            cout << totalPrice() << " |" << endl;
            cout.unsetf(ios::right);
            cout.unsetf( ios::fixed );


            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << (totalTax()+totalPrice()) << " |" << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }else{
           cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    //Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
    void Bill::setEmpty(){
        m_title[0] = '\0';
        m_items = nullptr;
    }

    //safe state check
    bool Bill::isValid()const{
        bool ret = true;
        if (m_title[0] != '\0' && m_items != nullptr){//means it's true
            int i;
            //if one of them is invalid it should be false and break
            for(i = 0;i< m_noOfItems;i++){
                if(!m_items[i].isValid()){
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }

    //If any of the arguments are invalid set empty
    //dynamically allocate an array of Items pointed by m_items member variable and the length of this array will be m_noOfItems
    void Bill::init(const char* title, int noOfItems){
        if(title== nullptr || noOfItems ==0){
            setEmpty();
        }else{
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title,title,36);
            m_title[36] = '\0';
            //m_items = nullptr;
            m_items = new Item[noOfItems];
            int i= 0;
            for(i = 0;i<m_noOfItems;i++){
                m_items[i].setEmpty();
            }
        }
    }


    /* If the number of added Items (m_itemsAdded) is less than the length of the m_items array,
    * this function will set the next available subject to the incoming argument values.
    * Then it will add one to the m_itemsAdded and return true;
    Otherwise, this function will do nothing, returning false;*/
    bool Bill::add(const char* item_name, double price, bool taxed){
        bool ret = false;
        if(m_itemsAdded < m_noOfItems){
            m_items[m_itemsAdded].set(item_name,price, taxed);
            m_itemsAdded += 1;
            ret = true;
        }

        return ret;
    }


    //This function will first print the title(),
    //then it will loop through the m_items elements, printing every one of them, and finally prints the footer().
    void Bill::display()const{
        Title();
        int i= 0;
        for(i = 0;i<m_noOfItems;i++){
            m_items[i].display();
        }
        footer();
    }

    //Deallocates the m_items arrays and sets the pointers to null.
    void Bill::deallocate(){
        delete[] m_items;
        m_items = nullptr;
    }

}
