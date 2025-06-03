/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date       : 23 May 2024

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

    int noOfEmployees;
    Employee* employees;

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    // loads a employee structure with its values from the file
    // TODO: Finish the implementation of the 1 arg display function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(struct Employee* emp) {
        bool ok = false;
        char name[128];
        /* if reading of employee number, salay and name are successful
                allocate memory to the size of the name + 1
                and keep its address in the name of the Employee Reference

                copy the name into the newly allocated memroy

                make sure the "ok" flag is set to true
           end if
        */
        if (read(emp->m_empNo) && read(emp->m_salary) && read(name)) {
            emp->m_name = new char[strlen(name) + 1];//the real name length of employees
            strcpy(emp->m_name, name);
            //cout << "NO :" << emp->m_empNo << " Salary :" << emp->m_salary << " Name :" << emp->m_name <<endl;
            ok = true;
        }

        return ok;
    }


    // TODO: Finish the implementation of the 0 arg load function
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            //FILE* pFile = fopen(DATAFILE, "r");
                /*
                 Set the noOfEmployees to the number of recoreds in the file.
                 dyanamically allocated an array of employees into the global
                 Employee pointer; "employees" to the size of the noOfEmployees.

                 In a loop load the employee records from the file into
                 the dynamic array.

                 If the number of the records does not match the number of reads
                    print the message
                   "Error: incorrect number of records read; the data is possibly corrupted"
                 Otherwise
                    set the ok flag to true
                 End if

                 close the file
                 */
            noOfEmployees = noOfRecords();
            employees = new struct Employee[noOfEmployees + 1];
            for (i = 0; i < noOfEmployees; i++) {
                load(&employees[i]);
                //cout <<"index " << i<< " emp num is "<< employees[i].m_empNo << endl;
            }

            if (i != noOfEmployees) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            ok = true;
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here

    void display(const struct Employee* emp) {
        cout << emp->m_empNo << ": " << emp->m_name << ", " << emp->m_salary << endl;
    }

    void display() {
        cout << "Employee Salary report, sorted by employee number\n"
            "no- Empno, Name, Salary\n"
            "------------------------------------------------" << endl;
        sort();
        int i = 0;
        for (i = 0; i < noOfEmployees; ++i) {
            cout << i + 1 << "- ";
            display(&employees[i]);
        }


    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        int i = 0;
        for (i = 0; i < noOfEmployees; ++i) {
            delete[] employees[i].m_name;
            employees[i].m_name = nullptr;
        }
        delete[] employees;
        employees = nullptr;
    }


}