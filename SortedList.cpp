#include  "SortedList.h"


template<typename T>
mtm::SortedList<T>::SortedList() {
    this->list= nullptr;
    size = 0 ;

}

template<typename T>
mtm::SortedList<T>::SortedList(T value) {
    this->list= new T[1];
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
        T* newlist = new T[size];
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

template<typename T>
mtm::SortedList<T>& mtm::SortedList<T>::operator=(T value) {

if(this->size == 1 && this->list[0] == value) {
    return *this;
}
    size = 1;
    T* newlist(new T[1]);
    newlist[0] = value;
    delete[] this->list;
    list = newlist;

    return *this;
}
template<typename T>
mtm::SortedList<T>::SortedList(const SortedList& other)
    : list(nullptr), size(other.size)
{
    if (size == 0) return;

    T* newlsit = new T[size];
    for (int i = 0; i < size; ++i) {
         newlsit[i] = other.list[i];
    }
    list = newlsit;
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
    int size = this->size ;
    int i = 0 , j = 0;
    bool inserted = false ;
   T* newlsit(new T[size+1]);

   while (j < size && i < size + 1   ) {
       if(this.list[j] < value && !inserted ) {
           newlsit[i]= value;
           inserted = true;
       }
       else {
           newlsit[i] = this.list[j];
           j++;
       }
       i++;
   }
    if (!inserted) {
        newlsit[size] = value;
    }
    delete[] list;
    list = newlsit;
    size++;

}
template<typename T>
typename   mtm::SortedList<T>::ConstIterator mtm::SortedList<T>::begin() const {

    return ConstIterator(list);
}
template<typename T>
typename   mtm::SortedList<T>::ConstIterator mtm::SortedList<T>::end() const {
    return ConstIterator(list + size);
}

template<typename T>
void mtm::SortedList<T>::remove(ConstIterator it) {
    int index = it.current -  list ;
    if(index >= this->size || index < 0) {
        throw index;
    }
    T* newlist = new T[size - 1];
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
template<typename T>
mtm::SortedList<T> mtm::SortedList<T>::filter(bool (*predicate)(const T&)) const {
    SortedList<T> new_list ;
    for(int i = 0 ; i < this->size ; i++) {
        if(predicate(list[i])) {
            new_list.insert(list[i]);
        }
    }

    return new_list;
}
template<typename T>
mtm::SortedList<T> mtm::SortedList<T>::apply(T (*predicate)(const T&)) const {
    SortedList<T> new_list;

    for(int i = 0 ; i < this->size ; i++) {
            new_list.insert(predicate(list[i]));
    }

    return new_list;
}