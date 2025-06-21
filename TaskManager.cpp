#include "TaskManager.h"




void TaskManager::assignTask(const string &personName, const Task &task) {
int index = -1 , i = 0 ;
for (SortedList<Person>::ConstIterator it = persons.begin(); it != persons.end();++it , i++) {
    if ((*it).getName() == personName) {
        index = i ;
    }
}
    if(index != -1) {
        persons[index].assignTask(task);
    } else {

    }
}
void TaskManager::completeTask(const string &personName) {
    int index = -1 , i = 0 ;
    for (SortedList<Person>::ConstIterator it = persons.begin(); it != persons.end();++it , i++) {
        if ((*it).getName() == personName) {
            index = i ;
        }
    }
        persons[index].completeTask();
}
