#include "TaskManager.h"




void TaskManager::assignTask(const std::string& personName, const Task& task) {
    bool flag = false;
for(int i = 0 ; i < persons.length() ; i++) {
    if(persons[i].getName() == personName) {
        Task new_task = task;
        new_task.setId(id++);
        persons[i].assignTask(new_task);
        flag = true;
    }
}
    if(!flag) {
        Person new_guy(personName);
        Task new_task = task;
        new_task.setId(id++);
        new_guy.assignTask(new_task);

addperson(new_guy);
    }
}

void TaskManager::completeTask(const string &personName) {
    int index = -1 , i = 0 ;
    for (SortedList<Person>::ConstIterator it = persons.begin(); it != persons.end();++it , i++) {
        if ((*it).getName() == personName) {
            index = i ;
        }
    }
    if (index == -1) {
        throw std::runtime_error("Person not found");
    }
    persons[index].completeTask();
}

void TaskManager::bumpPriorityByType(TaskType type, int priority) {
    if(priority > 0 ) {
        int  i = 0 ;
        for (SortedList<Person>::ConstIterator it = persons.begin(); it != persons.end();++it , i++) {
            SortedList<Task>::ConstIterator it2 = (*it).getTasks().begin();
            SortedList<Task> new_tasks;
while (it2 != (*it).getTasks().end() ) {
    if((*it2).getType() == type) {
        Task new_task((*it2).getPriority()+priority,
            (*it2).getType(),(*it2).getDescription());
        new_task.setId((*it2).getId());
        new_tasks.insert(new_task);
        ++it2;
    } else {
        new_tasks.insert((*it2));
        ++it2;
    }
}
 persons[i].setTasks(new_tasks);

        }
    }   else {

    }
}


void TaskManager::printAllEmployees() const {
    for (SortedList<Person>::ConstIterator it = persons.begin();
        it != persons.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void TaskManager::printAllTasks() const {
    TaskType type = TaskType::General ;
    printTask(type , 0);

}
void TaskManager::printTasksByType(TaskType type) const {

   printTask(type , 1);
}
void TaskManager::printTask(TaskType type , int flag ) const {
    SortedList<Task> new_tasks ;
    int i = 0;
    for (SortedList<Person>::ConstIterator it = persons.begin();
       it != persons.end(); ++it , i++) {
        for (SortedList<Task>::ConstIterator it2 = (*it).getTasks().begin();
      it2 != (*it).getTasks().end(); ++it2) {
            if((*it2).getType() == type || flag == 0 ) {
                new_tasks.insert((*it2));
            }
      }
       }
    for (SortedList<Task>::ConstIterator it3 = new_tasks.begin();
          it3 != new_tasks.end(); ++it3) {
        std::cout << *it3 << '\n';
          }
}


void TaskManager::addperson(Person &person) {

    SortedList<Person>::ConstIterator it = persons.begin();
    while ( it != persons.end()) {
        if ((*it).getName() == person.getName()) {
            throw std::runtime_error("Person '" + person.getName() + "' already exists");
        }
        ++it;
    }
    if (persons.length() >= MAX_PERSONS) {
        throw std::runtime_error("TaskManager is full. Cannot add more people.");
    }
    persons.addtoLst(person);

}
