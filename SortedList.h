#pragma once

#include <iostream>
#include <stdexcept>

namespace mtm {

    template <typename T>


    class SortedList {
     T value ;
     T* list ;
        int size;
    public:

SortedList();
        SortedList(T value);
        ~SortedList();
        SortedList& operator=(const SortedList& list);
        SortedList& operator=( T  value);
 SortedList(const SortedList& sorted_list);
void insert (const T value) ;

       class ConstIterator;
        ConstIterator begin() const;
         ConstIterator end() const;

 void remove(ConstIterator it);

        SortedList<T> filter (bool (*predicate)(const T&)) const;
        SortedList<T> apply (T (*predicate)(const T&)) const;

       T& SortedList& operator[](int i);
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
int length () const;
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


