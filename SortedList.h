#pragma once

#include <cassert>
#include <iostream>
#include <stdexcept>
#include "Node.h"


namespace mtm {

    template <typename T>


    class SortedList {
     Node<T>* list ;
       // int size;

        void clear() {
            Node<T>* curr = list;
            while (curr != nullptr) {
                Node<T>* next = curr->getNext();
                delete curr;
                curr = next;
            }
            list = nullptr;
        }
    public:
        /**
       // * constructors and destructor:

               * 2. copy constructor
               * 3. operator= - assignment operator

      */
        //* 1. SortedList() - creates an empty list.
SortedList() {
    list = nullptr;

}

     const   int length () const{
    if(list == nullptr) {
        return  0;
    }
    int length = 0;
    Node<T>* ptr = list ;
    while (ptr != nullptr) {
        length++;
        ptr = ptr->getNext();
    }
return length;
}



        //* 4. ~SortedList() - destructor
        ~SortedList() {
    clear();
}


        SortedList& operator=(const SortedList& other) {
    if (this == &other) return *this;
    if (other.list == nullptr) {
        this->list = nullptr;

    } else {
        if(list != nullptr) {
          clear();
        }
        Node<T>* S = new Node<T>(other.list->getValue());;
        Node<T>* tar = S;
        Node<T>* D = other.list;
        while (D->getNext() != nullptr) {
            D = D->getNext();
            S->add(D->getValue());
            S=S->getNext();
        }

        this->list= tar ;
    }
return  *this;
        }

        SortedList(const SortedList& other) {
    if (!other.list) {
        this->list = nullptr;

    } else {
        Node<T>* S = new Node<T>(other.list->getValue());;
        Node<T>* tar = S;
        Node<T>* D = other.list;
        while (D->getNext() != nullptr) {
            D = D->getNext();
            S->add(D->getValue());
            S=S->getNext();
        }

        this->list= tar ;
    }

        }
        SortedList(const Node<T>* other)
{
    if (!other) {
        this->list = nullptr;
    } else {
        Node<T>* S = new Node<T>(other->value);;
Node<T>* new_node = S ;
        Node<T>* D = other;
        while (D->getNext() != nullptr) {
  D =D->getNext();
            S->add(D->getValue());
            S = S->getNext();

        }
this->list = new_node ;
    }

}

        void insert(const T& value)
{
    bool inserted = false;
    Node<T>* new_node = new Node<T>(value);

    if (list == nullptr) {
        list = new_node;
        return;
    }

    Node<T>* new_list = nullptr;
    Node<T>* tial = nullptr;
    Node<T>* curr = list;

    while (curr != nullptr) {
        const T currvalue = curr->getValue();
        if (!inserted && currvalue > value) {
            Node<T>* n = new Node<T>(value);
            if (!new_list) {
                new_list = tial = n;
            } else {
                tial->setNext(n);
                tial = n;
            }
            inserted = true;
        }

        Node<T>* n = new Node<T>(curr->getValue());
        if (!new_list) {
            new_list = tial = n;
        } else {
            tial->setNext(n);
            tial = n;
        }
        curr = curr->getNext();
    }

    if (!inserted) {
        Node<T>* n = new Node<T>(value);
        if (!new_list) {
            new_list = n;
        } else {
            tial->setNext(n);
        }
    }

    clear();
    list = new_list;
}



       class ConstIterator;
        ConstIterator begin() const {
            return ConstIterator(list);
        }
         ConstIterator end() const {
            return ConstIterator( nullptr);
        }
        ConstIterator begin()  {
            return ConstIterator(list);
        }
        ConstIterator end()  {
            return ConstIterator( nullptr);
        }

        //* 9. remove - removes an element from the list
 void remove(ConstIterator it) {
            Node<T>* tar = it.current;
            if (tar == nullptr) {
                return;
            }

            if (tar == list) {
                Node<T>* del= list;
                list = list->getNext();
                delete del;
                return;
            }

            Node<T>* oldptr= list;
            Node<T>* new_list = new Node<T>(oldptr->getValue());
            Node<T>* ptr_new = new_list;
            oldptr = oldptr->getNext();

            while (oldptr != nullptr) {
                if (oldptr != tar) {
                    ptr_new->setNext(new Node<T>(oldptr->getValue()));
                    ptr_new = ptr_new->getNext();
                }
                oldptr = oldptr->getNext();
            }
            clear();
            list = new_list;
        }



//* 12. apply - returns a new list with elements that were modified by an operation
        SortedList<T> apply (T (*predicate)(const T&)) const {
            SortedList<T> new_list;
            Node<T>* ptr = list;
            while (ptr != nullptr) {
                    new_list.insert(predicate(ptr->getValue()));
                ptr = ptr->getNext();
            }
            return new_list;
        }

       // 11. filter - returns a new list with elements that satisfy a given condition
        SortedList<T> filter (bool (*predicate)(const T&)) const {
            SortedList<T> new_list;
            Node<T>* ptr = list;
            while (ptr != nullptr) {
                if(predicate(ptr->getValue())) {
                     new_list.insert(ptr->getValue());
                }
                ptr = ptr->getNext();
            }
            return new_list;
        }


        T& operator[](int index) {
            if (index < 0 || index >= length()) {
                throw index;
            }
            Node<T>* ptr = list;
            for (int i = 0; i < index; ++i) {
                ptr = ptr->getNext();
            }
            return ptr->getValue();

        }
        const  T& operator[](int index) const {
            if (index < 0 || index >= length()) {
                throw index;
            }
            Node<T>* ptr = list;
            for (int i = 0; i < index; ++i) {
                ptr = ptr->getNext();
            }
            return ptr->getValue();

        }
        /**
         *
         * the class should support the following public interface:
         * if needed, use =defualt / =delete
         *

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
        //delet later
        void print(std::ostream& os = std::cout, const char* sep = " ") const {
            Node<T>* ptr = list;
            bool first = true;
            while (ptr != nullptr) {
                if (!first) {
                    os << sep;
                }
                ptr->print();
                first = false;
                ptr  = ptr->getNext();
            }
        }


        void addtoLst(T& value) {
            if (!list) {
                list = new Node<T>(value);
            } else {
                list->add(value);
            }
        }
    };


    template <typename T>
   class SortedList<T>::ConstIterator {
        Node<T>* current;
friend  SortedList< T>;
    public:
        explicit ConstIterator(Node<T>* ptr) : current(ptr) {}
        ConstIterator(const ConstIterator&) = default;
        ConstIterator& operator=(const ConstIterator&) = default;
        ~ConstIterator() = default;
        const T& operator*() const {
            if (current == nullptr) {
                throw std::out_of_range("Dereference of end()");
            }
            return current->getValue();
        }

        ConstIterator& operator++() {
            if (current == nullptr) {
                throw std::out_of_range("Increment past end of SortedList");
            }
            current = current->getNext();
            return *this;
        }
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

