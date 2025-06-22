#pragma once

#include <cassert>
#include <iostream>
#include <stdexcept>

namespace mtm {

    template <typename T>


    class SortedList {
     T* list ;
        int size;
    public:

SortedList() {
  //  this->list= nullptr;
    size = 0 ;
}
       explicit  SortedList(T value) {
           this->list= new T[1];
           list[0] = value;
           size = 1 ;
       }
        ~SortedList() = default;
        SortedList& operator=(const SortedList& tarlist) {
            if (this == &tarlist) {
                return *this;
            }
            size = tarlist.size;
            if (tarlist.size != 0) {
                T* newlist = nullptr;
                for (int i = 0 ; i < this->size ; i++ ) {
                    newlist[i] =  this->list[i];
                }
                delete[] this->list;
                this->list = newlist;
                return *this;
            } else {
                delete[] this->list;
                this->list = nullptr;
                return *this;
            }
        }
        // SortedList& operator=( T  value) {
        //     if(this->size == 1 && this->list[0] == value) {
        //         return *this;
        //     }
        //     size = 1;
        //     T* newlist(new T[1]);
        //     newlist[0] = value;
        //     delete[] this->list;
        //     list = newlist;
        //
        //     return *this;
        // }
        SortedList(const SortedList& other) : list(nullptr), size(other.size)
        {
            if (size == 0) return;

            T* newlsit = new T[size];
            for (int i = 0; i < size; ++i) {
                newlsit[i] = other.list[i];
            }
            list = newlsit;
        }

void insert (const T value) {
            int size = this->size ;
            int i = 0 , j = 0;
            bool inserted = false ;
            T* newlsit = nullptr;

            while (j < size && i < size + 1   ) {
              const  T val = this->list[j] ;
                if(value > val  && !inserted ) {
                    newlsit[i]= value;
                    inserted = true;
                }
                else {
                    newlsit[i] = this->list[j];
                    j++;
                }
                i++;
            }
            if (!inserted) {
                newlsit[size] = value;
            }
            delete[] list;
            list = newlsit;
            this->size++;
        }

       class ConstIterator;
        ConstIterator begin() const {
            return ConstIterator(list);
        }
         ConstIterator end() const {
            return ConstIterator(list + size);
        }

 void remove(ConstIterator it) {
            int index = it.current -  list ;
            if(index >= this->size || index < 0) {
                throw index;
            }
            T* newlist = nullptr ;
            int j = 0;
            for (int i = 0 ; i < size  ;i++ ) {
                if(i != index) {
                    newlist[j] = list[i];
                    j++;
                }

            }
            delete [] this->list;
            this->list= newlist;
            this->size-=1;
        }

        SortedList<T> filter (bool (*predicate)(const T&)) const {
            SortedList<T> new_list ;
            for(int i = 0 ; i < this->size ; i++) {
                if(predicate(list[i])) {
                    new_list.insert(list[i]);
                }
            }

            return new_list;
        }
        SortedList<T> apply (T (*predicate)(const T&)) const {
            SortedList<T> new_list;

            for(int i = 0 ; i < this->size ; i++) {
                new_list.insert(predicate(list[i]));
            }

            return new_list;
        }



        T& operator[](int i) {
            if(i>0 && i < size) {
                return this->list[i];
            }
            return this->list[i];
            //add expction
        }
      const  T& operator[](int i) const {
          if(i>0 && i < size) {
              return this->list[i];
          }

          //add expction
      }
        /**
         *
         * the class should support the following public interface:
         * if needed, use =defualt / =delete
         *
         * constructors and destructor:
         * 1. SortedList() - creates an empty list.
         * 2. copy constructor
         * 3. operator= - assignment operator
         * 4. ~SortedList() - destructor
         *
         * iterator:
         * 5. class ConstIterator;
         * 6. begin method
         * 7. end method
         *
         * functions:
         * 8. insert - inserts a new element to the list
         * 9. remove - removes an element from the list
         * 10. length - returns the number of elements in the list
         * 11. filter - returns a new list with elements that satisfy a given condition
         * 12. apply - returns a new list with elements that were modified by an operation
         */
int length () const {
            return  this->size;
        }
    };


    template <class T>
    class SortedList<T>::ConstIterator {
        T* current;
        friend class  SortedList<T>;
    public:
        ConstIterator(T* ptr) : current(ptr) {}
        ConstIterator(const ConstIterator&) = default;
        ConstIterator& operator=(const ConstIterator&) = default;
        ~ConstIterator() = default;
        const T& operator*() const { return *current; }
        ConstIterator& operator++() { ++current; return *this; }
        bool operator!=(const ConstIterator& other) const {
            return current != other.current;
        }
    };
    /**
     * the class should support the following public interface:
     * if needed, use =defualt / =delete
     *
     * constructors and destructor:
     * 1. a ctor(or ctors) your implementation needs
     * 2. copy constructor
     * 3. operator= - assignment operator
     * 4. ~ConstIterator() - destructor
     *
     * operators:
     * 5. operator* - returns the element the iterator points to
     * 6. operator++ - advances the iterator to the next element
     * 7. operator!= - returns true if the iterator points to a different element
     *
     */
    };
#include "SortedList.cpp"

