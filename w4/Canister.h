/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZFF
Date       : 7 Jun 2024

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_BOX_H
#define SENECA_BOX_H
#include <iostream>
namespace seneca
{

 // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s);
  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src);
  // strCmp: Compares two C-strings
  int strCmp(const char *s1, const char *s2);

  class Canister
  {
    char *m_contentName;    // points to a dynamically allocated Cstring.
    double m_diameter;      // in centimeters
    double m_height;        // in centimeters
    double m_contentVolume; // in CCs
    bool m_usable;          // a flag to identify if the Canister is usable or unusable

    void setToDefault();

    // Sets the content name of the current Canister.
    void setName(const char *Cstr);

    // Returns true is the content volume is less than 0.00001 CCs.
    bool isEmpty() const;

    // Compares the content name of this Canister with the C's content name
    bool hasSameContent(const Canister &C) const;

  public:
    // Sets the attributes to their default values
    Canister();

    // Sets the attributes to their default values
    // Sets the Name to the incoming contentName argument.
    Canister(const char *contentName);

    // Sets the attributes to their default values
    // Sets the corresponding argument values if condition meet
    Canister(double hieght, double diameter, const char *contentName = nullptr);

    // Deallocates the dynamic memory pointed by the content name attribute.
    ~Canister();

    // It will set the Content name of the canister
    Canister &setContent(const char *contentName);

    // Adds the quantity argument to the content volume of the "this" Canister
    Canister &pour(double quantity);

    // Pours the content of the Canister argument into the "this" Canister
    Canister &pour(Canister &);

    // returns the content volume attribute
    double volume() const;

    std::ostream &display() const;

    // returns the capacity
    double capacity() const;

    // Clears an unusable Canister back to an empty Caniste
    void clear();

    // Created to delete allocated memory of content Name
    void deallocate();
  };
} 
#endif
