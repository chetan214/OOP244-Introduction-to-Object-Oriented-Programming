/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #10
Name: Chetan Arora
Email: carora18@myseneca.ca
Student ID: 100976240
Section: ZFF
Date:  Aug 7 2024
/////////////////////////////////////////////////////////////////////////////
I have done all the coding by myself and only copied
the code that my professor provided to complete my workshops and assignments.
////////////////////////////////////////////////////////////////////////////*/

/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// Collection template
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_COLLECTION_H_
#define SENECA_COLLECTION_H_
namespace seneca {
   template <typename T>
   class Collection {
      T* m_data = nullptr;
      int m_size = 0;
   public:
      Collection(int size = 0);
      Collection(const Collection<T>& CP);
      Collection<T>& operator=(const Collection<T>& RO);
      int size()const;
      void resize(int newsize);
      T& operator[](int index);
      Collection<T>& add(const T& element);
      ~Collection();
   };

   template <typename T>
   Collection<T>::Collection(int size) :m_size(size) {
      if (m_size <= 0) m_size = 0;
      if (m_size > 0) m_data = new T[m_size];
   }
   template <typename T>
   Collection<T>::Collection(const Collection<T>& CP) {
      operator=(CP);
   }
   template <typename T>
   Collection<T>& Collection<T>::operator=(const Collection<T>& RO) {
      if (this != &RO) {
         delete[] m_data;
         m_data = new T[m_size = RO.m_size];
         for (int i = 0; i < m_size; i++) m_data[i] = RO.m_data[i];
      }
      return *this;
   }

   template <typename T>
   int Collection<T>::size()const {
      return m_size;
   }

   template <typename T>
   void Collection<T>::resize(int newsize) {
      int i;
      T* temp = nullptr;
      if (newsize < 0) newsize = 0;
      if (newsize > 0) {
         temp = new T[newsize];
         for (i = 0; i < m_size && i < newsize; i++) {
            temp[i] = m_data[i];
         }
      }
      delete[] m_data;
      m_data = temp;
      m_size = newsize;
   }

   template <typename T>
   T& Collection<T>::operator[](int index) {
      if (index >= m_size) resize(index + 1);
      return m_data[index];
   }

   template <typename T>
   Collection<T>& Collection<T>::add(const T& element) {
      (*this)[size()] = element;
      return *this;
   }
   template <typename T>
   Collection<T>::~Collection() {
      delete[] m_data;
   }
}

#endif



