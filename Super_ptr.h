//
// Created by Admin on 14/06/2025.
//

#ifndef SUPER_PTR_H
#define SUPER_PTR_H

#endif //SUPER_PTR_H
template<typename  T >
class Super_ptr {
T* data ;

public:
    explicit  Super_ptr (T* ptr = nullptr) : data (ptr){}
    ~Super_ptr() {
            delete data;
    }

    T& operator*(){return *data;}
    T* operator->() {return data;}
Super_ptr(const Super_ptr&) = delete;
Super_ptr& operator=(const Super_ptr&) = delete;
    Super_ptr(Super_ptr&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    Super_ptr& operator=(Super_ptr&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
    T* get() const { return data; }
};
