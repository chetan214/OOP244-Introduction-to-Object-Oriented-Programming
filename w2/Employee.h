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

#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#define DATAFILE "employees.csv"
namespace seneca {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();

    // loads a employee structue with its values from the file
    bool load(struct Employee* employee);

    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load();

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:
    void display(const struct Employee* emp);

    // TODO: Declare the prototype for the display function that
    // first sorts the employees then displays all the employees on the screen
    void display();
    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array
    void deallocateMemory();
}
#endif //SENECA_EMPLOYEE_H
