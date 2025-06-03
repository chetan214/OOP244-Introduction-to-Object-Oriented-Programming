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

#include "Item.h"
#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {


        //for set the m_itemName
        void Item::setName(const char* name){
        //TODO :should deallocate and it's looks weird
        if(name[0]!= '\0'){
            if (strlen(name) <= 20)
                strcpy(m_itemName, name);
            else {
                strncpy(m_itemName, name, 20);
                m_itemName[20] = '\0';
            }
        }
        }

        //set the Item to Empty State
        //Setting the m_itemName to a blank string
        void Item::setEmpty(){
        m_price = 0.0;
        m_taxed = false;
        m_itemName[0] = '\0';
        //TODO::check the init
        }

/*Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method
 * and sets the m_price and m_taxed attributes to the corresponding arguments.
 * If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state (safe empty state).*/
        void Item::set(const char* name, double price, bool taxed){
            if (price < 0 ||name == nullptr){
                setEmpty();
            }else{
                m_price = price;
                m_taxed = taxed;
                setName(name);
            }
        }

        void Item::display()const{
            if(isValid()){
                cout <<"| " ;

                cout.setf( ios::left );
                cout.fill('.');
                cout.width(20);
                cout << m_itemName;
                cout.unsetf( ios::left );


                cout << " | " ;
                cout.setf( ios::right );
                cout.setf( ios::fixed );
                cout.precision( 2 );
                cout.fill(' ');
                cout.width(7);
                cout << m_price;
                cout.unsetf( ios::right );
                cout.unsetf( ios::fixed );

                cout << " | " ;

                (m_taxed)?cout << "Yes":cout << "No ";
                cout << " |" << endl;
            }else{
                cout <<"| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
            }
        }

        //safe state check
        bool Item::isValid()const{
            bool ret = true;
            if (m_price == 0.0 && !m_taxed && m_itemName[0] == '\0'){
                ret = false;
            }
            return ret;
        }

        //Returns the m_price attribute;
        double Item::price()const{
            return m_price;
        }

        //Returns the product of m_price and 0.13(define a constant double value for this tax rate).
        //Or it returns 0.0 if the m_taxed is false.
        double Item::tax()const{
            double ret = 0.0;
            if(m_taxed){
               ret = m_price*0.13;
            }
            //return (!m_taxed)? 0.0 :m_price*m_taxed;
            return ret;
        }

}
