#include  "SortedList.h"


template<typename T>
mtm::SortedList<T>::SortedList() {
    this->list= nullptr;
    size = 0 ;

}

template<typename T>
mtm::SortedList<T>::SortedList(T value) {
    this->list= new Super_ptr<T>[1];
         list[0] = value;
    size = 1 ;

}

template<typename T>
mtm::SortedList<T>& mtm::SortedList<T>::operator=(const mtm::SortedList<T> &tarlist) {
    if (this == &tarlist) {
        return *this;
    }
    size = tarlist.size;
    if (tarlist.size != 0) {
        Super_ptr<T[]> newlist = new Super_ptr<T[size]>;
        for (int i = 0 ; i < this->size ; i++ ) {
            newlist[i] = move(new T(*tarlist->list[i].get()));
        }
        this->list = std::move(newlist);
        return *this;
    } else {
       Super_ptr<T>* newlist = Super_ptr<T>(nullptr);
         this->list = std::move(newlist);
        return *this;
    }
}

template<typename T>
mtm::SortedList<T>& mtm::SortedList<T>::operator=(T value) {

if(this->size == 1 && this->list.get() == value) {
    return *this;
}
    size = 1;
    Super_ptr<T[]> newlist(new T[1]);
    newlist[0] = value;
    list = std::move(newlist);

    return *this;
}
template<typename T>
mtm::SortedList<T>::SortedList(const SortedList& other)
    : list(nullptr), size(other.size)
{
    if (size == 0) return;

    Super_ptr<T[]> newlsit(new T[size]);
    for (int i = 0; i < size; ++i) {
         newlsit[i] = other.list[i];
    }
    list = std::move(newlsit);
}
template<typename T>
mtm::SortedList<T>::~SortedList() {
}
template<typename T>
int mtm::SortedList<T>::length() const {
    return this->size;
}
template <class T>
 void  mtm::SortedList<T>::insert(const T value) {
    int size = this->size + 1;
    int i = 0 , j = 0;
    Super_ptr<T[]> newlsit(new T[size+1]);
    if(size == 1) {
        newlsit[0] = value;
    } else {
   while (j < size && i < size + 1   ) {
       if(this.list.get()[j] < value ) {
           newlsit[i]= std::move(value);

       }
       else {
           newlsit[i] = std::move(this.list.get()[j]);
           j++;
       }
       i++;
   }

    }

}