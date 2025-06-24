//
// Created by Admin on 22/06/2025.
//
// #include "SortedList.h"
// int function(const int& i) {
//     int j = i;
//     j += 100;
//     return j ;
// }
//
// bool applay(const int& i) {
//     return  (i < 100);
// }
//
// int main() {
//    mtm::SortedList<int> list  ;
//     list.insert(3);
//     list.insert(1);
//     list.insert(2);
//     int i = list[0];
//    std::cout << i << std::endl ;
//     auto new_list = list.apply(&function);  // produces {101, 102}
//
//    new_list.print();
//     new_list.insert( 89);
//     auto newrr_list = new_list.filter(&applay);
//     newrr_list.print();
//
//
//     std::cout << "List using iterator:\n";
//
//     for (auto it = list.begin(); it != list.end(); ++it) {
//         std::cout << *it << " ";   // dereference and print value
//     }
//     std::cout << "\n";
//     std::cout << "List using iterator:\n";
//
//     for (auto it = list.begin(); it != list.end(); ++it) {
//         std::cout << *it << " ";   // dereference and print value
//     }
//     std::cout << "\n";
//
//     return 0;
//    }
