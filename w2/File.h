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
#ifndef SENECA_FILE_H
#define SENECA_FILE_H
namespace seneca {
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    // TODO: Declare read prototypes

    bool read(char* name);
    bool read(int& intNum);
    bool read(double& dulNum);
}

#endif //SENECA_FILE_H
