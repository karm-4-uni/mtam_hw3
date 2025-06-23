//
// Created by Admin on 22/06/2025.
//

#ifndef NODE_H
#define NODE_H
#include <stdexcept>
#include <iostream>
#endif //NODE_H
enum Status{
    full,
    empty
};
template <typename T>
class  Node {
    T value;
    Node* next ;
Status stat;

public:
    Node() = delete ;
    Node(const T& value) : value(value), next(nullptr), stat(full) {}
    void add(T value) {
        if(stat == empty) {
            this->value = value;
            this->next = nullptr ;
            stat=full;
        }   else if (this->next == nullptr) {
            this->next = new Node<T>(value);
        } else {
            this->next->add(value);
        }

    }
     Node& operator=(const Node node )  {
        this,stat = node.stat ;
        if(this->stat == full) {
          this->value = node.value;
        }
        this->next = node.next;
        return *this;

    }
    Node& operator=(const T value )  {
        this->value = value;
        this->next = nullptr;
        stat = full;
        return *this;
    }
    ~Node() = default;
    bool operator< (const Node other ) const{
        if (this->stat == empty || other.stat == empty) {
            throw std::logic_error("Cannot compare empty nodes");
        }
        if(this->value < other.value) {
            return true;
        }
        return  false;
    }
    bool operator> (const Node other ) const {
        if (this->stat == empty || other.stat == empty) {
            throw std::logic_error("Cannot compare empty nodes");
        }
        if(this->value < other.value) {
            return false;
        }
        return  true;
    }
    void print() const {
        if(stat == full) {
            std::cout << value;
        }

    }
    T& getValue() {
        if(stat == full) {
            return  value;
        }
        throw std::logic_error("Accessing value of empty node");
    }
    const T getValue() const {
        if(stat == full) {
            return  value;
        }
        throw std::logic_error("Accessing value of empty node");
    }
    void setValue( T value) {
        this->value = value ;
        if(stat == empty) {
            stat = full;
        }
    }
    Node<T>* getNext() {
        return  next;
    }
    void setNext(Node<T>* next)  {
        this->next = next;
    }

};