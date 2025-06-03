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
#include <cstdio>
#include "File.h"

namespace seneca {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    // TODO: read functions go here

    bool read(char* name) {
        bool ret = false;

        if (fptr) {
            fscanf(fptr, "%[^\n]\n", name);
            ret = true;
        }
        return ret;
    }
    bool read(int& intNum) {
        bool ret = false;
        if (fptr) {
            fscanf(fptr, "%d,", &intNum);
            ret = true;
        }
        return ret;
    }
    bool read(double& dulNum) {
        bool ret = false;
        if (fptr) {
            fscanf(fptr, "%lf,", &dulNum);
            ret = true;
        }
        return ret;
    }

}